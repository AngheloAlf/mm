#ifndef SYS_FLASHROM_H
#define SYS_FLASHROM_H

#include "ultra64.h"

#define FLASH_VERSION_MX_PROTO_A 0x00C20000
#define FLASH_VERSION_MX_A       0x00C20001
#define FLASH_VERSION_MX_C       0x00C2001E
#define FLASH_VERSION_MX_B_AND_D 0x00C2001D
#define FLASH_VERSION_MEI        0x003200F1

#define FLASH_TYPE_MAGIC 0x11118001

#define FLASH_PAGE_SIZE 128

#define FLASHROM_REQUEST_WRITE 1
#define FLASHROM_REQUEST_READ 2

typedef struct FlashromRequest {
    /* 0x00 */ s32 requestType;
    /* 0x04 */ OSMesg response;
    /* 0x08 */ void* addr;
    /* 0x0C */ s32 pageNum;
    /* 0x10 */ s32 pageCount;
    /* 0x14 */ OSMesgQueue messageQueue;
} FlashromRequest; // size = 0x2C


s32 SysFlashrom_InitFlash(void);
s32 SysFlashrom_ReadData(void* addr, u32 pageNum, u32 pageCount);
void SysFlashrom_WriteDataAsync(u8* addr, u32 pageNum, u32 pageCount);
s32 SysFlashrom_IsBusy(void);
s32 SysFlashrom_AwaitResult(void);
void SysFlashrom_WriteDataSync(void* addr, u32 pageNum, u32 pageCount);


#endif
