#ifndef Z64_SRAM_H
#define Z64_SRAM_H

#include "ultra64.h"
#include "os.h"

struct GameState;
struct PlayState;
struct FileSelectState;

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

#define SAVE_BUFFER_SIZE 0x4000


void Sram_ActivateOwl(u8 owlId);
void Sram_ClearFlagsAtDawnOfTheFirstDay(void);
void Sram_SaveEndOfCycle(struct PlayState* play);
void Sram_IncrementDay(void);
u16 Sram_CalcChecksum(void* data, size_t count);
void Sram_InitNewSave(void);
void Sram_InitDebugSave(void);
void func_80144A94(SramContext* sramCtx);
void Sram_OpenSave(struct FileSelectState* fileSelect, SramContext* sramCtx);
void func_8014546C(SramContext* sramCtx);
void func_801457CC(struct FileSelectState* fileSelect, SramContext* sramCtx);
void func_80146580(struct FileSelectState* fileSelect2, SramContext* sramCtx, s32 fileNum);
void func_80146628(struct FileSelectState* fileSelect2, SramContext* sramCtx);
void Sram_InitSave(struct FileSelectState* fileSelect2, SramContext* sramCtx);
void func_80146DF8(SramContext* sramCtx);
void Sram_InitSram(struct GameState* gameState, SramContext* sramCtx);
void Sram_Alloc(struct GameState* gameState, SramContext* sramCtx);
void Sram_SaveSpecialEnterClockTown(struct PlayState* play);
void Sram_SaveSpecialNewDay(struct PlayState* play);
void func_80147008(SramContext* sramCtx, u32 curPage, u32 numPages);
void func_80147020(SramContext* sramCtx);
void func_80147068(SramContext* sramCtx);
void func_80147138(SramContext* sramCtx, s32 curPage, s32 numPages);
void func_80147150(SramContext* sramCtx);
void func_80147198(SramContext* sramCtx);

extern s32 D_801C6798[];
extern u8 gAmmoItems[];
extern s32 D_801C67C8[];
extern s32 D_801C67F0[];
extern s32 D_801C6818[];
extern s32 D_801C6840[];
extern s32 D_801C6850[];


#endif
