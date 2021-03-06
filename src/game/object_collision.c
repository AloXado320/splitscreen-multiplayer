#include <PR/ultratypes.h>

#include "sm64.h"
#include "debug.h"
#include "interaction.h"
#include "mario.h"
#include "object_list_processor.h"
#include "spawn_object.h"

struct Object *debug_print_obj_collision(struct Object *a) {
    struct Object *sp24;
    UNUSED s32 unused;
    s32 i;

    for (i = 0; i < a->numCollidedObjs; i++) {
        print_debug_top_down_objectinfo("ON", 0);
        sp24 = a->collidedObjs[i];
        if ((sp24 != gMarioObject) & (sp24 != gLuigiObject)) {
            return sp24;
        }
    }
    return NULL;
}
struct InteractionHandler {
    u32 interactType;
    u32 (*handler)(struct MarioState *, u32, struct Object *);
};
extern struct InteractionHandler sInteractionHandlers[];

extern u32 interact_bounce_top(struct MarioState *m, UNUSED u32 interactType, struct Object *o);
f32 IsBounceTop(struct Object *a, struct Object *b) { //this is a symptomatic treament and should not be finalized like this if possible, but i could not find the root issue of the bug that makes collision hurtboxes too big.
    f32 ret = 1.f;
    int i = 0;
    if ((a == gMarioObject) || (b == gMarioObject) || (a == gLuigiObject) || (b == gLuigiObject)) {

        for (i = 0; i < 31; i++) {
            if (sInteractionHandlers[i].interactType == a->oInteractType) {
                if (interact_bounce_top == sInteractionHandlers[i].handler) {
                    ret = 0.5f;
                }
            }
        }
        for (i = 0; i < 31; i++) {
            if (sInteractionHandlers[i].interactType == b->oInteractType) {
                if (interact_bounce_top == sInteractionHandlers[i].handler) {
                    ret = 0.5f;
                }
            }
        }
    }
    return ret;
};

s32 detect_object_hitbox_overlap(struct Object *a, struct Object *b) {
    f32 sp3C = a->oPosY - a->hitboxDownOffset;
    f32 sp38 = b->oPosY - b->hitboxDownOffset;
    f32 dx = a->oPosX - b->oPosX;
    UNUSED f32 sp30 = sp3C - sp38;
    f32 dz = a->oPosZ - b->oPosZ;
    f32 collisionRadius = a->hitboxRadius + b->hitboxRadius;
    f32 distance = sqrtf(dx * dx + dz * dz);
    struct Object *mObjHurtbox;
    struct Object *lObjHurtbox;
    if (gMarioObject) {
        mObjHurtbox = gMarioObject->oPlayerHurtbox;
    }
    if (gLuigiObject) {
        lObjHurtbox = gLuigiObject->oPlayerHurtbox;
    }

    if ((gActivePlayers < 2)
        || (!(((((a == gLuigiObject) & ((b == gLuigiObject->oPlayerHitbox) || (b == lObjHurtbox)))
                || ((b == gLuigiObject) & ((a == gLuigiObject->oPlayerHitbox) || (a == lObjHurtbox)))))
              || (((a == gMarioObject) & ((b == gMarioObject->oPlayerHitbox) || (b == mObjHurtbox)))
                  || ((b == gMarioObject)
                      & ((a == gMarioObject->oPlayerHitbox) || (a == mObjHurtbox))))))) {
        if ((collisionRadius * IsBounceTop(a, b)) > distance) {
            f32 sp20 = a->hitboxHeight + sp3C;
            f32 sp1C = b->hitboxHeight + sp38;

            if (sp3C > sp1C) {
                return 0;
            }
            if (sp20 < sp38) {
                return 0;
            }
            if (a->numCollidedObjs >= 4) {
                return 0;
            }
            if (b->numCollidedObjs >= 4) {
                return 0;
            }
            a->collidedObjs[a->numCollidedObjs] = b;
            b->collidedObjs[b->numCollidedObjs] = a;
            a->collidedObjInteractTypes |= b->oInteractType;
            b->collidedObjInteractTypes |= a->oInteractType;
            a->numCollidedObjs++;
            b->numCollidedObjs++;
            return 1;
        }
    }
}

s32 detect_object_hurtbox_overlap(struct Object *a, struct Object *b) {
    f32 sp3C = a->oPosY - a->hitboxDownOffset;
    f32 sp38 = b->oPosY - b->hitboxDownOffset;
    f32 sp34 = a->oPosX - b->oPosX;
    UNUSED f32 sp30 = sp3C - sp38;
    f32 sp2C = a->oPosZ - b->oPosZ;
    f32 sp28 = a->hurtboxRadius + b->hurtboxRadius;
    f32 sp24 = sqrtf(sp34 * sp34 + sp2C * sp2C);

    if (a == gMarioObject) {
        b->oInteractionSubtype |= INT_SUBTYPE_DELAY_INVINCIBILITY;
    }

    if (sp28 > sp24) {
        f32 sp20 = a->hitboxHeight + sp3C;
        f32 sp1C = b->hurtboxHeight + sp38;

        if (sp3C > sp1C) {
            return 0;
        }
        if (sp20 < sp38) {
            return 0;
        }
        if (a == gMarioObject) {
            b->oInteractionSubtype &= ~INT_SUBTYPE_DELAY_INVINCIBILITY;
        }
        return 1;
    }

    //! no return value
    return 0;
}

