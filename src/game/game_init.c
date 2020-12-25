#include <ultra64.h>

#include "sm64.h"
#include "gfx_dimensions.h"
#include "audio/external.h"
#include "buffers/buffers.h"
#include "buffers/gfx_output_buffer.h"
#include "buffers/framebuffers.h"
#include "buffers/zbuffer.h"
#include "engine/level_script.h"
#include "game_init.h"
#include "main.h"
#include "memory.h"
#include "profiler.h"
#include "save_file.h"
#include "seq_ids.h"
#include "sound_init.h"
#include "print.h"
#include "segment2.h"
#include "segment_symbols.h"
#include "rumble_init.h"
#include <prevent_bss_reordering.h>
#include "level_table.h"

// FIXME: I'm not sure all of these variables belong in this file, but I don't
// know of a good way to split them
struct Controller gControllers[3];
struct SPTask *gGfxSPTask;
Gfx *gDisplayListHead;
u8 *gGfxPoolEnd;
struct GfxPool *gGfxPool;
OSContStatus gControllerStatuses[4];
OSContPad gControllerPads[4];
u8 gControllerBits;
s8 gEepromProbe;
OSMesgQueue gGameVblankQueue;
OSMesgQueue D_80339CB8;
OSMesg D_80339CD0;
OSMesg D_80339CD4;
struct VblankHandler gGameVblankHandler;
uintptr_t gPhysicalFrameBuffers[3];
uintptr_t gPhysicalZBuffer;
void *D_80339CF0[2];
void *D_80339CF4;
struct MarioAnimation D_80339D10[2];
struct MarioAnimation gDemo;
UNUSED u8 filler80339D30[0x90];

s32 unused8032C690 = 0;
u32 gGlobalTimer = 0;

static u16 sCurrFBNum = 0;
u16 frameBufferIndex = 0;
void (*gGoddardVblankCallback)(void) = NULL;
struct Controller *gPlayer1Controller = &gControllers[0];
struct Controller *gPlayer2Controller = &gControllers[1];
// probably debug only, see note below
struct Controller *gPlayer3Controller = &gControllers[2];
struct DemoInput *gCurrDemoInput = NULL; // demo input sequence
u16 gDemoInputListID = 0;
u8 gActivePlayers = 2;
u8 singlePlayerChar = 0;
u8 coop = 0;
struct DemoInput gRecordedDemoInput = { 0 }; // possibly removed in EU. TODO: Check

/**
 * Initializes the Reality Display Processor (RDP).
 * This function initializes settings such as texture filtering mode,
 * scissoring, and render mode (although keep in mind that this render
 * mode is not used in-game, where it is set in render_graph_node.c).
 */
void my_rdp_init(void) {
    gDPPipeSync(gDisplayListHead++);
    gDPPipelineMode(gDisplayListHead++, G_PM_1PRIMITIVE);

    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);

    gDPSetTextureLOD(gDisplayListHead++, G_TL_TILE);
    gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
    gDPSetTextureDetail(gDisplayListHead++, G_TD_CLAMP);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    gDPSetTextureConvert(gDisplayListHead++, G_TC_FILT);

    gDPSetCombineKey(gDisplayListHead++, G_CK_NONE);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetColorDither(gDisplayListHead++, G_CD_MAGICSQ);
    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);

#ifdef VERSION_SH
    gDPSetAlphaDither(gDisplayListHead++, G_AD_PATTERN);
#endif
    gDPPipeSync(gDisplayListHead++);
}

/**
 * Initializes the RSP's built-in geometry and lighting engines.
 * Most of these (with the notable exception of gSPNumLights), are
 * almost immediately overwritten.
 */
void my_rsp_init(void) {
    gSPClearGeometryMode(gDisplayListHead++, G_SHADE | G_SHADING_SMOOTH | G_CULL_BOTH | G_FOG
                                                 | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR
                                                 | G_LOD);

    gSPSetGeometryMode(gDisplayListHead++, G_SHADE | G_SHADING_SMOOTH | G_CULL_BACK | G_LIGHTING);

    gSPNumLights(gDisplayListHead++, NUMLIGHTS_1);
    gSPTexture(gDisplayListHead++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);

    // @bug Nintendo did not explicitly define the clipping ratio.
    // For Fast3DEX2, this causes the dreaded warped vertices issue
    // unless the clipping ratio is changed back to the intended value,
    // as Fast3DEX2 uses a different initial value than Fast3D(EX).
#ifdef F3DEX_GBI_2
    gSPClipRatio(gDisplayListHead++, FRUSTRATIO_1);
#endif
}

