#ifndef Z64DMA_H
#define Z64DMA_H

#include "ultra64.h"
#include "libc/stddef.h"
#include "unk.h"


typedef struct {
    /* 0x00 */ uintptr_t    vromAddr;    // VROM address (source)
    /* 0x04 */ void*        dramAddr;    // DRAM address (destination)
    /* 0x08 */ size_t       size;        // File Transfer size
    /* 0x0C */ char*        filename;    // Filename for debugging
    /* 0x10 */ s32          line;        // Line for debugging
    /* 0x14 */ s32          unk14;
    /* 0x18 */ OSMesgQueue* notifyQueue; // Message queue for the notification message
    /* 0x1C */ OSMesg       notifyMsg;   // Completion notification message
} DmaRequest; // size = 0x20

typedef struct {
    /* 0x0 */ uintptr_t vromStart;
    /* 0x4 */ uintptr_t vromEnd;
    /* 0x8 */ uintptr_t romStart;
    /* 0xC */ uintptr_t romEnd;
} DmaEntry; // size = 0x10


s32 DmaMgr_DmaRomToRam(uintptr_t rom, void* ram, size_t size);
s32 DmaMgr_DmaHandler(OSPiHandle* pihandle, OSIoMesg* mb, s32 direction);
DmaEntry* DmaMgr_FindDmaEntry(uintptr_t vrom);
u32 DmaMgr_TranslateVromToRom(uintptr_t vrom);
s32 DmaMgr_FindDmaIndex(uintptr_t vrom);
const char* func_800809F4(uintptr_t param_1);
void DmaMgr_ProcessMsg(DmaRequest* req);
void DmaMgr_ThreadEntry(void* arg);
s32 DmaMgr_SendRequestImpl(DmaRequest* request, void* vramStart, uintptr_t vromStart, size_t size, UNK_TYPE4 unused, OSMesgQueue* queue, void* msg);
s32 DmaMgr_SendRequest0(void* vramStart, uintptr_t vromStart, size_t size);
void DmaMgr_Start(void);
void DmaMgr_Stop(void);

#endif
