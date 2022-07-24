#include "global.h"

#include "az/az.h"
#include "az/az_state.h"
#include "az/az_menu.h"
#include "az/az_printer.h"


typedef struct az_MenuState2 {
    s32 ySelection;
    s32 xSelection;
    s32 inSelection;
    s32 subSelectionIndex;
} az_MenuState2;

az_MenuState2 sAzActorMenuState;


void az_ActorMenu_CallbackReturn(GameState *gameState, void* param, void** data) {
    gAzState.menuType = AZ_MENU_TYPE_MAIN;
}

typedef enum az_MenuElementType {
    AZ_MENUELE_LABEL,
    AZ_MENUELE_BUTTON,
    AZ_MENUELE_INPUT_U8,
    AZ_MENUELE_INPUT_U16,
    AZ_MENUELE_INPUT_U32,
    AZ_MENUELE_INPUT_LIST
} az_MenuElementType;

typedef struct {
    const char *label;
    az_MenuElementType type;
    az_MenuElementFunc callback;
    void* param;
    void* data;
} az_MenuElement2;

#define AZ_MENU_COLUMN_MAX 10

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

az_MenuElement2 sAzActorMenuElements[][AZ_MENU_COLUMN_MAX] = {
    { { "Return", AZ_MENUELE_BUTTON, az_ActorMenu_CallbackReturn, NULL, NULL }, },
    { 0 },
    { { "Actor ID", AZ_MENUELE_LABEL, NULL, NULL, NULL }, { "", AZ_MENUELE_INPUT_U16, NULL, NULL, &sAzActorMenu_ActorId } },
    { { "Params  ", AZ_MENUELE_LABEL, NULL, NULL, NULL }, { "", AZ_MENUELE_INPUT_U16, NULL, NULL, &sAzActorMenu_Params } },
    { { "Position", AZ_MENUELE_LABEL, NULL, NULL, NULL }, { "", AZ_MENUELE_INPUT_U16, NULL, NULL, &sAzActorMenu_Position.x }, { "", AZ_MENUELE_INPUT_U16, NULL, NULL, &sAzActorMenu_Position.y }, { "", AZ_MENUELE_INPUT_U16, NULL, NULL, &sAzActorMenu_Position.z } },
    { { "Rotation", AZ_MENUELE_LABEL, NULL, NULL, NULL }, { "", AZ_MENUELE_INPUT_U16, NULL, NULL, &sAzActorMenu_Rotation.x }, { "", AZ_MENUELE_INPUT_U16, NULL, NULL, &sAzActorMenu_Rotation.y }, { "", AZ_MENUELE_INPUT_U16, NULL, NULL, &sAzActorMenu_Rotation.z } },
    { { "Spawn   ", AZ_MENUELE_BUTTON, az_ActorMenu_CallbackSpawn, NULL, NULL }, { "Fetch from Player", AZ_MENUELE_BUTTON, az_ActorMenu_CallbackFetchFromPlayer, NULL, NULL } },
};

