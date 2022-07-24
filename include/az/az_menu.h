#ifndef AZ_MENU_H
#define AZ_MENU_H

typedef enum az_MenuType {
    AZ_MENU_TYPE_MAIN,
    AZ_MENU_TYPE_ACTOR,
    AZ_MENU_TYPE_MAX
} az_MenuType;

struct GameState;

typedef void (*az_MenuFunc)(struct GameState *gameState);
typedef void (*az_MenuElementFunc)(struct GameState *gameState, void* param, void** data);

typedef struct az_MenuState {
    s32 selectedElement;
} az_MenuState;

typedef struct {
    const char *label;
    s32 xOffset;
    s32 yOffset;
    az_MenuFunc callback;
} az_MenuElement;

typedef struct az_MenuOverlay {
    az_MenuFunc update;
    az_MenuFunc draw;
} az_MenuOverlay;

extern az_MenuOverlay gAzMenusOverlayTable[];

#define AZ_DECLARE_MENU_FUNCS(name) \
    void az_ ## name ## _Update(struct GameState *gameState); \
    void az_ ## name ## _Draw(struct GameState *gameState);

AZ_DECLARE_MENU_FUNCS(MainMenu)
AZ_DECLARE_MENU_FUNCS(ActorMenu)


void az_Menus_Handle(struct GameState* gameState);
void az_Menus_Nop(GameState* gameState);

#endif
