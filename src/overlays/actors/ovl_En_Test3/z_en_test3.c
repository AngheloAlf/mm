/*
 * File: z_en_test3.c
 * Overlay: ovl_En_Test3
 * Description: Kafei.
 */

#include "z_en_test3.h"
#include "../ovl_En_Door/z_en_door.h"

#define FLAGS 0x04000030

#define THIS ((EnTest3*)thisx)

void EnTest3_Init(Actor* thisx, GlobalContext* globalCtx);
void EnTest3_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnTest3_Update(Actor* thisx, GlobalContext* globalCtx);

s32 func_80A3F080(EnTest3* this, GlobalContext* globalCtx, struct_80A417E8_arg2* arg2, struct_80A417E8_arg3* arg3);
s32 func_80A3F09C(EnTest3* this, GlobalContext* globalCtx);
s32 func_80A3F62C(EnTest3* this, GlobalContext* globalCtx, struct_80A417E8_arg2* arg2, struct_80A417E8_arg3* arg3);
s32 func_80A3F73C(EnTest3* this, GlobalContext* globalCtx);
s32 func_80A3F8D4(EnTest3* this, GlobalContext* globalCtx, struct_80A417E8_arg2* arg2, struct_80A417E8_arg3* arg3);
s32 func_80A3F9A4(EnTest3* this, GlobalContext* globalCtx);
s32 func_80A3F9E4(EnTest3* this, GlobalContext* globalCtx, struct_80A417E8_arg2* arg2, struct_80A417E8_arg3* arg3);
s32 func_80A3FA58(EnTest3* this, GlobalContext* globalCtx);
s32 func_80A3FBCC(EnTest3* this, GlobalContext* globalCtx, struct_80A417E8_arg2* arg2, struct_80A417E8_arg3* arg3);
s32 func_80A3FBE8(EnTest3* this, GlobalContext* globalCtx);
s32 func_80A3FDE4(EnTest3* this, GlobalContext* globalCtx, struct_80A417E8_arg2* arg2, struct_80A417E8_arg3* arg3);
s32 func_80A3FE20(EnTest3* this, GlobalContext* globalCtx);
s32 func_80A3FF10(EnTest3* this, GlobalContext* globalCtx, struct_80A417E8_arg2* arg2, struct_80A417E8_arg3* arg3);
s32 func_80A3FFD0(EnTest3* this, GlobalContext* globalCtx);
s32 func_80A40098(EnTest3* this, GlobalContext* globalCtx, struct_80A417E8_arg2* arg2, struct_80A417E8_arg3* arg3);
s32 func_80A40230(EnTest3* this, GlobalContext* globalCtx);

void func_80A40678(EnTest3* this, GlobalContext* globalCtx);
void func_80A40824(EnTest3* this, GlobalContext* globalCtx);
void func_80A4084C(EnTest3* this, GlobalContext* globalCtx);
void func_80A40908(EnTest3* this, GlobalContext* globalCtx);
void func_80A40A6C(EnTest3* this, GlobalContext* globalCtx);

void func_80A4129C(Actor* thisx, GlobalContext* globalCtx);

// bss
extern s32 D_80A41D20;
extern s32 D_80A41D24;
extern Input D_80A41D28;
extern f32 D_80A41D40;
extern s16 D_80A41D44;
extern s32 D_80A41D48;
extern Vec3f D_80A41D50;
extern s32 D_80A41D5C;
extern s32 D_80A41D60;
extern s32 D_80A41D64;
extern s32 D_80A41D68;
extern Vec3f* D_80A41D6C;

// Extenal
extern LinkAnimationHeader D_0400CF88;
extern FlexSkeletonHeader D_0600F7EC;

extern u8 D_80A41530[];
/*
u32 D_80A41530[] = {
    0x0C000142, 0x0A007018, 0x02063207, 0x140C0F07, 0x1E070033, 0x04010509, 0x0A050E06, 0x3207140F, 0x0A006F21,
    0x02060006, 0x1E150206, 0x1E06230D, 0x02062306, 0x3201050E, 0x06230632, 0x0E09010E, 0x0600061E, 0x0D050C00,
    0x02510033, 0x020A1100, 0x00330401, 0x0504000A, 0x0A007025, 0x0F0D00F0, 0x020F050F, 0x1915020F, 0x190F280D,
    0x020F2810, 0x0001050E, 0x0F281000, 0x1109010E, 0x0F050F19, 0x100A000D, 0x15020F37, 0x100A0902, 0x100A160A,
    0x01050903, 0x0E0F3710, 0x0A0C050D, 0x00030098, 0x01210800, 0x87014F40, 0x00820A00, 0x4F020907, 0x00332029,
    0x0A001324, 0x00330802, 0x0905003D, 0x08180033, 0x10070F13, 0x00010509, 0x05021300, 0x130A0105, 0x0E130013,
    0x0A140905, 0x050A0013, 0x07005A02, 0x02090905, 0x0A006C0D, 0x02040004, 0x0A01050E, 0x0400040A, 0x0B0A0061,
    0x2E02040A, 0x041E2200, 0x33011502, 0x041E042D, 0x0902042D, 0x06000105, 0x09060E04, 0x1E042D13, 0x02041E06,
    0x00010509, 0x080E040A, 0x041E1205, 0x0A000D07, 0x00330801, 0x05090405, 0x05000000,
};
*/

/*
const ActorInit En_Test3_InitVars = {
    ACTOR_EN_TEST3,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_TEST3,
    sizeof(EnTest3),
    (ActorFunc)EnTest3_Init,
    (ActorFunc)EnTest3_Destroy,
    (ActorFunc)EnTest3_Update,
    (ActorFunc)NULL,
};
*/

s32 func_80A3E7E0(EnTest3* this, EnTest3ActionFunc actionFunc) {
    if (actionFunc == this->actionFunc) {
        return 0;
    }

    this->actionFunc = actionFunc;
    this->unk_D8A = 0;
    this->schedule = 0;
    return 1;
}

extern KafeiActionSetupInfo D_80A4168C[];
/*
static KafeiActionSetupInfo actionSetupInfoList[] = {
    { func_80A40A6C, NULL },
    { NULL, NULL },
};
*/

s32 func_80A3E80C(EnTest3* this, GlobalContext* globalCtx, s32 actionIndex) {
    KafeiActionSetupInfo* actionSetup = &D_80A4168C[actionIndex];

    actionSetup->init(this, globalCtx);

    if (actionSetup->action == NULL) {
        return 0;
    }

    func_80A3E7E0(this, actionSetup->action);

    return 1;
}

s32 func_80A3E870(EnTest3* this, GlobalContext* globalCtx) {
    return 1;
}

s32 func_80A3E884(EnTest3* this, GlobalContext* globalCtx) {
    return 0;
}

s32 func_80A3E898(EnTest3* this, GlobalContext* globalCtx) {
    u16 textId = this->talkState->textId;

    if ((this->talkState->unk_00 == 4) && (gSaveContext.weekEventReg[0x33] & 0x08)) {
        func_80151BB4(globalCtx, 2);
    }

    if (textId == 0xFFFF) {
        func_801477B4(globalCtx);
    } else if (textId) {
        func_80151938(globalCtx, textId);
    }

    if (textId == 0x296B) {
        // SkelAnime_ChangeLinkAnimPlaybackStop(globalCtx, &this->actor.skelAnime, &D_0400CF88, 2.0f/3.0f);
        SkelAnime_ChangeLinkAnimPlaybackStop(globalCtx, &this->actor.skelAnime, &D_0400CF88, 0.6666667f);
    }

    return 0;
}

s32 func_80A3E960(EnTest3* this, GlobalContext* globalCtx) {
    this->timer = this->talkState->unk_01;
    return 0;
}

s32 func_80A3E97C(EnTest3* this, GlobalContext* globalCtx) {
    if (DECR(this->timer) == 0) {
        func_801518B0(globalCtx, this->talkState->textId, NULL);
        return 1;
    } else {
        return 0;
    }
}

