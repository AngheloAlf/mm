/*
 * File: z_en_zl4.c
 * Overlay: ovl_En_Zl4
 * Description: Glitched early version of Skull Kid stuck in a T-pose
 */

#include "z_en_zl4.h"

#define FLAGS (ACTOR_FLAG_10 | ACTOR_FLAG_20)

#define THIS ((EnZl4*)thisx)

void EnZl4_Init(Actor* thisx, PlayState* play);
void EnZl4_Destroy(Actor* thisx, PlayState* play);
void EnZl4_Update(Actor* thisx, PlayState* play);
void EnZl4_Draw(Actor* thisx, PlayState* play);

void func_809A1D0C(EnZl4* this, PlayState* play);

#if 0
ActorInit En_Zl4_InitVars = {
    /**/ ACTOR_EN_ZL4,
    /**/ ACTORCAT_ITEMACTION,
    /**/ FLAGS,
    /**/ OBJECT_STK,
    /**/ sizeof(EnZl4),
    /**/ EnZl4_Init,
    /**/ EnZl4_Destroy,
    /**/ EnZl4_Update,
    /**/ EnZl4_Draw,
};

#endif

extern UNK_TYPE D_06013328;

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zl4/func_809A1BB0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Zl4", func_809A1BB0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zl4/EnZl4_Init.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Zl4", EnZl4_Init);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zl4/EnZl4_Destroy.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Zl4", EnZl4_Destroy);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zl4/func_809A1D0C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Zl4", func_809A1D0C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zl4/EnZl4_Update.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Zl4", EnZl4_Update);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zl4/func_809A1D60.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Zl4", func_809A1D60);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zl4/func_809A1DA4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Zl4", func_809A1DA4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zl4/func_809A1DBC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Zl4", func_809A1DBC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zl4/func_809A1DD0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Zl4", func_809A1DD0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zl4/func_809A1E28.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Zl4", func_809A1E28);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Zl4/EnZl4_Draw.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Zl4", EnZl4_Draw);
