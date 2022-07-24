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

void az_Menus_Nop(GameState* gameState) {

}