s32 func_80A3E9DC(EnTest3* this, GlobalContext* globalCtx) {
    if (ActorCutscene_GetCanPlayNext(this->actorCutsceneId)) {
        ActorCutscene_StartAndSetUnkLinkFields(this->actorCutsceneId, &this->actor.actor);
        return 1;
    } else {
        ActorCutscene_SetIntentToPlay(this->actorCutsceneId);
        return 0;
    }
}

s32 func_80A3EA30(EnTest3* this, GlobalContext* globalCtx) {
    if (this->talkState->textId == 0x145F) {
        Actor* actor = func_ActorCategoryIterateById(globalCtx, NULL, ACTORCAT_BG, ACTOR_BG_IKNV_OBJ);

        if (actor != NULL) {
            this->actor.unk_730 = actor;
        }
    }

    if (this->talkState->unk_01 != 0) {
        ActorCutscene_Stop(0x7C);
        ActorCutscene_SetIntentToPlay(this->actorCutsceneId);
        globalCtx->msgCtx.unk11F22 = 0x44;
    }

    return 0;
}

s32 func_80A3EAC4(EnTest3* this, GlobalContext* game_play) {
    if (func_80152498(&game_play->msgCtx) == 6) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_80A3EAF8(EnTest3* this, GlobalContext* globalCtx) {
    if ((func_80152498(&globalCtx->msgCtx) == 5) && (func_80147624(globalCtx) != 0)) {
        if (this->talkState->textId == 0x145F) {
            ActorCutscene_Stop(this->actorCutsceneId);
            this->actorCutsceneId = 0x7C;
            ActorCutscene_SetIntentToPlay(this->actorCutsceneId);
            this->actor.unk_730 = &PLAYER->actor;
        }
        return 1;
    } else {
        return 0;
    }
}

s32 func_80A3EB8C(EnTest3* this, GlobalContext* globalCtx) {
    if (func_80A3EAF8(this, globalCtx) != 0) {
        Actor* actor = func_ActorCategoryIterateById(globalCtx, NULL, ACTORCAT_ITEMACTION, ACTOR_OBJ_NOZOKI);

        if (actor != NULL) {
            this->actor.unk_730 = actor;
        }

        globalCtx->msgCtx.unk11F22 = 0x44;
        return 1;
    } else {
        return 0;
    }
}

s32 func_80A3EBFC(EnTest3* this, GlobalContext* globalCtx) {
    if (func_80152498(&globalCtx->msgCtx) == 2) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_80A3EC30(EnTest3* this, GlobalContext* globalCtx) {
    return 0;
}

s32 func_80A3EC44(EnTest3* this, GlobalContext* globalCtx) {
    u8 ret;

    if ((func_80152498(&globalCtx->msgCtx) == 4) && func_80147624(globalCtx)) {
        if (globalCtx->msgCtx.choiceIndex) {
            func_8019F230();
        } else {
            func_8019F208();
        }

        if (globalCtx->msgCtx.choiceIndex) {
            return 1;
        } else {
            ret = this->talkState->unk_01;
            return ret + 1;
        }
    }

    return 0;
}

/*
static EnTest3_functions_80A4169C D_80A4169C[] = {
    func_80A3E898, func_80A3E898, func_80A3E884, func_80A3E898, func_80A3E898,
    func_80A3EA30, func_80A3E898, func_80A3E960, func_80A3E870,
};
*/
extern EnTest3_functions_80A4169C D_80A4169C[];

s32 func_80A3ECEC(EnTest3* this, GlobalContext* globalCtx) {

    return D_80A4169C[this->talkState->unk_00](this, globalCtx);
}

/*
static EnTest3_functions_80A4169C D_80A416C0[] = {
    func_80A3EAC4, func_80A3EAF8, func_80A3EBFC, func_80A3EC44,
    func_80A3EC30, func_80A3E9DC, func_80A3EB8C, func_80A3E97C,
};
*/
extern EnTest3_functions_80A4169C D_80A416C0[];

s32 func_80A3ED24(EnTest3* this, GlobalContext* globalCtx) {
    s32 index = D_80A416C0[this->talkState->unk_00](this, globalCtx);

    if (index != 0) {
        this->talkState = &this->talkState[index];
        return func_80A3ECEC(this, globalCtx);
    }

    return 0;
}

extern PlayerAgeProperties D_80A416E0;
/*
PlayerAgeProperties D_80A416E0 = {
    40.0f,
    60.0f,
    0.647059f,
    71.0f,
    50.0f,
    49.0f,
    39.0f,
    27.0f,
    19.0f,
    22.0f,
    32.4f,
    32.0f,
    48.0f,
    45.2941f,
    14.0f,
    12.0f,
    55.0f,
    { -24, 3565, 876 },
    {
        { -24, 3474, 862 },
        { -24, 4977, 937 },
        { 8, 4694, 380 },
        { 9, 6122, 359 },
    },
    {
        { -24, 4977, 0x03A9 },
        { -24, 6495, 0x03A9 },
        { 9, 6122, 359 },
        { 9, 7693, 380 },
    },
    {
        { 8, 4694, 380 },
        { 9, 6122, 359 },
        { -1592, 4694, 380 },
        { -1591, 6122, 359 },
    },
    0x20,
    0,
    22.0f,
    29.4343f,
    0x0400D128,
    0x0400D170,
    0x0400D1B8,
    0x0400D1F8,
    0x0400D200,
    { 0x0400D208, 0x0400D210, 0x0400DAB0, 0x0400DAB8 },
    { 0x0400DA90, 0x0400DA98 },
    { 0x0400D1D8, 0x0400D1E0 },
    { 0x0400D1F0, 0x0400D1E8 },
};
*/

extern u32 D_80A417BC[];
/*
u32 D_80A417BC[] = {
    0x00000000, 0x00080000, 0xFFFFFFFF, 0xFFFFFF40, 0xFFFFFF00, 0xFFFFFF00, 0x04000200, 0x00000000, 0x00000000,
};
*/

extern u32 D_80A417E0[];
/*
u32 D_80A417E0[] = {
    0x0000003F,
    0x00000F64,
};
*/

void EnTest3_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnTest3* this = THIS;
    s32 pad;
    Camera* camera;

    if (D_80A41D24) {
        Actor_MarkForDeath(&this->actor.actor);
        return;
    }

    D_80A41D24 = 1;
    this->actor.actor.room = -1;
    this->actor.unk_A86 = -1;
    this->actor.transformation = 4;
    this->actor.ageProperties = &D_80A416E0;
    this->actor.itemActionParam = 0;
    this->actor.heldItemId = 0;
    func_80123BD4(&this->actor.actor, 3);

    if (1) {}

    globalCtx->playerInit(&this->actor, globalCtx, &D_0600F7EC);

    Effect_Add(globalCtx, &this->actor.blureEffectIndex[0], 2, 0, 0, D_80A417BC);
    Effect_Add(globalCtx, &this->actor.blureEffectIndex[1], 2, 0, 0, D_80A417BC);
    Effect_Add(globalCtx, &this->actor.blureEffectIndex[2], 4, 0, 0, D_80A417E0);

    this->actor.maskObjectSegment = zelda_malloc(0x3800);

    globalCtx->func_18780(&this->actor, globalCtx);

    this->player = PLAYER;
    this->actor.giObjectSegment = this->player->giObjectSegment;
    this->actor.naviActor = this->player->naviActor;

    if ((CURRENT_DAY != 3) || (gSaveContext.weekEventReg[0x21] & 8) ||
        !(gSaveContext.weekEventReg[0x33] & 8)) {
        this->actor.currentMask = 5;
    }

    this->actor.prevMask = this->actor.currentMask;

    if (globalCtx->sceneNum == SCENE_SECOM) {
        this->camId = func_801694DC(globalCtx);
        camera = Play_GetCamera(globalCtx, this->camId);
        func_800DE0EC(camera, &this->actor.actor);
        Camera_SetFlags(camera, 64 | 1);
        func_80169590(globalCtx, this->camId, 1);
    }

    this->actor.actor.colChkInfo.cylRadius = 20;
    this->actor.actor.colChkInfo.cylHeight = 60;
    this->actor.actor.colChkInfo.health = 0xFF;

    if (((this->actor.actor.params >> 5) & 0xF) == 0) {
        func_80A3E7E0(this, func_80A40824);
    } else {
        func_80A3E7E0(this, func_80A40678);
    }
}

void EnTest3_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnTest3* this = THIS;

    Effect_Destroy(globalCtx, this->actor.blureEffectIndex[0]);
    Effect_Destroy(globalCtx, this->actor.blureEffectIndex[1]);
    Effect_Destroy(globalCtx, this->actor.blureEffectIndex[2]);

    Collider_DestroyCylinder(globalCtx, &this->actor.cylinder);
    Collider_DestroyCylinder(globalCtx, &this->actor.shieldCylinder);

    Collider_DestroyQuad(globalCtx, &this->actor.swordQuads[0]);
    Collider_DestroyQuad(globalCtx, &this->actor.swordQuads[1]);
    Collider_DestroyQuad(globalCtx, &this->actor.swordQuads[2]);

    zelda_free(this->actor.maskObjectSegment);

    func_800FE498();
}

