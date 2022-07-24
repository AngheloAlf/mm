#ifndef AZ_STATE_H
#define AZ_STATE_H

#include "ultra64.h"
#include "az/az_menu.h"

typedef struct azState {
    u8 initialized;
    u8 isMenuActive;
    az_MenuType menuType;
} azState;

extern azState gAzState;

#endif
