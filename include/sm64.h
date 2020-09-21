#ifndef SM64_H
#define SM64_H

// Global header for Super Mario 64

#include "types.h"
#include "config.h"
#include "object_fields.h"
#include "object_constants.h"
#include "audio_defines.h"
#include "model_ids.h"
#include "mario_animation_ids.h"
#include "mario_geo_switch_case_ids.h"
#include "surface_terrains.h"
#include "macros.h"

// Crash handler enhancement
#ifdef CRASH_SCREEN_INCLUDED
#define DEBUG_ASSERT(exp) do { if (!(exp)) _n64_assert(__FILE__, __LINE__, #exp, 1); } while (0)
#else
#define DEBUG_ASSERT(exp)
#endif

// Pointer casting is technically UB, and avoiding it gets rid of endian issues
// as well as a nice side effect.
#ifdef AVOID_UB
#define GET_HIGH_U16_OF_32(var) ((u16)((var) >> 16))
#define GET_HIGH_S16_OF_32(var) ((s16)((var) >> 16))
#define GET_LOW_U16_OF_32(var) ((u16)((var) & 0xFFFF))
#define GET_LOW_S16_OF_32(var) ((s16)((var) & 0xFFFF))
#define SET_HIGH_U16_OF_32(var, x) ((var) = ((var) & 0xFFFF) | ((x) << 16))
#define SET_HIGH_S16_OF_32(var, x) ((var) = ((var) & 0xFFFF) | ((x) << 16))
#else
#define GET_HIGH_U16_OF_32(var) (((u16 *)&(var))[0])
#define GET_HIGH_S16_OF_32(var) (((s16 *)&(var))[0])
#define GET_LOW_U16_OF_32(var) (((u16 *)&(var))[1])
#define GET_LOW_S16_OF_32(var) (((s16 *)&(var))[1])
#define SET_HIGH_U16_OF_32(var, x) ((((u16 *)&(var))[0]) = (x))
#define SET_HIGH_S16_OF_32(var, x) ((((s16 *)&(var))[0]) = (x))
#endif

// Layers
#define LAYER_FORCE             0
#define LAYER_OPAQUE            1
#define LAYER_OPAQUE_DECAL      2
#define LAYER_OPAQUE_INTER      3
#define LAYER_ALPHA             4
#define LAYER_TRANSPARENT       5
#define LAYER_TRANSPARENT_DECAL 6
#define LAYER_TRANSPARENT_INTER 7

#define INPUT_NONZERO_ANALOG         0x0001
#define INPUT_A_PRESSED              0x0002
#define INPUT_OFF_FLOOR              0x0004
#define INPUT_ABOVE_SLIDE            0x0008
#define INPUT_FIRST_PERSON           0x0010
#define INPUT_UNKNOWN_5              0x0020
#define INPUT_SQUISHED               0x0040
#define INPUT_A_DOWN                 0x0080
#define INPUT_IN_POISON_GAS          0x0100
#define INPUT_IN_WATER               0x0200
#define INPUT_UNKNOWN_10             0x0400
#define INPUT_INTERACT_OBJ_GRABBABLE 0x0800
#define INPUT_UNKNOWN_12             0x1000
#define INPUT_B_PRESSED              0x2000
#define INPUT_Z_DOWN                 0x4000
#define INPUT_Z_PRESSED              0x8000

#define GROUND_STEP_LEFT_GROUND              0
#define GROUND_STEP_NONE                     1
#define GROUND_STEP_HIT_WALL                 2
#define GROUND_STEP_HIT_WALL_STOP_QSTEPS     2
#define GROUND_STEP_HIT_WALL_CONTINUE_QSTEPS 3

#define AIR_STEP_CHECK_LEDGE_GRAB 0x00000001
#define AIR_STEP_CHECK_HANG       0x00000002

#define AIR_STEP_NONE            0
#define AIR_STEP_LANDED          1
#define AIR_STEP_HIT_WALL        2
#define AIR_STEP_GRABBED_LEDGE   3
#define AIR_STEP_GRABBED_CEILING 4
#define AIR_STEP_HIT_LAVA_WALL   6

#define WATER_STEP_NONE        0
#define WATER_STEP_HIT_FLOOR   1
#define WATER_STEP_HIT_CEILING 2
#define WATER_STEP_CANCELLED   3
#define WATER_STEP_HIT_WALL    4

#define PARTICLE_DUST                 /* 0x00000001 */ (1 <<  0)
#define PARTICLE_VERTICAL_STAR        /* 0x00000002 */ (1 <<  1)
#define PARTICLE_2                    /* 0x00000004 */ (1 <<  2)
#define PARTICLE_SPARKLES             /* 0x00000008 */ (1 <<  3)
#define PARTICLE_HORIZONTAL_STAR      /* 0x00000010 */ (1 <<  4)
#define PARTICLE_BUBBLE               /* 0x00000020 */ (1 <<  5)
#define PARTICLE_WATER_SPLASH         /* 0x00000040 */ (1 <<  6)
#define PARTICLE_IDLE_WATER_WAVE      /* 0x00000080 */ (1 <<  7)
#define PARTICLE_SHALLOW_WATER_WAVE   /* 0x00000100 */ (1 <<  8)
#define PARTICLE_PLUNGE_BUBBLE        /* 0x00000200 */ (1 <<  9)
#define PARTICLE_WAVE_TRAIL           /* 0x00000400 */ (1 << 10)
#define PARTICLE_FIRE                 /* 0x00000800 */ (1 << 11)
#define PARTICLE_SHALLOW_WATER_SPLASH /* 0x00001000 */ (1 << 12)
#define PARTICLE_LEAF                 /* 0x00002000 */ (1 << 13)
#define PARTICLE_SNOW                 /* 0x00004000 */ (1 << 14)
#define PARTICLE_DIRT                 /* 0x00008000 */ (1 << 15)
#define PARTICLE_MIST_CIRCLE          /* 0x00010000 */ (1 << 16)
#define PARTICLE_BREATH               /* 0x00020000 */ (1 << 17)
#define PARTICLE_TRIANGLE             /* 0x00040000 */ (1 << 18)
#define PARTICLE_19                   /* 0x00080000 */ (1 << 19)