extern struct_80A417E8 D_80A417E8[];
/*
struct_80A417E8 D_80A417E8[] = {
    { func_80A3F080, func_80A3F09C }, { func_80A40098, func_80A40230 }, { func_80A3F62C, func_80A3F73C },
    { func_80A3F8D4, func_80A3F9A4 }, { func_80A3F9E4, func_80A3FA58 }, { func_80A3FBCC, func_80A3FBE8 },
    { func_80A3FDE4, func_80A3FE20 }, { func_80A3FF10, func_80A3FFD0 },
};
*/

extern struct_80A417E8_arg2 D_80A41828[];
/*
struct_80A417E8_arg2 D_80A41828[] = {
    { 0, 0, 0 },  { 3, 14, 0 }, { 2, 15, 0 }, { 2, 15, 1 }, { 2, 15, 2 }, { 2, 1, 3 }, { 2, 14, 4 }, { 5, 1, 0 },
    { 7, 15, 0 }, { 6, 2, 0 },  { 4, 4, 0 },  { 1, 1, 0 },  { 1, 1, 0 },  { 1, 2, 0 }, { 1, 1, 0 },  { 1, 1, 0 },
    { 1, 2, 0 },  { 1, 3, 0 },  { 1, 1, 0 },  { 1, 2, 0 },  { 1, 1, 0 },  { 0, 0, 0 },
};
*/

extern TalkState D_80A41854[];
/*
TalkState D_80A41854[] = {
    { 0x04, 0x00, 0x2B25 },
};
*/

extern TalkState D_80A41858[];
/*
TalkState D_80A41858[] = {
    { 1, 0, 0x2969 }, { 3, 1, 0x296A }, { 1, 0, 0x296B }, { 5, 1, 0x0000 }, { 8, 0, 0x0000 },
};
*/

extern TalkState D_80A4186C[];
/*
TalkState D_80A4186C[] = {
    { 4, 0, 0x2976 },
};
*/

extern TalkState D_80A41870[];
/*
TalkState D_80A41870[] = {
    { 6, 0, 0x2977 },
    { 7, 10, 0x2978 },
    { 4, 1, 0x0000 },
};
*/

extern TalkState D_80A4187C[];
/*
TalkState D_80A4187C[] = {
    { 4, 0, 0x2968 },
};
*/

extern TalkState D_80A41880[];
/*
TalkState D_80A41880[] = {
    { 4, 0, 0x297A },
};
*/

extern TalkState D_80A41884[];
/*
TalkState D_80A41884[] = {
    { 1, 0, 0x145D }, { 1, 0, 0x145E }, { 5, 1, 0x145F }, { 1, 0, 0x145F }, { 5, 0, 0x0000 }, { 4, 0, 0x1460 },
};
*/

extern TalkState D_80A4189C[];
/*
TalkState D_80A4189C[] = {
    { 4, 0, 0x145C },
};
*/

extern TalkState D_80A418A0[];
/*
TalkState D_80A418A0[] = {
    { 4, 0, 0x2913 },
};
*/

s32 func_80A3F080(EnTest3* this, GlobalContext* globalCtx, struct_80A417E8_arg2* arg2, struct_80A417E8_arg3* arg3) {
    return 1;
}

s32 func_80A3F09C(EnTest3* this, GlobalContext* globalCtx) {
    this->actor.actor.draw = NULL;
    return 1;
}

void func_80A3F0B0(EnTest3* this, GlobalContext* globalCtx) {
    func_800BC154(globalCtx, &globalCtx->actorCtx, &this->player->actor, ACTORCAT_PLAYER);
    func_800BC154(globalCtx, &globalCtx->actorCtx, &this->actor.actor, ACTORCAT_NPC);

    this->player->stateFlags1 &= ~0x20;
}

void func_80A3F114(EnTest3* this, GlobalContext* globalCtx) {
    if (this->actor.unk_394 != 0) {
        globalCtx->startPlayerCutscene(globalCtx, &this->actor, 6);
    }
}

s32 func_80A3F15C(EnTest3* this, GlobalContext* globalCtx, struct_80A417E8_arg2* arg2) {
    s32 pathIndex = ABS_ALT(arg2->unk_01_0) - 1;

    if (pathIndex >= 0) {
        PathInfo* path = func_8013BB34(globalCtx, this->actor.actor.params & 0x1F, pathIndex);
        Vec3s* startPosP = Lib_SegmentedToVirtual(path->pos);
        Vec3s* nextPosP;
        Vec3f startPos;
        Vec3f nextPos;

        if (arg2->unk_01_0 > 0) {
            nextPosP = startPosP + 1;
        } else {
            startPosP += path->unk_00 - 1;
            nextPosP = startPosP - 1;
        }

        Math_Vec3s_ToVec3f(&startPos, startPosP);
        Math_Vec3s_ToVec3f(&nextPos, nextPosP);

        if (Math_Vec3f_DistXZ(&this->actor.actor.world.pos, &startPos) > 10.0f) {
            Math_Vec3f_Copy(&this->actor.actor.world.pos, &startPos);
            Math_Vec3f_Copy(&this->actor.actor.home.pos, &startPos);
            Math_Vec3f_Copy(&this->actor.actor.prevPos, &startPos);
            this->actor.currentYaw = Math_Vec3f_Yaw(&this->actor.actor.world.pos, &nextPos);

            if (arg2->unk_01_0 < 0) {
                this->actor.currentYaw += 0x8000;
            }

            this->actor.actor.shape.rot.y = this->actor.currentYaw;

            return 1;
        }
    }

    return 0;
}

Actor* func_80A3F2BC(GlobalContext* globalCtx, Actor* thisx, s32 actorId, s32 actorCat, f32 xzDist, f32 yDist) {
    Actor* curActor = globalCtx->actorCtx.actorList[actorCat].first;

    while (curActor != NULL) {
        if (actorId == curActor->id) {
            f32 dist = thisx->world.pos.y - curActor->world.pos.y;

            if ((fabsf(dist) < yDist) && (Actor_XZDistanceBetweenActors(thisx, curActor) < xzDist)) {
                return curActor;
            }
        }

        curActor = curActor->next;
    }

    return NULL;
}

s32 func_80A3F384(EnTest3* this, GlobalContext* globalCtx) {
    Player* player = PLAYER;
    EnDoor* doorActor =
        (EnDoor*)func_80A3F2BC(globalCtx, &this->actor.actor, ACTOR_EN_DOOR, ACTORCAT_DOOR, 55.0f, 20.0f);
    Vec3f dist;

    if (doorActor != NULL && doorActor->opening == 0) {
        if (player->doorType == 0 || &doorActor->actor != player->doorActor) {
            if (Actor_IsActorFacingActor(&this->actor.actor, &doorActor->actor, 0x3000)) {
                Actor_CalcOffsetOrientedToDrawRotation(&doorActor->actor, &dist, &this->actor.actor.world.pos);
                this->actor.doorType = 1;
                this->actor.doorDirection = (dist.z >= 0.0f) ? 1.0f : -1.0f;
                this->actor.doorActor = &doorActor->actor;
                this->actor.unk_A86 = -1;
                return 1;
            }
        }
    }

    return 0;
}


