/*
 * File: z_en_bsb.c
 * Overlay: ovl_En_Bsb
 * Description: Captain Keeta
 */

#include "z_en_bsb.h"
#include "z64rumble.h"
#include "z64shrink_window.h"

#define FLAGS (ACTOR_FLAG_TARGETABLE | ACTOR_FLAG_UNFRIENDLY | ACTOR_FLAG_10 | ACTOR_FLAG_20 | ACTOR_FLAG_2000000)

#define THIS ((EnBsb*)thisx)

void EnBsb_Init(Actor* thisx, PlayState* play);
void EnBsb_Destroy(Actor* thisx, PlayState* play);
void EnBsb_Update(Actor* thisx, PlayState* play);
void EnBsb_Draw(Actor* thisx, PlayState* play);

void func_80C0BFE8(EnBsb* this, PlayState* play);
void func_80C0C238(EnBsb* this, PlayState* play);
void func_80C0C364(EnBsb* this, PlayState* play);
void func_80C0C484(EnBsb* this, PlayState* play);
void func_80C0C6A8(EnBsb* this, PlayState* play);
void func_80C0C8EC(EnBsb* this, PlayState* play);
void func_80C0CB3C(EnBsb* this, PlayState* play);
void func_80C0CD04(EnBsb* this, PlayState* play);
void func_80C0CDE4(EnBsb* this, PlayState* play);
void func_80C0CFDC(EnBsb* this, PlayState* play);
void func_80C0D10C(EnBsb* this, PlayState* play);
void func_80C0D27C(EnBsb* this, PlayState* play);
void func_80C0D384(EnBsb* this, PlayState* play);
void func_80C0D51C(EnBsb* this, PlayState* play);
void func_80C0D9B4(EnBsb* this, PlayState* play);
void func_80C0DB18(EnBsb* this, PlayState* play);
void func_80C0E1C0(EnBsb* this, PlayState* play);
void func_80C0E480(EnBsb* this, PlayState* play);
void func_80C0E4FC(EnBsb* this, PlayState* play);

