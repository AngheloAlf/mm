#include <ultra64.h>
#include <global.h>

void *StartHeap_AllocMin1(u32 size) {
    u32 phi_a1;

    phi_a1 = size;
    if (size == 0) {
        phi_a1 = 1U;
    }
    return __osMalloc(&startHeap, phi_a1);
}

void StartHeap_FreeNull(void *pvParm1) {
    if (pvParm1 != NULL) {
        __osFree(&startHeap, pvParm1);
    }
}


/*
void func_8008633C(u32 param_1, s32 param_2, s32 param_3, void (*param_4)(u32)) {
    u32 phi_s0;

    for (phi_s0 = param_1; phi_s0 < param_1 + (param_2 * param_3); phi_s0 += param_3) {
        param_4(phi_s0);
    }
}
*/
#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x800862E0/func_8008633C.asm")

/*
void func_800863AC(u32 param_1, s32 param_2, s32 param_3, void *param_4) {
    u32 temp_s0;
    u32 temp_s1;
    u32 phi_s0;

    temp_s1 = param_1 + (param_2 * param_3);
    phi_s0 = param_1;
    if (param_1 < temp_s1) {
loop_1:
        param_4(phi_s0, 2);
        temp_s0 = phi_s0 + param_3;
        phi_s0 = temp_s0;
        if (temp_s0 < temp_s1) {
            goto loop_1;
        }
    }
}
*/
#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x800862E0/func_800863AC.asm")

/*
u32 func_8008641C(u32 arg0, s32 arg1, s32 arg2, void *arg3) {
    u32 temp_s0;
    u32 temp_s1;
    u32 phi_s4;
    u32 phi_s0;

    phi_s4 = arg0;
    if (arg0 == 0) {
        phi_s4 = (u32) StartHeap_AllocMin1(arg1 * arg2);
    }
    if ((phi_s4 != 0) && (arg3 != 0)) {
        temp_s1 = phi_s4 + (arg1 * arg2);
        phi_s0 = phi_s4;
        if (phi_s4 < temp_s1) {
loop_5:
            arg3(phi_s0, 0, 0, 0, 0, 0, 0, 0, 0);
            temp_s0 = phi_s0 + arg2;
            phi_s0 = temp_s0;
            if (temp_s0 < temp_s1) {
                goto loop_5;
            }
        }
    }
    return phi_s4;
}
*/
#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x800862E0/func_8008641C.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x800862E0/func_800864EC.asm")

/*
void *func_80086588(void) {
    void *temp_s0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;
    void *phi_s0;
    void *phi_v0;
    void *phi_s1;
    void *phi_s1_2;
    void *phi_return;

    temp_v0 = D_80097500;
    phi_s0 = &D_80097500;
    phi_v0 = temp_v0;
    phi_s1 = NULL;
    phi_s1_2 = NULL;
    phi_return = temp_v0;
    if (temp_v0 != 0) {
loop_1:
        temp_s0 = phi_s0 + phi_v0;
        temp_v1 = temp_s0->unk4;
        if (temp_v1 != 0) {
            temp_v1();
        }
        temp_v0_2 = temp_s0->unk0;
        temp_s0->unk0 = phi_s1;
        phi_s0 = temp_s0;
        phi_v0 = temp_v0_2;
        phi_s1 = temp_s0;
        phi_s1_2 = temp_s0;
        phi_return = temp_v0_2;
        if (temp_v0_2 != 0) {
            goto loop_1;
        }
    }
    D_80097500 = phi_s1_2;
    return phi_return;
}
*/
#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x800862E0/func_80086588.asm")

void StartHeap_Init(u32 base, u32 size) {
    StartHeap_InitArena(base, size);
    func_80086588();
}
//#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x800862E0/StartHeap_Init.asm")

s32 func_80086620(OSMesgQueue *mq, u8 *outMask, OSContStatus *status) {
    s32 ret;
    s32 i;

    *outMask = 0xFF;
    ret = osContInit(mq, outMask, status);
    if (ret != 0) {
        return ret;
    }
    if (*outMask == 0xFF) {
        if (osContStartQuery(mq) != 0) {
            return 1;
        }
        osRecvMesg(mq, NULL, 1);
        osContGetQuery(status);

        *outMask = 0;
        for (i = 0; i < 4; i++) {
            switch (status[i].errno) {
                case 0:
                    if (status[i].type == CONT_TYPE_NORMAL) {
                        *outMask |= 1 << i;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}
