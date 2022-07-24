#ifndef AZ_MENU_H
#define AZ_MENU_H

typedef enum az_MenuType {
    AZ_MENU_TYPE_MAIN,
    AZ_MENU_TYPE_MAX
} az_MenuType;

struct GameState;

typedef void (*az_MenuFunc)(struct GameState *gameState);

typedef struct az_MenuOverlay {
    az_MenuFunc init;
    az_MenuFunc destroy;
    az_MenuFunc update;
    az_MenuFunc draw;
} az_MenuOverlay;

extern az_MenuOverlay gAzMenusOverlayTable[];

#define AZ_DECLARE_MENU_FUNCS(name) \
    void az_ ## name ## _Init(struct GameState *gameState); \
    void az_ ## name ## _Destroy(struct GameState *gameState); \
    void az_ ## name ## _Update(struct GameState *gameState); \
    void az_ ## name ## _Draw(struct GameState *gameState);

AZ_DECLARE_MENU_FUNCS(MainMenu)


void az_Menus_Handle(struct GameState* gameState);
void az_Menus_Nop(GameState* gameState);

#endif
