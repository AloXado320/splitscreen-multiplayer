#include <PR/ultratypes.h>

#include "macros.h"
#include "dynlist_macros.h"
#include "dynlists.h"
#include "../dynlist_proc.h"

static s16 verts_mario_eyebrow_right[][3] = {
    { 105, 391, 363 }, { 62, 370, 378 },  { 86, 366, 370 },  { 171, 380, 339 }, { 139, 377, 353 },
    { 193, 353, 331 }, { 204, 314, 297 }, { 175, 342, 305 }, { 209, 361, 291 }, { 124, 360, 323 },
    { 161, 393, 306 }, { 230, 323, 286 }, { 233, 276, 289 }, { 123, 402, 319 }, { 85, 399, 334 },
    { 73, 355, 342 },  { 45, 330, 354 },  { 17, 294, 356 },  { 29, 348, 361 },  { 212, 358, 323 },
    { 214, 324, 318 }, { 139, 394, 353 }, { 57, 339, 377 },  { 231, 330, 311 }, { 58, 384, 349 },
    { 41, 345, 382 },
};

static struct GdVtxData vtx_mario_eyebrow_right = { ARRAY_COUNT(verts_mario_eyebrow_right), 0x1, verts_mario_eyebrow_right };

static u16 facedata_mario_eyebrow_right[][4] = {
    { 0, 0, 1, 2 },    { 0, 3, 4, 5 },    { 0, 20, 23, 19 }, { 0, 1, 25, 22 }, { 0, 0, 21, 13 },
    { 0, 2, 15, 9 },   { 0, 7, 6, 20 },   { 0, 3, 19, 8 },   { 0, 25, 1, 24 }, { 0, 19, 5, 20 },
    { 0, 19, 3, 5 },   { 0, 3, 21, 4 },   { 0, 21, 0, 4 },   { 0, 0, 2, 4 },   { 0, 1, 22, 2 },
    { 0, 20, 12, 23 }, { 0, 13, 14, 0 },  { 0, 4, 2, 9 },    { 0, 20, 5, 7 },  { 0, 22, 17, 16 },
    { 0, 8, 10, 3 },   { 0, 24, 18, 25 }, { 0, 23, 11, 8 },  { 0, 14, 24, 1 }, { 0, 5, 4, 9 },
    { 0, 2, 22, 15 },  { 0, 11, 23, 12 }, { 0, 25, 18, 17 }, { 0, 20, 6, 12 }, { 0, 10, 13, 21 },
    { 0, 8, 19, 23 },  { 0, 25, 17, 22 }, { 0, 1, 0, 14 },   { 0, 21, 3, 10 }, { 0, 22, 16, 15 },
    { 0, 9, 7, 5 },
};

static struct GdFaceData faces_mario_eyebrow_right = { ARRAY_COUNT(facedata_mario_eyebrow_right), 0x1, facedata_mario_eyebrow_right };

struct DynList dynlist_mario_eyebrow_right_shape[] = {
    BeginList(),

    MakeDynObj(D_DATA_GRP, DYNOBJ_MARIO_RIGHT_EYEBROW_VTX_GROUP),
        LinkWithPtr(&vtx_mario_eyebrow_right),

    MakeDynObj(D_DATA_GRP, DYNOBJ_MARIO_RIGHT_EYEBROW_TRI_GROUP),
        LinkWithPtr(&faces_mario_eyebrow_right),

    StartGroup(DYNOBJ_MARIO_RIGHT_EYEBROW_MTL_GROUP),
        MakeDynObj(D_MATERIAL, 0),
            SetId(0),
            SetAmbient(0.0, 0.005, 0.0),  // Why is green 0.005 on the right eyebrow, but 0.0 on the left eyebrow?
            SetDiffuse(0.0, 0.0, 0.0),
    EndGroup(DYNOBJ_MARIO_RIGHT_EYEBROW_MTL_GROUP),

