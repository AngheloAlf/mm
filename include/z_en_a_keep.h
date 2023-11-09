#ifndef Z_EN_A_KEEP_H
#define Z_EN_A_KEEP_H

#include "global.h"

struct EnAObj;

typedef void (*EnAObjActionFunc)(struct EnAObj*, struct PlayState*);

typedef struct EnAObj {
    /* 0x000 */ Actor actor;
    /* 0x144 */ EnAObjActionFunc actionFunc;
    /* 0x148 */ ColliderCylinder collision;
} EnAObj; // size = 0x194

typedef enum AObjType {
    /* 0 */ AOBJ_SIGNPOST_OBLONG,
    /* 1 */ AOBJ_SIGNPOST_ARROW
} AObjType;

#define AOBJ_GET_TEXTID(thisx) ((((thisx)->params >> 8) & 0xFF) | 0x300)
#define AOBJ_GET_TYPE(thisx) (((thisx)->params & 0xFF) - 9)

#define AOBJ_PARAMS(textId, type) ((((textId - 0x300) & 0xFF) << 8) | (type + 9))

#endif // Z_EN_A_KEEP_H
