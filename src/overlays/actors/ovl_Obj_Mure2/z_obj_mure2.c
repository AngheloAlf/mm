/*
 * File: z_obj_mure2.c
 * Overlay: ovl_Obj_Mure2
 * Description: Circle of rocks spawner
 */

#include "z_obj_mure2.h"

#define FLAGS 0x00000000

#define THIS ((ObjMure2*)thisx)

void ObjMure2_Init(Actor* thisx, PlayState* play);
void ObjMure2_Update(Actor* thisx, PlayState* play);

void func_809613C4(ObjMure2* this, PlayState* play);
void func_809613FC(ObjMure2* this, PlayState* play);
void func_80961490(ObjMure2* this, PlayState* play);

#if 0
ActorInit Obj_Mure2_InitVars = {
    /**/ ACTOR_OBJ_MURE2,
    /**/ ACTORCAT_PROP,
    /**/ FLAGS,
    /**/ GAMEPLAY_KEEP,
    /**/ sizeof(ObjMure2),
    /**/ ObjMure2_Init,
    /**/ Actor_Noop,
    /**/ ObjMure2_Update,
    /**/ NULL,
};

// static InitChainEntry sInitChain[] = {
static InitChainEntry D_809615F4[] = {
    ICHAIN_F32(uncullZoneForward, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 2100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 100, ICHAIN_STOP),
};

#endif

extern InitChainEntry D_809615F4[];

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_80960CF0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2", func_80960CF0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_80960E0C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2", func_80960E0C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_80960F0C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2", func_80960F0C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_80961018.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2", func_80961018);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_8096104C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2", func_8096104C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_809611BC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2", func_809611BC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_809612BC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2", func_809612BC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/ObjMure2_Init.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2", ObjMure2_Init);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_809613B0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2", func_809613B0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_809613C4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2", func_809613C4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_809613E8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2", func_809613E8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_809613FC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2", func_809613FC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_8096147C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2", func_8096147C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_80961490.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2", func_80961490);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/ObjMure2_Update.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2", ObjMure2_Update);