/** Clear the Z buffer. */
void clear_z_buffer(void) { // RISKY
    int height = SCREEN_HEIGHT;

    gDPPipeSync(gDisplayListHead++);

    gDPSetDepthSource(gDisplayListHead++, G_ZS_PIXEL);
    gDPSetDepthImage(gDisplayListHead++, gPhysicalZBuffer);

    gDPSetColorImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, gPhysicalZBuffer);
    gDPSetFillColor(gDisplayListHead++, GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0));

    if ((PLAYERCOUNT > 1) && ((gCurrLevelNum != LEVEL_MIN) && !gIsInStarSelect && !gIsGameEnding)) {
        gDPFillRectangle(gDisplayListHead++, 0, height - height / (luigiCamFirst + 1), SCREEN_WIDTH - 1,
                         height / 2 * (luigiCamFirst + 1) - 1);
    } else {
        gDPFillRectangle(gDisplayListHead++, 0, BORDER_HEIGHT, SCREEN_WIDTH - 1,
                         SCREEN_HEIGHT - 1 - BORDER_HEIGHT);
    }
}

/** Sets up the final framebuffer image. */
void display_frame_buffer(void) {
    int c = BORDER_HEIGHT;
    int d = SCREEN_HEIGHT;
    int e = 0;
    if (sCurrFBNum == 0) { // RED asked me to change this KAZENOTE
        e = 2;
    } else {
        e = sCurrFBNum - 1;
    }
    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    if ((!luigiCamFirst) || (PLAYERCOUNT < 2)) {
        gDPSetColorImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                         gPhysicalFrameBuffers[frameBufferIndex]);
    } else {
        gDPSetColorImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                         gPhysicalFrameBuffers[e]);
    }

    if ((PLAYERCOUNT > 1)
        && ((gCurrLevelNum != LEVEL_MIN) && !gIsInStarSelect && !gIsGameEnding)) { // RISKY
        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, d - d / (luigiCamFirst + 1),
                      SCREEN_WIDTH, d / 2 * (luigiCamFirst + 1));
    } else {
        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, c, SCREEN_WIDTH, d);
    }
}

/** Clears the framebuffer, allowing it to be overwritten. */
void clear_frame_buffer(s32 color) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);

    gDPSetFillColor(gDisplayListHead++, color);
    gDPFillRectangle(gDisplayListHead++, GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(0), BORDER_HEIGHT,
                     GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(0) - 1, SCREEN_HEIGHT - BORDER_HEIGHT - 1);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
}

/** Clears and initializes the viewport. */
void clear_viewport(Vp *viewport, s32 color) {
    s16 vpUlx = (viewport->vp.vtrans[0] - viewport->vp.vscale[0]) / 4 + 1;
    s16 vpUly = (viewport->vp.vtrans[1] - viewport->vp.vscale[1]) / 4 + 1;
    s16 vpLrx = (viewport->vp.vtrans[0] + viewport->vp.vscale[0]) / 4 - 2;
    s16 vpLry = (viewport->vp.vtrans[1] + viewport->vp.vscale[1]) / 4 - 2;

#ifdef WIDESCREEN
    vpUlx = GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(vpUlx);
    vpLrx = GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(SCREEN_WIDTH - vpLrx);
#endif

    gDPPipeSync(gDisplayListHead++);

    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);

    gDPSetFillColor(gDisplayListHead++, color);
    gDPFillRectangle(gDisplayListHead++, vpUlx, vpUly, vpLrx, vpLry);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
}

/** Draws the horizontal screen borders */
void draw_screen_borders(void) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);

    gDPSetFillColor(gDisplayListHead++, GPACK_RGBA5551(0, 0, 0, 0) << 16 | GPACK_RGBA5551(0, 0, 0, 0));

