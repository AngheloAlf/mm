#ifndef PADUTILS_H
#define PADUTILS_H

#include "ultra64.h"
#include "libc/stdbool.h"

struct Input;


void PadUtils_Init(struct Input* input);
void func_80085150(void);
void PadUtils_ResetPressRel(struct Input* input);

bool PadUtils_CheckCurExact(struct Input* input, u16 value);
bool PadUtils_CheckCur(struct Input* input, u16 key);
bool PadUtils_CheckPressed(struct Input* input, u16 key);
bool PadUtils_CheckReleased(struct Input* input, u16 key);

u16 PadUtils_GetCurButton(struct Input* input);
u16 PadUtils_GetPressButton(struct Input* input);
s8 PadUtils_GetCurX(struct Input* input);
s8 PadUtils_GetCurY(struct Input* input);
void PadUtils_SetRelXY(struct Input* input, s32 x, s32 y);
s8 PadUtils_GetRelXImpl(struct Input* input);
s8 PadUtils_GetRelYImpl(struct Input* input);
s8 PadUtils_GetRelX(struct Input* input);
s8 PadUtils_GetRelY(struct Input* input);
void PadUtils_UpdateRelXY(struct Input* input);

#endif
