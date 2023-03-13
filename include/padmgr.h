#ifndef PADMGR_H
#define PADMGR_H

#include "ultra64.h"
#include "padutils.h"
#include "irqmgr.h"


typedef struct {
    /* 0x000 */ u8 controllers; // bit 0 is set if controller 1 is plugged in, etc.
    /* 0x001 */ UNK_TYPE1 pad1[0x13];
    /* 0x014 */ OSContStatus statuses[4];
    /* 0x024 */ UNK_TYPE4 unk24;
    /* 0x028 */ OSMesg lockMesg[1];
    /* 0x02C */ OSMesg interrupts[8];
    /* 0x04C */ OSMesgQueue sSiIntMsgQ;
    /* 0x064 */ OSMesgQueue lock;
    /* 0x07C */ OSMesgQueue irqmgrCallbackQueue;
    /* 0x094 */ IrqMgrClient irqmgrCallbackQueueNode;
    /* 0x09C */ IrqMgr* irqmgr;
    /* 0x0A0 */ OSThread thread;
    /* 0x250 */ Input input[4];
    /* 0x2B0 */ OSContPad controllerState1[4];
    /* 0x2C8 */ u8 maxNumControllers;
    /* 0x2C9 */ UNK_TYPE1 pad2C9[0x1B3];
    /* 0x47C */ u8 unk47C;
    /* 0x47D */ u8 unk47D;
    /* 0x47E */ u8 hasStopped;
} PadMgr; // size = 0x480


u32 Padmgr_GetControllerBitmask(void);
void func_80174F24(void (*arg0)(void*), void* arg1);
void func_80174F44(void (*arg0)(void*), void* arg1);
void func_80174F7C(void (*arg0)(s32), void* arg1);
void func_80174F9C(void (*arg0)(s32), void* arg1);
// OSMesgQueue* Padmgr_GetEventCallback(void);
// void func_80175008(void);
void Padmgr_SetEventCallback(OSMesg pvParm1);
// void func_8017506C(void);
// void Padmgr_Lock(void);
// void Padmgr_Unlock(void);
// void func_801750FC(void);
// void func_80175364(void);
void func_80175434(void);
void func_8017544C(s32 port, s32 rumbleOn);
void PadMgr_RumbleSet(u8 rumbleEnabled[MAXCONTROLLERS]);
s32 PadMgr_ControllerHasRumblePak(s32 port);
void Padmgr_CalcStickEdges(Input* input);
// void Padmgr_ParseState(void);
// void func_801759BC(void);
// void func_80175AE0(void);
// void Padmgr_Update(void);
// void Padmgr_Stop(void);
void func_80175E68(Input* input, s32 param_2);
void Padmgr_GetInput(Input* input, s32 param_2);
void Padmgr_GetInput2(Input* input, s32 param_2);
void Padmgr_ThreadEntry(PadMgr* padmgr);
void PadMgr_Init(OSMesgQueue* siEventCallbackQueue, IrqMgr* irqmgr, OSId threadId, OSPri threadPri, void* stack);

#endif