#if 0
// static ColliderJntSphElementInit sJntSphElementsInit[7] = {
static ColliderJntSphElementInit D_80C0F8D4[7] = {
    {
        { ELEMTYPE_UNK0, { 0x00000000, 0x00, 0x00 }, { 0xF7CFFFFF, 0x00, 0x00 }, TOUCH_NONE | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 10, { { 1000, 400, 0 }, 40 }, 100 },
    },
    {
        { ELEMTYPE_UNK0, { 0xF7CFFFFF, 0x04, 0x08 }, { 0x00000000, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 9, { { 0, 700, 200 }, 35 }, 100 },
    },
    {
        { ELEMTYPE_UNK0, { 0x00000000, 0x00, 0x00 }, { 0xF7CFFFFF, 0x00, 0x00 }, TOUCH_NONE | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 6, { { 100, 600, 0 }, 35 }, 100 },
    },
    {
        { ELEMTYPE_UNK0, { 0x00000000, 0x00, 0x00 }, { 0xF7CFFFFF, 0x00, 0x00 }, TOUCH_NONE | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_NONE, },
        { 3, { { 400, 200, 0 }, 40 }, 100 },
    },
    {
        { ELEMTYPE_UNK0, { 0x00000000, 0x00, 0x00 }, { 0xF7CFFFFF, 0x00, 0x00 }, TOUCH_NONE | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 13, { { 700, -100, 0 }, 35 }, 100 },
    },
    {
        { ELEMTYPE_UNK0, { 0x00000000, 0x00, 0x00 }, { 0xF7CFFFFF, 0x00, 0x00 }, TOUCH_NONE | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 16, { { 200, 300, 0 }, 30 }, 100 },
    },
    {
        { ELEMTYPE_UNK0, { 0x00000000, 0x00, 0x00 }, { 0xF7CFFFFF, 0x00, 0x00 }, TOUCH_NONE | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 19, { { 200, 300, 0 }, 30 }, 100 },
    },
};

// static ColliderJntSphInit sJntSphInit = {
static ColliderJntSphInit D_80C0F9D0 = {
    { COLTYPE_HIT6, AT_ON | AT_TYPE_ENEMY, AC_ON | AC_TYPE_PLAYER, OC1_ON | OC1_TYPE_PLAYER, OC2_TYPE_1, COLSHAPE_JNTSPH, },
    ARRAY_COUNT(sJntSphElementsInit), D_80C0F8D4, // sJntSphElementsInit,
};

// static DamageTable sDamageTable = {
static DamageTable D_80C0F9E0 = {
    /* Deku Nut       */ DMG_ENTRY(0, 0x1),
    /* Deku Stick     */ DMG_ENTRY(1, 0xD),
    /* Horse trample  */ DMG_ENTRY(0, 0x0),
    /* Explosives     */ DMG_ENTRY(1, 0xE),
    /* Zora boomerang */ DMG_ENTRY(0, 0xF),
    /* Normal arrow   */ DMG_ENTRY(0, 0xF),
    /* UNK_DMG_0x06   */ DMG_ENTRY(0, 0x0),
    /* Hookshot       */ DMG_ENTRY(0, 0xF),
    /* Goron punch    */ DMG_ENTRY(1, 0xD),
    /* Sword          */ DMG_ENTRY(1, 0xD),
    /* Goron pound    */ DMG_ENTRY(1, 0xD),
    /* Fire arrow     */ DMG_ENTRY(0, 0x2),
    /* Ice arrow      */ DMG_ENTRY(0, 0x3),
    /* Light arrow    */ DMG_ENTRY(0, 0x4),
    /* Goron spikes   */ DMG_ENTRY(0, 0xF),
    /* Deku spin      */ DMG_ENTRY(0, 0xC),
    /* Deku bubble    */ DMG_ENTRY(0, 0xF),
    /* Deku launch    */ DMG_ENTRY(1, 0xE),
    /* UNK_DMG_0x12   */ DMG_ENTRY(0, 0x1),
    /* Zora barrier   */ DMG_ENTRY(1, 0x5),
    /* Normal shield  */ DMG_ENTRY(0, 0x0),
    /* Light ray      */ DMG_ENTRY(0, 0x0),
    /* Thrown object  */ DMG_ENTRY(0, 0xF),
    /* Zora punch     */ DMG_ENTRY(1, 0xD),
    /* Spin attack    */ DMG_ENTRY(1, 0xD),
    /* Sword beam     */ DMG_ENTRY(0, 0x0),
    /* Normal Roll    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1B   */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1C   */ DMG_ENTRY(0, 0x0),
    /* Unblockable    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1E   */ DMG_ENTRY(0, 0x0),
    /* Powder Keg     */ DMG_ENTRY(1, 0xD),
};

ActorInit En_Bsb_InitVars = {
    /**/ ACTOR_EN_BSB,
    /**/ ACTORCAT_PROP,
    /**/ FLAGS,
    /**/ OBJECT_BSB,
    /**/ sizeof(EnBsb),
    /**/ EnBsb_Init,
    /**/ EnBsb_Destroy,
    /**/ EnBsb_Update,
    /**/ EnBsb_Draw,
};

#endif

extern ColliderJntSphElementInit D_80C0F8D4[7];
extern ColliderJntSphInit D_80C0F9D0;
extern DamageTable D_80C0F9E0;

extern UNK_TYPE D_06000C50;
extern UNK_TYPE D_06004894;

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0B290.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0B290);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0B31C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0B31C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/EnBsb_Init.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", EnBsb_Init);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/EnBsb_Destroy.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", EnBsb_Destroy);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0B888.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0B888);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0B970.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0B970);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0BA58.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0BA58);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0BC30.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0BC30);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0BE1C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0BE1C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0BF2C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0BF2C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0BFE8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0BFE8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0C0F4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0C0F4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0C238.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0C238);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0C32C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0C32C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0C364.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0C364);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0C430.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0C430);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0C484.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0C484);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0C610.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0C610);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0C6A8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0C6A8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0C86C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0C86C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0C8EC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0C8EC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0CA28.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0CA28);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0CB3C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0CB3C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0CCCC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0CCCC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0CD04.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0CD04);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0CD90.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0CD90);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0CDE4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0CDE4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0CF4C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0CF4C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0CFDC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0CFDC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0D00C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0D00C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0D10C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0D10C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0D214.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0D214);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0D27C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0D27C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0D334.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0D334);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0D384.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0D384);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0D3C0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0D3C0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0D51C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0D51C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0D964.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0D964);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0D9B4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0D9B4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0DA58.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0DA58);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0DB18.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0DB18);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0E178.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0E178);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0E1C0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0E1C0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0E3B8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0E3B8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0E480.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0E480);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0E4FC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0E4FC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0E618.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0E618);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0E9CC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0E9CC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/EnBsb_Update.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", EnBsb_Update);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0EEA0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0EEA0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0F078.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0F078);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0F170.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0F170);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/EnBsb_Draw.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", EnBsb_Draw);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0F544.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0F544);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0F640.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0F640);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Bsb/func_80C0F758.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Bsb", func_80C0F758);