s32 func_80A3F4A4(GlobalContext *globalCtx) {
    return Player_GetMask(globalCtx) == PLAYER_MASK_NONE || Player_GetMask(globalCtx) == PLAYER_MASK_BUNNY_HOOD || Player_GetMask(globalCtx) == PLAYER_MASK_POSTMANS_HAT || Player_GetMask(globalCtx) == PLAYER_MASK_KEATON_MASK || Player_GetMask(globalCtx) == PLAYER_MASK_KAFEIS_MASK;
}

void func_80A3F534(EnTest3* this, GlobalContext* globalCtx) {
    if (!func_80A3F4A4(globalCtx)) {
        this->talkState = D_80A4187C;
    } else if (gSaveContext.weekEventReg[0x33] & 0x08) {
        this->talkState = D_80A41870;
    } else {
        this->talkState = D_80A41858;
    }

    this->actorCutsceneId = this->actor.actor.cutscene;
}


extern TalkState D_80A41898[];

void func_80A3F5A4(EnTest3 *this, GlobalContext *globalCtx) {
    if (!(gSaveContext.weekEventReg[0x33] & 8) || !func_80A3F4A4(globalCtx)) {
        this->talkState = D_80A4189C;
        D_80A41D5C = 0;
    } else if (D_80A41D5C != 0) {
        this->talkState = D_80A41898;
    } else {
        this->talkState = D_80A41884;
    }
    this->actorCutsceneId = this->actor.actor.cutscene;
}


extern TalkState* D_80A418A8[];
/*
TalkState* D_80A418A8[] = {
    D_80A41854, D_80A41858, D_80A41880, D_80A41884, D_80A418A0,
};
*/


s32 func_80A3F62C(EnTest3 *this, GlobalContext *globalCtx, struct_80A417E8_arg2 *arg2, struct_80A417E8_arg3 *arg3) {
    if (((func_80A3F15C(this, globalCtx, arg2) != 0 || this->schedule >= 8) && (arg2->unk_01_1 == 1 || arg2->unk_01_1 == 2)) || (arg2->unk_01_1 == 4)) {
        if (arg2->unk_01_1 == 4) {
            this->actor.actor.home.rot.y = 0x7FFF;
        } else {
            this->actor.actor.home.rot.y = this->actor.actor.shape.rot.y + 0x8000;
        }
        this->actor.stateFlags2 |= 0x40000;
        globalCtx->startPlayerCutscene(globalCtx, &this->actor, -1);
    }
    this->talkState = D_80A418A8[arg2->unk_01_1];
    return 1;
}



s32 func_80A3F73C(EnTest3 *this, GlobalContext *globalCtx) {
    if (func_800B84D0(&this->actor.actor, globalCtx) != 0) {
        func_80A3E7E0(this, func_80A4084C);
        this->actor.unk_730 = &PLAYER->actor;
        this->actor.stateFlags2 &= ~0x40000;
        D_80A41D5C = 1;
        if ((this->talkState->unk_00 == 4) && (gSaveContext.weekEventReg[0x33] & 8)) {
            func_80151BB4(globalCtx, 2);
        }
    } else {
        if ((globalCtx->actorCtx.unk5 & 0x10)) {
            globalCtx->actorCtx.unk5 &= ~0x10;
            this->actor.stateFlags2 &= ~0x40000;
            this->player->stateFlags1 |= 0x20;
            func_800BC154(globalCtx, &globalCtx->actorCtx, &this->player->actor, 4);
            func_800BC154(globalCtx, &globalCtx->actorCtx, &this->actor.actor, 2);
            ActorCutscene_SetReturnCamera(this->camId);
            globalCtx->startPlayerCutscene(globalCtx, &this->actor, 7);
        }
        func_800B863C(&this->actor.actor, globalCtx);
        if (this->schedule == 3) {
            func_80A3F534(this, globalCtx);
        } else if (this->schedule == 5) {
            func_80A3F5A4(this, globalCtx);
        }
        this->actor.actor.textId = this->talkState->textId;
        this->actor.actor.flags |= 9;
    }
    return 0;
}


s32 func_80A3F8D4(EnTest3 *this, GlobalContext *globalCtx, struct_80A417E8_arg2 *arg2, struct_80A417E8_arg3 *arg3) {
    Actor *phi_a1;

    func_80A3F15C(this, globalCtx, arg2);
    phi_a1 = func_80A3F2BC(globalCtx, &this->actor.actor, 0x1F2, 6, 100.0f, 20.0f);
    if ((phi_a1 != NULL) || (phi_a1 = func_80A3F2BC(globalCtx, &this->actor.actor, 0x1D5, 4, 100.0f, 20.0f)) != NULL) {
        this->actor.actor.home.rot.y = Actor_YawBetweenActors(&this->actor.actor, phi_a1);
    }
    globalCtx->startPlayerCutscene(globalCtx, &this->actor, 0x61);
    return 1;
}


s32 func_80A3F9A4(EnTest3* this, GlobalContext* globalCtx) {
    Math_ScaledStepToS(&this->actor.actor.shape.rot.y, this->actor.actor.home.rot.y, 800);
    this->actor.currentYaw = this->actor.actor.shape.rot.y;
    return 0;
}

s32 func_80A3F9E4(EnTest3* this, GlobalContext* globalCtx, struct_80A417E8_arg2* arg2, struct_80A417E8_arg3* arg3) {
    arg3->unk_04 = (gSaveContext.time - 0x3FFC) & 0xFFFF;
    arg3->unk_08 = (arg3->unk_04 + 0x46) & 0xFFFF;
    func_80A40098(this, globalCtx, arg2, arg3);

    if (this->actor.actor.xzDistToPlayer < 300.0f) {
        this->unk_D8A = -1;
    } else {
        this->unk_D8A = 0x78;
    }

    return 1;
}

#ifdef NON_MATCHING
s32 func_80A3FA58(EnTest3 *this, GlobalContext *globalCtx) {
    Player* player = PLAYER;
    struct_80A417E8_arg2 sp40;
    struct_80A417E8_arg3 sp30;

    if (player->stateFlags1 & 0x40) {
        return 0;
    } else {
        s32 phi_t0 = func_80A40230(this, globalCtx) != 0;

        if (this->unk_D8A > 0) {
            // This redundant variable seems to be neccesary
            s32 phi_t0_2 = phi_t0;

            this->unk_D8A--;

            if (phi_t0_2) {
                phi_t0_2 = false;
                if (this->actor.actor.xzDistToPlayer < 200.0f) {
                    phi_t0_2 = true;
                }
            }

            if (phi_t0_2 || this->unk_D8A <= 0) {

                func_80A3F114(this, globalCtx);
                sp40.unk_01_0 = 0x5;

                sp30.unk_04 = (u16)(gSaveContext.time - 0x3FFC);
                sp30.unk_04 = (sp30.unk_04 & 0xFFFF);
                sp30.unk_08 = (u16)(((phi_t0_2) ? 0x50 : 0x8C) + (u16)(sp30.unk_04));

                func_80A40098(this, globalCtx, &sp40, &sp30);
                this->unk_D8A = -0x28;
                return 0;
            } else if (this->unk_D8A == 0x5A) {
                globalCtx->startPlayerCutscene(globalCtx, &this->actor, 0x15);
            }
        } else {
            this->unk_D8A++;

            if (this->unk_D8A == 0) {
                gSaveContext.weekEventReg[0x33] &= (u8)~0x04;
                this->schedule = 0;
            }
        }
    }

    return 0;
}
#else
#pragma GLOBAL_ASM("./asm/non_matchings/overlays/ovl_En_Test3_0x80A3E7E0/func_80A3FA58.asm")
#endif

s32 func_80A3FBCC(EnTest3* this, GlobalContext* globalCtx, struct_80A417E8_arg2* arg2, struct_80A417E8_arg3* arg3) {
    return 1;
}

extern TalkState D_80A418A4[];
/*
TalkState D_80A418A4[] = {
    { 4, 0, 0x1465 },
};
*/

