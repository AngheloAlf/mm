#include "global.h"

#include "az/az.h"
#include "az/az_state.h"

azState gAzState;

void az_InitState(void) {
    gAzState.initialized = true;

    gAzState.isMenuActive = false;
    gAzState.menuType = AZ_MENU_TYPE_MAIN;
}

void az_Main(GameState* gameState) {
    if (!gAzState.initialized) {
        az_InitState();
    }

    az_Menus_Handle(gameState);
}
