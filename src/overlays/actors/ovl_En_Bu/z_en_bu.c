#include "z_en_bu.h"

#define FLAGS 0x00000001

#define THIS ((EnBu*)thisx)

void EnBu_Init(Actor* thisx, GameState* game);
void EnBu_Destroy(Actor* thisx, GameState* game);
void EnBu_Update(Actor* thisx, GameState* game);
void EnBu_Draw(Actor* thisx, GameState* game);

void EnBu_DoNothing(EnBu* this, GlobalContext* globalCtx);

const ActorInit En_Bu_InitVars = {
    ACTOR_EN_BU,
    ACTORCAT_ENEMY,
    FLAGS,
    GAMEPLAY_KEEP,
    sizeof(EnBu),
    (ActorFunc)EnBu_Init,
    (ActorFunc)EnBu_Destroy,
    (ActorFunc)EnBu_Update,
    (ActorFunc)EnBu_Draw,
};

void EnBu_Init(Actor* thisx, GameState* game) {
    EnBu* this = THIS;

    this->actionFunc = EnBu_DoNothing;
}

void EnBu_Destroy(Actor* thisx, GameState* game) {
}

void EnBu_DoNothing(EnBu* this, GlobalContext* globalCtx) {
}

void EnBu_Update(Actor* thisx, GameState* game) {
    EnBu* this = THIS;

    Actor_SetVelocityAndMoveYRotationAndGravity(&this->actor);
    this->actionFunc(this, game);
}

void EnBu_Draw(Actor* thisx, GameState* game) {
    EnBu* this = THIS;

    OPEN_DISPS(game->gfxCtx);

    SysMatrix_InsertTranslation(this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z, 0);
    SysMatrix_InsertZRotation_s(this->actor.shape.rot.z, 1);
    Matrix_RotateY(this->actor.shape.rot.y, 1);
    SysMatrix_InsertXRotation_s(this->actor.shape.rot.x, 1);
    Matrix_Scale(0.01f, 0.01f, 0.01f, 1);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(game->gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, this->displayListPtr);

    CLOSE_DISPS(game->gfxCtx);
}