#if BORDER_HEIGHT != 0
    gDPFillRectangle(gDisplayListHead++, GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(0), 0,
                     GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(0) - 1, BORDER_HEIGHT - 1);
    gDPFillRectangle(gDisplayListHead++, GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(0),
                     SCREEN_HEIGHT - BORDER_HEIGHT, GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(0) - 1,
                     SCREEN_HEIGHT - 1);
#endif
}

void make_viewport_clip_rect(Vp *viewport) {
    s16 vpUlx = (viewport->vp.vtrans[0] - viewport->vp.vscale[0]) / 4 + 1;
    s16 vpPly = (viewport->vp.vtrans[1] - viewport->vp.vscale[1]) / 4 + 1;
    s16 vpLrx = (viewport->vp.vtrans[0] + viewport->vp.vscale[0]) / 4 - 1;
    s16 vpLry = (viewport->vp.vtrans[1] + viewport->vp.vscale[1]) / 4 - 1;

    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, vpUlx, vpPly, vpLrx, vpLry);
}

/**
 * Loads the F3D microcodes.
 * Refer to this function if you would like to load
 * other microcodes (i.e. S2DEX).
 */
void create_task_structure(void) {
    s32 entries = gDisplayListHead - gGfxPool->buffer;

    gGfxSPTask->msgqueue = &D_80339CB8;
    gGfxSPTask->msg = (OSMesg) 2;
    gGfxSPTask->task.t.type = M_GFXTASK;
    gGfxSPTask->task.t.ucode_boot = rspF3DBootStart;
    gGfxSPTask->task.t.ucode_boot_size = ((u8 *) rspF3DBootEnd - (u8 *) rspF3DBootStart);
    gGfxSPTask->task.t.flags = 0;
    gGfxSPTask->task.t.ucode = rspF3DStart;
    gGfxSPTask->task.t.ucode_data = rspF3DDataStart;
    gGfxSPTask->task.t.ucode_size = SP_UCODE_SIZE; // (this size is ignored)
    gGfxSPTask->task.t.ucode_data_size = SP_UCODE_DATA_SIZE;
    gGfxSPTask->task.t.dram_stack = (u64 *) gGfxSPTaskStack;
    gGfxSPTask->task.t.dram_stack_size = SP_DRAM_STACK_SIZE8;
    gGfxSPTask->task.t.output_buff = gGfxSPTaskOutputBuffer;
    gGfxSPTask->task.t.output_buff_size =
        (u64 *) ((u8 *) gGfxSPTaskOutputBuffer + sizeof(gGfxSPTaskOutputBuffer));
    gGfxSPTask->task.t.data_ptr = (u64 *) &gGfxPool->buffer;
    gGfxSPTask->task.t.data_size = entries * sizeof(Gfx);
    gGfxSPTask->task.t.yield_data_ptr = (u64 *) gGfxSPTaskYieldBuffer;
    gGfxSPTask->task.t.yield_data_size = OS_YIELD_DATA_SIZE;
}

/** Starts rendering the scene. */
void init_render_image(void) {
    move_segment_table_to_dmem();
    my_rdp_init();
    my_rsp_init();
    clear_z_buffer();
    display_frame_buffer();
}

/** Ends the master display list. */
void end_master_display_list(void) {
    draw_screen_borders();
    if (gShowProfiler) {
        draw_profiler();
    }

    gDPFullSync(gDisplayListHead++);
    gSPEndDisplayList(gDisplayListHead++);

    create_task_structure();
}

