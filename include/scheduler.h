#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "PR/ultratypes.h"
#include "PR/sched.h"
#include "ultra64/vi.h"
#include "ultra64/sptask.h"
#include "irqmgr.h"

#define TASK_FRAMEBUFFER(task) ((CfbInfo*)(task)->framebuffer)

typedef struct CfbInfo {
    /* 0x00 */ u16*      fb1;
    /* 0x04 */ u16*      swapBuffer;
    /* 0x08 */ OSViMode* viMode;
    /* 0x0C */ u32       features;
    /* 0x10 */ u8        unk_10;
    /* 0x11 */ s8        updateRate;
    /* 0x12 */ s8        updateRate2;
    /* 0x13 */ u8        unk_13;
    /* 0x14 */ f32       xScale;
    /* 0x18 */ f32       yScale;
} CfbInfo; // size = 0x1C

typedef struct SchedContext {
    /* 0x000 */ OSMesgQueue  interruptQ;
    /* 0x018 */ OSMesg       intBuf[64];
    /* 0x118 */ OSMesgQueue  cmdQ;
    /* 0x130 */ OSMesg       cmdMsgBuf[8];
    /* 0x150 */ OSThread     thread;
    /* 0x300 */ OSScTask*    audioListHead;
    /* 0x304 */ OSScTask*    gfxListHead;
    /* 0x308 */ OSScTask*    audioListTail;
    /* 0x30C */ OSScTask*    gfxListTail;
    /* 0x310 */ OSScTask*    curRSPTask;
    /* 0x314 */ OSScTask*    curRDPTask;
    /* 0x318 */ s32          retraceCount;
    /* 0x318 */ s32          doAudio;
    /* 0x320 */ CfbInfo*     curBuf;
    /* 0x324 */ CfbInfo*     pendingSwapBuf1;
    /* 0x328 */ CfbInfo*     pendingSwapBuf2;
    /* 0x32C */ char         unk_32C[0x3];
    /* 0x32F */ u8           shouldUpdateVi;
    /* 0x330 */ IrqMgrClient irqClient;
} SchedContext; // size = 0x338

void Sched_SwapFramebuffer(CfbInfo* cfbInfo);
void Sched_RetraceUpdateFramebuffer(SchedContext* sched, CfbInfo* cfbInfo);
void Sched_HandleReset(SchedContext* sched);
void Sched_HandleStop(SchedContext* sched);
void Sched_HandleAudioCancel(SchedContext* sched);
void Sched_HandleGfxCancel(SchedContext* sched);
void Sched_QueueTask(SchedContext* sched, OSScTask* task);
void Sched_Yield(SchedContext* sched);
s32 Sched_Schedule(SchedContext* sched, OSScTask** spTask, OSScTask** dpTask, s32 state);
void Sched_TaskUpdateFramebuffer(SchedContext* sched, OSScTask* task);
void Sched_NotifyDone(SchedContext* sched, OSScTask* task);
void Sched_RunTask(SchedContext* sched, OSScTask* spTask, OSScTask* dpTask);
void Sched_HandleEntry(SchedContext* sched);
void Sched_HandleRetrace(SchedContext* sched);
void Sched_HandleRSPDone(SchedContext* sched);
void Sched_HandleRDPDone(SchedContext* sched);
void Sched_SendEntryMsg(SchedContext* sched);
void Sched_SendAudioCancelMsg(SchedContext* sched);
void Sched_SendGfxCancelMsg(SchedContext* sched);
void Sched_FaultClient(void* param1, void* param2);
void Sched_ThreadEntry(void* arg);
void Sched_Init(SchedContext* sched, void* stack, OSPri pri, UNK_TYPE arg3, UNK_TYPE arg4, IrqMgr* irqMgr);

#endif