#define MODEL_STATE_NOISE_ALPHA 0x180
#define MODEL_STATE_METAL       0x200

#define MARIO_NORMAL_CAP                0x00000001
#define MARIO_VANISH_CAP                0x00000002
#define MARIO_METAL_CAP                 0x00000004
#define MARIO_WING_CAP                  0x00000008
#define MARIO_CAP_ON_HEAD               0x00000010
#define MARIO_CAP_IN_HAND               0x00000020
#define MARIO_METAL_SHOCK               0x00000040
#define MARIO_TELEPORTING               0x00000080
#define MARIO_UNKNOWN_08                0x00000100
#define MARIO_UNKNOWN_13                0x00002000
#define MARIO_ACTION_SOUND_PLAYED       0x00010000
#define MARIO_MARIO_SOUND_PLAYED        0x00020000
#define MARIO_UNKNOWN_18                0x00040000
#define MARIO_PUNCHING                  0x00100000
#define MARIO_KICKING                   0x00200000
#define MARIO_TRIPPING                  0x00400000
#define MARIO_UNKNOWN_25                0x02000000
#define MARIO_UNKNOWN_30                0x40000000
#define MARIO_UNKNOWN_31                0x80000000

#define MARIO_SPECIAL_CAPS (MARIO_VANISH_CAP | MARIO_METAL_CAP | MARIO_WING_CAP)
#define MARIO_CAPS (MARIO_NORMAL_CAP | MARIO_SPECIAL_CAPS)

#define ACT_ID_MASK 0x000001FF

#define ACT_GROUP_MASK       0x000001C0
#define ACT_GROUP_STATIONARY /* 0x00000000 */ (0 << 6)
#define ACT_GROUP_MOVING     /* 0x00000040 */ (1 << 6)
#define ACT_GROUP_AIRBORNE   /* 0x00000080 */ (2 << 6)
#define ACT_GROUP_SUBMERGED  /* 0x000000C0 */ (3 << 6)
#define ACT_GROUP_CUTSCENE   /* 0x00000100 */ (4 << 6)
#define ACT_GROUP_AUTOMATIC  /* 0x00000140 */ (5 << 6)
#define ACT_GROUP_OBJECT     /* 0x00000180 */ (6 << 6)

#define ACT_FLAG_STATIONARY                  /* 0x00000200 */ (1 <<  9)
#define ACT_FLAG_MOVING                      /* 0x00000400 */ (1 << 10)
#define ACT_FLAG_AIR                         /* 0x00000800 */ (1 << 11)
#define ACT_FLAG_INTANGIBLE                  /* 0x00001000 */ (1 << 12)
#define ACT_FLAG_SWIMMING                    /* 0x00002000 */ (1 << 13)
#define ACT_FLAG_METAL_WATER                 /* 0x00004000 */ (1 << 14)
#define ACT_FLAG_SHORT_HITBOX                /* 0x00008000 */ (1 << 15)
#define ACT_FLAG_RIDING_SHELL                /* 0x00010000 */ (1 << 16)
#define ACT_FLAG_INVULNERABLE                /* 0x00020000 */ (1 << 17)
#define ACT_FLAG_BUTT_OR_STOMACH_SLIDE       /* 0x00040000 */ (1 << 18)
#define ACT_FLAG_DIVING                      /* 0x00080000 */ (1 << 19)
#define ACT_FLAG_ON_POLE                     /* 0x00100000 */ (1 << 20)
#define ACT_FLAG_HANGING                     /* 0x00200000 */ (1 << 21)
#define ACT_FLAG_IDLE                        /* 0x00400000 */ (1 << 22)
#define ACT_FLAG_ATTACKING                   /* 0x00800000 */ (1 << 23)
#define ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION  /* 0x01000000 */ (1 << 24)
#define ACT_FLAG_CONTROL_JUMP_HEIGHT         /* 0x02000000 */ (1 << 25)
#define ACT_FLAG_ALLOW_FIRST_PERSON          /* 0x04000000 */ (1 << 26)
#define ACT_FLAG_PAUSE_EXIT                  /* 0x08000000 */ (1 << 27)
#define ACT_FLAG_SWIMMING_OR_FLYING          /* 0x10000000 */ (1 << 28)
#define ACT_FLAG_WATER_OR_TEXT               /* 0x20000000 */ (1 << 29)
#define ACT_FLAG_THROWING                    /* 0x80000000 */ (1 << 31)

#define ACT_UNINITIALIZED              0x00000000 // (0x000)

