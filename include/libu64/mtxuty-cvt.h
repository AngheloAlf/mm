#ifndef LIBU64_MTXUTY_CVT_H
#define LIBU64_MTXUTY_CVT_H

#include "ultra64.h"

void MtxConv_F2L(Mtx* mtx, f32 mf[4][4]);
void MtxConv_L2F(f32 mf[4][4], Mtx* mtx);

#endif
