#include "global.h"

#include "az/az.h"
#include "az/az_state.h"
#include "az/az_menu.h"


#define AZ_MENU_OVL_ENTRY(name) \
    { \
        az_ ## name ## _Update, az_ ## name ## _Draw \
    }

az_MenuOverlay gAzMenusOverlayTable[] = {
    AZ_MENU_OVL_ENTRY(MainMenu),
    AZ_MENU_OVL_ENTRY(ActorMenu),
};

void az_Menus_Handle(GameState* gameState) {
    Input* controller1 = CONTROLLER1(gameState);
    az_MenuOverlay* tableEntry;

    if (CHECK_BTN_ALL(controller1->press.button, BTN_L | BTN_R)) {
        gAzState.isMenuActive = !gAzState.isMenuActive;

        if (gAzState.isMenuActive) {
            return;
        }
    }

    if (!gAzState.isMenuActive) {
        return;
    }

    tableEntry = &gAzMenusOverlayTable[gAzState.menuType];

    tableEntry->update(gameState);
    tableEntry->draw(gameState);

    controller1->cur.button &= ~(BTN_L | BTN_DUP | BTN_DDOWN | BTN_DLEFT | BTN_DRIGHT);
    controller1->prev.button &= ~(BTN_L | BTN_DUP | BTN_DDOWN | BTN_DLEFT | BTN_DRIGHT);
    controller1->press.button &= ~(BTN_L | BTN_DUP | BTN_DDOWN | BTN_DLEFT | BTN_DRIGHT);
    controller1->rel.button &= ~(BTN_L | BTN_DUP | BTN_DDOWN | BTN_DLEFT | BTN_DRIGHT);
}

void az_Menus_Nop(GameState* gameState, void* param, void** data) {
}

