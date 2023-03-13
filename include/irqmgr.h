#ifndef IRQMGR_H
#define IRQMGR_H

#include "ultra64.h"
#include "PR/sched.h"
#include "ultra64/message.h"


typedef struct IrqMgrClient {
    /* 0x0 */ struct IrqMgrClient* next;
    /* 0x4 */ OSMesgQueue* queue;
} IrqMgrClient; // size = 0x8

typedef struct {
    /* 0x000 */ OSScMsg verticalRetraceMesg;
    /* 0x020 */ OSScMsg prenmiMsg;
    /* 0x040 */ OSScMsg nmiMsg;
    /* 0x060 */ OSMesgQueue irqQueue;
    /* 0x078 */ OSMesg irqBuffer[8];
    /* 0x098 */ OSThread thread;
    /* 0x248 */ IrqMgrClient* callbacks;
    /* 0x24C */ u8 prenmiStage;
    /* 0x250 */ OSTime lastPrenmiTime;
    /* 0x258 */ OSTimer prenmiTimer;
    /* 0x278 */ OSTime lastFrameTime;
} IrqMgr; // size = 0x280


void IrqMgr_AddClient(IrqMgr* irqmgr, IrqMgrClient* client, OSMesgQueue* msgQueue);
void IrqMgr_RemoveClient(IrqMgr* irqmgr, IrqMgrClient* remove);
void IrqMgr_SendMesgForClient(IrqMgr* irqmgr, OSMesg msg);
void IrqMgr_JamMesgForClient(IrqMgr* irqmgr, OSMesg msg);
void IrqMgr_HandlePreNMI(IrqMgr* irqmgr);
void IrqMgr_CheckStack(void);
void IrqMgr_HandlePRENMI450(IrqMgr* irqmgr);
void IrqMgr_HandlePRENMI480(IrqMgr* irqmgr);
void IrqMgr_HandlePRENMI500(IrqMgr* irqmgr);
void IrqMgr_HandleRetrace(IrqMgr* irqmgr);
void IrqMgr_ThreadEntry(IrqMgr* irqmgr);
void IrqMgr_Init(IrqMgr* irqmgr, void* stack, OSPri pri, u8 retraceCount);

#endif