void draw_reset_bars(void) {
    s32 sp24;
    s32 sp20;
    s32 fbNum;
    u64 *sp18;
    int e;

    if (gResetTimer != 0 && D_8032C648 < 15) {
        if (sCurrFBNum == 0) {
            fbNum = 2;
        } else {
            fbNum = sCurrFBNum - 1;
        }

        if (fbNum == 0) {
            e = 2;
        } else {
            e = fbNum - 1;
        }

        if ((!luigiCamFirst) || (PLAYERCOUNT < 2)) {
            sp18 = (u64 *) PHYSICAL_TO_VIRTUAL(gPhysicalFrameBuffers[fbNum]);
        } else {
            sp18 = (u64 *) PHYSICAL_TO_VIRTUAL(gPhysicalFrameBuffers[e]);
        }

        sp18 += D_8032C648++ * (SCREEN_WIDTH / 4);

        for (sp24 = 0; sp24 < ((SCREEN_HEIGHT / 16) + 1); sp24++) {
            // Loop must be one line to match on -O2
            for (sp20 = 0; sp20 < (SCREEN_WIDTH / 4); sp20++)
                *sp18++ = 0;
            sp18 += ((SCREEN_WIDTH / 4) * 14);
        }
    }

    osWritebackDCacheAll();
    osRecvMesg(&gGameVblankQueue, &D_80339BEC, OS_MESG_BLOCK);
    osRecvMesg(&gGameVblankQueue, &D_80339BEC, OS_MESG_BLOCK);
}

void rendering_init(void) {
    gGfxPool = &gGfxPools[0];
    set_segment_base_addr(1, gGfxPool->buffer);
    gGfxSPTask = &gGfxPool->spTask;
    gDisplayListHead = gGfxPool->buffer;
    gGfxPoolEnd = (u8 *) (gGfxPool->buffer + GFX_POOL_SIZE);
    init_render_image();
    clear_frame_buffer(0);
    end_master_display_list();
    send_display_list(&gGfxPool->spTask);

    frameBufferIndex++;
    gGlobalTimer++;
}

void config_gfx_pool(void) {
    gGfxPool = &gGfxPools[gGlobalTimer % 2];
    set_segment_base_addr(1, gGfxPool->buffer);
    gGfxSPTask = &gGfxPool->spTask;
    gDisplayListHead = gGfxPool->buffer;
    gGfxPoolEnd = (u8 *) (gGfxPool->buffer + GFX_POOL_SIZE);
}

/** Handles vsync. */
void display_and_vsync(void) {
    profiler_log_thread5_time(BEFORE_DISPLAY_LISTS);
    osRecvMesg(&D_80339CB8, &D_80339BEC, OS_MESG_BLOCK);
    if (gGoddardVblankCallback != NULL) {
        gGoddardVblankCallback();
        gGoddardVblankCallback = NULL;
    }
    send_display_list(&gGfxPool->spTask);
    profiler_log_thread5_time(AFTER_DISPLAY_LISTS);
    if (PLAYERCOUNT < 2) {
        osRecvMesg(&gGameVblankQueue, &D_80339BEC, OS_MESG_BLOCK);
    }

    if ((gCurrLevelNum == LEVEL_MIN) && !gIsInStarSelect && !gIsGameEnding) {
        osRecvMesg(&gGameVblankQueue, &D_80339BEC, OS_MESG_BLOCK);
    }
    if (PLAYERCOUNT < 2) {

        osViSwapBuffer((void *) PHYSICAL_TO_VIRTUAL(gPhysicalFrameBuffers[sCurrFBNum]));
    } else {

        if ((gCurrLevelNum != LEVEL_MIN) && !gIsInStarSelect && !gIsGameEnding) {
            if (!luigiCamFirst) {
                osViSwapBuffer((void *) PHYSICAL_TO_VIRTUAL(gPhysicalFrameBuffers[sCurrFBNum]));
            }
        } else {
            osViSwapBuffer((void *) PHYSICAL_TO_VIRTUAL(gPhysicalFrameBuffers[sCurrFBNum]));
        }
    }

    profiler_log_thread5_time(THREAD5_END);
    osRecvMesg(&gGameVblankQueue, &D_80339BEC, OS_MESG_BLOCK);
    if (++sCurrFBNum == 3) {
        sCurrFBNum = 0;
    }
    if (++frameBufferIndex == 3) {
        frameBufferIndex = 0;
    }
    gGlobalTimer++;
}

// this function records distinct inputs over a 255-frame interval to RAM locations and was likely
// used to record the demo sequences seen in the final game. This function is unused.
static void record_demo(void) {
}