// group 0x000: stationary actions
#define ACT_IDLE                       0x0C400201 // (0x001 | ACT_FLAG_STATIONARY | ACT_FLAG_IDLE | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_START_SLEEPING             0x0C400202 // (0x002 | ACT_FLAG_STATIONARY | ACT_FLAG_IDLE | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_SLEEPING                   0x0C000203 // (0x003 | ACT_FLAG_STATIONARY | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_WAKING_UP                  0x0C000204 // (0x004 | ACT_FLAG_STATIONARY | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_PANTING                    0x0C400205 // (0x005 | ACT_FLAG_STATIONARY | ACT_FLAG_IDLE | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_HOLD_PANTING_UNUSED        0x08000206 // (0x006 | ACT_FLAG_STATIONARY | ACT_FLAG_PAUSE_EXIT)
#define ACT_HOLD_IDLE                  0x08000207 // (0x007 | ACT_FLAG_STATIONARY | ACT_FLAG_PAUSE_EXIT)
#define ACT_HOLD_HEAVY_IDLE            0x08000208 // (0x008 | ACT_FLAG_STATIONARY | ACT_FLAG_PAUSE_EXIT)
#define ACT_STANDING_AGAINST_WALL      0x0C400209 // (0x009 | ACT_FLAG_STATIONARY | ACT_FLAG_IDLE | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_COUGHING                   0x0C40020A // (0x00A | ACT_FLAG_STATIONARY | ACT_FLAG_IDLE | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_SHIVERING                  0x0C40020B // (0x00B | ACT_FLAG_STATIONARY | ACT_FLAG_IDLE | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_IN_QUICKSAND               0x0002020D // (0x00D | ACT_FLAG_STATIONARY | ACT_FLAG_INVULNERABLE)
#define ACT_UNKNOWN_0002020E           0x0002020E // (0x00E | ACT_FLAG_STATIONARY | ACT_FLAG_INVULNERABLE)
#define ACT_CROUCHING                  0x0C008220 // (0x020 | ACT_FLAG_STATIONARY | ACT_FLAG_SHORT_HITBOX | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_START_CROUCHING            0x0C008221 // (0x021 | ACT_FLAG_STATIONARY | ACT_FLAG_SHORT_HITBOX | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_STOP_CROUCHING             0x0C008222 // (0x022 | ACT_FLAG_STATIONARY | ACT_FLAG_SHORT_HITBOX | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_START_CRAWLING             0x0C008223 // (0x023 | ACT_FLAG_STATIONARY | ACT_FLAG_SHORT_HITBOX | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_STOP_CRAWLING              0x0C008224 // (0x024 | ACT_FLAG_STATIONARY | ACT_FLAG_SHORT_HITBOX | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_SLIDE_KICK_SLIDE_STOP      0x08000225 // (0x025 | ACT_FLAG_STATIONARY | ACT_FLAG_PAUSE_EXIT)
#define ACT_SHOCKWAVE_BOUNCE           0x00020226 // (0x026 | ACT_FLAG_STATIONARY | ACT_FLAG_INVULNERABLE)
#define ACT_FIRST_PERSON               0x0C000227 // (0x027 | ACT_FLAG_STATIONARY | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_BACKFLIP_LAND_STOP         0x0800022F // (0x02F | ACT_FLAG_STATIONARY | ACT_FLAG_PAUSE_EXIT)
#define ACT_JUMP_LAND_STOP             0x0C000230 // (0x030 | ACT_FLAG_STATIONARY | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_DOUBLE_JUMP_LAND_STOP      0x0C000231 // (0x031 | ACT_FLAG_STATIONARY | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_FREEFALL_LAND_STOP         0x0C000232 // (0x032 | ACT_FLAG_STATIONARY | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_SIDE_FLIP_LAND_STOP        0x0C000233 // (0x033 | ACT_FLAG_STATIONARY | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_HOLD_JUMP_LAND_STOP        0x08000234 // (0x034 | ACT_FLAG_STATIONARY | ACT_FLAG_PAUSE_EXIT)
#define ACT_HOLD_FREEFALL_LAND_STOP    0x08000235 // (0x035 | ACT_FLAG_STATIONARY | ACT_FLAG_PAUSE_EXIT)
#define ACT_AIR_THROW_LAND             0x80000A36 // (0x036 | ACT_FLAG_STATIONARY | ACT_FLAG_AIR | ACT_FLAG_THROWING)
#define ACT_TWIRL_LAND                 0x18800238 // (0x038 | ACT_FLAG_STATIONARY | ACT_FLAG_ATTACKING | ACT_FLAG_PAUSE_EXIT | ACT_FLAG_SWIMMING_OR_FLYING)
#define ACT_LAVA_BOOST_LAND            0x08000239 // (0x039 | ACT_FLAG_STATIONARY | ACT_FLAG_PAUSE_EXIT)
#define ACT_TRIPLE_JUMP_LAND_STOP      0x0800023A // (0x03A | ACT_FLAG_STATIONARY | ACT_FLAG_PAUSE_EXIT)
#define ACT_LONG_JUMP_LAND_STOP        0x0800023B // (0x03B | ACT_FLAG_STATIONARY | ACT_FLAG_PAUSE_EXIT)
#define ACT_GROUND_POUND_LAND          0x0080023C // (0x03C | ACT_FLAG_STATIONARY | ACT_FLAG_ATTACKING)
#define ACT_BRAKING_STOP               0x0C00023D // (0x03D | ACT_FLAG_STATIONARY | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_BUTT_SLIDE_STOP            0x0C00023E // (0x03E | ACT_FLAG_STATIONARY | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_PAUSE_EXIT)
#define ACT_HOLD_BUTT_SLIDE_STOP       0x0800043F // (0x03F | ACT_FLAG_MOVING | ACT_FLAG_PAUSE_EXIT)