void az_ActorMenu_Update(GameState *gameState) {
    Input* controller1 = CONTROLLER1(gameState);

    if (sAzActorMenuState.inSelection) {
        az_MenuElement2* entry = &sAzActorMenuElements[sAzActorMenuState.ySelection][sAzActorMenuState.xSelection];
        u32 mask = 0x0000000F << (sAzActorMenuState.subSelectionIndex * 4);
        u32 inc = 0x0001 << (sAzActorMenuState.subSelectionIndex * 4);
        u8* bytePtr;
        u16* halfPtr;
        u32* wordPtr;

        if (CHECK_BTN_ALL(controller1->press.button, BTN_DUP)) {
            switch (entry->type) {
                case AZ_MENUELE_LABEL:
                case AZ_MENUELE_BUTTON:
                    break;

                case AZ_MENUELE_INPUT_U8:
                    bytePtr = entry->data;
                    *bytePtr = (*bytePtr & ~mask) | ((*bytePtr + inc) & mask);
                    break;

                case AZ_MENUELE_INPUT_U16:
                    halfPtr = entry->data;
                    *halfPtr = (*halfPtr & ~mask) | ((*halfPtr + inc) & mask);
                    break;

                case AZ_MENUELE_INPUT_U32:
                    wordPtr = entry->data;
                    *wordPtr = (*wordPtr & ~mask) | ((*wordPtr + inc) & mask);
                    break;

                case AZ_MENUELE_INPUT_LIST:
                    break;
            }
        } else if (CHECK_BTN_ALL(controller1->press.button, BTN_DDOWN)) {
            switch (entry->type) {
                case AZ_MENUELE_LABEL:
                case AZ_MENUELE_BUTTON:
                    break;

                case AZ_MENUELE_INPUT_U8:
                    bytePtr = entry->data;
                    *bytePtr = (*bytePtr & ~mask) | ((*bytePtr - inc) & mask);
                    break;

                case AZ_MENUELE_INPUT_U16:
                    halfPtr = entry->data;
                    *halfPtr = (*halfPtr & ~mask) | ((*halfPtr - inc) & mask);
                    break;

                case AZ_MENUELE_INPUT_U32:
                    wordPtr = entry->data;
                    *wordPtr = (*wordPtr & ~mask) | ((*wordPtr - inc) & mask);
                    break;

                case AZ_MENUELE_INPUT_LIST:
                    break;
            }
        } else if (CHECK_BTN_ALL(controller1->press.button, BTN_DRIGHT)) {
            sAzActorMenuState.subSelectionIndex--;
            if (sAzActorMenuState.subSelectionIndex < 0) {
                switch (entry->type) {
                    case AZ_MENUELE_LABEL:
                    case AZ_MENUELE_BUTTON:
                        break;

                    case AZ_MENUELE_INPUT_U8:
                        sAzActorMenuState.subSelectionIndex = 1;
                        break;

                    case AZ_MENUELE_INPUT_U16:
                        sAzActorMenuState.subSelectionIndex = 3;
                        break;

                    case AZ_MENUELE_INPUT_U32:
                        sAzActorMenuState.subSelectionIndex = 7;
                        break;

                    case AZ_MENUELE_INPUT_LIST:
                        break;
                }
            }
        } else if (CHECK_BTN_ALL(controller1->press.button, BTN_DLEFT)) {
            sAzActorMenuState.subSelectionIndex++;
            switch (entry->type) {
                case AZ_MENUELE_LABEL:
                case AZ_MENUELE_BUTTON:
                    break;

                case AZ_MENUELE_INPUT_U8:
                    if (sAzActorMenuState.subSelectionIndex >= 2) {
                        sAzActorMenuState.subSelectionIndex = 0;
                    }
                    break;

                case AZ_MENUELE_INPUT_U16:
                    if (sAzActorMenuState.subSelectionIndex >= 4) {
                        sAzActorMenuState.subSelectionIndex = 0;
                    }
                    break;

                case AZ_MENUELE_INPUT_U32:
                    if (sAzActorMenuState.subSelectionIndex >= 8) {
                        sAzActorMenuState.subSelectionIndex = 0;
                    }
                    break;

                case AZ_MENUELE_INPUT_LIST:
                    break;
            }
        }

        if (CHECK_BTN_ALL(controller1->press.button, BTN_L)) {
            sAzActorMenuState.inSelection = false;
        }

        return;
    }

    if (CHECK_BTN_ALL(controller1->press.button, BTN_DUP)) {
        while (true) {
            sAzActorMenuState.ySelection--;
            if (sAzActorMenuState.ySelection < 0) {
                sAzActorMenuState.ySelection = ARRAY_COUNT(sAzActorMenuElements) -1;
            }

            if (sAzActorMenuElements[sAzActorMenuState.ySelection][0].label == NULL) {
                continue;
            }

            while (sAzActorMenuState.xSelection > 0 && sAzActorMenuElements[sAzActorMenuState.ySelection][sAzActorMenuState.xSelection].label == NULL) {
                sAzActorMenuState.xSelection--;
            }
            break;
        }
    } else if (CHECK_BTN_ALL(controller1->press.button, BTN_DDOWN)) {
        while (true) {
            sAzActorMenuState.ySelection++;
            sAzActorMenuState.ySelection %= ARRAY_COUNT(sAzActorMenuElements);

            if (sAzActorMenuElements[sAzActorMenuState.ySelection][0].label == NULL) {
                continue;
            }

            while (sAzActorMenuState.xSelection > 0 && sAzActorMenuElements[sAzActorMenuState.ySelection][sAzActorMenuState.xSelection].label == NULL) {
                sAzActorMenuState.xSelection--;
            }
            break;
        }
    } else if (CHECK_BTN_ALL(controller1->press.button, BTN_DRIGHT)) {
        sAzActorMenuState.xSelection++;
        if (sAzActorMenuElements[sAzActorMenuState.ySelection][sAzActorMenuState.xSelection].label == NULL) {
            sAzActorMenuState.xSelection = 0;
        }
    } else if (CHECK_BTN_ALL(controller1->press.button, BTN_DLEFT)) {
        sAzActorMenuState.xSelection--;
        if (sAzActorMenuState.xSelection < 0) {
            sAzActorMenuState.xSelection = AZ_MENU_COLUMN_MAX-1;
            while (sAzActorMenuElements[sAzActorMenuState.ySelection][sAzActorMenuState.xSelection].label == NULL) {
                sAzActorMenuState.xSelection--;
            }
        }
    }

    if (CHECK_BTN_ALL(controller1->press.button, BTN_L)) {
        az_MenuElement2* entry = &sAzActorMenuElements[sAzActorMenuState.ySelection][sAzActorMenuState.xSelection];

        switch (entry->type) {
            case AZ_MENUELE_BUTTON:
                if (entry->callback != NULL){
                    entry->callback(gameState, entry->param, &entry->data);
                }
                break;

            case AZ_MENUELE_INPUT_U8:
            case AZ_MENUELE_INPUT_U16:
            case AZ_MENUELE_INPUT_U32:
            case AZ_MENUELE_INPUT_LIST:
                sAzActorMenuState.inSelection = true;
                sAzActorMenuState.subSelectionIndex = 0;
                break;

            case AZ_MENUELE_LABEL:
                break;
        }
    }
}

