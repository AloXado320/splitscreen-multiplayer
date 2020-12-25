#ifndef GD_DYNLISTS_H
#define GD_DYNLISTS_H

#include "../gd_types.h"

// Dynamic Object names
enum {
    DYNOBJ_MARIO_RIGHT_MUSTACHE_JOINT_2          = 3,
    DYNOBJ_MARIO_RIGHT_MUSTACHE_JOINT_1          = 6,
    DYNOBJ_MARIO_RIGHT_MUSTACHE_ANIMDATA_GROUP   = 7,
    DYNOBJ_MARIO_RIGHT_MUSTACHE_ANIMATOR         = 8,
    DYNOBJ_MARIO_RIGHT_MUSTACHE_SKIN_NET         = 9,
    DYNOBJ_MARIO_LEFT_MUSTACHE_JOINT_2           = 12,
    DYNOBJ_MARIO_LEFT_MUSTACHE_JOINT_1           = 15,
    DYNOBJ_MARIO_LEFT_MUSTACHE_ANIMDATA_GROUP    = 16,
    DYNOBJ_MARIO_LEFT_MUSTACHE_ANIMATOR          = 17,
    DYNOBJ_MARIO_LEFT_MUSTACHE_SKIN_NET          = 18,
    DYNOBJ_MARIO_MUSTACHE_NET                    = 21,  // (left and right mustache skin nets are attached to this net)
    DYNOBJ_MARIO_MUSTACHE_VTX_GROUP              = 22,
    DYNOBJ_MARIO_MUSTACHE_TRI_GROUP              = 23,
    DYNOBJ_MARIO_MUSTACHE_MTL_GROUP              = 24,
    DYNOBJ_MARIO_MUSTACHE_SHAPE                  = 25,
    DYNOBJ_MARIO_LEFT_EYEBROW_MPART_JOINT_2      = 28,
    DYNOBJ_MARIO_LEFT_EYEBROW_MPART_JOINT_1      = 31,
    DYNOBJ_MARIO_LEFT_EYEBROW_MPART_SKIN_NET     = 34,
    DYNOBJ_MARIO_LEFT_EYEBROW_RPART_JOINT_2      = 37,
    DYNOBJ_MARIO_LEFT_EYEBROW_RPART_JOINT_1      = 40,
    DYNOBJ_MARIO_LEFT_EYEBROW_RPART_SKIN_NET     = 43,
    DYNOBJ_MARIO_LEFT_EYEBROW_LPART_JOINT_2      = 46,
    DYNOBJ_MARIO_LEFT_EYEBROW_LPART_JOINT_1      = 49,
    DYNOBJ_MARIO_LEFT_EYEBROW_LPART_SKIN_NET     = 52,
    DYNOBJ_MARIO_LEFT_EYEBROW_NET                = 55,
    DYNOBJ_MARIO_LEFT_EYEBROW_VTX_GROUP          = 56,
    DYNOBJ_MARIO_LEFT_EYEBROW_TRI_GROUP          = 57,
    DYNOBJ_MARIO_LEFT_EYEBROW_MTL_GROUP          = 58,
    DYNOBJ_MARIO_LEFT_EYEBROW_SHAPE              = 59,
    DYNOBJ_MARIO_RIGHT_EYEBROW_MPART_JOINT_2     = 62,
    DYNOBJ_MARIO_RIGHT_EYEBROW_MPART_JOINT_1     = 65,
    DYNOBJ_MARIO_RIGHT_EYEBROW_MPART_SKIN_NET    = 68,
    DYNOBJ_MARIO_RIGHT_EYEBROW_LPART_JOINT_2     = 71,
    DYNOBJ_MARIO_RIGHT_EYEBROW_LPART_JOINT_1     = 74,
    DYNOBJ_MARIO_RIGHT_EYEBROW_LPART_SKIN_NET    = 77,
    DYNOBJ_MARIO_RIGHT_EYEBROW_RPART_JOINT_2     = 80,
    DYNOBJ_MARIO_RIGHT_EYEBROW_RPART_JOINT_1     = 83,
    DYNOBJ_MARIO_RIGHT_EYEBROW_RPART_SKIN_NET    = 86,
    DYNOBJ_MARIO_RIGHT_EYEBROW_NET               = 89,
    DYNOBJ_MARIO_RIGHT_EYEBROW_VTX_GROUP         = 90,
    DYNOBJ_MARIO_RIGHT_EYEBROW_TRI_GROUP         = 91,
    DYNOBJ_MARIO_RIGHT_EYEBROW_MTL_GROUP         = 92,
    DYNOBJ_MARIO_RIGHT_EYEBROW_SHAPE             = 93,
    DYNOBJ_MARIO_LEFT_EYE_UNKNOWN_NET            = 96,
    DYNOBJ_MARIO_LEFT_EYE_VTX_GROUP              = 97,
    DYNOBJ_MARIO_LEFT_EYE_TRI_GROUP              = 98,
    DYNOBJ_MARIO_LEFT_EYE_MTL_GROUP              = 99,
    DYNOBJ_MARIO_LEFT_EYE_SHAPE                  = 100,
    DYNOMJ_MARIO_LEFT_EYE_JOINT_2                = 103,
    DYNOBJ_MARIO_LEFT_EYE_JOINT_1                = 106,
    DYNOBJ_MARIO_LEFT_EYE_ANIMDATA_GROUP         = 107,
    DYNOBJ_MARIO_LEFT_EYE_ANIMATOR               = 108,
    DYNOBJ_MARIO_LEFT_EYE_SKIN_NET               = 109,
    DYNOBJ_MARIO_RIGHT_EYE_UNKNOWN_NET           = 112,
    DYNOBJ_MARIO_RIGHT_EYE_VTX_GROUP             = 113,
    DYNOBJ_MARIO_RIGHT_EYE_TRI_GROUP             = 114,
    DYNOBJ_MARIO_RIGHT_EYE_MTL_GROUP             = 115,
    DYNOBJ_MARIO_RIGHT_EYE_SHAPE                 = 116,
    DYNOBJ_MARIO_RIGHT_EYE_JOINT_2               = 119,
    DYNOBJ_MARIO_RIGHT_EYE_JOINT_1               = 122,
    DYNOBJ_MARIO_RIGHT_EYE_ANIMDATA_GROUP        = 123,
    DYNOBJ_MARIO_RIGHT_EYE_ANIMATOR              = 124,
    DYNOBJ_MARIO_RIGHT_EYE_SKIN_NET              = 125,
    DYNOBJ_MARIO_CAP_JOINT_2                     = 128,
    DYNOBJ_MARIO_CAP_JOINT_1                     = 131,
    DYNOBJ_MARIO_CAP_ANIMDATA_GROUP              = 132,
    DYNOBJ_MARIO_CAP_ANIMATOR                    = 133,
    DYNOBJ_MARIO_CAP_SKIN_NET                    = 134,
    DYNOBJ_MARIO_UNKNOWN_137                     = 137,
    DYNOBJ_MARIO_UNKNOWN_140                     = 140,
    DYNOBJ_MARIO_LEFT_LIP_CORNER_JOINT_2         = 146,
    DYNOBJ_MARIO_LEFT_LIP_CORNER_JOINT_1         = 149,
    DYNOBJ_MARIO_LEFT_LIP_CORNER_ANIMDATA_GROUP  = 150,
    DYNOBJ_MARIO_LEFT_LIP_CORNER_ANIMATOR        = 151,
    DYNOBJ_MARIO_LEFT_LIP_CORNER_SKIN_NET        = 152,
    DYNOBJ_MARIO_RIGHT_LIP_CORNER_JOINT_2        = 155,
    DYNOBJ_MARIO_RIGHT_LIP_CORNER_JOINT_1        = 158,
    DYNOBJ_MARIO_RIGHT_LIP_CORNER_ANIMDATA_GROUP = 159,
    DYNOBJ_MARIO_RIGHT_LIP_CORNER_ANIMATOR       = 160,
    DYNOBJ_MARIO_RIGHT_LIP_CORNER_SKIN_NET       = 161,
    DYNOBJ_MARIO_LEFT_EAR_JOINT_2                = 164,
    DYNOBJ_MARIO_LEFT_EAR_JOINT_1                = 167,  // 167 "N167l"
    DYNOBJ_MARIO_LEFT_EAR_ANIMDATA_GROUP         = 168,
    DYNOBJ_MARIO_LEFT_EAR_ANIMATOR               = 169,
    DYNOBJ_MARIO_LEFT_EAR_SKIN_NET               = 170,
    DYNOBJ_MARIO_RIGHT_EAR_JOINT_2               = 173,
    DYNOBJ_MARIO_RIGHT_EAR_JOINT_1               = 176,
    DYNOBJ_MARIO_RIGHT_EAR_ANIMADATA_GROUP       = 177,
    DYNOBJ_MARIO_RIGHT_EAR_ANIMATOR              = 178,
    DYNOBJ_MARIO_RIGHT_EAR_SKIN_NET              = 179,
    DYNOBJ_MARIO_NOSE_JOINT_2                    = 182,
    DYNOBJ_MARIO_NOSE_JOINT_1                    = 185,
    DYNOBJ_MARIO_NOSE_ANIMDATA_GROUP             = 186,
    DYNOBJ_MARIO_NOSE_ANIMATOR                   = 187,
    DYNOBJ_MARIO_NOSE_SKIN_NET                   = 188,
    DYNOBJ_MARIO_UNKNOWN_191                     = 191,
    DYNOBJ_MARIO_LEFT_JAW_JOINT                  = 194,
    DYNOBJ_MARIO_LEFT_JAW_ANIMDATA_GROUP         = 195,
    DYNOBJ_MARIO_LEFT_JAW_ANIMATOR               = 196,
    DYNOBJ_MARIO_RIGHT_JAW_JOINT                 = 197,
    DYNOBJ_MARIO_RIGHT_JAW_ANIMDATA_GROUP        = 198,
    DYNOBJ_MARIO_RIGHT_JAW_ANIMATOR              = 199,
    DYNOBJ_MARIO_JAW_SKIN_NET                    = 200,
    DYNOBJ_LEFT_EYELID_JOINT_2                   = 203,
    DYNOBJ_LEFT_EYELID_JOINT_1                   = 206,
    DYNOBJ_LEFT_EYELID_ANIMDATA_GROUP            = 207,
    DYNOBJ_LEFT_EYELID_ANIMATOR                  = 208,
    DYNOBJ_LEFT_EYELID_SKIN_NET                  = 209,
    DYNOBJ_RIGHT_EYELID_JOINT_2                  = 212,
    DYNOBJ_RIGHT_EYELID_JOINT_1                  = 215,
    DYNOBJ_RIGHT_EYELID_ANIMDATA_GROUP           = 216,
    DYNOBJ_RIGHT_EYELID_ANIMATOR                 = 217,
    DYNOBJ_RIGHT_EYELID_SKIN_NET                 = 218,
    DYNOBJ_MARIO_MAIN_NET                        = 221,  // rename to HEAD_NET?
    DYNOBJ_MARIO_FACE_VTX_GROUP                  = 222,
    DYNOBJ_MARIO_FACE_TRI_GROUP                  = 223,
    DYNOBJ_MARIO_FACE_MTL_GROUP                  = 224,
    DYNOBJ_MARIO_FACE_SHAPE                      = 225,
    DYNOBJ_MARIO_HEAD_ANIMDATA_GROUP             = 226,
    DYNOBJ_MARIO_HEAD_ANIMATOR                   = 227,
    DYNOBJ_SILVER_STAR_LIGHT                     = 228,  // "N228l"
    DYNOBJ_SILVER_STAR_ANIMDATA_GROUP            = 229,
    DYNOBJ_SILVER_STAR_ANIMATOR                  = 230,
    DYNOBJ_RED_STAR_LIGHT                        = 231,  // "N231l"
    DYNOBJ_RED_STAR_ANIMDATA_GROUP               = 232,
    DYNOBJ_RED_STAR_ANIMATOR                     = 233,
    DYNOBJ_MARIO_MAIN_SHAPES_GROUP               = 1000,  // "N1000l"
    DYNOBJ_MARIO_MAIN_ANIMATOR                   = 1001  // root animator
};

extern struct DynList dynlist_test_cube[];
extern struct DynList dynlist_spot_shape[];
extern struct DynList dynlist_mario_face_shape[];
extern struct DynList dynlist_mario_eye_right_shape[];
extern struct DynList dynlist_mario_eye_left_shape[];
extern struct DynList dynlist_mario_eyebrow_right_shape[];
extern struct DynList dynlist_mario_eyebrow_left_shape[];
extern struct DynList dynlist_mario_mustache_shape[];
extern struct DynList dynlist_mario_master[];


extern struct DynList dynlist_luigi_face[44];
extern struct DynList dynlist_luigi_eye_right[28];
extern struct DynList dynlist_luigi_eye_left[28];
extern struct DynList dynlist_luigi_eyebrow_right[16];
extern struct DynList dynlist_luigi_eyebrow_left[16];
extern struct DynList dynlist_luigi_mustache[16];
extern struct DynList dynlist_luigi_master[1026];
#endif // GD_DYNLISTS_H