// group 0x040: moving (ground) actions
#define ACT_WALKING                    0x04000440 // (0x040 | ACT_FLAG_MOVING | ACT_FLAG_ALLOW_FIRST_PERSON)
#define ACT_HOLD_WALKING               0x00000442 // (0x042 | ACT_FLAG_MOVING)
#define ACT_TURNING_AROUND             0x00000443 // (0x043 | ACT_FLAG_MOVING)
#define ACT_FINISH_TURNING_AROUND      0x00000444 // (0x044 | ACT_FLAG_MOVING)
#define ACT_BRAKING                    0x04000445 // (0x045 | ACT_FLAG_MOVING | ACT_FLAG_ALLOW_FIRST_PERSON)
#define ACT_RIDING_SHELL_GROUND        0x20810446 // (0x046 | ACT_FLAG_MOVING | ACT_FLAG_RIDING_SHELL | ACT_FLAG_ATTACKING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_HOLD_HEAVY_WALKING         0x00000447 // (0x047 | ACT_FLAG_MOVING)
#define ACT_CRAWLING                   0x04008448 // (0x048 | ACT_FLAG_MOVING | ACT_FLAG_SHORT_HITBOX | ACT_FLAG_ALLOW_FIRST_PERSON)
#define ACT_BURNING_GROUND             0x00020449 // (0x049 | ACT_FLAG_MOVING | ACT_FLAG_INVULNERABLE)
#define ACT_DECELERATING               0x0400044A // (0x04A | ACT_FLAG_MOVING | ACT_FLAG_ALLOW_FIRST_PERSON)
#define ACT_HOLD_DECELERATING          0x0000044B // (0x04B | ACT_FLAG_MOVING)
#define ACT_BEGIN_SLIDING              0x00000050 // (0x050)
#define ACT_HOLD_BEGIN_SLIDING         0x00000051 // (0x051)
#define ACT_BUTT_SLIDE                 0x00840452 // (0x052 | ACT_FLAG_MOVING | ACT_FLAG_BUTT_OR_STOMACH_SLIDE | ACT_FLAG_ATTACKING)
#define ACT_STOMACH_SLIDE              0x008C0453 // (0x053 | ACT_FLAG_MOVING | ACT_FLAG_BUTT_OR_STOMACH_SLIDE | ACT_FLAG_DIVING | ACT_FLAG_ATTACKING)
#define ACT_HOLD_BUTT_SLIDE            0x00840454 // (0x054 | ACT_FLAG_MOVING | ACT_FLAG_BUTT_OR_STOMACH_SLIDE | ACT_FLAG_ATTACKING)
#define ACT_HOLD_STOMACH_SLIDE         0x008C0455 // (0x055 | ACT_FLAG_MOVING | ACT_FLAG_BUTT_OR_STOMACH_SLIDE | ACT_FLAG_DIVING | ACT_FLAG_ATTACKING)
#define ACT_DIVE_SLIDE                 0x00880456 // (0x056 | ACT_FLAG_MOVING | ACT_FLAG_DIVING | ACT_FLAG_ATTACKING)
#define ACT_MOVE_PUNCHING              0x00800457 // (0x057 | ACT_FLAG_MOVING | ACT_FLAG_ATTACKING)
#define ACT_CROUCH_SLIDE               0x04808459 // (0x059 | ACT_FLAG_MOVING | ACT_FLAG_SHORT_HITBOX | ACT_FLAG_ATTACKING | ACT_FLAG_ALLOW_FIRST_PERSON)
#define ACT_SLIDE_KICK_SLIDE           0x0080045A // (0x05A | ACT_FLAG_MOVING | ACT_FLAG_ATTACKING)
#define ACT_HARD_BACKWARD_GROUND_KB    0x00020460 // (0x060 | ACT_FLAG_MOVING | ACT_FLAG_INVULNERABLE)
#define ACT_HARD_FORWARD_GROUND_KB     0x00020461 // (0x061 | ACT_FLAG_MOVING | ACT_FLAG_INVULNERABLE)
#define ACT_BACKWARD_GROUND_KB         0x00020462 // (0x062 | ACT_FLAG_MOVING | ACT_FLAG_INVULNERABLE)
#define ACT_FORWARD_GROUND_KB          0x00020463 // (0x063 | ACT_FLAG_MOVING | ACT_FLAG_INVULNERABLE)
#define ACT_SOFT_BACKWARD_GROUND_KB    0x00020464 // (0x064 | ACT_FLAG_MOVING | ACT_FLAG_INVULNERABLE)
#define ACT_SOFT_FORWARD_GROUND_KB     0x00020465 // (0x065 | ACT_FLAG_MOVING | ACT_FLAG_INVULNERABLE)
#define ACT_GROUND_BONK                0x00020466 // (0x066 | ACT_FLAG_MOVING | ACT_FLAG_INVULNERABLE)
#define ACT_DEATH_EXIT_LAND            0x00020467 // (0x067 | ACT_FLAG_MOVING | ACT_FLAG_INVULNERABLE)
#define ACT_JUMP_LAND                  0x04000470 // (0x070 | ACT_FLAG_MOVING | ACT_FLAG_ALLOW_FIRST_PERSON)
#define ACT_FREEFALL_LAND              0x04000471 // (0x071 | ACT_FLAG_MOVING | ACT_FLAG_ALLOW_FIRST_PERSON)
#define ACT_DOUBLE_JUMP_LAND           0x04000472 // (0x072 | ACT_FLAG_MOVING | ACT_FLAG_ALLOW_FIRST_PERSON)
#define ACT_SIDE_FLIP_LAND             0x04000473 // (0x073 | ACT_FLAG_MOVING | ACT_FLAG_ALLOW_FIRST_PERSON)
#define ACT_HOLD_JUMP_LAND             0x00000474 // (0x074 | ACT_FLAG_MOVING)
#define ACT_HOLD_FREEFALL_LAND         0x00000475 // (0x075 | ACT_FLAG_MOVING)
#define ACT_QUICKSAND_JUMP_LAND        0x00000476 // (0x076 | ACT_FLAG_MOVING)
#define ACT_HOLD_QUICKSAND_JUMP_LAND   0x00000477 // (0x077 | ACT_FLAG_MOVING)
#define ACT_TRIPLE_JUMP_LAND           0x04000478 // (0x078 | ACT_FLAG_MOVING | ACT_FLAG_ALLOW_FIRST_PERSON)
#define ACT_LONG_JUMP_LAND             0x00000479 // (0x079 | ACT_FLAG_MOVING)
#define ACT_BACKFLIP_LAND              0x0400047A // (0x07A | ACT_FLAG_MOVING | ACT_FLAG_ALLOW_FIRST_PERSON)