void az_Menus_CommonUpdate(GameState* gameState, az_MenuState* menuState, size_t menuElementsCount, az_MenuElement menuElements[][AZ_MENU_COLUMN_MAX]) {
        Input* controller1 = CONTROLLER1(gameState);

    if (menuState->inSelection) {
        az_MenuElement* entry = &menuElements[menuState->ySelection][menuState->xSelection];
        u32 mask = 0x0000000F << (menuState->subSelectionIndex * 4);
        u32 inc = 0x0001 << (menuState->subSelectionIndex * 4);
        u8* bytePtr;
        u16* halfPtr;
        u32* wordPtr;

        if (CHECK_BTN_ALL(controller1->press.button, BTN_DUP)) {
            switch (entry->type) {
                case AZ_MENUELE_NONE:
                    break;

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
                case AZ_MENUELE_NONE:
                    break;

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
            menuState->subSelectionIndex--;
            if (menuState->subSelectionIndex < 0) {
                switch (entry->type) {
                case AZ_MENUELE_NONE:
                    break;

                    case AZ_MENUELE_LABEL:
                    case AZ_MENUELE_BUTTON:
                        break;

                    case AZ_MENUELE_INPUT_U8:
                        menuState->subSelectionIndex = 1;
                        break;

                    case AZ_MENUELE_INPUT_U16:
                        menuState->subSelectionIndex = 3;
                        break;

                    case AZ_MENUELE_INPUT_U32:
                        menuState->subSelectionIndex = 7;
                        break;

                    case AZ_MENUELE_INPUT_LIST:
                        break;
                }
            }
        } else if (CHECK_BTN_ALL(controller1->press.button, BTN_DLEFT)) {
            menuState->subSelectionIndex++;
            switch (entry->type) {
                case AZ_MENUELE_NONE:
                    break;

                case AZ_MENUELE_LABEL:
                case AZ_MENUELE_BUTTON:
                    break;

                case AZ_MENUELE_INPUT_U8:
                    if (menuState->subSelectionIndex >= 2) {
                        menuState->subSelectionIndex = 0;
                    }
                    break;

                case AZ_MENUELE_INPUT_U16:
                    if (menuState->subSelectionIndex >= 4) {
                        menuState->subSelectionIndex = 0;
                    }
                    break;

                case AZ_MENUELE_INPUT_U32:
                    if (menuState->subSelectionIndex >= 8) {
                        menuState->subSelectionIndex = 0;
                    }
                    break;

                case AZ_MENUELE_INPUT_LIST:
                    break;
            }
        }

        if (CHECK_BTN_ALL(controller1->press.button, BTN_L)) {
            menuState->inSelection = false;
        }

        return;
    }

    if (CHECK_BTN_ALL(controller1->press.button, BTN_DUP)) {
        while (true) {
            menuState->ySelection--;
            if (menuState->ySelection < 0) {
                menuState->ySelection = menuElementsCount - 1;
            }

            if (menuElements[menuState->ySelection][0].type == AZ_MENUELE_NONE) {
                continue;
            }

            while (menuState->xSelection > 0 && menuElements[menuState->ySelection][menuState->xSelection].type == AZ_MENUELE_NONE) {
                menuState->xSelection--;
            }
            break;
        }
    } else if (CHECK_BTN_ALL(controller1->press.button, BTN_DDOWN)) {
        while (true) {
            menuState->ySelection++;
            menuState->ySelection %= menuElementsCount;

            if (menuElements[menuState->ySelection][0].type == AZ_MENUELE_NONE) {
                continue;
            }

            while (menuState->xSelection > 0 && menuElements[menuState->ySelection][menuState->xSelection].type == AZ_MENUELE_NONE) {
                menuState->xSelection--;
            }
            break;
        }
    } else if (CHECK_BTN_ALL(controller1->press.button, BTN_DRIGHT)) {
        menuState->xSelection++;
        if (menuElements[menuState->ySelection][menuState->xSelection].type == AZ_MENUELE_NONE) {
            menuState->xSelection = 0;
        }
    } else if (CHECK_BTN_ALL(controller1->press.button, BTN_DLEFT)) {
        menuState->xSelection--;
        if (menuState->xSelection < 0) {
            menuState->xSelection = AZ_MENU_COLUMN_MAX-1;
            while (menuElements[menuState->ySelection][menuState->xSelection].type == AZ_MENUELE_NONE) {
                menuState->xSelection--;
            }
        }
    }

    if (CHECK_BTN_ALL(controller1->press.button, BTN_L)) {
        az_MenuElement* entry = &menuElements[menuState->ySelection][menuState->xSelection];

        switch (entry->type) {
            case AZ_MENUELE_NONE:
                break;

            case AZ_MENUELE_BUTTON:
                if (entry->callback != NULL){
                    entry->callback(gameState, entry->param, &entry->data);
                }
                break;

            case AZ_MENUELE_INPUT_U8:
            case AZ_MENUELE_INPUT_U16:
            case AZ_MENUELE_INPUT_U32:
            case AZ_MENUELE_INPUT_LIST:
                menuState->inSelection = true;
                menuState->subSelectionIndex = 0;
                break;

            case AZ_MENUELE_LABEL:
                break;
        }
    }

}

void az_Menus_PrintElement(GameState* gameState, az_MenuState* menuState, az_MenuElement* entry, GfxPrint *printer, s32 i, s32 j) {
    if (j == menuState->ySelection && i == menuState->xSelection) {
        GfxPrint_SetColor(printer, 255, 20, 20, 255);

        if (menuState->inSelection) {
            u32 value = 0;
            u32 exp = 0;
            u32 digit;
            s32 k;

            switch (entry->type) {
                case AZ_MENUELE_NONE:
                    break;

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
                if (k == menuState->subSelectionIndex) {
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
            return;
        }
    } else {
        GfxPrint_SetColor(printer, 200, 200, 55, 255);
    }

    switch (entry->type) {
        case AZ_MENUELE_NONE:
            break;

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

void az_Menus_PrintAllElements(GameState* gameState, az_MenuState* menuState, size_t menuElementsCount, az_MenuElement menuElements[][AZ_MENU_COLUMN_MAX], GfxPrint *printer, s32 x, s32 y) {
    size_t i;
    size_t j;

    for (j = 0; j < menuElementsCount; j++) {
        GfxPrint_SetPos(printer, x, y+j);

        for (i = 0; i < AZ_MENU_COLUMN_MAX; i++) {
            az_MenuElement* entry = &menuElements[j][i];

            if (entry->type == AZ_MENUELE_NONE) {
                break;
            }

            az_Menus_PrintElement(gameState, menuState, entry, printer, i, j);
        }
    }
}