void az_ActorMenu_PrintElements(GameState *gameState, GfxPrint *printer) {
    s32 x = 3;
    s32 y = 3;
    s32 i;
    s32 j;

    //GfxPrint_SetPos(printer, 1, 1);
    //GfxPrint_SetColor(printer, 200, 200, 55, 255);
    //GfxPrint_Printf(printer, "%i", sAzActorMenuState.subSelectionIndex);

    for (j = 0; j < ARRAY_COUNT(sAzActorMenuElements); j++) {
        GfxPrint_SetPos(printer, x, y+j);

        for (i = 0; i < AZ_MENU_COLUMN_MAX && sAzActorMenuElements[j][i].label != NULL; i++) {
            az_MenuElement2* entry = &sAzActorMenuElements[j][i];

            if (j == sAzActorMenuState.ySelection && i == sAzActorMenuState.xSelection) {
                GfxPrint_SetColor(printer, 255, 20, 20, 255);

                if (sAzActorMenuState.inSelection) {
                    u32 value = 0;
                    u32 exp = 0;
                    u32 digit;
                    s32 k;

                    switch (entry->type) {
                        case AZ_MENUELE_LABEL:
                        case AZ_MENUELE_BUTTON:
                            break;

                        case AZ_MENUELE_INPUT_U8:
                            value = *(u8*)entry->data;
                            exp = 0x10;
                            k = 1;
                            break;

                        case AZ_MENUELE_INPUT_U16:
                            value = *(u16*)entry->data;
                            exp = 0x1000;
                            k = 3;
                            break;

                        case AZ_MENUELE_INPUT_U32:
                            value = *(u32*)entry->data;
                            exp = 0x10000000;
                            k = 7;
                            break;

                        case AZ_MENUELE_INPUT_LIST:
                            break;
                    }
                    while (k >= 0) {
                        if (k == sAzActorMenuState.subSelectionIndex) {
                            GfxPrint_SetColor(printer, 20, 20, 255, 255);
                        } else {
                            GfxPrint_SetColor(printer, 200, 200, 55, 255);
                        }
                        digit = value / exp;
                        GfxPrint_Printf(printer, "%X", digit);
                        value -= digit * exp;
                        exp /= 0x10;
                        k--;
                    }

                    GfxPrint_Printf(printer, " ");
                    continue;
                }
            } else {
                GfxPrint_SetColor(printer, 200, 200, 55, 255);
            }

            switch (entry->type) {
                case AZ_MENUELE_LABEL:
                case AZ_MENUELE_BUTTON:
                    GfxPrint_Printf(printer, "%s ", entry->label);
                    break;

                case AZ_MENUELE_INPUT_U8:
                    GfxPrint_Printf(printer, "%02X ", *(u8*)entry->data);
                    break;

                case AZ_MENUELE_INPUT_U16:
                    GfxPrint_Printf(printer, "%04X ", *(u16*)entry->data);
                    break;

                case AZ_MENUELE_INPUT_U32:
                    GfxPrint_Printf(printer, "%08X ", *(u32*)entry->data);
                    break;

                case AZ_MENUELE_INPUT_LIST:
                    break;
            }
        }
    }
}

void az_ActorMenu_Draw(GameState *gameState) {
    OPEN_DISPS(gameState->gfxCtx);
    func_8012C4C0(gameState->gfxCtx);

    AZ_OPEN_PRINTER_OVERLAY();

    az_ActorMenu_PrintElements(gameState, &AZ_PRINTER);

    AZ_CLOSE_PRINTER_OVERLAY();

    CLOSE_DISPS(gameState->gfxCtx);
}
