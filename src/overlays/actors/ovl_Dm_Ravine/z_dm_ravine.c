/*
 * File: z_dm_ravine.c
 * Overlay: ovl_Dm_Ravine
 * Description: Lost Woods Cutscene - Tree Trunk
 */

#include "z_dm_ravine.h"

#define FLAGS 0x00000030

#define THIS ((DmRavine*)thisx)

void DmRavine_Init(Actor* thisx, GameState* game);
void DmRavine_Destroy(Actor* thisx, GameState* game);
void DmRavine_DoNothing(DmRavine* this, GlobalContext* globalCtx);
void DmRavine_Update(Actor* thisx, GameState* game);
void DmRavine_Draw(Actor* thisx, GameState* game);

const ActorInit Dm_Ravine_InitVars = {
    ACTOR_DM_RAVINE,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_KEIKOKU_DEMO,
    sizeof(DmRavine),
    (ActorFunc)DmRavine_Init,
    (ActorFunc)DmRavine_Destroy,
    (ActorFunc)DmRavine_Update,
    (ActorFunc)DmRavine_Draw,
};

void DmRavine_Init(Actor* thisx, GameState* game) {
    DmRavine* this = THIS;
    u8 flag = gSaveContext.weekEventReg[0];
    if (((flag & 0x10) | cREG(0)) != 0) {
        Actor_MarkForDeath(&this->actor);
        return;
    }

    this->isActive = false;
    ((GlobalContext*)game)->roomCtx.unk7A[0] = 1;
    ((GlobalContext*)game)->roomCtx.unk7A[1] = 0;
    this->state = 0;
    Actor_SetScale(&this->actor, 1.0f);
    this->actionFunc = DmRavine_DoNothing;
}

void DmRavine_Destroy(Actor* thisx, GameState* game) {
}

void DmRavine_DoNothing(DmRavine* this, GlobalContext* globalCtx) {
}

void DmRavine_Update(Actor* thisx, GameState* game) {
    DmRavine* this = THIS;
    RoomContext* roomCtx;

    switch ((DmRavineState)this->state) {
        case DM_RAVINE_STATE_INITIALIZED:
            return;
        case DM_RAVINE_STATE_ACTIVE:
            this->isActive = true;
            ((GlobalContext*)game)->roomCtx.unk7A[1]++;
            if (((GlobalContext*)game)->roomCtx.unk7A[1] > 254) {
                ((GlobalContext*)game)->roomCtx.unk7A[1] = 254;
                if (((GlobalContext*)game)->csCtx.frames > 700) {
                    ((GlobalContext*)game)->roomCtx.unk7A[1] = 255;
                    ((GlobalContext*)game)->roomCtx.unk7A[0] = 0;
                    this->state++; // -> DM_RAVINE_STATE_PENDING_DEATH
                }
            }
            break;
        case DM_RAVINE_STATE_PENDING_DEATH:
            Actor_MarkForDeath(&this->actor);
            break;
    }
}

void DmRavine_Draw(Actor* thisx, GameState* game) {
}