    MakeDynObj(D_SHAPE, DYNOBJ_MARIO_RIGHT_EYEBROW_SHAPE),
        SetNodeGroup(DYNOBJ_MARIO_RIGHT_EYEBROW_VTX_GROUP),
        SetPlaneGroup(DYNOBJ_MARIO_RIGHT_EYEBROW_TRI_GROUP),
        SetMaterialGroup(DYNOBJ_MARIO_RIGHT_EYEBROW_MTL_GROUP),

    EndList(),
};

static s16 verts_mario_eyebrow_left[][3] = {
    { -57, 339, 377 },  { -17, 294, 356 },  { -45, 341, 383 },  { -45, 330, 354 },  { -73, 355, 342 },
    { -52, 377, 349 },  { -139, 394, 353 }, { -123, 402, 319 }, { -161, 393, 306 }, { -233, 276, 289 },
    { -204, 314, 297 }, { -214, 324, 318 }, { -29, 335, 363 },  { -231, 330, 311 }, { -230, 323, 286 },
    { -86, 366, 370 },  { -124, 360, 323 }, { -139, 377, 353 }, { -193, 353, 331 }, { -62, 370, 378 },
    { -85, 399, 334 },  { -209, 361, 291 }, { -171, 380, 339 }, { -175, 342, 305 }, { -105, 391, 363 },
    { -212, 358, 323 },
};

static struct GdVtxData vtx_mario_eyebrow_left = { ARRAY_COUNT(verts_mario_eyebrow_left), 0x1, verts_mario_eyebrow_left };

static u16 facedata_mario_eyebrow_left[][4] = {
    { 0, 0, 1, 2 },    { 0, 8, 22, 6 },   { 0, 6, 7, 8 },    { 0, 9, 10, 11 },  { 0, 1, 12, 2 },
    { 0, 9, 13, 14 },  { 0, 4, 0, 15 },   { 0, 16, 17, 18 }, { 0, 19, 5, 20 },  { 0, 21, 14, 13 },
    { 0, 2, 12, 5 },   { 0, 22, 8, 21 },  { 0, 3, 1, 0 },    { 0, 23, 18, 11 }, { 0, 16, 15, 17 },
    { 0, 24, 20, 7 },  { 0, 13, 9, 11 },  { 0, 15, 0, 19 },  { 0, 17, 15, 24 }, { 0, 17, 24, 6 },
    { 0, 17, 6, 22 },  { 0, 18, 22, 25 }, { 0, 11, 18, 25 }, { 0, 4, 3, 0 },    { 0, 18, 23, 16 },
    { 0, 20, 24, 19 }, { 0, 13, 25, 21 }, { 0, 5, 19, 2 },   { 0, 21, 25, 22 }, { 0, 11, 10, 23 },
    { 0, 18, 17, 22 }, { 0, 15, 19, 24 }, { 0, 16, 4, 15 },  { 0, 7, 6, 24 },   { 0, 0, 2, 19 },
    { 0, 25, 13, 11 },
};

static struct GdFaceData faces_mario_eyebrow_left = { ARRAY_COUNT(facedata_mario_eyebrow_left), 0x1, facedata_mario_eyebrow_left };

struct DynList dynlist_mario_eyebrow_left_shape[] = {
    BeginList(),

    MakeDynObj(D_DATA_GRP, DYNOBJ_MARIO_LEFT_EYEBROW_VTX_GROUP),
        LinkWithPtr(&vtx_mario_eyebrow_left),

    MakeDynObj(D_DATA_GRP, DYNOBJ_MARIO_LEFT_EYEBROW_TRI_GROUP),
        LinkWithPtr(&faces_mario_eyebrow_left),

    StartGroup(DYNOBJ_MARIO_LEFT_EYEBROW_MTL_GROUP),
        MakeDynObj(D_MATERIAL, 0),
            SetId(0),
            SetAmbient(0.0, 0.0, 0.0),
            SetDiffuse(0.0, 0.0, 0.0),
    EndGroup(DYNOBJ_MARIO_LEFT_EYEBROW_MTL_GROUP),