s32 func_80A3FBE8(EnTest3* this, GlobalContext* globalCtx) {
    if (D_80A41D20 == 0) {
        if (func_801690CC(globalCtx) == 0) {
            D_80A41D20 = 1;
            this->talkState = D_80A418A4;
            this->actorCutsceneId = this->actor.actor.cutscene;
            this->actor.actor.textId = D_80A418A4->textId;
        }
    } else if (D_80A41D20 == 1) {
        if (this->actorCutsceneId >= 0) {
            if (func_80A3E9DC(this, globalCtx)) {
                this->actorCutsceneId = -1;
                func_800FE484();
            }
        } else {
            if ((globalCtx->actorCtx.unk5 & 0x40) || (globalCtx->actorCtx.unk5 & 0x20)) {
                this->actorCutsceneId = ActorCutscene_GetAdditionalCutscene(this->actor.actor.cutscene);
                gSaveContext.weekEventReg[0x5A] |= 2;

                if (globalCtx->actorCtx.unk5 & 0x20) {
                    this->actorCutsceneId = ActorCutscene_GetAdditionalCutscene(this->actorCutsceneId);
                }

                func_801A89A8(0x100100FF);

                D_80A41D20 = 2;
            } else {
                func_80A3F73C(this, globalCtx);
            }
        }
    } else if (D_80A41D20 == 2) {
        if (func_80A3E9DC(this, globalCtx)) {
            ActorCutscene_SetReturnCamera(0);
            func_800FE498();

            if (gSaveContext.time > 0x4000) {
                //func_800FE658(fabsf((f32) (s16) ((s32) (0, gSaveContext.time) * -1)) / (0x10000 / (f32)0x5a0));
                func_800FE658(fabsf((s16)(-((void)0, gSaveContext.time))) / 45.511112f);
            }

            if (globalCtx->actorCtx.unk5 & 0x40) {
                gSaveContext.weekEventReg[0x33] |= 0x20;
                gSaveContext.weekEventReg[0x5A] &= 0xFD;
            }

            D_80A41D20 = 3;
        }
    }

    return 0;
}

s32 func_80A3FDE4(EnTest3* this, GlobalContext* globalCtx, struct_80A417E8_arg2* arg2, struct_80A417E8_arg3* arg3) {
    this->actorCutsceneId = ActorCutscene_GetAdditionalCutscene(this->actor.actor.cutscene);
    return 1;
}


s32 func_80A3FE20(EnTest3 *this, GlobalContext *globalCtx) {
    struct_80A417E8_arg2 sp2C;
    struct_80A417E8_arg3 sp1C;

    if (D_80A41D64 == 0) {
        if (func_80A3E9DC(this, globalCtx) != 0) {
            sp2C.unk_01_0 = 0x2;
            sp1C.unk_08 = (u16)(((u16)(gSaveContext.time - 0x3FFC)) + 0x3E8);
            sp1C.unk_04 = (u16)(gSaveContext.time - 0x3FFC);
            func_80A40098(this, globalCtx, &sp2C, &sp1C);
            D_80A41D64 = 1;

            return 0;
        }
    } else if (D_80A41D64 == 1) {
        func_80A40230(this, globalCtx);
    } else if (D_80A41D64 == 2) {
        ActorCutscene_Stop(this->actorCutsceneId);
        gSaveContext.weekEventReg[0x5A] |= 2;
        D_80A41D64 = 3;
    }
    return 0;
}

//Vec3f D_80A418BC[] = { -420.0f, 210.0f, -162.0f };
extern Vec3f D_80A418BC[];

