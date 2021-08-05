#include "z_obj_kepn_koya.h"

#define FLAGS 0x00000000

#define THIS ((ObjKepnKoya*)thisx)

void ObjKepnKoya_Init(Actor* thisx, GameState* game);
void ObjKepnKoya_Destroy(Actor* thisx, GameState* game);
void ObjKepnKoya_Update(Actor* thisx, GameState* game);
void ObjKepnKoya_Draw(Actor* thisx, GameState* game);

const ActorInit Obj_Kepn_Koya_InitVars = {
    ACTOR_OBJ_KEPN_KOYA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_KEPN_KOYA,
    sizeof(ObjKepnKoya),
    (ActorFunc)ObjKepnKoya_Init,
    (ActorFunc)ObjKepnKoya_Destroy,
    (ActorFunc)ObjKepnKoya_Update,
    (ActorFunc)ObjKepnKoya_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneScale, 1200, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 900, ICHAIN_STOP),
};

extern CollisionHeader D_0600805C;
extern Gfx D_06003478[];

void ObjKepnKoya_Init(Actor* thisx, GameState* game) {
    ObjKepnKoya* this = THIS;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    Actor_SetScale(&this->dyna.actor, 0.1f);
    BcCheck3_BgActorInit(&this->dyna, 0);
    BgCheck3_LoadMesh(game, &this->dyna, &D_0600805C);
    if (this->dyna.bgId == 0x32) {
        Actor_MarkForDeath(&this->dyna.actor);
    }
}

void ObjKepnKoya_Destroy(Actor* thisx, GameState* game) {
    ObjKepnKoya* this = THIS;

    BgCheck_RemoveActorMesh(game, &((GlobalContext*)game)->colCtx.dyna, this->dyna.bgId);
}

void ObjKepnKoya_Update(Actor* thisx, GameState* game) {
}

void ObjKepnKoya_Draw(Actor* thisx, GameState* game) {
    func_800BDFC0(game, D_06003478);
}
