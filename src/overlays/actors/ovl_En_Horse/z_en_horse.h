#ifndef Z_EN_HORSE_H
#define Z_EN_HORSE_H

#include <global.h>

struct EnHorse;

typedef struct EnHorse {
    /* 0x000 */ Actor actor;
    /* 0x144 */ char unk_144[0xBC];
    /* 0x200 */ UNK_TYPE unk_200;
    /* 0x204 */ char unk_204[0x33C];
    /* 0x540 */ Vec3f unk_540;
    /* 0x54C */ UNK_TYPE unk_54C;
    /* 0x550 */ UNK_TYPE unk_550;
    /* 0x554 */ UNK_TYPE unk_554;
    /* 0x558 */ UNK_TYPE unk_558;
    /* 0x55C */ UNK_TYPE unk_55C;
    /* 0x560 */ UNK_TYPE unk_560;
    /* 0x564 */ char unk_564[0x4];
    /* 0x568 */ f32 unk_568;
    /* 0x56C */ f32 unk_56C;
    /* 0x570 */ Vec3f unk_570;
    /* 0x57C */ Vec3f unk_57C;
    /* 0x588 */ s16 unk_588;
    /* 0x58A */ char unk_58A[0xA];
} EnHorse; // size = 0x594

extern const ActorInit En_Horse_InitVars;

#endif // Z_EN_HORSE_H