#ifdef NON_MATCHING
// v0/v1 problems
s32 func_80A3FF10(EnTest3 *this, GlobalContext *globalCtx, struct_80A417E8_arg2 *arg2, struct_80A417E8_arg3 *arg3) {
    if (gSaveContext.weekEventReg[0x33] & 0x40) {
        D_80A41D68 = 2;
        Math_Vec3f_Copy(&this->actor.actor.world.pos, D_80A418BC);
        Math_Vec3f_Copy(&this->actor.actor.home.pos, D_80A418BC);
        this->actor.actor.home.rot.y = -0x2AAB;
        this->actor.actor.shape.rot.y = -0x2AAB;
        this->actor.currentYaw = -0x2AAB;
        return 1;
    } else {
        func_80A3F15C(this, globalCtx, arg2);
        this->actorCutsceneId = this->actor.actor.cutscene;
        if (globalCtx->roomCtx.currRoom.num == 2) {
            this->actorCutsceneId = ActorCutscene_GetAdditionalCutscene(this->actorCutsceneId);
        }
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("./asm/non_matchings/overlays/ovl_En_Test3_0x80A3E7E0/func_80A3FF10.asm")
#endif


s32 func_80A3FFD0(EnTest3 *this, GlobalContext *globalCtx) {
    if (D_80A41D68 == 0) {
        if ((func_801690CC(globalCtx) == 0) && (globalCtx->roomCtx.currRoom.num == 2)) {
            D_80A41D68 = 1;
        }
    } else if (D_80A41D68 == 1) {
        if (func_80A3E9DC(this, globalCtx) != 0) {
            D_80A41D68 = 2;
        }
    } else {
        gSaveContext.weekEventReg[0x33] |= 0x40;
        globalCtx->startPlayerCutscene(globalCtx, &this->actor, 0x6E);
    }
    return 0;
}

s32 func_80A40098(EnTest3 *this, GlobalContext *globalCtx, struct_80A417E8_arg2 *arg2, struct_80A417E8_arg3 *arg3) {
    u16 sp26 = gSaveContext.time - 0x3FFC;
    u16 phi_a0;

    func_80A3F15C(this, globalCtx, arg2);
    this->path = func_8013BB34(globalCtx, this->actor.actor.params & 0x1F, ABS_ALT(arg2->unk_01_0) - 1);

    if (this->schedule < 7 && this->schedule != 0 && this->unk_D80 >= 0) {
        phi_a0 = sp26;
    } else {
        phi_a0 = arg3->unk_06_half;
    }

    if (arg3->unk_08 < phi_a0) {
        this->unk_DA8 = (phi_a0 - arg3->unk_08) + 0xFFFF;
    } else {
        this->unk_DA8 = arg3->unk_08 - phi_a0;
    }

    this->unk_DB4 = sp26 - phi_a0;

    phi_a0 = this->path->unk_00 - 2;
    this->unk_DAC = this->unk_DA8 / phi_a0;
    this->unk_DB0 = (this->unk_DB4 / this->unk_DAC) + 2;

    this->actionId &= ~1;
    this->unk_D84 = 1.0f;

    return 1;
}


extern f32 D_80A41934;

#ifdef NON_MATCHING
// float regalloc
s32 func_80A40230(EnTest3 *this, GlobalContext *globalCtx) {
    UNK_TYPE1 pad[0x408];

    f32 *sp4C;
    s32 *sp48;
    s32 *sp44;

    s32 pad2;

    Vec3f sp94;
    Vec3f sp88;
    Vec3f sp7C;
    Vec3f sp70;

    s32 sp6C;
    s32 sp68;
    s32 pad3;
    f32 sp60;
    f32 sp5C;
    s32 sp58;

    sp6C = 0;
    sp68 = 0;
    sp58 = 0;

    func_8013AF00(&sp94, 3, this->path->unk_00 + 3);

    if ((this->actionId & 1) == 0) {
        sp70 = D_801D15B0;
        sp4C = &this->unk_DA4;
        sp48 = &this->unk_DB4;
        sp44 = &this->unk_DB0;
        func_8013B6B0(this->path, sp4C, sp48, this->unk_DAC, this->unk_DA8, sp44, &sp94, &sp70, this->unk_D80);
        func_8013B878(globalCtx, this->path, this->unk_DB0, &sp70);
        Math_Vec3f_Copy(&this->actor.actor.home.pos, &sp70);
        Math_Vec3f_Copy(&this->actor.actor.prevPos, &sp70);
        this->actor.actor.world.pos.y = sp70.y;
        this->actionId |= 1;
    } else {
        sp70 = this->unk_D98;
        sp44 = &this->unk_DB0;
        sp48 = &this->unk_DB4;
        sp4C = &this->unk_DA4;
    }

    this->actor.actor.world.pos.x = sp70.x;
    this->actor.actor.world.pos.z = sp70.z;

    if (globalCtx->unk_18B4A != 0) {
        sp6C = this->unk_DB4;
        sp68 = this->unk_DB0;
        sp70 = this->actor.actor.world.pos;
    }

    this->unk_D98 = D_801D15B0;

    if (func_8013B6B0(this->path, sp4C, sp48, this->unk_DAC, this->unk_DA8, sp44, &sp94, &this->unk_D98, this->unk_D80) != 0) {
        if (this->schedule == 0x14) {
            gSaveContext.weekEventReg[0x3A] &= (u8)~0x80;
            this->actor.actor.draw = NULL;
        } else if (this->schedule == 9) {
            D_80A41D64 = 2;
        }
        sp58 = 1;
    } else {
        sp88 = this->actor.actor.world.pos;
        sp7C = this->unk_D98;

        this->actor.actor.world.rot.y = Math_Vec3f_Yaw(&sp88, &sp7C);
    }

    if (globalCtx->unk_18B4A != 0) {
        this->unk_DB4 = sp6C;
        this->unk_DB0 = sp68;

        this->unk_D98 = sp70;
    }

    sp60 = this->actor.actor.world.pos.x;
    sp60 -= this->actor.actor.prevPos.x;

    sp5C = this->actor.actor.world.pos.z;
    sp5C -= this->actor.actor.prevPos.z;

    if (Math_StepToF(&this->unk_D84, 1.0f, 0.1f) == 0) {
        this->actor.actor.world.pos.x = this->actor.actor.prevPos.x + (sp60 *  this->unk_D84);
        this->actor.actor.world.pos.z = this->actor.actor.prevPos.z + (sp5C *  this->unk_D84);
    }

    Math_Vec3f_Copy(&D_80A41D50, &this->actor.actor.world.pos);
    this->actor.linearVelocity = sqrtf(SQ(this->actor.actor.world.pos.x - this->actor.actor.prevPos.x) + SQ(this->actor.actor.world.pos.z - this->actor.actor.prevPos.z));
    this->actor.linearVelocity *= 1.0f + (D_80A41934 * fabsf(Math_SinS(this->actor.unk_B6C)));

    D_80A41D40 = this->actor.linearVelocity * 10.0f + 20.0f;
    D_80A41D40 = CLAMP_MAX(D_80A41D40, 60.0f);

    D_80A41D44 = (s16) this->actor.actor.world.rot.y;
    this->actor.actor.world.pos.x = this->actor.actor.prevPos.x;
    this->actor.actor.world.pos.z = this->actor.actor.prevPos.z;

    if (func_80A3F384(this, globalCtx) == 0) {
        D_80A41D48 = 1;
    }

    return sp58;
}
#else
#pragma GLOBAL_ASM("./asm/non_matchings/overlays/ovl_En_Test3_0x80A3E7E0/func_80A40230.asm")
#endif


void func_80A40678(EnTest3* this, GlobalContext* globalCtx) {
    struct_80A417E8_arg2* temp_a2;
    struct_80A417E8_arg3 sp2C;
    u8 phi_v1;

    if (this->schedule == 0x14 || this->schedule == 0xA || this->schedule == 9) {
        this->unk_D80 = 3;
    } else {
        s32 phi_v0;

        if (func_801690CC(globalCtx) != 0) {
            phi_v0 = 0;
        } else {
            // This does a lw on gSaveContext.unk_14. TODO: Consider an union.
            phi_v0 = REG(15) + *(s32*)(&gSaveContext.unk_14);
        }
        this->unk_D80 = phi_v0;
    }

    if (func_80133038(globalCtx, D_80A41530, &sp2C) != 0) {
        phi_v1 = sp2C.unk_00;

        if (this->schedule != sp2C.unk_00) {
            temp_a2 = &D_80A41828[sp2C.unk_00];

            func_80A3F114(this, globalCtx);
            if (temp_a2->unk_00 != 4) {
                gSaveContext.weekEventReg[0x33] &= (u8)~0x04;
            }

            if (D_80A417E8[temp_a2->unk_00].unk_00(this, globalCtx, temp_a2, &sp2C) == 0) {
                return;
            }

            phi_v1 = sp2C.unk_00;
            if (sp2C.unk_00 == 6) {
                this->actor.actor.home.rot.y = 0x7FFF;
                this->actor.stateFlags2 |= 0x40000;
                globalCtx->startPlayerCutscene(globalCtx, (Player* ) this, -1);
                phi_v1 = sp2C.unk_00;
            }
        }
    } else {
        sp2C.unk_00 = 0;
        phi_v1 = 0;
    }

    this->schedule = phi_v1;
    temp_a2 = &D_80A41828[this->schedule];
    D_80A417E8[temp_a2->unk_00].unk_04(this, globalCtx);
}

void func_80A40824(EnTest3* this, GlobalContext* globalCtx) {
    this->talkState = D_80A41854;
    func_80A3F73C(this, globalCtx);
}


void func_80A4084C(EnTest3 *this, GlobalContext *globalCtx) {
    if (func_800B867C(&this->actor.actor, globalCtx) != 0) {
        if (this->talkState->unk_01 == 0 || func_80A3E80C(this, globalCtx, this->talkState->unk_01 - 1) == 0) {
            if (!((this->actor.actor.params >> 5) & 0xF)) {
                func_80A3E7E0(this, func_80A40824);
            } else {
                func_80A3E7E0(this, func_80A40678);
            }
            this->actor.unk_730 = NULL;
        }
    } else if (func_80A3ED24(this, globalCtx) != 0) {
        func_80A3E7E0(this, func_80A40908);
    }
}

extern f32 D_80A41938;
#ifdef NON_MATCHING
// rodata issues
void func_80A40908(EnTest3 *this, GlobalContext *globalCtx) {
    f32 temp_f0;

    if (func_800B84D0(&this->actor.actor, globalCtx) != 0) {
        func_80A3E7E0(this, func_80A4084C);
        this->actor.unk_730 = &PLAYER->actor;
        gSaveContext.weekEventReg[0x33] |= 8;
        func_80151BB4(globalCtx, 0x19);
        func_80151BB4(globalCtx, 2);
    } else {
        temp_f0 = D_80A41938;
        func_800B8500(&this->actor.actor, globalCtx, temp_f0, temp_f0, -1);
        this->talkState = D_80A4186C;
        this->actor.actor.textId = D_80A4186C->textId;
        this->actor.actor.flags |= 0x09;
    }
}
#else
#pragma GLOBAL_ASM("./asm/non_matchings/overlays/ovl_En_Test3_0x80A3E7E0/func_80A40908.asm")
#endif


// UpdateController?
void func_80A409D4(EnTest3 *this, GlobalContext *globalCtx) {
    if ((globalCtx->actorCtx.unk5 & 0x20) || (globalCtx->actorCtx.unk5 & 0x10)) {
        globalCtx->actorCtx.unk5 &= ~0x10;
        func_80A3F0B0(this, globalCtx);
        ActorCutscene_SetReturnCamera(0);
    } else {
        D_80A41D28 = globalCtx->state.input[0];
    }
}

void func_80A40A6C(EnTest3* this, GlobalContext* globalCtx) {
    gSaveContext.weekEventReg[0x40] |= 0x20;
}

#ifdef NON_MATCHING
// stack
void EnTest3_Update(Actor *thisx, GlobalContext *globalCtx) {
    s32 pad;
    EnTest3* this = THIS;

    D_80A41D28.rel.button = D_80A41D28.cur.button;
    D_80A41D28.cur.button = 0;
    D_80A41D28.rel.stick_x = 0;
    D_80A41D28.rel.stick_y = 0;
    globalCtx->actorCtx.unk5 &= ~0x80;
    this->actor.actor.draw = func_80A4129C;
    D_80A41D48 = 0;
    this->actor.actor.flags &= ~0x09;

    if ((func_800EE29C(globalCtx, 0x1FA) != 0) && (this->actor.actor.category != 2 || (!(globalCtx->actorCtx.unk5 & 0x20) && !(globalCtx->actorCtx.unk5 & 0x10)))) {
        if (this->actor.unk_394 != 5) {
            globalCtx->startPlayerCutscene(globalCtx, &this->actor, 5);
        }
        globalCtx->actorCtx.unk5 &= ~0x10;
    } else if (this->actor.actor.category == 2) {
        func_80A409D4(this, globalCtx);
    } else {
        if (globalCtx->startPlayerCutscene(globalCtx, &this->actor, 0) != 0) {
            if (this->schedule >= 7) {
                Vec3f sp34;
                s32 pad2;

                Math_Vec3f_Copy(&sp34, &this->actor.actor.world.pos);
                this->unk_D80 = 4;
                func_80A40230(this, globalCtx);
                Math_Vec3f_Copy(&this->actor.actor.world.pos, &sp34);
                D_80A41D48 = 0;
                this->unk_D84 = 0.0f;
            }
        } else {
            D_80A41D40 = 0.0f;
            D_80A41D44 = this->actor.actor.shape.rot.y;
            this->actionFunc(this, globalCtx);
            D_80A41D28.press.button = (D_80A41D28.rel.button ^ D_80A41D28.cur.button) & D_80A41D28.cur.button;
            func_800B6F20(globalCtx, &D_80A41D28, D_80A41D40, D_80A41D44);
        }
    }

    globalCtx->playerUpdate(&this->actor, globalCtx, &D_80A41D28);
    if (D_80A41D48 != 0) {
        this->actor.actor.world.pos.x = D_80A41D50.x;
        this->actor.actor.world.pos.z = D_80A41D50.z;
        this->actor.linearVelocity = 0.0f;
    }
}
#else
#pragma GLOBAL_ASM("./asm/non_matchings/overlays/ovl_En_Test3_0x80A3E7E0/EnTest3_Update.asm")
#endif

extern s32 D_80A418C8;
/*
s32 D_80A418C8 = 0;
*/

#ifdef NON_EQUIVALENT
s32 EnTest3_OverrideLimbDraw(GlobalContext *globalCtx, s32 limbIndex, Gfx **dList, Vec3f *pos, Vec3s *rot, Actor *thisx) {
    EnTest3* this = THIS;

    if (limbIndex == 1) {
        //D_80A41D6C = (Vec3f *) (actor + 0xBE0);
        D_80A41D6C = &this->actor.swordInfo[2].base;
        if (((this->actor.skelAnime.flags & 0x04) == 0) || (((this->actor.skelAnime.flags & 0x01) != 0))) {
            pos->x *= this->actor.ageProperties->unk_08;
            pos->z *= this->actor.ageProperties->unk_08;
        }

        if (((this->actor.skelAnime.flags & 0x04) == 0) || ((this->actor.skelAnime.flags & 0x02))) {
            pos->y *= this->actor.ageProperties->unk_08;
        }

        pos->y -= this->actor.unk_AB8;
        if (this->actor.unk_AAA != 0) {
            SysMatrix_InsertTranslation(pos->x, ((Math_CosS(this->actor.unk_AAA) - 1.0f) * 200.0f) + pos->y, pos->z, 1);
            SysMatrix_InsertXRotation_s(this->actor.unk_AAA, 1);
            SysMatrix_InsertRotation(rot->x, rot->y, rot->z, 1);
            func_80125318(pos, rot);
        }
    } else {
        if (*dList != NULL) {
            D_80A41D6C++;
        }

        if (D_80A418C8 != 0) {
            *dList = NULL;
        }

        if (limbIndex == 0xB) {
            rot->x += this->actor.unk_AAC.z;
            rot->y -= this->actor.unk_AAC.y;
            rot->z += this->actor.unk_AAC.x;
        } else if (limbIndex == 0xA) {
            if (this->actor.unk_AA8 != 0) {
                SysMatrix_InsertZRotation_s(0x44C, 1);
                Matrix_RotateY(this->actor.unk_AA8, 1);
            }

            if (this->actor.unk_AB2.y != 0) {
                Matrix_RotateY(this->actor.unk_AB2.y, 1);
            }
            SysMatrix_InsertXRotation_s(this->actor.unk_AB2.y, 1);

            if (this->actor.unk_AB2.z != 0) {
                SysMatrix_InsertZRotation_s(this->actor.unk_AB2.z, 1);
            }
        } else {
            func_80125500(this, limbIndex, pos, rot);
        }
    }
    return 0;
}
#else
s32 EnTest3_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx);
#pragma GLOBAL_ASM("./asm/non_matchings/overlays/ovl_En_Test3_0x80A3E7E0/EnTest3_OverrideLimbDraw.asm")
#endif

extern Vec3f D_80A418CC;
/*
static Vec3f D_80A418CC = { 1100.0f, -700.0f, 0.0f };
*/

// I'm not sure about the type 
extern LinkAnimationHeader D_0400D0A8;
extern LinkAnimationHeader D_0400D0C8;

extern Gfx D_0600EDD0[];
extern Gfx D_0600CB60[];
extern Gfx D_0A0004A0[];



#ifdef NON_EQUIVALENT
void EnTest3_PostLimbDraw(GlobalContext *globalCtx, s32 limbIndex, Gfx **dList1, Gfx **dList2, Vec3s *rot, Actor *thisx) {
    EnTest3* this = THIS;
    MtxF sp58;
    //void *sp54;
    Vec3s sp40;
    //s16 *sp38;
    //MtxF *sp1C;
    //Gfx *temp_a2;
    //Gfx *temp_v1;
    //Gfx *temp_v1_3;
    //Gfx *temp_v1_4;
    //GraphicsContext *temp_a0;
    //GraphicsContext *temp_a0_3;
    //GraphicsContext *temp_a0_4;
    //MtxF *temp_a0_2;
    //LinkAnimationHeader* temp_v0_3;
    u8 temp_v1_2;
    Actor *temp_v0;
    //Actor *temp_v0_2;

    //OPEN_DISPS(globalCtx->state.gfxCtx);

    if (*dList2 != NULL) {
        SysMatrix_GetStateTranslation(D_80A41D6C);
    }

    if (limbIndex == 0x10) {
        Math_Vec3f_Copy(&this->actor.leftHandWorld.pos, D_80A41D6C);
        //temp_a2 = *dList1;
        if (*dList1 != NULL) {
            func_80128640(globalCtx, &this->actor, *dList1, &this->actor.actor);
            //if ((this->actor.stateFlags3 * 4) < 0) {
            if ((this->actor.stateFlags3 & 0x020000000)) {
                OPEN_DISPS(globalCtx->state.gfxCtx);
                /*
                temp_a0 = globalCtx->state.gfxCtx;
                temp_v1 = temp_a0->polyOpa.p;
                temp_a0->polyOpa.p = temp_v1 + 8;
                temp_v1->words.w1 = 0x600EDD0;
                temp_v1->words.w0 = 0xDE000000;
                */
                gSPDisplayList(POLY_OPA_DISP++, D_0600EDD0);
                CLOSE_DISPS(globalCtx->state.gfxCtx);
            }
        }
        //temp_v0 = actor->unk34C;
        //temp_a0_2 = actor + 0xCC4;
        //if ((temp_v0 != 0) && ((actor->unkA6C & 0x800) != 0)) {
        temp_v0 = this->actor.leftHandActor;
        //temp_a0_2 = &this->actor.mf_CC4;
        if ((temp_v0 != NULL) && ((this->actor.stateFlags1 & 0x800) != 0)) {
            //sp54 = temp_v0;
            SysMatrix_CopyCurrentState((MtxF *) &sp58);
            func_8018219C((MtxF *) &sp58, (Vec3s *) &sp40, 0);
            temp_v0->world.pos.y = (this->actor.actor.shape.rot.y + this->actor.leftHandWorld.rot.y);
            //temp_v0->unkBE = (s16) temp_v0->unk32;
            temp_v0->shape.rot.y = temp_v0->world.rot.y;
            //return;
        } else {
            //sp1C = temp_a0_2;
            SysMatrix_CopyCurrentState(&this->actor.mf_CC4);
            //func_8018219C(temp_a0_2, actor + 0x35C, 0);
            func_8018219C(&this->actor.mf_CC4, &this->actor.leftHandWorld.rot, 0);
            func_80126B8C(globalCtx, &this->actor.actor);
            //return;
        }
        //return;
    } else if (limbIndex == 0x13) {
        //temp_v0_2 = actor->unk34C;
        //temp_v0_2 = this->actor.leftHandActor;
        if (this->actor.leftHandActor != NULL) {
            this->actor.leftHandActor->world.pos.x = ((this->actor.bodyPartsPos[0xF].x + this->actor.leftHandWorld.pos.x) * 0.5f);
            this->actor.leftHandActor->world.pos.y = ((this->actor.bodyPartsPos[0xF].y + this->actor.leftHandWorld.pos.y) * 0.5f);
            this->actor.leftHandActor->world.pos.z = ((this->actor.bodyPartsPos[0xF].z + this->actor.leftHandWorld.pos.z) * 0.5f);
            //return;
        }
        //return;
    } else if (limbIndex == 0xB) {
        Vec3f* focusPos;

        if (*dList1 != NULL) {
            temp_v1_2 = this->actor.currentMask;
            //if ((temp_v1_2 != 0) && ((this->actor.stateFlags2 << 7) >= 0)) {
            if ((temp_v1_2 != 0) && !(this->actor.stateFlags2 & 0x01000000)) {
                //temp_v0_3 = ;
                if ((this->actor.skelAnime.linkAnimetionSeg != &D_0400D0A8) && ((this->actor.skelAnime.linkAnimetionSeg != &D_0400D0C8) || (this->actor.skelAnime.animCurrentFrame >= 12.0f))) {
                    //sp38 = this->actor.unk_730;
                    if (func_80127438(globalCtx, &this->actor.actor, temp_v1_2, &this->actor.actor) != 0) {
                        OPEN_DISPS(globalCtx->state.gfxCtx);
                        /*
                        temp_a0_3 = globalCtx->state.gfxCtx;
                        temp_v1_3 = temp_a0_3->polyOpa.p;
                        temp_a0_3->polyOpa.p = temp_v1_3 + 8;
                        temp_v1_3->words.w1 = 0xA0004A0;
                        temp_v1_3->words.w0 = 0xDE000000;
                        */
                        gSPDisplayList(POLY_OPA_DISP++, D_0A0004A0);
                        CLOSE_DISPS(globalCtx->state.gfxCtx);
                    }
                }
            }
        }

        focusPos = &this->actor.actor.focus.pos;
        if ((this->actor.unk_730 != NULL) && (this->actor.unk_730->id == ACTOR_BG_IKNV_OBJ)) {
            Math_Vec3f_Copy(focusPos, &this->actor.unk_730->focus.pos);
            //return;
        } else {
            SysMatrix_MultiplyVector3fByState(&D_80A418CC, focusPos);
        }
        //return;
    } else if (limbIndex == 0x15) {
        //if ((D_80A41D60 != 0) || ((gSaveContext.weekEventReg[0x30] & 0x80) != 0) || (gSaveContext.inventory.items[*(u8 *)0x801C20A8] == 0x30) || (this->actor.unk_B2A == 0x6F)) {
        if ((D_80A41D60 != 0) || ((gSaveContext.weekEventReg[0x30] & 0x80) != 0) || (INV_CONTENT(0x30) == 0x30) || (this->actor.unk_B2A == 0x6F)) {
            D_80A41D60 = 1;
            //return;
        } else {
            OPEN_DISPS(globalCtx->state.gfxCtx);
            /*
            temp_a0_4 = globalCtx->state.gfxCtx;
            temp_v1_4 = temp_a0_4->polyOpa.p;
            temp_a0_4->polyOpa.p = temp_v1_4 + 8;
            temp_v1_4->words.w1 = 0x600CB60;
            temp_v1_4->words.w0 = 0xDE000000;
            */
            gSPDisplayList(POLY_OPA_DISP++, D_0600CB60);
            CLOSE_DISPS(globalCtx->state.gfxCtx);
        }
        //return;
    } else {
        func_80128B74(globalCtx, &this->actor.actor, limbIndex, &this->actor.actor);
    }

    //CLOSE_DISPS(globalCtx->state.gfxCtx);
}
#else
void EnTest3_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList1, Gfx** dList2, Vec3s* rot, Actor* actor);
#pragma GLOBAL_ASM("./asm/non_matchings/overlays/ovl_En_Test3_0x80A3E7E0/EnTest3_PostLimbDraw.asm")
#endif


