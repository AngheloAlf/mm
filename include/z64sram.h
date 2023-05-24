#ifndef Z64_SRAM_H
#define Z64_SRAM_H

#include "ultra64.h"
#include "os.h"

typedef struct SramContext {
    /* 0x00 */ u8* readBuff;
    /* 0x04 */ u8 *saveBuf;
    /* 0x08 */ char unk_08[4];
    /* 0x0C */ s16 status;
    /* 0x10 */ u32 curPage;
    /* 0x14 */ u32 numPages;
    /* 0x18 */ OSTime unk_18;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ s16 unk_22;
    /* 0x24 */ s16 unk_24;
} SramContext; // size = 0x28


void func_80147008(SramContext* sramCtx, u32 curPage, u32 numPages);
void func_80147020(SramContext* sramCtx);
void func_80147068(SramContext* sramCtx);
void func_80147138(SramContext* sramCtx, s32 curPage, s32 numPages);
void func_80147150(SramContext* sramCtx);
void func_80147198(SramContext* sramCtx);
void func_80147314(SramContext* sramCtx, s32 fileNum);
void func_80147414(SramContext* sramCtx, s32 fileNum, s32 arg2);

#endif
