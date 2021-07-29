#include "global.h"

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013A7C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013A860.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013AB00.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013AD6C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013AD9C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013AED4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013AF00.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013B010.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013B0C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013B350.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013B6B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013B878.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013BB34.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013BB7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013BC6C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013BD40.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013BEDC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013C068.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013C624.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013C8B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013C964.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013CC2C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013CD64.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013CF04.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013D0E0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013D2E0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013D5E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013D648.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013D68C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013D720.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013D768.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013D83C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013D8DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013D924.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_ActorCategoryIterateById.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013D9C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013DB90.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013DC40.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013DCCC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013DCE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013DE04.s")

typedef struct {
    /* 0x00 */ Vec3f unk_00;
} struct_8013DF3C_arg1_unk_44; // size >= 0x0C

typedef struct {
    /* 0x00 */ UNK_TYPE1 unk_00[0x08];
    /* 0x08 */ Vec3s* unk_08;
    /* 0x0C */ UNK_TYPE1 unk_0C[0x04];
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ UNK_TYPE1 unk_14[0x0C];
    /* 0x20 */ Vec3f unk_20;
    /* 0x2C */ Vec3f unk_2C;
    /* 0x38 */ UNK_TYPE1 unk_38[0xC];
    /* 0x44 */ struct_8013DF3C_arg1_unk_44* unk_44; // another struct?
    /* 0x48 */ UNK_TYPE1 unk_48[0x04];
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ f32 unk_50;
    /* 0x54 */ Vec3s unk_54; // Not sure if it is a Vec3s
} struct_8013DF3C_arg1; // size >= 0x5A

void func_8013DF3C(s32 arg0, struct_8013DF3C_arg1* arg1) {
    Vec3f sp2C;

    arg1->unk_20.x = arg1->unk_08[arg1->unk_10].x + arg1->unk_2C.x;
    arg1->unk_20.y = arg1->unk_08[arg1->unk_10].y + arg1->unk_2C.y;
    arg1->unk_20.z = arg1->unk_08[arg1->unk_10].z + arg1->unk_2C.z;
    sp2C.x = arg1->unk_20.x - arg1->unk_44->unk_00.x;
    sp2C.y = arg1->unk_20.y - arg1->unk_44->unk_00.y;
    sp2C.z = arg1->unk_20.z - arg1->unk_44->unk_00.z;
    arg1->unk_4C = Math3D_XZLengthSquared(sp2C.x, sp2C.z);
    arg1->unk_50 = Math3D_LengthSquared(&sp2C);
    arg1->unk_54.y = Math_FAtan2F(sp2C.z, sp2C.x);
    arg1->unk_54.x = Math_FAtan2F(sqrtf(arg1->unk_4C), -sp2C.y);
    arg1->unk_54.z = 0;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013E054.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013E07C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013E0A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013E1C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013E2D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013E3B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013E4B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013E5CC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013E640.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013E748.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013E7C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013E8F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sub_s/func_8013E950.s")
