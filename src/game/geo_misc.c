#include <PR/ultratypes.h>

#include "sm64.h"
#include "geo_misc.h"

#include "area.h"
#include "engine/math_util.h"
#include "level_update.h"
#include "levels/castle_inside/header.h"
#include "levels/ending/header.h"
#include "levels/rr/header.h"
#include "mario.h"
#include "mario_actions_cutscene.h"
#include "memory.h"
#include "object_list_processor.h"
#include "rendering_graph_node.h"
#include "save_file.h"
#include "segment2.h"

/**
 * @file geo_misc.c
 * This file contains miscellaneous geo_asm scripts.
 *
 * In particular, it builds:
 *   - the light that shows the player where to look for Tower of the Wing Cap,
 *   - the flying carpets seen in Rainbow Ride, and
 *   - the end screen displaying Peach's delicious cake.
 */

#define NUM_FLYING_CARPET_VERTICES 21
extern const s16 flying_carpet_static_vertex_data[NUM_FLYING_CARPET_VERTICES];

static s16 sCurAreaTimer = 1;
static s16 sPrevAreaTimer = 0;
static s16 sFlyingCarpetRippleTimer = 0;

s8 gFlyingCarpetState;

/**
 * Create a vertex with the given parameters and insert it into `vtx` at
 * position `n`.
 *
 * Texture coordinates are s10.5 fixed-point, which means you should left-shift the actual coordinates
 * by 5.
 */