// group 0x080: airborne actions
#define ACT_JUMP                       0x03000880 // (0x080 | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION | ACT_FLAG_CONTROL_JUMP_HEIGHT)
#define ACT_DOUBLE_JUMP                0x03000881 // (0x081 | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION | ACT_FLAG_CONTROL_JUMP_HEIGHT)
#define ACT_TRIPLE_JUMP                0x01000882 // (0x082 | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_BACKFLIP                   0x01000883 // (0x083 | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_STEEP_JUMP                 0x03000885 // (0x085 | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION | ACT_FLAG_CONTROL_JUMP_HEIGHT)
#define ACT_WALL_KICK_AIR              0x03000886 // (0x086 | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION | ACT_FLAG_CONTROL_JUMP_HEIGHT)
#define ACT_SIDE_FLIP                  0x01000887 // (0x087 | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_LONG_JUMP                  0x03000888 // (0x088 | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION | ACT_FLAG_CONTROL_JUMP_HEIGHT)
#define ACT_WATER_JUMP                 0x01000889 // (0x089 | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_DIVE                       0x0188088A // (0x08A | ACT_FLAG_AIR | ACT_FLAG_DIVING | ACT_FLAG_ATTACKING | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_FREEFALL                   0x0100088C // (0x08C | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_TOP_OF_POLE_JUMP           0x0300088D // (0x08D | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION | ACT_FLAG_CONTROL_JUMP_HEIGHT)
#define ACT_BUTT_SLIDE_AIR             0x0300088E // (0x08E | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION | ACT_FLAG_CONTROL_JUMP_HEIGHT)
#define ACT_FLYING_TRIPLE_JUMP         0x03000894 // (0x094 | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION | ACT_FLAG_CONTROL_JUMP_HEIGHT)
#define ACT_SHOT_FROM_CANNON           0x00880898 // (0x098 | ACT_FLAG_AIR | ACT_FLAG_DIVING | ACT_FLAG_ATTACKING)
#define ACT_FLYING                     0x10880899 // (0x099 | ACT_FLAG_AIR | ACT_FLAG_DIVING | ACT_FLAG_ATTACKING | ACT_FLAG_SWIMMING_OR_FLYING)
#define ACT_RIDING_SHELL_JUMP          0x0281089A // (0x09A | ACT_FLAG_AIR | ACT_FLAG_RIDING_SHELL | ACT_FLAG_ATTACKING | ACT_FLAG_CONTROL_JUMP_HEIGHT)
#define ACT_RIDING_SHELL_FALL          0x0081089B // (0x09B | ACT_FLAG_AIR | ACT_FLAG_RIDING_SHELL | ACT_FLAG_ATTACKING)
#define ACT_VERTICAL_WIND              0x1008089C // (0x09C | ACT_FLAG_AIR | ACT_FLAG_DIVING | ACT_FLAG_SWIMMING_OR_FLYING)
#define ACT_HOLD_JUMP                  0x030008A0 // (0x0A0 | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION | ACT_FLAG_CONTROL_JUMP_HEIGHT)
#define ACT_HOLD_FREEFALL              0x010008A1 // (0x0A1 | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_HOLD_BUTT_SLIDE_AIR        0x010008A2 // (0x0A2 | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_HOLD_WATER_JUMP            0x010008A3 // (0x0A3 | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_TWIRLING                   0x108008A4 // (0x0A4 | ACT_FLAG_AIR | ACT_FLAG_ATTACKING | ACT_FLAG_SWIMMING_OR_FLYING)
#define ACT_FORWARD_ROLLOUT            0x010008A6 // (0x0A6 | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_AIR_HIT_WALL               0x000008A7 // (0x0A7 | ACT_FLAG_AIR)
#define ACT_RIDING_HOOT                0x000004A8 // (0x0A8 | ACT_FLAG_MOVING)
#define ACT_GROUND_POUND               0x008008A9 // (0x0A9 | ACT_FLAG_AIR | ACT_FLAG_ATTACKING)
#define ACT_SLIDE_KICK                 0x018008AA // (0x0AA | ACT_FLAG_AIR | ACT_FLAG_ATTACKING | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_AIR_THROW                  0x830008AB // (0x0AB | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION | ACT_FLAG_CONTROL_JUMP_HEIGHT | ACT_FLAG_THROWING)
#define ACT_JUMP_KICK                  0x018008AC // (0x0AC | ACT_FLAG_AIR | ACT_FLAG_ATTACKING | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_BACKWARD_ROLLOUT           0x010008AD // (0x0AD | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_CRAZY_BOX_BOUNCE           0x000008AE // (0x0AE | ACT_FLAG_AIR)
#define ACT_SPECIAL_TRIPLE_JUMP        0x030008AF // (0x0AF | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION | ACT_FLAG_CONTROL_JUMP_HEIGHT)
#define ACT_BACKWARD_AIR_KB            0x010208B0 // (0x0B0 | ACT_FLAG_AIR | ACT_FLAG_INVULNERABLE | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_FORWARD_AIR_KB             0x010208B1 // (0x0B1 | ACT_FLAG_AIR | ACT_FLAG_INVULNERABLE | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_HARD_FORWARD_AIR_KB        0x010208B2 // (0x0B2 | ACT_FLAG_AIR | ACT_FLAG_INVULNERABLE | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_HARD_BACKWARD_AIR_KB       0x010208B3 // (0x0B3 | ACT_FLAG_AIR | ACT_FLAG_INVULNERABLE | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_BURNING_JUMP               0x010208B4 // (0x0B4 | ACT_FLAG_AIR | ACT_FLAG_INVULNERABLE | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_BURNING_FALL               0x010208B5 // (0x0B5 | ACT_FLAG_AIR | ACT_FLAG_INVULNERABLE | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_SOFT_BONK                  0x010208B6 // (0x0B6 | ACT_FLAG_AIR | ACT_FLAG_INVULNERABLE | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_LAVA_BOOST                 0x010208B7 // (0x0B7 | ACT_FLAG_AIR | ACT_FLAG_INVULNERABLE | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_GETTING_BLOWN              0x010208B8 // (0x0B8 | ACT_FLAG_AIR | ACT_FLAG_INVULNERABLE | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_THROWN_FORWARD             0x010208BD // (0x0BD | ACT_FLAG_AIR | ACT_FLAG_INVULNERABLE | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
#define ACT_THROWN_BACKWARD            0x010208BE // (0x0BE | ACT_FLAG_AIR | ACT_FLAG_INVULNERABLE | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)

