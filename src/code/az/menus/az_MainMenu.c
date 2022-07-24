#include "global.h"

#include "az/az.h"
#include "az/az_state.h"
#include "az/az_menu.h"
#include "az/az_printer.h"


typedef struct az_MenuState {
    s32 selectedElement;
} az_MenuState;

typedef struct {
    const char *label;
    s32 xOffset;
    s32 yOffset;
    az_MenuFunc callback;
} az_MenuElement;

az_MenuState sAzMainMenuState;


void az_MainMenu_CallbackReturn(GameState *gameState) {
    gAzState.isMenuActive = false;
}

az_MenuElement sAzMainMenuElements[] = {
    { "return", 0, 0, az_MainMenu_CallbackReturn },
    { "actors", 0, 1, az_Menus_Nop },
};

void az_MainMenu_Init(GameState *gameState) {

}

void az_MainMenu_Destroy(GameState *gameState) {

}

void az_MainMenu_Update(GameState *gameState) {
    Input* controller1 = CONTROLLER1(gameState);

    if (CHECK_BTN_ALL(controller1->press.button, BTN_DUP)) {
        sAzMainMenuState.selectedElement--;
        if (sAzMainMenuState.selectedElement < 0) {
            sAzMainMenuState.selectedElement = ARRAY_COUNT(sAzMainMenuElements) -1;
        }
    } else if (CHECK_BTN_ALL(controller1->press.button, BTN_DDOWN)) {
        sAzMainMenuState.selectedElement++;
        sAzMainMenuState.selectedElement %= ARRAY_COUNT(sAzMainMenuElements);
    }

    if (CHECK_BTN_ALL(controller1->press.button, BTN_L)) {
        az_MenuElement* entry = &sAzMainMenuElements[sAzMainMenuState.selectedElement];

        if (entry->callback != NULL){
            entry->callback(gameState);
        }
    }
}

void az_MainMenu_PrintElements(GameState *gameState, GfxPrint *printer) {
    s32 x = 3;
    s32 y = 3;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(sAzMainMenuElements); i++) {
        az_MenuElement* entry = &sAzMainMenuElements[i];

        GfxPrint_SetPos(printer, x + entry->xOffset, y + entry->yOffset);

        if (i == sAzMainMenuState.selectedElement) {
            GfxPrint_SetColor(printer, 255, 20, 20, 255);
        } else {
            GfxPrint_SetColor(printer, 200, 200, 55, 255);
        }

        GfxPrint_Printf(printer, entry->label);
    }
}

void az_MainMenu_Draw(GameState *gameState) {
    OPEN_DISPS(gameState->gfxCtx);
    func_8012C4C0(gameState->gfxCtx);

    AZ_OPEN_PRINTER_OVERLAY();

    az_MainMenu_PrintElements(gameState, &AZ_PRINTER);

    AZ_CLOSE_PRINTER_OVERLAY();

    CLOSE_DISPS(gameState->gfxCtx);
}
