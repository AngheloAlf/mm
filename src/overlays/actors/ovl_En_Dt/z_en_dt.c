/*
 * File: z_en_dt.c
 * Overlay: ovl_En_Dt
 * Description: Mayor Dotour
 */

#include "z_en_dt.h"

#define FLAGS (ACTOR_FLAG_TARGETABLE | ACTOR_FLAG_FRIENDLY)

#define THIS ((EnDt*)thisx)

void EnDt_Init(Actor* thisx, PlayState* play);
void EnDt_Destroy(Actor* thisx, PlayState* play);
void EnDt_Update(Actor* thisx, PlayState* play);
void EnDt_Draw(Actor* thisx, PlayState* play);

#if 0
ActorInit En_Dt_InitVars = {
    /**/ ACTOR_EN_DT,
    /**/ ACTORCAT_NPC,
    /**/ FLAGS,
    /**/ OBJECT_DT,
    /**/ sizeof(EnDt),
    /**/ EnDt_Init,
    /**/ EnDt_Destroy,
    /**/ EnDt_Update,
    /**/ EnDt_Draw,
};

// static ColliderCylinderInit sCylinderInit = {
static ColliderCylinderInit D_80BEB29C = {
    { COLTYPE_NONE, AT_NONE, AC_NONE, OC1_ON | OC1_TYPE_ALL, OC2_TYPE_2, COLSHAPE_CYLINDER, },
    { ELEMTYPE_UNK0, { 0x00000000, 0x00, 0x00 }, { 0xF7CFFFFF, 0x00, 0x00 }, TOUCH_NONE | TOUCH_SFX_NORMAL, BUMP_NONE, OCELEM_ON, },
    { 25, 70, 0, { 0, 0, 0 } },
};

#endif

extern ColliderCylinderInit D_80BEB29C;

extern UNK_TYPE D_0600112C;

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/EnDt_Init.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", EnDt_Init);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/EnDt_Destroy.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", EnDt_Destroy);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/func_80BE9C74.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", func_80BE9C74);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/func_80BE9CE8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", func_80BE9CE8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/func_80BE9D9C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", func_80BE9D9C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/func_80BE9DF8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", func_80BE9DF8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/func_80BE9E94.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", func_80BE9E94);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/func_80BE9EF8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", func_80BE9EF8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/func_80BEA088.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", func_80BEA088);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/func_80BEA254.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", func_80BEA254);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/func_80BEA394.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", func_80BEA394);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/func_80BEA8F0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", func_80BEA8F0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/func_80BEAAF8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", func_80BEAAF8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/func_80BEAB44.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", func_80BEAB44);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/func_80BEABF8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", func_80BEABF8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/func_80BEAC84.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", func_80BEAC84);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/func_80BEAD2C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", func_80BEAD2C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/func_80BEADB8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", func_80BEADB8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/func_80BEADD4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", func_80BEADD4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/EnDt_Update.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", EnDt_Update);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/func_80BEB06C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", func_80BEB06C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Dt/EnDt_Draw.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Dt", EnDt_Draw);
