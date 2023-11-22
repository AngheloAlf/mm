#include "libu64/mtxuty-cvt.h"

void MtxConv_F2L(Mtx* mtx, f32 mf[4][4]) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            s32 value = (mf[i][j] * 0x10000);

            mtx->intPart[i][j] = value >> 16;
            mtx->fracPart[i][j] = value;
        }
    }
}

void MtxConv_L2F(f32 mf[4][4], Mtx* mtx) {
    guMtxL2F(mf, mtx);
}
