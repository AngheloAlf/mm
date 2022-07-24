#include "global.h"

#include "az/az.h"
#include "az/az_state.h"
#include "az/az_menu.h"
#include "az/az_printer.h"


az_MenuState sAzActorMenuState;


void az_ActorMenu_CallbackReturn(GameState *gameState, void* param, void** data) {
    gAzState.menuType = AZ_MENU_TYPE_MAIN;
}

u16 sAzActorMenu_ActorId;
u16 sAzActorMenu_Params;
Vec3s sAzActorMenu_Position;
Vec3s sAzActorMenu_Rotation;

void az_ActorMenu_CallbackSpawn(GameState *gameState, void* param, void** data) {
    PlayState* play = (PlayState*)gameState;

    // Ensure current State is Play
    if (gameState->destroy != Play_Fini) {
        return;
    }

    if (sAzActorMenu_ActorId >= ACTOR_ID_MAX) {
        return;
    }

    Actor_Spawn(&play->actorCtx, play, sAzActorMenu_ActorId, sAzActorMenu_Position.x, sAzActorMenu_Position.y, sAzActorMenu_Position.z, sAzActorMenu_Rotation.x, sAzActorMenu_Rotation.y, sAzActorMenu_Rotation.z, sAzActorMenu_Params);
}

void az_ActorMenu_CallbackFetchFromPlayer(GameState *gameState, void* param, void** data) {
    PlayState* play = (PlayState*)gameState;
    Player* player;

    // Ensure current State is Play
    if (gameState->destroy != Play_Fini) {
        return;
    }

    player = GET_PLAYER(play);

    sAzActorMenu_Position.x = player->actor.world.pos.x;
    sAzActorMenu_Position.y = player->actor.world.pos.y;
    sAzActorMenu_Position.z = player->actor.world.pos.z;
    sAzActorMenu_Rotation = player->actor.world.rot;
}

az_MenuElement sAzActorMenuElements[][AZ_MENU_COLUMN_MAX] = {
    { { AZ_MENUELE_BUTTON, "Return", az_ActorMenu_CallbackReturn, NULL, NULL }, },
    { 0 },
    { { AZ_MENUELE_LABEL,  "Actor ID", NULL, NULL, NULL }, { AZ_MENUELE_INPUT_U16, NULL, NULL, NULL, &sAzActorMenu_ActorId } },
    { { AZ_MENUELE_LABEL,  "Params  ", NULL, NULL, NULL }, { AZ_MENUELE_INPUT_U16, NULL, NULL, NULL, &sAzActorMenu_Params } },
    { { AZ_MENUELE_LABEL,  "Position", NULL, NULL, NULL }, { AZ_MENUELE_INPUT_U16, NULL, NULL, NULL, &sAzActorMenu_Position.x }, { AZ_MENUELE_INPUT_U16, NULL, NULL, NULL, &sAzActorMenu_Position.y }, { AZ_MENUELE_INPUT_U16, NULL, NULL, NULL, &sAzActorMenu_Position.z } },
    { { AZ_MENUELE_LABEL,  "Rotation", NULL, NULL, NULL }, { AZ_MENUELE_INPUT_U16, NULL, NULL, NULL, &sAzActorMenu_Rotation.x }, { AZ_MENUELE_INPUT_U16, NULL, NULL, NULL, &sAzActorMenu_Rotation.y }, { AZ_MENUELE_INPUT_U16, NULL, NULL, NULL, &sAzActorMenu_Rotation.z } },
    { { AZ_MENUELE_BUTTON, "Spawn   ", az_ActorMenu_CallbackSpawn, NULL, NULL }, { AZ_MENUELE_BUTTON, "Fetch from Player", az_ActorMenu_CallbackFetchFromPlayer, NULL, NULL } },
};

void az_ActorMenu_Update(GameState *gameState) {
    az_Menus_CommonUpdate(gameState, &sAzActorMenuState, ARRAY_COUNT(sAzActorMenuElements), sAzActorMenuElements);
}

void az_ActorMenu_PrintElements(GameState *gameState, GfxPrint *printer) {
    s32 x = 3;
    s32 y = 3;

    az_Menus_PrintAllElements(gameState, &sAzActorMenuState, ARRAY_COUNT(sAzActorMenuElements), sAzActorMenuElements, printer, x, y);
}

void az_ActorMenu_Draw(GameState *gameState) {
    OPEN_DISPS(gameState->gfxCtx);
    func_8012C4C0(gameState->gfxCtx);

    AZ_OPEN_PRINTER_OVERLAY();

    az_ActorMenu_PrintElements(gameState, &AZ_PRINTER);

    AZ_CLOSE_PRINTER_OVERLAY();

    CLOSE_DISPS(gameState->gfxCtx);
}
