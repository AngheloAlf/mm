#include <ultra64.h>
#include <global.h>

typedef void (*arg3_8008633C)(void*);
typedef void (*arg3_800863AC)(void*, u32);
typedef void (*arg3_8008641C)(void*, u32, u32, u32, u32, u32, u32, u32, u32);
typedef void (*arg3_800864EC)(void*, u32);

typedef struct InitFunc {
    s32 nextOffset;
    void (*func)(void);
} InitFunc;

// D_80097500;
extern void* sInitFuncs;
//static void* sInitFuncs = NULL;

/*
static s32 D_80097504[] = {
    0x00000000, 0x00000000, 0x00000000, 0x7F800000,
    0xFF800000, 0x00000000, 0x80000000, 0x7FBFFFFF,
};
*/

void *StartHeap_AllocMin1(u32 size) {
    u32 phi_a1;

    phi_a1 = size;
    if (size == 0) {
        phi_a1 = 1U;
    }
    return __osMalloc(&startHeap, phi_a1);
}

void StartHeap_FreeNull(void *pvParm1) {
    if (pvParm1 != NULL) {
        __osFree(&startHeap, pvParm1);
    }
}



void func_8008633C(void* blk, s32 nBlk, s32 blkSize, arg3_8008633C arg3) {
    u32 pos;

    for (pos = (u32)blk; pos < (u32)blk + (nBlk * blkSize); pos += (blkSize) & ~0) {
        arg3((void*)pos);
    }
}

void func_800863AC(void* blk, s32 nBlk, s32 blkSize, arg3_800863AC arg3) {
    u32 pos;

    for (pos = (u32)blk; pos < (u32)blk + (nBlk * blkSize); pos += (blkSize) & ~0) {
        arg3((void*)pos, 2);
    }
}

void* func_8008641C(void* blk, u32 nBlk, u32 blkSize, arg3_8008641C arg3) {
    u32 pos;

    if (blk == NULL) {
        blk = StartHeap_AllocMin1(nBlk * blkSize);
    }

    if (blk != NULL && arg3 != NULL) {
        pos = (u32)blk;
        while (pos < (u32)blk + (nBlk * blkSize)) {
            arg3((void*)pos, 0, 0, 0, 0, 0, 0, 0, 0);
            pos = (u32)pos + (blkSize & ~0);
        }
    }
    return blk;
}

void func_800864EC(void* blk, u32 nBlk, u32 blkSize, arg3_800864EC arg3, s32 arg4) {
    u32 pos;
    u32 end;
    s32 masked_arg2;

    if (blk == 0) {
        return;
    }
    if (arg3 != 0) {
        end = (u32)blk;
        masked_arg2 = (s32)(blkSize & ~0);
        pos = (u32)end + (nBlk * blkSize);

        if (masked_arg2) {}

        while (pos > end) {
            do {
                pos -= masked_arg2;
                arg3((void*)pos, 2);
            } while (0);
        }

        if (!masked_arg2) {}
    }

    if (arg4 != 0) {
        StartHeap_FreeNull(blk);
    }
}

void *func_80086588(void) {
    InitFunc* initFunc = (InitFunc*)&sInitFuncs;
    u32 nextOffset = initFunc->nextOffset;
    InitFunc* prev = NULL;

    while (nextOffset != 0) {
        initFunc = (InitFunc*)((s32)initFunc + nextOffset);

        if (initFunc->func != NULL) {
            (*initFunc->func)();
        }

        nextOffset = initFunc->nextOffset;
        initFunc->nextOffset = (s32)prev;
        prev = initFunc;
    }

    sInitFuncs = prev;
}

void StartHeap_Init(u32 base, u32 size) {
    StartHeap_InitArena(base, size);
    func_80086588();
}

// PadSetup_Init
s32 PadSetup_Init(OSMesgQueue *mq, u8 *outMask, OSContStatus *status) {
    s32 ret;
    s32 i;

    *outMask = 0xFF;
    ret = osContInit(mq, outMask, status);
    if (ret != 0) {
        return ret;
    }
    if (*outMask == 0xFF) {
        if (osContStartQuery(mq) != 0) {
            return 1;
        }
        osRecvMesg(mq, NULL, 1);
        osContGetQuery(status);

        *outMask = 0;
        for (i = 0; i < 4; i++) {
            switch (status[i].errno) {
                case 0:
                    if (status[i].type == CONT_TYPE_NORMAL) {
                        *outMask |= 1 << i;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}