    MakeDynObj(D_SHAPE, DYNOBJ_MARIO_LEFT_EYEBROW_SHAPE),
        SetNodeGroup(DYNOBJ_MARIO_LEFT_EYEBROW_VTX_GROUP),
        SetPlaneGroup(DYNOBJ_MARIO_LEFT_EYEBROW_TRI_GROUP),
        SetMaterialGroup(DYNOBJ_MARIO_LEFT_EYEBROW_MTL_GROUP),

    EndList(),
};

static s16 verts_mario_mustache[][3] = {
    { -202, 15, 400 },   { -295, -13, 358 },  { -287, -45, 362 },  { 229, -89, 385 },
    { 214, -126, 385 },  { 221, -131, 360 },  { -266, 73, 363 },   { -202, 15, 375 },
    { -154, -160, 372 }, { -154, -148, 397 }, { -191, -150, 387 }, { 276, -74, 345 },
    { 287, -45, 362 },   { 276, -74, 370 },   { -221, -131, 360 }, { -214, -126, 385 },
    { -229, -89, 385 },  { -298, -45, 337 },  { 293, 20, 357 },    { 295, -13, 358 },
    { 307, -13, 333 },   { 202, 15, 400 },    { 266, 73, 363 },    { 202, 15, 375 },
    { -95, -25, 457 },   { 95, -25, 457 },    { -95, -25, 406 },   { 95, -25, 406 },
    { 154, -148, 397 },  { 110, -178, 416 },  { 121, -188, 384 },  { 266, 88, 338 },
    { -293, 20, 357 },   { -266, 88, 338 },   { -276, -74, 370 },  { -239, -95, 359 },
    { 197, -155, 362 },  { 191, -150, 387 },  { -68, -181, 427 },  { -110, -178, 416 },
    { -75, -191, 396 },  { -4, -157, 406 },   { 4, -157, 406 },    { -4, -157, 444 },
    { -197, -155, 362 }, { 154, -160, 372 },  { 239, -95, 359 },   { 298, -45, 337 },
    { -307, -13, 333 },  { -276, -74, 345 },  { 68, -181, 427 },   { 4, -157, 444 },
    { -121, -188, 384 }, { 75, -191, 396 },   { 304, 20, 332 },    { -304, 20, 332 },
};

static struct GdVtxData vtx_mario_mustache = { ARRAY_COUNT(verts_mario_mustache), 0x1, verts_mario_mustache };