// take the updated controller struct and calculate
// the new x, y, and distance floats.
void adjust_analog_stick(struct Controller *controller) {
    UNUSED u8 pad[8];

    // reset the controller's x and y floats.
    controller->stickX = 0;
    controller->stickY = 0;

    // modulate the rawStickX and rawStickY to be the new f32 values by adding/subtracting 6.
    if (controller->rawStickX <= -8) {
        controller->stickX = controller->rawStickX + 6;
    }

    if (controller->rawStickX >= 8) {
        controller->stickX = controller->rawStickX - 6;
    }

    if (controller->rawStickY <= -8) {
        controller->stickY = controller->rawStickY + 6;
    }

    if (controller->rawStickY >= 8) {
        controller->stickY = controller->rawStickY - 6;
    }

    // calculate f32 magnitude from the center by vector length.
    controller->stickMag =
        sqrtf(controller->stickX * controller->stickX + controller->stickY * controller->stickY);

    // magnitude cannot exceed 64.0f: if it does, modify the values appropriately to
    // flatten the values down to the allowed maximum value.
    if (controller->stickMag > 64) {
        controller->stickX *= 64 / controller->stickMag;
        controller->stickY *= 64 / controller->stickMag;
        controller->stickMag = 64;
    }
}

// if a demo sequence exists, this will run the demo
// input list until it is complete. called every frame.
void run_demo_inputs(void) {
}

// update the controller struct with available inputs if present.
void read_controller_inputs(void) {
    s32 i;

    for (i = 0; i < PLAYERCOUNT; i++) {
        struct Controller *controller = &gControllers[i];

        // if we're receiving inputs, update the controller struct
        // with the new button info.
        if (controller->controllerData != NULL) {
            controller->rawStickX = controller->controllerData->stick_x;
            controller->rawStickY = controller->controllerData->stick_y;
            controller->buttonPressed = controller->controllerData->button
                                        & (controller->controllerData->button ^ controller->buttonDown);
            // 0.5x A presses are a good meme
            controller->buttonDown = controller->controllerData->button;
            adjust_analog_stick(controller);
        } else // otherwise, if the controllerData is NULL, 0 out all of the inputs.
        {
            controller->rawStickX = 0;
            controller->rawStickY = 0;
            controller->buttonPressed = 0;
            controller->buttonDown = 0;
            controller->stickX = 0;
            controller->stickY = 0;
            controller->stickMag = 0;
        }
    }

    // For some reason, player 1's inputs are copied to player 3's port. This
    // potentially may have been a way the developers "recorded" the inputs
    // for demos, despite record_demo existing.
    gPlayer3Controller->rawStickX = gPlayer1Controller->rawStickX;
    gPlayer3Controller->rawStickY = gPlayer1Controller->rawStickY;
    gPlayer3Controller->stickX = gPlayer1Controller->stickX;
    gPlayer3Controller->stickY = gPlayer1Controller->stickY;
    gPlayer3Controller->stickMag = gPlayer1Controller->stickMag;
    gPlayer3Controller->buttonPressed = gPlayer1Controller->buttonPressed;
    gPlayer3Controller->buttonDown = gPlayer1Controller->buttonDown;
}

// initialize the controller structs to point at the OSCont information.
void init_controllers(void) {
    s16 port, cont;

    // set controller 1 to point to the set of status/pads for input 1 and
    // init the controllers.
    gControllers[0].statusData = &gControllerStatuses[0];
    gControllers[0].controllerData = &gControllerPads[0];
    osContInit(&gSIEventMesgQueue, &gControllerBits, &gControllerStatuses[0]);
    // strangely enough, the EEPROM probe for save data is done in this function.
    // save pak detection?
    gEepromProbe = osEepromProbe(&gSIEventMesgQueue);

    // loop over the 4 ports and link the controller structs to the appropriate
    // status and pad. Interestingly, although there are pointers to 3 controllers,
    // only 2 are connected here. The third seems to have been reserved for debug
    // purposes and was never connected in the retail ROM, thus gPlayer3Controller
    // cannot be used, despite being referenced in various code.
    for (cont = 0, port = 0; port < 4 && cont < 2; port++) {
        // is controller plugged in?
        if (gControllerBits & (1 << port)) {
            // the game allows you to have just 1 controller plugged
            // into any port in order to play the game. this was probably
            // so if any of the ports didn't work, you can have controllers
            // plugged into any of them and it will work.
#ifdef VERSION_SH
            gControllers[cont].port = port;
#endif
            gControllers[cont].statusData = &gControllerStatuses[port];
            gControllers[cont++].controllerData = &gControllerPads[port];
        }
    }
}

