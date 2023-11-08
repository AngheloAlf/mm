/*
 * File: z_en_an.c
 * Overlay: ovl_En_An
 * Description: Anju
 */

#include "z_en_an.h"

#define FLAGS (ACTOR_FLAG_TARGETABLE | ACTOR_FLAG_FRIENDLY | ACTOR_FLAG_10 | ACTOR_FLAG_20)

#define THIS ((EnAn*)thisx)

void EnAn_Init(Actor* thisx, PlayState* play);
void EnAn_Destroy(Actor* thisx, PlayState* play);
void EnAn_Update(Actor* thisx, PlayState* play);

void func_80B577F0(EnAn* this, PlayState* play);
void func_80B578F8(EnAn* this, PlayState* play);
void func_80B57A44(EnAn* this, PlayState* play);

#if 0
ActorInit En_An_InitVars = {
    /**/ ACTOR_EN_AN,
    /**/ ACTORCAT_NPC,
    /**/ FLAGS,
    /**/ OBJECT_AN1,
    /**/ sizeof(EnAn),
    /**/ EnAn_Init,
    /**/ EnAn_Destroy,
    /**/ EnAn_Update,
    /**/ NULL,
};

// static ColliderCylinderInit sCylinderInit = {
static ColliderCylinderInit D_80B58BBC = {
    { COLTYPE_HIT1, AT_NONE, AC_NONE, OC1_ON | OC1_TYPE_ALL, OC2_TYPE_1, COLSHAPE_CYLINDER, },
    { ELEMTYPE_UNK1, { 0x00000000, 0x00, 0x00 }, { 0x00000000, 0x00, 0x00 }, TOUCH_NONE | TOUCH_SFX_NORMAL, BUMP_NONE, OCELEM_ON, },
    { 14, 62, 0, { 0, 0, 0 } },
};

// sColChkInfoInit
static CollisionCheckInfoInit2 D_80B58BE8 = { 0, 0, 0, 0, MASS_IMMOVABLE };

#endif

extern ColliderCylinderInit D_80B58BBC;
extern CollisionCheckInfoInit2 D_80B58BE8;

extern UNK_TYPE D_060111E8;
extern UNK_TYPE D_06012618;

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B53840.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B53840);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B539CC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B539CC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B53A7C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B53A7C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B53B3C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B53B3C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B53BA8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B53BA8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B53CE8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B53CE8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B53ED4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B53ED4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B53F84.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B53F84);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B54124.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B54124);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B54678.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B54678);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B546F4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B546F4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B54750.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B54750);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B547C8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B547C8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B5492C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B5492C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B54A94.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B54A94);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B54BC4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B54BC4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B54C5C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B54C5C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B54D18.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B54D18);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B54DF4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B54DF4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B55180.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B55180);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B552E4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B552E4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B553AC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B553AC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B554E8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B554E8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B555C8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B555C8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B556F8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B556F8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B557AC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B557AC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B55860.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B55860);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B55914.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B55914);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B55D20.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B55D20);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B55D98.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B55D98);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B55ECC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B55ECC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B55F8C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B55F8C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B5600C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B5600C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B56094.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B56094);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B5611C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B5611C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B561A4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B561A4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B56418.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B56418);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B56744.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B56744);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B56880.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B56880);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B56B00.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B56B00);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B56BC0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B56BC0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B56CAC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B56CAC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B56D28.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B56D28);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B56E44.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B56E44);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B56EB4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B56EB4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B5702C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B5702C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B572D4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B572D4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B573F4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B573F4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B575BC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B575BC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B57674.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B57674);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B57718.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B57718);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B577F0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B577F0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B578F8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B578F8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B57A44.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B57A44);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B57B48.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B57B48);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/EnAn_Init.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", EnAn_Init);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/EnAn_Destroy.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", EnAn_Destroy);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/EnAn_Update.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", EnAn_Update);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B57EE8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B57EE8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B57FC4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B57FC4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_An/func_80B580C0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_An", func_80B580C0);