// group 0x0C0: submerged actions
#define ACT_WATER_IDLE                 0x380022C0 // (0x0C0 | ACT_FLAG_STATIONARY | ACT_FLAG_SWIMMING | ACT_FLAG_PAUSE_EXIT | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_HOLD_WATER_IDLE            0x380022C1 // (0x0C1 | ACT_FLAG_STATIONARY | ACT_FLAG_SWIMMING | ACT_FLAG_PAUSE_EXIT | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_WATER_ACTION_END           0x300022C2 // (0x0C2 | ACT_FLAG_STATIONARY | ACT_FLAG_SWIMMING | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_HOLD_WATER_ACTION_END      0x300022C3 // (0x0C3 | ACT_FLAG_STATIONARY | ACT_FLAG_SWIMMING | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_DROWNING                   0x300032C4 // (0x0C4 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE | ACT_FLAG_SWIMMING | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_BACKWARD_WATER_KB          0x300222C5 // (0x0C5 | ACT_FLAG_STATIONARY | ACT_FLAG_SWIMMING | ACT_FLAG_INVULNERABLE | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_FORWARD_WATER_KB           0x300222C6 // (0x0C6 | ACT_FLAG_STATIONARY | ACT_FLAG_SWIMMING | ACT_FLAG_INVULNERABLE | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_WATER_DEATH                0x300032C7 // (0x0C7 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE | ACT_FLAG_SWIMMING | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_WATER_SHOCKED              0x300222C8 // (0x0C8 | ACT_FLAG_STATIONARY | ACT_FLAG_SWIMMING | ACT_FLAG_INVULNERABLE | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_BREASTSTROKE               0x300024D0 // (0x0D0 | ACT_FLAG_MOVING | ACT_FLAG_SWIMMING | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_SWIMMING_END               0x300024D1 // (0x0D1 | ACT_FLAG_MOVING | ACT_FLAG_SWIMMING | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_FLUTTER_KICK               0x300024D2 // (0x0D2 | ACT_FLAG_MOVING | ACT_FLAG_SWIMMING | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_HOLD_BREASTSTROKE          0x300024D3 // (0x0D3 | ACT_FLAG_MOVING | ACT_FLAG_SWIMMING | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_HOLD_SWIMMING_END          0x300024D4 // (0x0D4 | ACT_FLAG_MOVING | ACT_FLAG_SWIMMING | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_HOLD_FLUTTER_KICK          0x300024D5 // (0x0D5 | ACT_FLAG_MOVING | ACT_FLAG_SWIMMING | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_WATER_SHELL_SWIMMING       0x300024D6 // (0x0D6 | ACT_FLAG_MOVING | ACT_FLAG_SWIMMING | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_WATER_THROW                0x300024E0 // (0x0E0 | ACT_FLAG_MOVING | ACT_FLAG_SWIMMING | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_WATER_PUNCH                0x300024E1 // (0x0E1 | ACT_FLAG_MOVING | ACT_FLAG_SWIMMING | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_WATER_PLUNGE               0x300022E2 // (0x0E2 | ACT_FLAG_STATIONARY | ACT_FLAG_SWIMMING | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_CAUGHT_IN_WHIRLPOOL        0x300222E3 // (0x0E3 | ACT_FLAG_STATIONARY | ACT_FLAG_SWIMMING | ACT_FLAG_INVULNERABLE | ACT_FLAG_SWIMMING_OR_FLYING | ACT_FLAG_WATER_OR_TEXT)
#define ACT_METAL_WATER_STANDING       0x080042F0 // (0x0F0 | ACT_FLAG_STATIONARY | ACT_FLAG_METAL_WATER | ACT_FLAG_PAUSE_EXIT)
#define ACT_HOLD_METAL_WATER_STANDING  0x080042F1 // (0x0F1 | ACT_FLAG_STATIONARY | ACT_FLAG_METAL_WATER | ACT_FLAG_PAUSE_EXIT)
#define ACT_METAL_WATER_WALKING        0x000044F2 // (0x0F2 | ACT_FLAG_MOVING | ACT_FLAG_METAL_WATER)
#define ACT_HOLD_METAL_WATER_WALKING   0x000044F3 // (0x0F3 | ACT_FLAG_MOVING | ACT_FLAG_METAL_WATER)
#define ACT_METAL_WATER_FALLING        0x000042F4 // (0x0F4 | ACT_FLAG_STATIONARY | ACT_FLAG_METAL_WATER)
#define ACT_HOLD_METAL_WATER_FALLING   0x000042F5 // (0x0F5 | ACT_FLAG_STATIONARY | ACT_FLAG_METAL_WATER)
#define ACT_METAL_WATER_FALL_LAND      0x000042F6 // (0x0F6 | ACT_FLAG_STATIONARY | ACT_FLAG_METAL_WATER)
#define ACT_HOLD_METAL_WATER_FALL_LAND 0x000042F7 // (0x0F7 | ACT_FLAG_STATIONARY | ACT_FLAG_METAL_WATER)
#define ACT_METAL_WATER_JUMP           0x000044F8 // (0x0F8 | ACT_FLAG_MOVING | ACT_FLAG_METAL_WATER)
#define ACT_HOLD_METAL_WATER_JUMP      0x000044F9 // (0x0F9 | ACT_FLAG_MOVING | ACT_FLAG_METAL_WATER)
#define ACT_METAL_WATER_JUMP_LAND      0x000044FA // (0x0FA | ACT_FLAG_MOVING | ACT_FLAG_METAL_WATER)
#define ACT_HOLD_METAL_WATER_JUMP_LAND 0x000044FB // (0x0FB | ACT_FLAG_MOVING | ACT_FLAG_METAL_WATER)

