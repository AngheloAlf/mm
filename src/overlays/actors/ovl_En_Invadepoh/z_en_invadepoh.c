#include "z_en_invadepoh.h"

#define FLAGS (ACTOR_FLAG_10)

#define THIS ((EnInvadepoh*)thisx)

void EnInvadepoh_Init(Actor* thisx, PlayState* play);
void EnInvadepoh_Destroy(Actor* thisx, PlayState* play);
void EnInvadepoh_Update(Actor* thisx, PlayState* play);

#if 0
ActorInit En_Invadepoh_InitVars = {
    /**/ ACTOR_EN_INVADEPOH,
    /**/ ACTORCAT_PROP,
    /**/ FLAGS,
    /**/ GAMEPLAY_KEEP,
    /**/ sizeof(EnInvadepoh),
    /**/ EnInvadepoh_Init,
    /**/ EnInvadepoh_Destroy,
    /**/ EnInvadepoh_Update,
    /**/ NULL,
};
#endif

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B439B0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B439B0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B43A24.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B43A24);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B43A74.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B43A74);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B43A9C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B43A9C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B43AB0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B43AB0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B43AF0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B43AF0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B43B80.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B43B80);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B43BC8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B43BC8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B43DD4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B43DD4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B43E6C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B43E6C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B43F0C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B43F0C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B43F70.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B43F70);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44024.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44024);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4407C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4407C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B440B8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B440B8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44234.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44234);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B442E4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B442E4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B443A0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B443A0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B444BC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B444BC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B444F4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B444F4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44514.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44514);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44540.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44540);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44570.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44570);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44620.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44620);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44640.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44640);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44664.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44664);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44690.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44690);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B446D0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B446D0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44700.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44700);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B447C0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B447C0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44A90.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44A90);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44B78.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44B78);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44B84.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44B84);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44C24.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44C24);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44C80.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44C80);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44E90.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44E90);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44EFC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44EFC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44F58.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44F58);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B44FEC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B44FEC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B45080.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B45080);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B450C0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B450C0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4516C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4516C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B451A0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B451A0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B452EC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B452EC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B453F4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B453F4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B45460.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B45460);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B454BC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B454BC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B45518.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B45518);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B45550.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B45550);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4560C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4560C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B45648.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B45648);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B456A8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B456A8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B457A0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B457A0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B458D8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B458D8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B45980.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B45980);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B459E8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B459E8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B45A4C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B45A4C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B45A94.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B45A94);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B45B1C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B45B1C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B45BB8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B45BB8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B45C04.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B45C04);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B45CE0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B45CE0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B45EC8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B45EC8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46118.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46118);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46184.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46184);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B461DC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B461DC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4627C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4627C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46414.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46414);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46520.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46520);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B465CC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B465CC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46644.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46644);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B468B4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B468B4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B469C4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B469C4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46A80.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46A80);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/EnInvadepoh_Init.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", EnInvadepoh_Init);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46BB0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46BB0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46BC0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46BC0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46C08.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46C08);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46C34.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46C34);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46C50.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46C50);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46C7C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46C7C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46C94.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46C94);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46CC0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46CC0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46CF4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46CF4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46D28.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46D28);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/EnInvadepoh_Destroy.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", EnInvadepoh_Destroy);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46DA8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46DA8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46DC8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46DC8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46E20.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46E20);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46E44.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46E44);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46EC0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46EC0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46EE8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46EE8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46F88.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46F88);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B46FA8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B46FA8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B47064.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B47064);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B47084.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B47084);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B470E0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B470E0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B47108.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B47108);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B471C0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B471C0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B471E0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B471E0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B47248.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B47248);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B47268.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B47268);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B47278.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B47278);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B47298.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B47298);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B47304.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B47304);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B47324.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B47324);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/EnInvadepoh_Update.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", EnInvadepoh_Update);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B47380.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B47380);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B473E4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B473E4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B47478.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B47478);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B474DC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B474DC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B47568.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B47568);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B47600.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B47600);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4770C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4770C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B477B4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B477B4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B47830.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B47830);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B478F4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B478F4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B47938.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B47938);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B479E8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B479E8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B47BAC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B47BAC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B47D30.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B47D30);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B47FA8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B47FA8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B48060.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B48060);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B481C4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B481C4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4827C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4827C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B482D4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B482D4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B48324.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B48324);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B48374.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B48374);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B483CC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B483CC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4843C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4843C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B484EC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B484EC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B48588.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B48588);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B48610.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B48610);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B48620.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B48620);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4873C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4873C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B487B4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B487B4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B48848.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B48848);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B48948.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B48948);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B48AD4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B48AD4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B48DE4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B48DE4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B48E4C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B48E4C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B48FB0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B48FB0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B490F0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B490F0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B491EC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B491EC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B49228.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B49228);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B492FC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B492FC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4934C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4934C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B49404.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B49404);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B49454.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B49454);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B49628.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B49628);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B49670.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B49670);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B497A4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B497A4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B497EC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B497EC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B49904.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B49904);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4994C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4994C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B499BC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B499BC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B49A00.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B49A00);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B49B1C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B49B1C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B49BD0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B49BD0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B49C38.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B49C38);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B49DA0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B49DA0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B49DFC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B49DFC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B49F88.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B49F88);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4A168.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4A168);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4A1B8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4A1B8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4A2C0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4A2C0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4A350.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4A350);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4A570.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4A570);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4A5E4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4A5E4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4A614.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4A614);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4A67C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4A67C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4A7C0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4A7C0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4A81C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4A81C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4A9C8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4A9C8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4AB8C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4AB8C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4ABDC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4ABDC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4ACDC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4ACDC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4ACF0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4ACF0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4AD3C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4AD3C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4AD60.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4AD60);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4ADB8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4ADB8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4ADCC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4ADCC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4AEC0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4AEC0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4AEDC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4AEDC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4AF80.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4AF80);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4AF94.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4AF94);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4B024.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4B024);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4B048.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4B048);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4B0C4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4B0C4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4B218.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4B218);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4B3DC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4B3DC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4B430.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4B430);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4B484.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4B484);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4B510.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4B510);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4B564.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4B564);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4B724.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4B724);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4B768.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4B768);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4B820.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4B820);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4B864.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4B864);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4B8BC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4B8BC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4BA30.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4BA30);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4BA84.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4BA84);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4BBE0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4BBE0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4BC4C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4BC4C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4BFFC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4BFFC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4C058.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4C058);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4C1BC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4C1BC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4C218.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4C218);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4C3A0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4C3A0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4C568.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4C568);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4C5C0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4C5C0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4C6C8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4C6C8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4C730.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4C730);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4CAB0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4CAB0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4CB0C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4CB0C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4CC70.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4CC70);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4CCCC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4CCCC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4CE54.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4CE54);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4CFFC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4CFFC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4D054.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4D054);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4D15C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4D15C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4D290.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4D290);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4D3E4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4D3E4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4D480.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4D480);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4D670.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4D670);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4D760.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4D760);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4D7B8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4D7B8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4D9B4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4D9B4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4D9D8.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4D9D8);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4D9F4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4D9F4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4DB14.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4DB14);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4E120.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4E120);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4E158.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4E158);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4E1B0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4E1B0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4E200.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4E200);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4E2AC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4E2AC);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4E324.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4E324);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4E3F0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4E3F0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4E5B0.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4E5B0);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4E61C.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4E61C);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4E660.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4E660);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4E6E4.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4E6E4);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4E784.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4E784);

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh/func_80B4E7BC.s")
INCLUDE_ASM("asm/non_matchings/overlays/ovl_En_Invadepoh", func_80B4E7BC);