void clear_object_collision(struct Object *a) {
    struct Object *sp4 = (struct Object *) a->header.next;

    while (sp4 != a) {
        sp4->numCollidedObjs = 0;
        sp4->collidedObjInteractTypes = 0;
        if (sp4->oIntangibleTimer > 0) {
            sp4->oIntangibleTimer--;
        }
        sp4 = (struct Object *) sp4->header.next;
    }
}

void check_collision_in_list(struct Object *a, struct Object *b, struct Object *c) {
    if (a->oIntangibleTimer == 0) {
        while (b != c) {
            if (b->oIntangibleTimer == 0) {
                if (detect_object_hitbox_overlap(a, b) && b->hurtboxRadius != 0.0f) {
                    detect_object_hurtbox_overlap(a, b);
                }
            }
            b = (struct Object *) b->header.next;
        }
    }
}

void check_player_object_collision(void) {
    struct Object *sp1C = (struct Object *) &gObjectLists[OBJ_LIST_PLAYER];
    struct Object *sp18 = (struct Object *) sp1C->header.next;

    while (sp18 != sp1C) {
        check_collision_in_list(sp18, (struct Object *) sp18->header.next, sp1C);
        check_collision_in_list(sp18, (struct Object *) gObjectLists[OBJ_LIST_POLELIKE].next,
                                (struct Object *) &gObjectLists[OBJ_LIST_POLELIKE]);
        check_collision_in_list(sp18, (struct Object *) gObjectLists[OBJ_LIST_LEVEL].next,
                                (struct Object *) &gObjectLists[OBJ_LIST_LEVEL]);
        check_collision_in_list(sp18, (struct Object *) gObjectLists[OBJ_LIST_GENACTOR].next,
                                (struct Object *) &gObjectLists[OBJ_LIST_GENACTOR]);
        check_collision_in_list(sp18, (struct Object *) gObjectLists[OBJ_LIST_PUSHABLE].next,
                                (struct Object *) &gObjectLists[OBJ_LIST_PUSHABLE]);
        check_collision_in_list(sp18, (struct Object *) gObjectLists[OBJ_LIST_SURFACE].next,
                                (struct Object *) &gObjectLists[OBJ_LIST_SURFACE]);
        check_collision_in_list(sp18, (struct Object *) gObjectLists[OBJ_LIST_DESTRUCTIVE].next,
                                (struct Object *) &gObjectLists[OBJ_LIST_DESTRUCTIVE]);
        sp18 = (struct Object *) sp18->header.next;
    }
}

void check_pushable_object_collision(void) {
    struct Object *sp1C = (struct Object *) &gObjectLists[OBJ_LIST_PUSHABLE];
    struct Object *sp18 = (struct Object *) sp1C->header.next;

    while (sp18 != sp1C) {
        check_collision_in_list(sp18, (struct Object *) sp18->header.next, sp1C);
        sp18 = (struct Object *) sp18->header.next;
    }
}

void check_destructive_object_collision(void) {
    struct Object *sp1C = (struct Object *) &gObjectLists[OBJ_LIST_DESTRUCTIVE];
    struct Object *sp18 = (struct Object *) sp1C->header.next;

    while (sp18 != sp1C) {
        if (sp18->oDistanceToMario < 2000.0f && !(sp18->activeFlags & ACTIVE_FLAG_UNK9)) {
            check_collision_in_list(sp18, (struct Object *) sp18->header.next, sp1C);
            check_collision_in_list(sp18, (struct Object *) gObjectLists[OBJ_LIST_GENACTOR].next,
                                    (struct Object *) &gObjectLists[OBJ_LIST_GENACTOR]);
            check_collision_in_list(sp18, (struct Object *) gObjectLists[OBJ_LIST_PUSHABLE].next,
                                    (struct Object *) &gObjectLists[OBJ_LIST_PUSHABLE]);
            check_collision_in_list(sp18, (struct Object *) gObjectLists[OBJ_LIST_SURFACE].next,
                                    (struct Object *) &gObjectLists[OBJ_LIST_SURFACE]);
        }
        sp18 = (struct Object *) sp18->header.next;
    }
}

void detect_object_collisions(void) {
    clear_object_collision((struct Object *) &gObjectLists[OBJ_LIST_POLELIKE]);
    clear_object_collision((struct Object *) &gObjectLists[OBJ_LIST_PLAYER]);
    clear_object_collision((struct Object *) &gObjectLists[OBJ_LIST_PUSHABLE]);
    clear_object_collision((struct Object *) &gObjectLists[OBJ_LIST_GENACTOR]);
    clear_object_collision((struct Object *) &gObjectLists[OBJ_LIST_LEVEL]);
    clear_object_collision((struct Object *) &gObjectLists[OBJ_LIST_SURFACE]);
    clear_object_collision((struct Object *) &gObjectLists[OBJ_LIST_DESTRUCTIVE]);
    check_player_object_collision();
    check_destructive_object_collision();
    check_pushable_object_collision();
}
