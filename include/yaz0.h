#ifndef YAZ0_H
#define YAZ0_H

#include "ultra64.h"
#include "libc/stddef.h"
#include "libc/stdint.h"


void* Yaz0_FirstDMA(void);
void* Yaz0_NextDMA(void* curSrcPos);
s32 Yaz0_DecompressImpl(u8* src, u8* dst);
void Yaz0_Decompress(uintptr_t romStart, void* dst, size_t size);

#endif