static u16 facedata_mario_mustache[][4] = {
    { 0, 0, 1, 2 },    { 0, 3, 4, 5 },    { 0, 3, 5, 46 },   { 0, 6, 0, 7 },    { 0, 6, 7, 33 },
    { 0, 8, 9, 10 },   { 0, 8, 10, 44 },  { 0, 11, 47, 12 }, { 0, 11, 12, 13 }, { 0, 14, 15, 16 },
    { 0, 14, 16, 35 }, { 0, 2, 1, 48 },   { 0, 2, 48, 17 },  { 0, 18, 19, 20 }, { 0, 18, 20, 54 },
    { 0, 21, 22, 31 }, { 0, 21, 31, 23 }, { 0, 24, 25, 27 }, { 0, 24, 27, 26 }, { 0, 27, 25, 21 },
    { 0, 27, 21, 23 }, { 0, 0, 24, 26 },  { 0, 0, 26, 7 },   { 0, 28, 29, 30 }, { 0, 28, 30, 45 },
    { 0, 31, 22, 18 }, { 0, 31, 18, 54 }, { 0, 32, 6, 33 },  { 0, 32, 33, 55 }, { 0, 16, 34, 49 },
    { 0, 16, 49, 35 }, { 0, 36, 5, 4 },   { 0, 36, 4, 37 },  { 0, 38, 39, 52 }, { 0, 38, 52, 40 },
    { 0, 41, 42, 51 }, { 0, 41, 51, 43 }, { 0, 10, 15, 14 }, { 0, 10, 14, 44 }, { 0, 37, 28, 45 },
    { 0, 37, 45, 36 }, { 0, 35, 7, 26 },  { 0, 13, 3, 46 },  { 0, 13, 46, 11 }, { 0, 19, 12, 47 },
    { 0, 19, 47, 20 }, { 0, 1, 32, 55 },  { 0, 1, 55, 48 },  { 0, 34, 2, 17 },  { 0, 34, 17, 49 },
    { 0, 43, 38, 40 }, { 0, 43, 40, 41 }, { 0, 42, 53, 50 }, { 0, 42, 50, 51 }, { 0, 39, 9, 8 },
    { 0, 39, 8, 52 },  { 0, 29, 50, 53 }, { 0, 29, 53, 30 }, { 0, 51, 50, 25 }, { 0, 43, 51, 25 },
    { 0, 43, 25, 24 }, { 0, 29, 28, 25 }, { 0, 3, 13, 12 },  { 0, 3, 12, 21 },  { 0, 3, 21, 25 },
    { 0, 50, 29, 25 }, { 0, 25, 37, 4 },  { 0, 25, 28, 37 }, { 0, 25, 4, 3 },   { 0, 9, 39, 24 },
    { 0, 16, 15, 24 }, { 0, 39, 38, 24 }, { 0, 38, 43, 24 }, { 0, 10, 9, 24 },  { 0, 24, 0, 16 },
    { 0, 15, 10, 24 }, { 0, 8, 44, 14 },  { 0, 18, 22, 21 }, { 0, 19, 18, 21 }, { 0, 12, 19, 21 },
    { 0, 0, 6, 32 },   { 0, 0, 32, 1 },   { 0, 2, 34, 16 },  { 0, 2, 16, 0 },   { 0, 23, 11, 46 },
    { 0, 8, 14, 35 },  { 0, 23, 31, 54 }, { 0, 46, 27, 23 }, { 0, 8, 35, 26 },  { 0, 27, 46, 45 },
    { 0, 54, 20, 47 }, { 0, 54, 47, 11 }, { 0, 55, 33, 7 },  { 0, 7, 49, 55 },  { 0, 49, 17, 55 },
    { 0, 17, 48, 55 }, { 0, 35, 49, 7 },  { 0, 54, 11, 23 }, { 0, 46, 5, 45 },  { 0, 5, 36, 45 },
};

static struct GdFaceData faces_mario_mustache = { ARRAY_COUNT(facedata_mario_mustache), 0x1, facedata_mario_mustache };

struct DynList dynlist_mario_mustache_shape[] = {
    BeginList(),

    MakeDynObj(D_DATA_GRP, DYNOBJ_MARIO_MUSTACHE_VTX_GROUP),
        LinkWithPtr(&vtx_mario_mustache),

    MakeDynObj(D_DATA_GRP, DYNOBJ_MARIO_MUSTACHE_TRI_GROUP),
        LinkWithPtr(&faces_mario_mustache),

    StartGroup(DYNOBJ_MARIO_MUSTACHE_MTL_GROUP),
        MakeDynObj(D_MATERIAL, 0),
            SetId(0),
            SetAmbient(0.0, 0.0, 0.0),
            SetDiffuse(0.0, 0.0, 0.0),
    EndGroup(DYNOBJ_MARIO_MUSTACHE_MTL_GROUP),

    MakeDynObj(D_SHAPE, DYNOBJ_MARIO_MUSTACHE_SHAPE),
        SetNodeGroup(DYNOBJ_MARIO_MUSTACHE_VTX_GROUP),
        SetPlaneGroup(DYNOBJ_MARIO_MUSTACHE_TRI_GROUP),
        SetMaterialGroup(DYNOBJ_MARIO_MUSTACHE_MTL_GROUP),

    EndList(),
};












#define VTX_NUM 26
/* @ 040042E0 */
s16 verts_luigi_eyebrow_right[VTX_NUM][3] = {{103, 401, 363}, {60, 379, 378}, {84, 375, 370}, {167, 389, 339}, {136, 386, 353}, {189, 362, 331}, {200, 323, 297}, {171, 351, 305}, {205, 370, 291}, {121, 369, 323}, {158, 403, 306}, {225, 332, 286}, {228, 284, 289}, {120, 412, 319}, {83, 409, 334}, {71, 364, 342}, {44, 339, 354}, {16, 302, 356}, {28, 357, 361}, {208, 367, 323}, {210, 333, 318}, {136, 404, 353}, {55, 348, 377}, {226, 339, 311}, {56, 393, 349}, {40, 354, 382}};

