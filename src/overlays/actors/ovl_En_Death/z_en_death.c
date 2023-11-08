/*
 * File: z_en_death.c
 * Overlay: ovl_En_Death
 * Description: Gomess
 */

#include "z_en_death.h"
#include "z64rumble.h"

#define FLAGS (ACTOR_FLAG_TARGETABLE | ACTOR_FLAG_UNFRIENDLY | ACTOR_FLAG_10 | ACTOR_FLAG_20 | ACTOR_FLAG_IGNORE_QUAKE)

#define THIS ((EnDeath*)thisx)

void EnDeath_Init(Actor* thisx, PlayState* play);
void EnDeath_Destroy(Actor* thisx, PlayState* play);
void EnDeath_Update(Actor* thisx, PlayState* play);
void EnDeath_Draw(Actor* thisx, PlayState* play);

void func_808C589C(EnDeath* this, PlayState* play);
void func_808C5AB8(EnDeath* this, PlayState* play);
void func_808C5CB4(EnDeath* this, PlayState* play);
void func_808C5E90(EnDeath* this, PlayState* play);
void func_808C6070(EnDeath* this, PlayState* play);
void func_808C64DC(EnDeath* this, PlayState* play);
void func_808C66A8(EnDeath* this, PlayState* play);
void func_808C682C(EnDeath* this, PlayState* play);
void func_808C692C(EnDeath* this, PlayState* play);
void func_808C6AB0(EnDeath* this, PlayState* play);
void func_808C6CDC(EnDeath* this, PlayState* play);
void func_808C6F6C(EnDeath* this, PlayState* play);
void func_808C72AC(EnDeath* this, PlayState* play);
void func_808C74F8(EnDeath* this, PlayState* play);
void func_808C7888(EnDeath* this, PlayState* play);
void func_808C7AAC(EnDeath* this, PlayState* play);
void func_808C7B88(EnDeath* this, PlayState* play);
void func_808C7C88(EnDeath* this, PlayState* play);
void func_808C7D34(EnDeath* this, PlayState* play);
void func_808C7DCC(EnDeath* this, PlayState* play);

#if 0
ActorInit En_Death_InitVars = {
    /**/ ACTOR_EN_DEATH,
    /**/ ACTORCAT_ENEMY,
    /**/ FLAGS,
    /**/ OBJECT_DEATH,
    /**/ sizeof(EnDeath),
    /**/ EnDeath_Init,
    /**/ EnDeath_Destroy,
    /**/ EnDeath_Update,
    /**/ EnDeath_Draw,
};

// static ColliderSphereInit sSphereInit = {
static ColliderSphereInit D_808C98E0 = {
    { COLTYPE_HIT3, AT_NONE, AC_NONE | AC_TYPE_PLAYER, OC1_NONE, OC2_TYPE_1, COLSHAPE_SPHERE, },
    { ELEMTYPE_UNK0, { 0xF7CFFFFF, 0x00, 0x00 }, { 0xF7CFFFFF, 0x00, 0x00 }, TOUCH_NONE | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_NONE, },
    { 1, { { 0, 0, 0 }, 22 }, 100 },
};

// static ColliderCylinderInit sCylinderInit = {
static ColliderCylinderInit D_808C990C = {
    { COLTYPE_NONE, AT_NONE, AC_NONE, OC1_ON | OC1_TYPE_ALL, OC2_TYPE_1, COLSHAPE_CYLINDER, },
    { ELEMTYPE_UNK0, { 0x00000000, 0x00, 0x00 }, { 0x00000000, 0x00, 0x00 }, TOUCH_NONE | TOUCH_SFX_NORMAL, BUMP_NONE, OCELEM_ON, },
    { 35, 90, 20, { 0, 0, 0 } },
};