void setup_game_memory(void) {
    int i = 0;
    UNUSED u8 pad[8];

    set_segment_base_addr(0, (void *) 0x80000000);
    osCreateMesgQueue(&D_80339CB8, &D_80339CD4, 1);
    osCreateMesgQueue(&gGameVblankQueue, &D_80339CD0, 1);
    gPhysicalZBuffer = VIRTUAL_TO_PHYSICAL(gZBuffer);
    gPhysicalFrameBuffers[0] = VIRTUAL_TO_PHYSICAL(gFrameBuffer0);
    gPhysicalFrameBuffers[1] = VIRTUAL_TO_PHYSICAL(gFrameBuffer1);
    gPhysicalFrameBuffers[2] = VIRTUAL_TO_PHYSICAL(gFrameBuffer2);

    for (i = 0; i < PLAYERCOUNT; i++) {
        D_80339CF0[i] = main_pool_alloc(0x4000, MEMORY_POOL_LEFT);
        set_segment_base_addr(17, (void *) D_80339CF0[i]);
        func_80278A78(&D_80339D10[i], gMarioAnims, D_80339CF0[i]);
    }

    D_80339CF4 = main_pool_alloc(2048, MEMORY_POOL_LEFT);
    set_segment_base_addr(24, (void *) D_80339CF4);
    func_80278A78(&gDemo, gDemoInputs, D_80339CF4);
    load_segment(0x10, _entrySegmentRomStart, _entrySegmentRomEnd, MEMORY_POOL_LEFT);
    load_segment_decompress(2, _segment2_mio0SegmentRomStart, _segment2_mio0SegmentRomEnd);
}

// main game loop thread. runs forever as long as the game
// continues.
void thread5_game_loop(UNUSED void *arg) {
    struct LevelCommand *addr;

    setup_game_memory();
#ifdef VERSION_SH
    init_rumble_pak_scheduler_queue();
#endif
    init_controllers();
#ifdef VERSION_SH
    create_thread_6();
#endif
    save_file_load_all();

    set_vblank_handler(2, &gGameVblankHandler, &gGameVblankQueue, (OSMesg) 1);

    // point addr to the entry point into the level script data.
    addr = segmented_to_virtual(level_script_entry);

    play_music(SEQ_PLAYER_SFX, SEQUENCE_ARGS(0, SEQ_SOUND_PLAYER), 0);
    set_sound_mode(save_file_get_sound_mode());
    rendering_init();

    while (TRUE) {
        // if the reset timer is active, run the process to reset the game.
        if (gResetTimer) {
            draw_reset_bars();
            continue;
        }
        profiler_log_thread5_time(THREAD5_START);

        // if any controllers are plugged in, start read the data for when
        // read_controller_inputs is called later.
        if (gControllerBits) {
#ifdef VERSION_SH
            block_until_rumble_pak_free();
#endif
            osContStartReadData(&gSIEventMesgQueue);
        }

        audio_game_loop_tick();
        config_gfx_pool();
        if (gControllerBits) {
            osRecvMesg(&gSIEventMesgQueue, &D_80339BEC, OS_MESG_BLOCK);
            osContGetReadData(&gControllerPads[0]);
        }
        if ((PLAYERCOUNT < 2)
            || (!luigiCamFirst)) { // dont drop inputs 50% of the time. you also need to put the game to
            // 60fps and run object loops every other frame. implement frame skip.
            read_controller_inputs();
        }
        addr = level_script_execute(addr);

        display_and_vsync();

        // when debug info is enabled, print the "BUF %d" information.
        if (gShowDebugText) {
            // subtract the end of the gfx pool with the display list to obtain the
            // amount of free space remaining.
            print_text_fmt_int(180, 20, "BUF %d", gGfxPoolEnd - (u8 *) gDisplayListHead);
        }
    }
}
