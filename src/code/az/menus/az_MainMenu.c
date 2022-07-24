#include "global.h"

#include "az/az.h"
#include "az/az_state.h"
#include "az/az_menu.h"
#include "az/az_printer.h"


az_MenuState sAzMainMenuState;


void az_MainMenu_CallbackReturn(GameState *gameState, void* param, void** data) {
    gAzState.isMenuActive = false;
}

void az_MainMenu_CallbackActors(GameState *gameState, void* param, void** data) {
    gAzState.menuType = AZ_MENU_TYPE_ACTOR;
}

az_MenuElement sAzMainMenuElements[][AZ_MENU_COLUMN_MAX] = {
    { { AZ_MENUELE_BUTTON, "return", az_MainMenu_CallbackReturn, NULL, NULL }, },
    { { AZ_MENUELE_BUTTON, "actors", az_MainMenu_CallbackActors, NULL, NULL }, },
};

void az_MainMenu_Update(GameState *gameState) {
    az_Menus_CommonUpdate(gameState, &sAzMainMenuState, ARRAY_COUNT(sAzMainMenuElements), sAzMainMenuElements);
}

void az_MainMenu_PrintElements(GameState *gameState, GfxPrint *printer) {
    s32 x = 3;
    s32 y = 3;

    az_Menus_PrintAllElements(gameState, &sAzMainMenuState, ARRAY_COUNT(sAzMainMenuElements), sAzMainMenuElements, printer, x, y);
}

void az_MainMenu_Draw(GameState *gameState) {
    OPEN_DISPS(gameState->gfxCtx);
    func_8012C4C0(gameState->gfxCtx);

    AZ_OPEN_PRINTER_OVERLAY();

    az_MainMenu_PrintElements(gameState, &AZ_PRINTER);

    AZ_CLOSE_PRINTER_OVERLAY();

    CLOSE_DISPS(gameState->gfxCtx);
}