/* @ 0400437C */
struct GdVtxData vtx_luigi_eyebrow_right = { VTX_NUM, 0x1, verts_luigi_eyebrow_right };
#undef VTX_NUM

#define FACE_NUM 36
/* @ 04004388 */
u16 facedata_luigi_eyebrow_right[FACE_NUM][4]   = {{0, 0, 1, 2}, {0, 3, 4, 5}, {0, 20, 23, 19}, {0, 1, 25, 22}, {0, 0, 21, 13}, {0, 2, 15, 9}, {0, 7, 6, 20}, {0, 3, 19, 8}, {0, 25, 1, 24}, {0, 19, 5, 20}, {0, 19, 3, 5}, {0, 3, 21, 4}, {0, 21, 0, 4}, {0, 0, 2, 4}, {0, 1, 22, 2}, {0, 20, 12, 23}, {0, 13, 14, 0}, {0, 4, 2, 9}, {0, 20, 5, 7}, {0, 22, 17, 16}, {0, 8, 10, 3}, {0, 24, 18, 25}, {0, 23, 11, 8}, {0, 14, 24, 1}, {0, 5, 4, 9}, {0, 2, 22, 15}, {0, 11, 23, 12}, {0, 25, 18, 17}, {0, 20, 6, 12}, {0, 10, 13, 21}, {0, 8, 19, 23}, {0, 25, 17, 22}, {0, 1, 0, 14}, {0, 21, 3, 10}, {0, 22, 16, 15}, {0, 9, 7, 5}};

/* @ 040044A8 */
struct GdFaceData faces_luigi_eyebrow_right = { FACE_NUM, 0x1, facedata_luigi_eyebrow_right };
#undef FACE_NUM

/* @ 040044B4 */
struct DynList dynlist_luigi_eyebrow_right[16] = {
    BeginList(),
    MakeDynObj(D_DATA_GRP, 0x5A),
    LinkWithPtr(&vtx_luigi_eyebrow_right),
    MakeDynObj(D_DATA_GRP, 0x5B),
    LinkWithPtr(&faces_luigi_eyebrow_right),
    StartGroup(0x5C),
    MakeDynObj(D_MATERIAL, 0x0),
    SetId(0),
    SetAmbient(0.0, 0.0, 0.0),
    SetDiffuse(0.0, 0.0, 0.0),
    EndGroup(0x5C),
    MakeDynObj(D_SHAPE, 0x5D),
    SetNodeGroup(0x5A),
    SetPlaneGroup(0x5B),
    SetMaterialGroup(0x5C),
    EndList(),
};

#define VTX_NUM 26
/* @ 04004634 */
s16 verts_luigi_eyebrow_left[VTX_NUM][3] = {{-55, 348, 377}, {-16, 302, 356}, {-44, 350, 382}, {-44, 339, 353}, {-71, 364, 341}, {-51, 386, 348}, {-136, 404, 352}, {-120, 412, 318}, {-158, 403, 306}, {-228, 284, 289}, {-200, 323, 297}, {-210, 333, 317}, {-28, 344, 363}, {-226, 339, 310}, {-225, 332, 285}, {-84, 375, 370}, {-121, 369, 322}, {-136, 386, 352}, {-189, 362, 330}, {-60, 379, 377}, {-83, 409, 333}, {-205, 370, 290}, {-167, 389, 338}, {-171, 351, 305}, {-103, 401, 363}, {-208, 367, 323}};


/* @ 040046D0 */
struct GdVtxData vtx_luigi_eyebrow_left = { VTX_NUM, 0x1, verts_luigi_eyebrow_left };
#undef VTX_NUM

