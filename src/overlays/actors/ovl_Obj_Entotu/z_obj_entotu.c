#include "z_obj_entotu.h"

#define FLAGS 0x00000030

#define THIS ((ObjEntotu*)thisx)

void ObjEntotu_Init(Actor* thisx, GameState* game);
void ObjEntotu_Destroy(Actor* thisx, GameState* game);
void ObjEntotu_Update(Actor* thisx, GameState* game);
void ObjEntotu_Draw(Actor* thisx, GameState* game);

#if 0
const ActorInit Obj_Entotu_InitVars = {
    ACTOR_OBJ_ENTOTU,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_F53_OBJ,
    sizeof(ObjEntotu),
    (ActorFunc)ObjEntotu_Init,
    (ActorFunc)ObjEntotu_Destroy,
    (ActorFunc)ObjEntotu_Update,
    (ActorFunc)ObjEntotu_Draw,
};

#endif

extern UNK_TYPE D_06000158;
extern UNK_TYPE D_06001C00;

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Entotu/func_80A34700.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Entotu/func_80A349C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Entotu/func_80A34A44.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Entotu/func_80A34B28.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Entotu/ObjEntotu_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Entotu/ObjEntotu_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Entotu/ObjEntotu_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Entotu/ObjEntotu_Draw.s")
