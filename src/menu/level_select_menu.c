#include <PR/ultratypes.h>

#include "audio/external.h"
#include "engine/math_util.h"
#include "game/area.h"
#include "game/game_init.h"
#include "game/level_update.h"
#include "game/main.h"
#include "game/memory.h"
#include "game/print.h"
#include "game/save_file.h"
#include "game/sound_init.h"
#include "level_table.h"
#include "seq_ids.h"
#include "sm64.h"

#define PRESS_START_DEMO_TIMER 800

#define STUB_LEVEL(textname, _1, _2, _3, _4, _5, _6, _7, _8) textname,
#define DEFINE_LEVEL(textname, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) textname,

static char gLevelSelect_StageNamesText[64][16] = {
    #include "levels/level_defines.h"
};
#undef STUB_LEVEL
#undef DEFINE_LEVEL

static u16 gDemoCountdown = 0;
#ifndef VERSION_JP
static s16 D_U_801A7C34 = 1;
static s16 gameOverNotPlayed = 1;
#endif

// run the demo timer on the PRESS START screen.
// this function will return a non-0 timer once
// the demo starts, signaling to the subsystem that
// the demo needs to be ran.

// don't shift this function from being the first function in the segment.
// the level scripts assume this function is the first, so it cant be moved.
s32 run_press_start_demo_timer(s32 timer) {
    gCurrDemoInput = NULL;

    if (timer == 0) {
        if (!gPlayer1Controller->buttonDown && !gPlayer1Controller->stickMag) {
            if ((++gDemoCountdown) == PRESS_START_DEMO_TIMER) {
            }
        } else { // activity was detected, so reset the demo countdown.
            gDemoCountdown = 0;
        }
    }
    return timer;
}

// input loop for the level select menu. updates the selected stage
// count if an input was received. signals the stage to be started
// or the level select to be exited if start or the quit combo is
// pressed.
//also allow player 2 inputs
s16 level_select_input_loop(void) {
}

int startGame = 0; //set this to 1 if a mode has been selected
extern int toggle;
s32 intro_default(void) {
    s32 sp1C = 0;

    if (D_U_801A7C34 == 1) {
        if (gGlobalTimer < 0x81) {
            play_sound(SOUND_MARIO_HELLO, gDefaultSoundArgs);
        } else {
            play_sound(SOUND_MARIO_PRESS_START_TO_PLAY, gDefaultSoundArgs);
        }
        D_U_801A7C34 = 0;
        startGame = 0;
    }
    if (!toggle){
        startGame = 0;
    }
    print_intro_text();
    if (startGame/* || ((gPlayer1Controller->buttonPressed | gPlayer2Controller->buttonPressed) & START_BUTTON)*/) {
        play_sound(SOUND_MENU_STAR_SOUND, gDefaultSoundArgs);
        sp1C = 100 + gDebugLevelSelect;
        D_U_801A7C34 = 1;
    }
    return run_press_start_demo_timer(sp1C);
}

s32 intro_game_over(void) {
    s32 sp1C = 0;

#ifndef VERSION_JP
    if (gameOverNotPlayed == 1) {
        play_sound(SOUND_MARIO_GAME_OVER, gDefaultSoundArgs);
        gameOverNotPlayed = 0;
    }
#endif

    print_intro_text();

    if ((gPlayer1Controller->buttonPressed | gPlayer2Controller->buttonPressed) & START_BUTTON) {
        play_sound(SOUND_MENU_STAR_SOUND, gDefaultSoundArgs);
        sp1C = 100 + gDebugLevelSelect;
#ifndef VERSION_JP
        gameOverNotPlayed = 1;
#endif
    }
    return run_press_start_demo_timer(sp1C);
}

s32 intro_play_its_a_me_mario(void) {
    set_background_music(0, SEQ_SOUND_PLAYER, 0);
    play_sound(SOUND_MENU_COIN_ITS_A_ME_MARIO, gDefaultSoundArgs);
    return 1;
}

s32 lvl_intro_update(s16 arg1, UNUSED s32 arg2) {
    s32 retVar;

    switch (arg1) {
        case 0:
            retVar = intro_play_its_a_me_mario();
            break;
        case 1:
            retVar = intro_default();
            break;
        case 2:
            retVar = intro_game_over();
            break;
        case 3:
            retVar = level_select_input_loop();
            break;
    }
    return retVar;
}