#define FACE_NUM 36
/* @ 040046DC */
u16 facedata_luigi_eyebrow_left[FACE_NUM][4] = {{0, 0, 1, 2}, {0, 8, 22, 6}, {0, 6, 7, 8}, {0, 9, 10, 11}, {0, 1, 12, 2}, {0, 9, 13, 14}, {0, 4, 0, 15}, {0, 16, 17, 18}, {0, 19, 5, 20}, {0, 21, 14, 13}, {0, 2, 12, 5}, {0, 22, 8, 21}, {0, 3, 1, 0}, {0, 23, 18, 11}, {0, 16, 15, 17}, {0, 24, 20, 7}, {0, 13, 9, 11}, {0, 15, 0, 19}, {0, 17, 15, 24}, {0, 17, 24, 6}, {0, 17, 6, 22}, {0, 18, 22, 25}, {0, 11, 18, 25}, {0, 4, 3, 0}, {0, 18, 23, 16}, {0, 20, 24, 19}, {0, 13, 25, 21}, {0, 5, 19, 2}, {0, 21, 25, 22}, {0, 11, 10, 23}, {0, 18, 17, 22}, {0, 15, 19, 24}, {0, 16, 4, 15}, {0, 7, 6, 24}, {0, 0, 2, 19}, {0, 25, 13, 11}};


/* @ 040047FC */
struct GdFaceData faces_luigi_eyebrow_left = { FACE_NUM, 0x1, facedata_luigi_eyebrow_left };
#undef FACE_NUM

/* @ 04004808 */
struct DynList dynlist_luigi_eyebrow_left[16] = {
    BeginList(),
    MakeDynObj(D_DATA_GRP, 0x38),
    LinkWithPtr(&vtx_luigi_eyebrow_left),
    MakeDynObj(D_DATA_GRP, 0x39),
    LinkWithPtr(&faces_luigi_eyebrow_left),
    StartGroup(0x3A),
    MakeDynObj(D_MATERIAL, 0x0),
    SetId(0),
    SetAmbient(0.0, 0.0, 0.0),
    SetDiffuse(0.0, 0.0, 0.0),
    EndGroup(0x3A),
    MakeDynObj(D_SHAPE, 0x3B),
    SetNodeGroup(0x38),
    SetPlaneGroup(0x39),
    SetMaterialGroup(0x3A),
    EndList(),
};

#define VTX_NUM 56
/* @ 04004988 */
s16 verts_luigi_mustache[VTX_NUM][3] = {{-207, -23, 394}, {-309, -49, 356}, {-297, -77, 359}, {274, -127, 368}, {232, -164, 376}, {239, -170, 352}, {282, -129, 343}, {-286, 27, 360}, {-207, -23, 371}, {-288, 40, 337}, {-163, -192, 367}, {-152, -188, 391}, {-194, -177, 382}, {-200, -182, 359}, {305, -101, 339}, {321, -77, 335}, {310, -77, 359}, {294, -101, 363}, {-226, -170, 352}, {-219, -164, 376}, {-261, -127, 368}, {-269, -129, 343}, {-321, -50, 333}, {-309, -77, 335}, {322, -20, 355}, {321, -49, 356}, {334, -50, 333}, {334, -21, 332}, {220, -21, 394}, {299, 27, 360}, {300, 40, 337}, {220, -21, 371}, {-94, -56, 446}, {104, -50, 446}, {104, -50, 400}, {-94, -56, 400}, {164, -188, 391}, {119, -190, 409}, {131, -199, 380}, {175, -192, 367}, {-310, -20, 355}, {-321, -21, 332}, {-282, -101, 363}, {-292, -101, 339}, {213, -182, 359}, {206, -177, 382}, {-50, -190, 417}, {-107, -190, 409}, {-118, -199, 380}, {-56, -199, 394}, {4, -169, 398}, {27, -183, 399}, {20, -169, 427}, {4, -165, 427}, {69, -199, 394}, {63, -190, 417}};


/* @ 04004AD8 */
struct GdVtxData vtx_luigi_mustache = { VTX_NUM, 0x1, verts_luigi_mustache };
#undef VTX_NUM