extern void* D_80A418D8[];
/*
static void* eyeTextures[] = {
    0x06000DC0, 0x06003680, 0x06003E80, 0x06004680, 0x06004E80, 0x06005680, 0x06005E80, 0x06006680,
};
*/

extern void* D_80A418F8[];
/*
static void* mouthTextures[] = {
    0x060009C0,
    0x06006E80,
    0x06007280,
    0x06007680,
};
*/

extern FaceAnimKeyFrame D_80A41908[];
/*
static FaceAnimKeyFrame faceAnimInfo[] = {
    { 0, 0 }, { 1, 0 }, { 2, 0 }, { 0, 0 }, { 1, 0 }, { 2, 0 }, { 4, 0 }, { 5, 1 }, { 7, 2 }, { 0, 2 },
    { 3, 0 }, { 4, 0 }, { 2, 2 }, { 1, 1 }, { 0, 2 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 },
};
*/

// Draw
void func_80A4129C(Actor* thisx, GlobalContext* globalCtx) {
    EnTest3* this = THIS;
    s32 pad;
    s32 eyeTexId = (this->actor.skelAnime.limbDrawTbl[22].x & 0xF) - 1;
    s32 mouthTexId = ((this->actor.skelAnime.limbDrawTbl[22].x >> 4) & 0xF) - 1;
    Gfx* gfx;

    OPEN_DISPS(globalCtx->state.gfxCtx);

    func_8012C268(globalCtx);

    if (this->actor.invincibilityTimer > 0) {
        s32 lodFrac;

        this->actor.unk_B5F += CLAMP(50 - this->actor.invincibilityTimer, 8, 40);
        lodFrac = 4000 - (s32)(Math_CosS(this->actor.unk_B5F << 8) * 2000.0f);
        POLY_OPA_DISP = Gfx_SetFog(POLY_OPA_DISP, 255, 0, 0, 0, 0, lodFrac);
    }

    func_800B8050(thisx, globalCtx, 0);
    D_80A418C8 = 0;

    if (this->actor.stateFlags1 & 0x100000) {
        Vec3f cameraPos;

        SkinMatrix_Vec3fMtxFMultXYZ(&globalCtx->projectionMatrix, &this->actor.actor.focus.pos, &cameraPos);

        if (cameraPos.z < -4.0f) {
            D_80A418C8 = 1;
        }
    }

    gfx = POLY_OPA_DISP;

    if (eyeTexId < 0) {
        eyeTexId = D_80A41908[thisx->shape.face].eyeTexId;
    }

    gSPSegment(&gfx[0], 0x08, Lib_SegmentedToVirtual(D_80A418D8[eyeTexId]));

    if (mouthTexId < 0) {
        mouthTexId = D_80A41908[this->actor.actor.shape.face].mouthTexId;
    }

    gSPSegment(&gfx[1], 0x09, Lib_SegmentedToVirtual(D_80A418F8[mouthTexId]));

    POLY_OPA_DISP = &gfx[2];

    SkelAnime_LodDrawSV(globalCtx, this->actor.skelAnime.skeleton, this->actor.skelAnime.limbDrawTbl,
                        this->actor.skelAnime.dListCount, EnTest3_OverrideLimbDraw, EnTest3_PostLimbDraw, &this->actor.actor, 0);

    if (this->actor.invincibilityTimer > 0) {
        POLY_OPA_DISP = func_801660B8(globalCtx, POLY_OPA_DISP);
    }

    if (this->actor.unk_B2A != 0) {
        func_8012697C(globalCtx, &this->actor);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx);
}