// group 0x100: cutscene actions
#define ACT_DISAPPEARED                0x00001300 // (0x100 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_INTRO_CUTSCENE             0x04001301 // (0x101 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE | ACT_FLAG_ALLOW_FIRST_PERSON)
#define ACT_STAR_DANCE_EXIT            0x00001302 // (0x102 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_STAR_DANCE_WATER           0x00001303 // (0x103 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_FALL_AFTER_STAR_GRAB       0x00001904 // (0x104 | ACT_FLAG_AIR | ACT_FLAG_INTANGIBLE)
#define ACT_READING_AUTOMATIC_DIALOG   0x20001305 // (0x105 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE | ACT_FLAG_WATER_OR_TEXT)
#define ACT_READING_NPC_DIALOG         0x20001306 // (0x106 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE | ACT_FLAG_WATER_OR_TEXT)
#define ACT_STAR_DANCE_NO_EXIT         0x00001307 // (0x107 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_READING_SIGN               0x00001308 // (0x108 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_JUMBO_STAR_CUTSCENE        0x00001909 // (0x109 | ACT_FLAG_AIR | ACT_FLAG_INTANGIBLE)
#define ACT_WAITING_FOR_DIALOG         0x0000130A // (0x10A | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_DEBUG_FREE_MOVE            0x0000130F // (0x10F | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_STANDING_DEATH             0x00021311 // (0x111 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE | ACT_FLAG_INVULNERABLE)
#define ACT_QUICKSAND_DEATH            0x00021312 // (0x112 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE | ACT_FLAG_INVULNERABLE)
#define ACT_ELECTROCUTION              0x00021313 // (0x113 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE | ACT_FLAG_INVULNERABLE)
#define ACT_SUFFOCATION                0x00021314 // (0x114 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE | ACT_FLAG_INVULNERABLE)
#define ACT_DEATH_ON_STOMACH           0x00021315 // (0x115 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE | ACT_FLAG_INVULNERABLE)
#define ACT_DEATH_ON_BACK              0x00021316 // (0x116 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE | ACT_FLAG_INVULNERABLE)
#define ACT_EATEN_BY_BUBBA             0x00021317 // (0x117 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE | ACT_FLAG_INVULNERABLE)
#define ACT_END_PEACH_CUTSCENE         0x00001918 // (0x118 | ACT_FLAG_AIR | ACT_FLAG_INTANGIBLE)
#define ACT_CREDITS_CUTSCENE           0x00001319 // (0x119 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_END_WAVING_CUTSCENE        0x0000131A // (0x11A | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_PULLING_DOOR               0x00001320 // (0x120 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_PUSHING_DOOR               0x00001321 // (0x121 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_WARP_DOOR_SPAWN            0x00001322 // (0x122 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_EMERGE_FROM_PIPE           0x00001923 // (0x123 | ACT_FLAG_AIR | ACT_FLAG_INTANGIBLE)
#define ACT_SPAWN_SPIN_AIRBORNE        0x00001924 // (0x124 | ACT_FLAG_AIR | ACT_FLAG_INTANGIBLE)
#define ACT_SPAWN_SPIN_LANDING         0x00001325 // (0x125 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_EXIT_AIRBORNE              0x00001926 // (0x126 | ACT_FLAG_AIR | ACT_FLAG_INTANGIBLE)
#define ACT_EXIT_LAND_SAVE_DIALOG      0x00001327 // (0x127 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_DEATH_EXIT                 0x00001928 // (0x128 | ACT_FLAG_AIR | ACT_FLAG_INTANGIBLE)
#define ACT_UNUSED_DEATH_EXIT          0x00001929 // (0x129 | ACT_FLAG_AIR | ACT_FLAG_INTANGIBLE)
#define ACT_FALLING_DEATH_EXIT         0x0000192A // (0x12A | ACT_FLAG_AIR | ACT_FLAG_INTANGIBLE)
#define ACT_SPECIAL_EXIT_AIRBORNE      0x0000192B // (0x12B | ACT_FLAG_AIR | ACT_FLAG_INTANGIBLE)
#define ACT_SPECIAL_DEATH_EXIT         0x0000192C // (0x12C | ACT_FLAG_AIR | ACT_FLAG_INTANGIBLE)
#define ACT_FALLING_EXIT_AIRBORNE      0x0000192D // (0x12D | ACT_FLAG_AIR | ACT_FLAG_INTANGIBLE)
#define ACT_UNLOCKING_KEY_DOOR         0x0000132E // (0x12E | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_UNLOCKING_STAR_DOOR        0x0000132F // (0x12F | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_ENTERING_STAR_DOOR         0x00001331 // (0x131 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_SPAWN_NO_SPIN_AIRBORNE     0x00001932 // (0x132 | ACT_FLAG_AIR | ACT_FLAG_INTANGIBLE)
#define ACT_SPAWN_NO_SPIN_LANDING      0x00001333 // (0x133 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_BBH_ENTER_JUMP             0x00001934 // (0x134 | ACT_FLAG_AIR | ACT_FLAG_INTANGIBLE)
#define ACT_BBH_ENTER_SPIN             0x00001535 // (0x135 | ACT_FLAG_MOVING | ACT_FLAG_INTANGIBLE)
#define ACT_TELEPORT_FADE_OUT          0x00001336 // (0x136 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_TELEPORT_FADE_IN           0x00001337 // (0x137 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_SHOCKED                    0x00020338 // (0x138 | ACT_FLAG_STATIONARY | ACT_FLAG_INVULNERABLE)
#define ACT_SQUISHED                   0x00020339 // (0x139 | ACT_FLAG_STATIONARY | ACT_FLAG_INVULNERABLE)
#define ACT_HEAD_STUCK_IN_GROUND       0x0002033A // (0x13A | ACT_FLAG_STATIONARY | ACT_FLAG_INVULNERABLE)
#define ACT_BUTT_STUCK_IN_GROUND       0x0002033B // (0x13B | ACT_FLAG_STATIONARY | ACT_FLAG_INVULNERABLE)
#define ACT_FEET_STUCK_IN_GROUND       0x0002033C // (0x13C | ACT_FLAG_STATIONARY | ACT_FLAG_INVULNERABLE)
#define ACT_PUTTING_ON_CAP             0x0000133D // (0x13D | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)