#define FACE_NUM 100
/* @ 04004AE4 */
u16 facedata_luigi_mustache[FACE_NUM][4]  = {{0, 0, 1, 2}, {0, 3, 4, 5}, {0, 3, 5, 6}, {0, 7, 0, 8}, {0, 7, 8, 9}, {0, 10, 11, 12}, {0, 10, 12, 13}, {0, 14, 15, 16}, {0, 14, 16, 17}, {0, 18, 19, 20}, {0, 18, 20, 21}, {0, 2, 1, 22}, {0, 2, 22, 23}, {0, 24, 25, 26}, {0, 24, 26, 27}, {0, 28, 29, 30}, {0, 28, 30, 31}, {0, 32, 33, 34}, {0, 32, 34, 35}, {0, 34, 33, 28}, {0, 34, 28, 31}, {0, 0, 32, 35}, {0, 0, 35, 8}, {0, 36, 37, 38}, {0, 36, 38, 39}, {0, 30, 29, 24}, {0, 30, 24, 27}, {0, 40, 7, 9}, {0, 40, 9, 41}, {0, 20, 42, 43}, {0, 20, 43, 21}, {0, 44, 5, 4}, {0, 44, 4, 45}, {0, 46, 47, 48}, {0, 46, 48, 49}, {0, 50, 51, 52}, {0, 50, 52, 53}, {0, 12, 19, 18}, {0, 12, 18, 13}, {0, 45, 36, 39}, {0, 45, 39, 44}, {0, 21, 8, 35}, {0, 17, 3, 6}, {0, 17, 6, 14}, {0, 25, 16, 15}, {0, 25, 15, 26}, {0, 1, 40, 41}, {0, 1, 41, 22}, {0, 42, 2, 23}, {0, 42, 23, 43}, {0, 53, 46, 49}, {0, 53, 49, 50}, {0, 51, 54, 55}, {0, 51, 55, 52}, {0, 47, 11, 10}, {0, 47, 10, 48}, {0, 37, 55, 54}, {0, 37, 54, 38}, {0, 52, 55, 33}, {0, 53, 52, 33}, {0, 53, 33, 32}, {0, 37, 36, 33}, {0, 3, 17, 16}, {0, 3, 16, 28}, {0, 3, 28, 33}, {0, 55, 37, 33}, {0, 33, 45, 4}, {0, 33, 36, 45}, {0, 33, 4, 3}, {0, 11, 47, 32}, {0, 20, 19, 32}, {0, 47, 46, 32}, {0, 46, 53, 32}, {0, 12, 11, 32}, {0, 32, 0, 20}, {0, 19, 12, 32}, {0, 10, 13, 18}, {0, 24, 29, 28}, {0, 25, 24, 28}, {0, 16, 25, 28}, {0, 0, 7, 40}, {0, 0, 40, 1}, {0, 2, 42, 20}, {0, 2, 20, 0}, {0, 31, 14, 6}, {0, 10, 18, 21}, {0, 31, 30, 27}, {0, 6, 34, 31}, {0, 10, 21, 35}, {0, 34, 6, 39}, {0, 27, 26, 15}, {0, 27, 15, 14}, {0, 41, 9, 8}, {0, 8, 43, 41}, {0, 43, 23, 41}, {0, 23, 22, 41}, {0, 21, 43, 8}, {0, 27, 14, 31}, {0, 6, 5, 39}, {0, 5, 44, 39}};


/* @ 04004E04 */
struct GdFaceData faces_luigi_mustache = { FACE_NUM, 0x1, facedata_luigi_mustache };
#undef FACE_NUM

/* @ 04004E10 */
struct DynList dynlist_luigi_mustache[16] = {
    BeginList(),
    MakeDynObj(D_DATA_GRP, 0x16),
    LinkWithPtr(&vtx_luigi_mustache),
    MakeDynObj(D_DATA_GRP, 0x17),
    LinkWithPtr(&faces_luigi_mustache),
    StartGroup(0x18),
    MakeDynObj(D_MATERIAL, 0x0),
    SetId(0),
    SetAmbient(0.0, 0.0, 0.0),
    SetDiffuse(0.0, 0.0, 0.0),
    EndGroup(0x18),
    MakeDynObj(D_SHAPE, 0x19),
    SetNodeGroup(0x16),
    SetPlaneGroup(0x17),
    SetMaterialGroup(0x18),
    EndList(),
};