#ifndef GBI_FLOATS
void make_vertex(Vtx *vtx, s32 n, s16 x, s16 y, s16 z, s16 tx, s16 ty, u8 r, u8 g, u8 b, u8 a) {
#else
void make_vertex(Vtx *vtx, s32 n, f32 x, f32 y, f32 z, s16 tx, s16 ty, u8 r, u8 g, u8 b, u8 a) {
#endif
    vtx[n].v.ob[0] = x;
    vtx[n].v.ob[1] = y;
    vtx[n].v.ob[2] = z;

    vtx[n].v.flag = 0;

    vtx[n].v.tc[0] = tx;
    vtx[n].v.tc[1] = ty;

    vtx[n].v.cn[0] = r;
    vtx[n].v.cn[1] = g;
    vtx[n].v.cn[2] = b;
    vtx[n].v.cn[3] = a;
}

/**
 * Round `num` to the nearest `s16`.
 */
s16 round_float(f32 num) {
    // Note that double literals are used here, rather than float literals.
    if (num >= 0.0) {
        return num + 0.5;
    } else {
        return num - 0.5;
    }
}

extern Vtx sample_Plane_mesh_vtx_0[4];
extern Vtx sample_Plane_mesh_vtx_1[4];
extern Vtx sample_Plane_mesh_vtx_2[4];
extern Vtx sample_Plane_mesh_vtx_3[4];
/**
 * Create a display list for the light in the castle lobby that shows the
 * player where to look to enter Tower of the Wing Cap.
 */
#define scaleDist 2500.f
void editLights(Vtx *a) {
    f32 x;
    f32 z;
    int Max = 0x700;
    x = gMarioStates[luigiCamFirst].pos[0] - 7178.f;
    z = gMarioStates[luigiCamFirst].pos[2] - 6168.f;
  /*  if (x > (gMarioStates[1].pos[0] - 7178.f)) {
        x = gMarioStates[1].pos[0] - 7178.f;
    }
    if (z > (gMarioStates[1].pos[2] - 6168.f)) {
        z = gMarioStates[1].pos[2] - 6168.f;
    }*/

    Max -= (sqrtf(x * x + z * z) / scaleDist) * 290.f;
    if (Max < 0) {
        Max = 0;
    }
    if (Max > 0xff) {
        Max = 0xff;
    }
    a->v.cn[3] = Max; // ff is bowser, 0 is peach
}
Gfx *geo_exec_inside_castle_light(s32 callContext, struct GraphNode *node, UNUSED f32 mtx[4][4]) {
    s32 flags;
    struct GraphNodeGenerated *generatedNode;
    Gfx *displayListHead = NULL;
    Gfx *displayList = NULL;
    int i;
    Vtx *manipulate;

    if (callContext == GEO_CONTEXT_RENDER) {
        manipulate = segmented_to_virtual(sample_Plane_mesh_vtx_0);
        for (i = 0; i < 4; i++) {
            editLights(&manipulate[i]);
        }
        manipulate = segmented_to_virtual(sample_Plane_mesh_vtx_1);
        for (i = 0; i < 4; i++) {
            editLights(&manipulate[i]);
        }
        manipulate = segmented_to_virtual(sample_Plane_mesh_vtx_2);
        for (i = 0; i < 4; i++) {
            editLights(&manipulate[i]);
        }
        manipulate = segmented_to_virtual(sample_Plane_mesh_vtx_3);
        for (i = 0; i < 4; i++) {
            editLights(&manipulate[i]);
        }

        flags = save_file_get_flags();
        if (gHudDisplay.stars >= 10 && !(flags & SAVE_FLAG_HAVE_WING_CAP)) {
            displayList = alloc_display_list(2 * sizeof(*displayList));

            if (displayList == NULL) {
                return NULL;
            } else {
                displayListHead = displayList;
            }

            generatedNode = (struct GraphNodeGenerated *) node;
            generatedNode->fnNode.node.flags = (generatedNode->fnNode.node.flags & 0xFF) | 0x500;

            gSPDisplayList(displayListHead++, dl_castle_lobby_wing_cap_light);
            gSPEndDisplayList(displayListHead);
        }
    }

    return displayList;
}

/**
 * Update static timer variables that control the flying carpets' ripple effect.
 */
Gfx *geo_exec_flying_carpet_timer_update(s32 callContext, UNUSED struct GraphNode *node,
                                         UNUSED f32 mtx[4][4]) {
    if (callContext != GEO_CONTEXT_RENDER) {
        sFlyingCarpetRippleTimer = 0;
        sPrevAreaTimer = gAreaUpdateCounter - 1;
        sCurAreaTimer = gAreaUpdateCounter;
        gFlyingCarpetState = FLYING_CARPET_IDLE;
    } else {
        sPrevAreaTimer = sCurAreaTimer;
        sCurAreaTimer = gAreaUpdateCounter;
        if (sPrevAreaTimer != sCurAreaTimer) {
            sFlyingCarpetRippleTimer += 0x400;
        }
    }

    return NULL;
}

/**
 * Create a display list for a flying carpet with dynamic ripples.
 */
Gfx *geo_exec_flying_carpet_create(s32 callContext, struct GraphNode *node, UNUSED f32 mtx[4][4]) {
    s16 n, row, col, x, y, z, tx, ty;
    Vtx *verts;
    struct GraphNodeGenerated *generatedNode = (struct GraphNodeGenerated *) node;

    s16 *sp64 = segmented_to_virtual(&flying_carpet_static_vertex_data);
    Gfx *displayList = NULL;
    Gfx *displayListHead = NULL;
    struct Object *curGraphNodeObject;

    if (callContext == GEO_CONTEXT_RENDER) {
        verts = alloc_display_list(NUM_FLYING_CARPET_VERTICES * sizeof(*verts));
        displayList = alloc_display_list(7 * sizeof(*displayList));
        displayListHead = displayList;

        if (verts == NULL || displayList == NULL) {
            return NULL;
        }

        generatedNode->fnNode.node.flags = (generatedNode->fnNode.node.flags & 0xFF) | 0x100;

        for (n = 0; n <= 20; n++) {
            row = n / 3;
            col = n % 3;

            x = sp64[n * 4 + 0];
            y = round_float(sins(sFlyingCarpetRippleTimer + (row << 12) + (col << 14)) * 20.0);
            z = sp64[n * 4 + 1];
            tx = sp64[n * 4 + 2];
            ty = sp64[n * 4 + 3];

            make_vertex(verts, n, x, y, z, tx, ty, 0, 127, 0, 255);
        }

        gSPDisplayList(displayListHead++, dl_flying_carpet_begin);

        // The forward half.
        gSPVertex(displayListHead++, verts, 12, 0);
        gSPDisplayList(displayListHead++, dl_flying_carpet_model_half);

        // The back half.
        gSPVertex(displayListHead++, verts + 9, 12, 0);
        gSPDisplayList(displayListHead++, dl_flying_carpet_model_half);

        gSPDisplayList(displayListHead++, dl_flying_carpet_end);
        gSPEndDisplayList(displayListHead);

        curGraphNodeObject = (struct Object *) gCurGraphNodeObject;
        if (gMarioObject->platform == curGraphNodeObject) {
            gFlyingCarpetState = FLYING_CARPET_MOVING_WITH_MARIO;
        } else if (curGraphNodeObject->oForwardVel != 0.0) {
            gFlyingCarpetState = FLYING_CARPET_MOVING_WITHOUT_MARIO;
        } else {
            gFlyingCarpetState = FLYING_CARPET_IDLE;
        }
    }

    return displayList;
}
void copyData(u32 *destination, u32 *source, u32 size) {
    u32 *end = destination + size;
    while (destination < end) {
        *destination = *source;
        destination++;
        source++;
    }
}
extern const u8 cake_end_texture_0[];
extern const u8 cake_end_texture_luigi_0[];
extern const u8 cake_end_texture_mario_0[];
/**
 * Create a display list for the end screen with Peach's delicious cake.
 */
Gfx *geo_exec_cake_end_screen(s32 callContext, struct GraphNode *node, UNUSED f32 mtx[4][4]) {
    struct GraphNodeGenerated *generatedNode = (struct GraphNodeGenerated *) node;
    Gfx *displayList = NULL;
    Gfx *displayListHead = NULL;
    // overwrite texture with other texture if not in coop mode
    if (ASSUMELOW == 1) {
        if (singlePlayerChar) {
            copyData(segmented_to_virtual(cake_end_texture_0),
                     segmented_to_virtual(cake_end_texture_luigi_0), 0xc80 * 12);
        } else {
            copyData(segmented_to_virtual(cake_end_texture_0),
                     segmented_to_virtual(cake_end_texture_mario_0), 0xc80 * 12);
        }
    }
    if (callContext == GEO_CONTEXT_RENDER) {
        displayList = alloc_display_list(3 * sizeof(*displayList));
        displayListHead = displayList;

        generatedNode->fnNode.node.flags = (generatedNode->fnNode.node.flags & 0xFF) | 0x100;
        gSPDisplayList(displayListHead++, dl_proj_mtx_fullscreen);
        gSPDisplayList(displayListHead++, dl_cake_end_screen);
        gSPEndDisplayList(displayListHead);
    }

    return displayList;
}
