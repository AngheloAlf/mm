#include "z_en_ending_hero2.h"

#define FLAGS 0x00000009

#define THIS ((EnEndingHero2*)thisx)

void EnEndingHero2_Init(Actor* thisx, GameState* game);
void EnEndingHero2_Destroy(Actor* thisx, GameState* game);
void EnEndingHero2_Update(Actor* thisx, GameState* game);
void EnEndingHero2_Draw(Actor* thisx, GameState* game);

void func_80C232E8(EnEndingHero2* this);
void func_80C23304(EnEndingHero2* this, GlobalContext* globalCtx);

const ActorInit En_Ending_Hero2_InitVars = {
    ACTOR_EN_ENDING_HERO2,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_BAI,
    sizeof(EnEndingHero2),
    (ActorFunc)EnEndingHero2_Init,
    (ActorFunc)EnEndingHero2_Destroy,
    (ActorFunc)EnEndingHero2_Update,
    (ActorFunc)EnEndingHero2_Draw,
};

extern FlexSkeletonHeader D_06007908;
extern AnimationHeader D_060011C0;

void EnEndingHero2_Init(Actor* thisx, GameState* game) {
    EnEndingHero2* this = THIS;

    this->actor.colChkInfo.mass = 0xFF;
    Actor_SetScale(&this->actor, 0.01f);
    this->actor.targetMode = 6;
    this->actor.gravity = -3.0f;
    SkelAnime_InitSV(game, &this->skelAnime, &D_06007908, &D_060011C0, this->limbDrawTable,
                     this->transitionDrawTable, 20);
    ActorShape_Init(&this->actor.shape, 0.0f, func_800B3FC0, 25.0f);
    func_80C232E8(this);
}

void EnEndingHero2_Destroy(Actor* thisx, GameState* game) {
}

void func_80C232E8(EnEndingHero2* this) {
    this->unk27C = 1;
    this->actionFunc = func_80C23304;
}

void func_80C23304(EnEndingHero2* this, GlobalContext* globalCtx) {
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
}

void EnEndingHero2_Update(Actor* thisx, GameState* game) {
    EnEndingHero2* this = THIS;

    this->actionFunc(this, game);
    Actor_SetVelocityAndMoveYRotationAndGravity(&this->actor);
    Actor_UpdateBgCheckInfo(game, &this->actor, 20.0f, 20.0f, 50.0f, 0x1D);
}

void EnEndingHero2_Draw(Actor* thisx, GameState* game) {
    EnEndingHero2* this = THIS;

    func_8012C28C(game->gfxCtx);
    func_8012C2DC(game->gfxCtx);
    SkelAnime_DrawSV(game, this->skelAnime.skeleton, this->skelAnime.limbDrawTbl, this->skelAnime.dListCount, 0, 0,
                     &this->actor);
}