// group 0x140: "automatic" actions
#define ACT_HOLDING_POLE               0x08100340 // (0x140 | ACT_FLAG_STATIONARY | ACT_FLAG_ON_POLE | ACT_FLAG_PAUSE_EXIT)
#define ACT_GRAB_POLE_SLOW             0x00100341 // (0x141 | ACT_FLAG_STATIONARY | ACT_FLAG_ON_POLE)
#define ACT_GRAB_POLE_FAST             0x00100342 // (0x142 | ACT_FLAG_STATIONARY | ACT_FLAG_ON_POLE)
#define ACT_CLIMBING_POLE              0x00100343 // (0x143 | ACT_FLAG_STATIONARY | ACT_FLAG_ON_POLE)
#define ACT_TOP_OF_POLE_TRANSITION     0x00100344 // (0x144 | ACT_FLAG_STATIONARY | ACT_FLAG_ON_POLE)
#define ACT_TOP_OF_POLE                0x00100345 // (0x145 | ACT_FLAG_STATIONARY | ACT_FLAG_ON_POLE)
#define ACT_START_HANGING              0x08200348 // (0x148 | ACT_FLAG_STATIONARY | ACT_FLAG_HANGING | ACT_FLAG_PAUSE_EXIT)
#define ACT_HANGING                    0x00200349 // (0x149 | ACT_FLAG_STATIONARY | ACT_FLAG_HANGING)
#define ACT_HANG_MOVING                0x0020054A // (0x14A | ACT_FLAG_MOVING | ACT_FLAG_HANGING)
#define ACT_LEDGE_GRAB                 0x0800034B // (0x14B | ACT_FLAG_STATIONARY | ACT_FLAG_PAUSE_EXIT)
#define ACT_LEDGE_CLIMB_SLOW_1         0x0000054C // (0x14C | ACT_FLAG_MOVING)
#define ACT_LEDGE_CLIMB_SLOW_2         0x0000054D // (0x14D | ACT_FLAG_MOVING)
#define ACT_LEDGE_CLIMB_DOWN           0x0000054E // (0x14E | ACT_FLAG_MOVING)
#define ACT_LEDGE_CLIMB_FAST           0x0000054F // (0x14F | ACT_FLAG_MOVING)
#define ACT_GRABBED                    0x00020370 // (0x170 | ACT_FLAG_STATIONARY | ACT_FLAG_INVULNERABLE)
#define ACT_IN_CANNON                  0x00001371 // (0x171 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)
#define ACT_TORNADO_TWIRLING           0x10020372 // (0x172 | ACT_FLAG_STATIONARY | ACT_FLAG_INVULNERABLE | ACT_FLAG_SWIMMING_OR_FLYING)
#define ACT_BUBBLED                    0x00001373 // (0x173 | ACT_FLAG_STATIONARY | ACT_FLAG_INTANGIBLE)

// group 0x180: object actions
#define ACT_PUNCHING                   0x00800380 // (0x180 | ACT_FLAG_STATIONARY | ACT_FLAG_ATTACKING)
#define ACT_PICKING_UP                 0x00000383 // (0x183 | ACT_FLAG_STATIONARY)
#define ACT_DIVE_PICKING_UP            0x00000385 // (0x185 | ACT_FLAG_STATIONARY)
#define ACT_STOMACH_SLIDE_STOP         0x00000386 // (0x186 | ACT_FLAG_STATIONARY)
#define ACT_PLACING_DOWN               0x00000387 // (0x187 | ACT_FLAG_STATIONARY)
#define ACT_THROWING                   0x80000588 // (0x188 | ACT_FLAG_MOVING | ACT_FLAG_THROWING)
#define ACT_HEAVY_THROW                0x80000589 // (0x189 | ACT_FLAG_MOVING | ACT_FLAG_THROWING)
#define ACT_PICKING_UP_BOWSER          0x00000390 // (0x190 | ACT_FLAG_STATIONARY)
#define ACT_HOLDING_BOWSER             0x00000391 // (0x191 | ACT_FLAG_STATIONARY)
#define ACT_RELEASING_BOWSER           0x00000392 // (0x192 | ACT_FLAG_STATIONARY)

/*
 this input mask is unused by the controller,
 but END_DEMO is used internally to signal
 the demo to end. This button cannot
 be pressed normally by a controller.
*/
#define END_DEMO       (1 << 7)

#define VALID_BUTTONS (A_BUTTON   | B_BUTTON   | Z_TRIG     | START_BUTTON | \
                       U_JPAD     | D_JPAD     | L_JPAD     | R_JPAD       | \
                       L_TRIG     | R_TRIG     |                             \
                       U_CBUTTONS | D_CBUTTONS | L_CBUTTONS | R_CBUTTONS   )

#define C_BUTTONS     (U_CBUTTONS | D_CBUTTONS | L_CBUTTONS | R_CBUTTONS   )

#endif // SM64_H
