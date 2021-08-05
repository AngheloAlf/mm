#include "z_item_inbox.h"

#define FLAGS 0x00000009

#define THIS ((ItemInbox*)thisx)

void ItemInbox_Init(Actor* thisx, GameState* game);
void ItemInbox_Destroy(Actor* thisx, GameState* game);
void ItemInbox_Update(Actor* thisx, GameState* game);
void ItemInbox_Draw(Actor* thisx, GameState* game);

void ItemInbox_Idle(ItemInbox* this, GlobalContext* globalCtx);

const ActorInit Item_Inbox_InitVars = {
    ACTOR_ITEM_INBOX,
    ACTORCAT_NPC,
    FLAGS,
    GAMEPLAY_KEEP,
    sizeof(ItemInbox),
    (ActorFunc)ItemInbox_Init,
    (ActorFunc)ItemInbox_Destroy,
    (ActorFunc)ItemInbox_Update,
    (ActorFunc)ItemInbox_Draw,
};

void ItemInbox_Init(Actor* thisx, GameState* game) {
    ItemInbox* this = THIS;

    this->actionFunc = ItemInbox_Idle;
    Actor_SetScale(&this->actor, 0.2f);
}

void ItemInbox_Destroy(Actor* thisx, GameState* game) {
}

void ItemInbox_Idle(ItemInbox* this, GlobalContext* globalCtx) {
    if (Actor_GetChestFlag(globalCtx, (this->actor.params >> 8) & 0x1F)) {
        Actor_MarkForDeath(&this->actor);
    }
}

void ItemInbox_Update(Actor* thisx, GameState* game) {
    ItemInbox* this = THIS;

    this->actionFunc(this, game);
}

void ItemInbox_Draw(Actor* thisx, GameState* game) {
    ItemInbox* this = THIS;

    func_800B8050(&this->actor, game, 0);
    func_800B8118(&this->actor, game, 0);
    GetItem_Draw(game, this->actor.params & 0xFF);
}
