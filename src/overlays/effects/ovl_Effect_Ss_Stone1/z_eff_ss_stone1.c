/*
 * File: z_eff_ss_stone1.c
 * Overlay: ovl_Effect_Ss_Stone1
 * Description:
 */

#include "z_eff_ss_stone1.h"

#define PARAMS ((EffectSsStone1InitParams*)initParamsx)

s32 EffectSsStone1_Init(GameState* game, u32 index, EffectSs* this, void* initParamsx);
void EffectSsStone1_Update(GameState* game, u32 index, EffectSs* this);
void EffectSsStone1_Draw(GameState* game, u32 index, EffectSs* this);

#if 0
const EffectSsInit Effect_Ss_Stone1_InitVars = {
    EFFECT_SS_STONE1,
    EffectSsStone1_Init,
};

#endif

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Effect_Ss_Stone1/EffectSsStone1_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Effect_Ss_Stone1/EffectSsStone1_Draw.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Effect_Ss_Stone1/EffectSsStone1_Update.s")
