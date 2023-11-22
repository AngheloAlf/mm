#ifndef GFXPRINT_H
#define GFXPRINT_H

#include "color.h"
#include "PR/gbi.h"
#include "PR/ultratypes.h"
#include "PR/xstdio.h"
#include "unk.h"

#define GFXP_UNUSED "\x8E"
#define GFXP_UNUSED_CHAR 0x8E
#define GFXP_HIRAGANA "\x8D"
#define GFXP_HIRAGANA_CHAR 0x8D
#define GFXP_KATAKANA "\x8C"
#define GFXP_KATAKANA_CHAR 0x8C
#define GFXP_RAINBOW_ON "\x8B"
#define GFXP_RAINBOW_ON_CHAR 0x8B
#define GFXP_RAINBOW_OFF "\x8A"
#define GFXP_RAINBOW_OFF_CHAR 0x8A

typedef struct GfxPrint {
    /* 0x00 */ PrintCallback callback;
    /* 0x04 */ Gfx* dList;
    /* 0x08 */ u16 posX;
    /* 0x0A */ u16 posY;
    /* 0x0C */ u16 baseX;
    /* 0x0E */ u8 baseY;
    /* 0x0F */ u8 flags;
    /* 0x10 */ Color_RGBA8_u32 color;
    /* 0x14 */ UNK_TYPE1 unk_14[0x1C]; // unused
} GfxPrint; // size = 0x30

void gfxprint_setup(GfxPrint* this);
void gfxprint_color(GfxPrint* this, u32 r, u32 g, u32 b, u32 a);
void gfxprint_locate(GfxPrint* this, s32 x, s32 y);
void gfxprint_locate8x8(GfxPrint* this, s32 x, s32 y);
void gfxprint_setoffset(GfxPrint* this, s32 x, s32 y);
void gfxprint_putc1(GfxPrint* this, u8 c);
void gfxprint_putc(GfxPrint* this, u8 c);
void gfxprint_write(GfxPrint* this, const void* buffer, size_t charSize, size_t charCount);
void gfxprint_puts(GfxPrint* this, const char* str);
void* gfxprint_prout(void* arg, const char* str, size_t size);
void gfxprint_init(GfxPrint* this);
void gfxprint_cleanup(GfxPrint* printer);
void gfxprint_open(GfxPrint* this, Gfx* dList);
Gfx* gfxprint_close(GfxPrint* this);
s32 gfxprint_vprintf(GfxPrint* this, const char* fmt, va_list args);
s32 gfxprint_printf(GfxPrint* this, const char* fmt, ...);

#endif