// static ColliderTrisElementInit sTrisElementsInit[2] = {
static ColliderTrisElementInit D_808C9938[2] = {
    {
        { ELEMTYPE_UNK2, { 0xF7CFFFFF, 0x04, 0x20 }, { 0xF7CFFFFF, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_NONE, },
        { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
    },
    {
        { ELEMTYPE_UNK2, { 0xF7CFFFFF, 0x04, 0x20 }, { 0xF7CFFFFF, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_NONE, },
        { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
    },
};

// static ColliderTrisInit sTrisInit = {
static ColliderTrisInit D_808C99B0 = {
    { COLTYPE_METAL, AT_ON | AT_TYPE_ENEMY, AC_ON | AC_HARD | AC_TYPE_PLAYER, OC1_NONE, OC2_TYPE_1, COLSHAPE_TRIS, },
    ARRAY_COUNT(sTrisElementsInit), D_808C9938, // sTrisElementsInit,
};

// static ColliderQuadInit sQuadInit = {
static ColliderQuadInit D_808C99C0 = {
    { COLTYPE_NONE, AT_NONE | AT_TYPE_ENEMY, AC_NONE, OC1_NONE, OC2_TYPE_2, COLSHAPE_QUAD, },
    { ELEMTYPE_UNK0, { 0xF7CFFFFF, 0x04, 0x20 }, { 0x00000000, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL | TOUCH_UNK7, BUMP_NONE, OCELEM_NONE, },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

// static DamageTable sDamageTable = {
static DamageTable D_808C9A10 = {
    /* Deku Nut       */ DMG_ENTRY(0, 0x0),
    /* Deku Stick     */ DMG_ENTRY(1, 0x0),
    /* Horse trample  */ DMG_ENTRY(0, 0x0),
    /* Explosives     */ DMG_ENTRY(1, 0xF),
    /* Zora boomerang */ DMG_ENTRY(1, 0x0),
    /* Normal arrow   */ DMG_ENTRY(1, 0x0),
    /* UNK_DMG_0x06   */ DMG_ENTRY(0, 0x0),
    /* Hookshot       */ DMG_ENTRY(1, 0x0),
    /* Goron punch    */ DMG_ENTRY(1, 0x0),
    /* Sword          */ DMG_ENTRY(1, 0x0),
    /* Goron pound    */ DMG_ENTRY(0, 0x0),
    /* Fire arrow     */ DMG_ENTRY(1, 0x2),
    /* Ice arrow      */ DMG_ENTRY(1, 0x3),
    /* Light arrow    */ DMG_ENTRY(2, 0x4),
    /* Goron spikes   */ DMG_ENTRY(1, 0x0),
    /* Deku spin      */ DMG_ENTRY(0, 0x0),
    /* Deku bubble    */ DMG_ENTRY(1, 0x0),
    /* Deku launch    */ DMG_ENTRY(2, 0x0),
    /* UNK_DMG_0x12   */ DMG_ENTRY(0, 0x0),
    /* Zora barrier   */ DMG_ENTRY(0, 0x0),
    /* Normal shield  */ DMG_ENTRY(0, 0x0),
    /* Light ray      */ DMG_ENTRY(0, 0x0),
    /* Thrown object  */ DMG_ENTRY(1, 0x0),
    /* Zora punch     */ DMG_ENTRY(1, 0x0),
    /* Spin attack    */ DMG_ENTRY(1, 0x0),
    /* Sword beam     */ DMG_ENTRY(0, 0x0),
    /* Normal Roll    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1B   */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1C   */ DMG_ENTRY(0, 0x0),
    /* Unblockable    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1E   */ DMG_ENTRY(0, 0x0),
    /* Powder Keg     */ DMG_ENTRY(1, 0xF),
};

// sColChkInfoInit
static CollisionCheckInfoInit2 D_808C9A30 = { 20, 28, 90, 20, 100 };

// static InitChainEntry sInitChain[] = {
static InitChainEntry D_808C9A60[] = {
    ICHAIN_VEC3F(scale, 0, ICHAIN_CONTINUE),
    ICHAIN_S8(hintId, TATL_HINT_ID_GOMESS, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 6000, ICHAIN_CONTINUE),
    ICHAIN_U8(targetMode, TARGET_MODE_5, ICHAIN_STOP),
};

#endif

extern ColliderSphereInit D_808C98E0;
extern ColliderCylinderInit D_808C990C;
extern ColliderTrisElementInit D_808C9938[2];
extern ColliderTrisInit D_808C99B0;
extern ColliderQuadInit D_808C99C0;
extern DamageTable D_808C9A10;
extern CollisionCheckInfoInit2 D_808C9A30;
extern InitChainEntry D_808C9A60[];

extern UNK_TYPE D_06000E64;
extern UNK_TYPE D_060015B4;
extern UNK_TYPE D_06001834;
extern UNK_TYPE D_06001F80;
extern UNK_TYPE D_06002DE8;
extern UNK_TYPE D_0600352C;
extern UNK_TYPE D_06003CAC;
extern UNK_TYPE D_06006F88;
extern UNK_TYPE D_060073D0;
extern UNK_TYPE D_06009988;
extern UNK_TYPE D_06009F10;
extern UNK_TYPE D_0600B284;
extern UNK_TYPE D_0600B508;
extern UNK_TYPE D_0600CB2C;

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/EnDeath_Init.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", EnDeath_Init);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/EnDeath_Destroy.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", EnDeath_Destroy);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C5310.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C5310);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C5394.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C5394);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C5428.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C5428);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C54F0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C54F0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C566C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C566C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C571C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C571C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C589C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C589C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C597C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C597C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C5AB8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C5AB8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C5C0C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C5C0C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C5CB4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C5CB4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C5D6C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C5D6C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C5E90.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C5E90);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C5F58.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C5F58);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C6070.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C6070);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C645C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C645C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C64DC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C64DC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C6620.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C6620);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C66A8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C66A8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C67C8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C67C8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C682C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C682C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C68B8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C68B8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C692C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C692C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C6A08.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C6A08);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C6AB0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C6AB0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C6C5C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C6C5C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C6CDC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C6CDC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C6D40.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C6D40);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C6F6C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C6F6C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C70D8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C70D8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C72AC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C72AC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C74A4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C74A4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C74F8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C74F8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C7800.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C7800);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C7888.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C7888);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C7A30.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C7A30);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C7AAC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C7AAC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C7AEC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C7AEC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C7B88.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C7B88);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C7C04.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C7C04);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C7C88.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C7C88);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C7CFC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C7CFC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C7D34.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C7D34);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C7DB8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C7DB8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C7DCC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C7DCC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C7E24.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C7E24);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C7EDC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C7EDC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/EnDeath_Update.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", EnDeath_Update);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C84A4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C84A4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C8690.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C8690);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C882C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C882C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C8D18.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C8D18);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C9160.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C9160);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C9220.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C9220);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/func_808C9340.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", func_808C9340);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Death/EnDeath_Draw.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Death", EnDeath_Draw);
