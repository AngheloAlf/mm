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
    s32 ySelection;
    s32 xSelection;
    s32 inSelection;
    s32 subSelectionIndex;
} az_MenuState;

typedef enum az_MenuElementType {
    AZ_MENUELE_NONE = 0,
    AZ_MENUELE_LABEL,
    AZ_MENUELE_BUTTON,
    AZ_MENUELE_INPUT_U8,
    AZ_MENUELE_INPUT_U16,
    AZ_MENUELE_INPUT_U32,
    AZ_MENUELE_INPUT_LIST
} az_MenuElementType;

typedef struct az_MenuElement {
    az_MenuElementType type;
    const char *label;
    az_MenuElementFunc callback;
    void* param;
    void* data;
} az_MenuElement;

#define AZ_MENU_COLUMN_MAX 10


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
void az_Menus_Nop(GameState* gameState, void* param, void** data);

void az_Menus_CommonUpdate(GameState* gameState, az_MenuState* menuState, size_t menuElementsCount, az_MenuElement menuElements[][AZ_MENU_COLUMN_MAX]);
void az_Menus_PrintElement(GameState* gameState, az_MenuState* menuState, az_MenuElement* entry, GfxPrint *printer, s32 i, s32 j);
void az_Menus_PrintAllElements(GameState* gameState, az_MenuState* menuState, size_t menuElementsCount, az_MenuElement menuElements[][AZ_MENU_COLUMN_MAX], GfxPrint *printer, s32 x, s32 y);

#endif
