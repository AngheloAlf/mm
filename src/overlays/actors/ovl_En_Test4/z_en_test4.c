/*
 * File: z_en_test4.c
 * Overlay: ovl_En_Test4
 * Description: Three-Day Events: day-night transitions, shrink screen before next day,
 * play bell sounds, triggers clocktown midnight cutscene, controls weather events,
 * sets skybox star count
 */

#include "z_en_test4.h"

#include "z64horse.h"

#include "overlays/gamestates/ovl_daytelop/z_daytelop.h"
#include "overlays/actors/ovl_En_Horse/z_en_horse.h"

#define FLAGS (ACTOR_FLAG_UPDATE_CULLING_DISABLED | ACTOR_FLAG_DRAW_CULLING_DISABLED | ACTOR_FLAG_FREEZE_EXCEPTION)

void EnTest4_Init(Actor* thisx, PlayState* play);
void EnTest4_Destroy(Actor* thisx, PlayState* play);
void EnTest4_Update(Actor* thisx, PlayState* play);

void EnTest4_HandleEvents(EnTest4* this, PlayState* play);
void EnTest4_HandleCutscene(EnTest4* this, PlayState* play);

ActorProfile En_Test4_Profile = {
    /**/ ACTOR_EN_TEST4,
    /**/ ACTORCAT_SWITCH,
    /**/ FLAGS,
    /**/ GAMEPLAY_KEEP,
    /**/ sizeof(EnTest4),
    /**/ EnTest4_Init,
    /**/ EnTest4_Destroy,
    /**/ EnTest4_Update,
    /**/ NULL,
};

static s32 sIsLoaded = false;

static s16 sCsIdList[THREEDAY_DAYTIME_MAX];
static s16 sCurCsId;

#if MM_VERSION >= N64_US
/**
 * Handles the transition from day-night and night-day.
 * This does not handle DayTelop transitions.
 * Only differs from `EnTest4_HandleDayNightSwap` with an extra telescope check when turning day without a cutscene.
 */
void EnTest4_HandleDayNightSwapFromInit(EnTest4* this, PlayState* play) {
    // "Night of ..."
    static s16 sNightOfTextIds[] = { 0x1BB4, 0x1BB5, 0x1BB6 };
    // "Dawn of ..." (Note: first two message are the same)
    static s16 sDawnOfTextIds[] = { 0x1BB2, 0x1BB2, 0x1BB3 };

    if (this->daytimeIndex != THREEDAY_DAYTIME_NIGHT) {
        // Previously day, turning night
        Message_DisplaySceneTitleCard(play, sNightOfTextIds[CURRENT_DAY - 1]);
    } else if ((sCsIdList[this->daytimeIndex] <= CS_ID_NONE) || (play->actorCtx.flags & ACTORCTX_FLAG_TELESCOPE_ON)) {
        // Previously night, turning day, without a cutscene
        if (play->actorCtx.flags & ACTORCTX_FLAG_TELESCOPE_ON) {
            Sram_IncrementDay();
            gSaveContext.save.time = CLOCK_TIME(6, 0);
            Message_DisplaySceneTitleCard(play, sDawnOfTextIds[CURRENT_DAY - 1]);
        } else {
            this->daytimeIndex = THREEDAY_DAYTIME_NIGHT;
            gSaveContext.save.time += CLOCK_TIME_MINUTE;
            this->prevTime = CURRENT_TIME;
        }

        Interface_NewDay(play, CURRENT_DAY);
        gSceneSeqState = SCENESEQ_MORNING;
        Environment_PlaySceneSequence(play);
        Environment_NewDay(&play->envCtx);
        this->actionFunc = EnTest4_HandleEvents;
    }

    if (gSaveContext.cutsceneTrigger == 0) {
        // No scripted cutscene
        if ((sCsIdList[this->daytimeIndex] > CS_ID_NONE) && !(play->actorCtx.flags & ACTORCTX_FLAG_TELESCOPE_ON)) {
            // Day-Night transition cutscene
            this->actionFunc = EnTest4_HandleCutscene;
            sCurCsId = sCsIdList[this->daytimeIndex];
            this->transitionCsTimer = 0;
            SET_EVENTINF(EVENTINF_17);
        } else if (this->daytimeIndex == THREEDAY_DAYTIME_NIGHT) {
            // Previously night, turning day, without cutscene
            Audio_PlaySfx(NA_SE_EV_CHICKEN_CRY_M);
        } else {
            // Previously day, turning night, without cutscene
            Audio_PlaySfx_2(NA_SE_EV_DOG_CRY_EVENING);
        }
    } else {
        // In a scripted cutscene
        this->actionFunc = EnTest4_HandleEvents;
        if (this->daytimeIndex == THREEDAY_DAYTIME_NIGHT) {
            this->daytimeIndex = THREEDAY_DAYTIME_DAY;
        } else {
            this->daytimeIndex = THREEDAY_DAYTIME_NIGHT;
        }

        gSaveContext.save.time += CLOCK_TIME_MINUTE;
        this->prevTime = CURRENT_TIME;
    }
}
#endif

#if MM_VERSION < N64_US
const char RO_STR_80A46240_unknown[] =
    "framescale_scale=%f  time_change_event_ID=%d, TELESCOPE=%d, Day_Of_The_Week=%d, zelda_time=%x(%x)->  ";
const char RO_STR_80A462A8_unknown[] = "framescale_scale=%f\n";

// "Player & Enemy Stop Player & Enemy Stop Player & Enemy Stop\n"
const char RO_STR_80A462C0_unknown[] = "プレイヤー＆敵停止 プレイヤー＆敵停止 プレイヤー＆敵停止\n";

// "Check the screen scale!!!!!!!!!!!!!!!\n"
const char RO_STR_80A462FC_unknown[] = "画面スケールチェック！！！！！！！！！！！！！！！\n";

const char RO_STR_80A46330_unknown[] =
    "framescale_flag=%d  framescale_scale=%d  time_change_event_ID=%d  notice_time=%x\n";

// "Check the screen scale!!!!!!!!!!!!!!!\n"
const char RO_STR_80A46384_unknown[] = "画面スケールチェック！！！！！！！！！！！！！！！\n";

const char RO_STR_80A463B8_unknown[] = "framescale_flag=%d  framescale_scale=%d\n";
const char RO_STR_80A463E4_unknown[] = "\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n";
const char RO_STR_80A4640C_unknown[] = "zelda_time=%x  check_time=%x  old_time=%x\n";
const char RO_STR_80A46438_unknown[] = "now_time_dist=%x  old_time_dist=%x  check_time_ID=%x\n";
const char RO_STR_80A46470_unknown[] = "↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑\n\n";

// "To the weekend demo To the weekend demo To the weekend demo\n"
const char RO_STR_80A46498_unknown[] = "週末デモへ 週末デモへ 週末デモへ\n";
const char RO_STR_80A464BC_unknown[] = "週末デモへ 週末デモへ 週末デモへ\n";
const char RO_STR_80A464E0_unknown[] = "週末デモへ 週末デモへ 週末デモへ\n";
const char RO_STR_80A46504_unknown[] = "週末デモへ 週末デモへ 週末デモへ\n";
const char RO_STR_80A46528_unknown[] = "週末デモへ 週末デモへ 週末デモへ\n";
const char RO_STR_80A4654C_unknown[] = "週末デモへ 週末デモへ 週末デモへ\n";

// "Player & Enemy Stop  time_change_event_ID[%d]=%d\n"
const char RO_STR_80A46570_unknown[] = "プレイヤー＆敵停止  time_change_event_ID[%d]=%d\n";

// "Next check time set time_change_event_ID[%d]=%d\n"
const char RO_STR_80A465A4_unknown[] = "次のチェック時刻セットtime_change_event_ID[%d]=%d\n";

// "last day last day last day last day last day last day last day\n"
const char RO_STR_80A465D8_unknown[] = "最後の日 最後の日 最後の日 最後の日 最後の日 最後の日 最後の日\n";

const char RO_STR_80A46618_unknown[] = "notice_time=%x(%x)  scene_data_ID=%d(%d)\n";

// "Clock Tower Transformation Demo  Clock Tower Transformation Demo  Clock Tower Transformation Demo"
const char RO_STR_80A46644_unknown[] = "時計塔変形デモへ 時計塔変形デモへ 時計塔変形デモへ\n";

const char RO_STR_80A46678_unknown[] = "!!!!!!!!!  notice_time=%x\n";

// "Bell sound   this->notice_time = %x\n"
const char RO_STR_80A46694_unknown[] = "鐘の音   this->notice_time = %x\n";
const char RO_STR_80A466B8_unknown[] = "=======\n";
const char RO_STR_80A466C4_unknown[] = "=======\n";
const char RO_STR_80A466D0_unknown[] = "=======\n";
const char RO_STR_80A466DC_unknown[] = "=======\n";

// "Next check time set  zelda_time=%x\n"
const char RO_STR_80A466E8_unknown[] = "次のチェック時刻セット  zelda_time=%x\n";

const char RO_STR_80A46710_unknown[] = "=======\n";
const char RO_STR_80A4671C_unknown[] = "=======\n";
const char RO_STR_80A46728_unknown[] = "=======\n";
const char RO_STR_80A46734_unknown[] = "=======\n";
#endif

/**
 * Handles the transition from day-night and night-day.
 * This does not handle DayTelop transitions.
 */
void EnTest4_HandleDayNightSwap(EnTest4* this, PlayState* play) {
    // "Night of ..."
    static s16 sNightOfTextIds[] = { 0x1BB4, 0x1BB5, 0x1BB6 };
    // "Dawn of ..." (Note: first two message are the same)
    static s16 sDawnOfTextIds[] = { 0x1BB2, 0x1BB2, 0x1BB3 };

    if (this->daytimeIndex != THREEDAY_DAYTIME_NIGHT) {
        // Previously day, turning night
        Message_DisplaySceneTitleCard(play, sNightOfTextIds[CURRENT_DAY - 1]);
    } else if ((sCsIdList[this->daytimeIndex] <= CS_ID_NONE) || (play->actorCtx.flags & ACTORCTX_FLAG_TELESCOPE_ON)) {
        // Previously night, turning day, without a cutscene
        Sram_IncrementDay();
        gSaveContext.save.time = CLOCK_TIME(6, 0);
        Interface_NewDay(play, CURRENT_DAY);
        Message_DisplaySceneTitleCard(play, sDawnOfTextIds[CURRENT_DAY - 1]);
        gSceneSeqState = SCENESEQ_MORNING;
        Environment_PlaySceneSequence(play);
        Environment_NewDay(&play->envCtx);
        this->actionFunc = EnTest4_HandleEvents;
    }

    if (gSaveContext.cutsceneTrigger == 0) {
        // No scripted cutscene
        if ((sCsIdList[this->daytimeIndex] > CS_ID_NONE) && !(play->actorCtx.flags & ACTORCTX_FLAG_TELESCOPE_ON)) {
            // Day-Night transition cutscene
            this->actionFunc = EnTest4_HandleCutscene;
            sCurCsId = sCsIdList[this->daytimeIndex];
            this->transitionCsTimer = 0;
            SET_EVENTINF(EVENTINF_17);
        } else if (this->daytimeIndex == THREEDAY_DAYTIME_NIGHT) {
            // Previously night, turning day, without cutscene
            Audio_PlaySfx(NA_SE_EV_CHICKEN_CRY_M);
        } else {
            // Previously day, turning night, without cutscene
            Audio_PlaySfx_2(NA_SE_EV_DOG_CRY_EVENING);
        }
    } else {
        // In a scripted cutscene
        this->actionFunc = EnTest4_HandleEvents;
        if (this->daytimeIndex == THREEDAY_DAYTIME_NIGHT) {
            this->daytimeIndex = THREEDAY_DAYTIME_DAY;
        } else {
            this->daytimeIndex = THREEDAY_DAYTIME_NIGHT;
        }

        gSaveContext.save.time += CLOCK_TIME_MINUTE;
        this->prevTime = CURRENT_TIME;
    }
}

/**
 * Get the next bell time on Day 3
 */
void EnTest4_GetBellTimeOnDay3(EnTest4* this) {
    if ((CURRENT_TIME >= CLOCK_TIME(6, 0)) && (CURRENT_TIME <= CLOCK_TIME(18, 0))) {
        if (CURRENT_TIME < CLOCK_TIME(17, 30)) {
            this->nextBellTime = CLOCK_TIME(17, 30);
        } else if (CURRENT_TIME < CLOCK_TIME(17, 36)) {
            this->nextBellTime = CLOCK_TIME(17, 36);
        } else if (CURRENT_TIME < CLOCK_TIME(17, 42)) {
            this->nextBellTime = CLOCK_TIME(17, 42);
        } else if (CURRENT_TIME < CLOCK_TIME(17, 48)) {
            this->nextBellTime = CLOCK_TIME(17, 48);
        } else if (CURRENT_TIME < CLOCK_TIME(17, 54)) {
            this->nextBellTime = CLOCK_TIME(17, 54);
        } else {
            this->nextBellTime = CLOCK_TIME(0, 0);
        }
    } else if (CURRENT_TIME > CLOCK_TIME(6, 0)) {
        this->nextBellTime = CLOCK_TIME(0, 0);
    } else if (CURRENT_TIME < CLOCK_TIME(0, 10)) {
        this->nextBellTime = CLOCK_TIME(0, 10);
    } else if (CURRENT_TIME < CLOCK_TIME(0, 20)) {
        this->nextBellTime = CLOCK_TIME(0, 20);
    } else if (CURRENT_TIME < CLOCK_TIME(0, 30)) {
        this->nextBellTime = CLOCK_TIME(0, 30);
    } else if (CURRENT_TIME < CLOCK_TIME(0, 40)) {
        this->nextBellTime = CLOCK_TIME(0, 40);
    } else if (CURRENT_TIME < CLOCK_TIME(0, 50)) {
        this->nextBellTime = CLOCK_TIME(0, 50);
    } else if (CURRENT_TIME < CLOCK_TIME(1, 0)) {
        this->nextBellTime = CLOCK_TIME(1, 0);
    } else if (CURRENT_TIME < CLOCK_TIME(1, 10)) {
        this->nextBellTime = CLOCK_TIME(1, 10);
    } else if (CURRENT_TIME < CLOCK_TIME(1, 20)) {
        this->nextBellTime = CLOCK_TIME(1, 20);
    } else if (CURRENT_TIME < CLOCK_TIME(1, 30) - 1) {
        this->nextBellTime = CLOCK_TIME(1, 30) - 1;
    } else if (CURRENT_TIME < CLOCK_TIME(1, 40) - 1) {
        this->nextBellTime = CLOCK_TIME(1, 40) - 1;
    } else if (CURRENT_TIME < CLOCK_TIME(1, 50) - 1) {
        this->nextBellTime = CLOCK_TIME(1, 50) - 1;
    } else if (CURRENT_TIME < CLOCK_TIME(2, 0)) {
        this->nextBellTime = CLOCK_TIME(2, 0);
    } else if (CURRENT_TIME < CLOCK_TIME(2, 10)) {
        this->nextBellTime = CLOCK_TIME(2, 10);
    } else if (CURRENT_TIME < CLOCK_TIME(2, 20)) {
        this->nextBellTime = CLOCK_TIME(2, 20);
    } else if (CURRENT_TIME < CLOCK_TIME(2, 30)) {
        this->nextBellTime = CLOCK_TIME(2, 30);
    } else if (CURRENT_TIME < CLOCK_TIME(2, 40)) {
        this->nextBellTime = CLOCK_TIME(2, 40);
    } else if (CURRENT_TIME < CLOCK_TIME(2, 50)) {
        this->nextBellTime = CLOCK_TIME(2, 50);
    } else if (CURRENT_TIME < CLOCK_TIME(3, 0)) {
        this->nextBellTime = CLOCK_TIME(3, 0);
    } else if (CURRENT_TIME < CLOCK_TIME(3, 10)) {
        this->nextBellTime = CLOCK_TIME(3, 10);
    } else if (CURRENT_TIME < CLOCK_TIME(3, 20)) {
        this->nextBellTime = CLOCK_TIME(3, 20);
    } else if (CURRENT_TIME < CLOCK_TIME(3, 30)) {
        this->nextBellTime = CLOCK_TIME(3, 30);
    } else if (CURRENT_TIME < CLOCK_TIME(3, 40)) {
        this->nextBellTime = CLOCK_TIME(3, 40);
    } else if (CURRENT_TIME < CLOCK_TIME(3, 50)) {
        this->nextBellTime = CLOCK_TIME(3, 50);
    } else if (CURRENT_TIME < CLOCK_TIME(4, 0)) {
        this->nextBellTime = CLOCK_TIME(4, 0);
    } else if (CURRENT_TIME < CLOCK_TIME(4, 10)) {
        this->nextBellTime = CLOCK_TIME(4, 10);
    } else if (CURRENT_TIME < CLOCK_TIME(4, 20)) {
        this->nextBellTime = CLOCK_TIME(4, 20);
    } else if (CURRENT_TIME < CLOCK_TIME(4, 30) - 1) {
        this->nextBellTime = CLOCK_TIME(4, 30) - 1;
    } else if (CURRENT_TIME < CLOCK_TIME(4, 40) - 1) {
        this->nextBellTime = CLOCK_TIME(4, 40) - 1;
    } else if (CURRENT_TIME < CLOCK_TIME(4, 50) - 1) {
        this->nextBellTime = CLOCK_TIME(4, 50) - 1;
    } else if (CURRENT_TIME < CLOCK_TIME(5, 0)) {
        this->nextBellTime = CLOCK_TIME(5, 0);
    } else if (CURRENT_TIME < CLOCK_TIME(5, 5)) {
        this->nextBellTime = CLOCK_TIME(5, 5);
    } else if (CURRENT_TIME < CLOCK_TIME(5, 10)) {
        this->nextBellTime = CLOCK_TIME(5, 10);
    } else if (CURRENT_TIME < CLOCK_TIME(5, 15) - 1) {
        this->nextBellTime = CLOCK_TIME(5, 15) - 1;
    } else if (CURRENT_TIME < CLOCK_TIME(5, 20)) {
        this->nextBellTime = CLOCK_TIME(5, 20);
    } else if (CURRENT_TIME < CLOCK_TIME(5, 25) - 1) {
        this->nextBellTime = CLOCK_TIME(5, 25) - 1;
    } else if (CURRENT_TIME < CLOCK_TIME(5, 30)) {
        this->nextBellTime = CLOCK_TIME(5, 30);
    } else if (CURRENT_TIME < CLOCK_TIME(5, 33) - 1) {
        this->nextBellTime = CLOCK_TIME(5, 33) - 1;
    } else if (CURRENT_TIME < CLOCK_TIME(5, 36)) {
        this->nextBellTime = CLOCK_TIME(5, 36);
    } else if (CURRENT_TIME < CLOCK_TIME(5, 39) - 1) {
        this->nextBellTime = CLOCK_TIME(5, 39) - 1;
    } else if (CURRENT_TIME < CLOCK_TIME(5, 42)) {
        this->nextBellTime = CLOCK_TIME(5, 42);
    } else if (CURRENT_TIME < CLOCK_TIME(5, 45)) {
        this->nextBellTime = CLOCK_TIME(5, 45);
    } else if (CURRENT_TIME < CLOCK_TIME(5, 48)) {
        this->nextBellTime = CLOCK_TIME(5, 48);
    } else if (CURRENT_TIME < CLOCK_TIME(5, 51)) {
        this->nextBellTime = CLOCK_TIME(5, 51);
    } else if (CURRENT_TIME < CLOCK_TIME(5, 54)) {
        this->nextBellTime = CLOCK_TIME(5, 54);
    } else if (CURRENT_TIME < CLOCK_TIME(5, 57)) {
        this->nextBellTime = CLOCK_TIME(5, 57);
    } else if (CURRENT_TIME < CLOCK_TIME(6, 0)) {
        this->nextBellTime = CLOCK_TIME(6, 0);
    }
}

#if MM_VERSION >= N64_US
#define SCREEN_SCALE_FACTOR 50.0f
#else
#define SCREEN_SCALE_FACTOR 100.0f
#endif

/**
 * Get the next bell time and shrinks screen near the end of the day on days 1 and 2
 */
void EnTest4_GetBellTimeAndShrinkScreenBeforeDay3(EnTest4* this, PlayState* play) {
    gSaveContext.screenScale = 1000.0f;

    if ((CURRENT_TIME >= CLOCK_TIME(6, 0)) && (CURRENT_TIME < CLOCK_TIME(18, 0))) {
        if (CURRENT_TIME < CLOCK_TIME(17, 30)) {
            this->nextBellTime = CLOCK_TIME(17, 30);
        } else if (CURRENT_TIME < CLOCK_TIME(17, 36)) {
            this->nextBellTime = CLOCK_TIME(17, 36);
        } else if (CURRENT_TIME < CLOCK_TIME(17, 42)) {
            this->nextBellTime = CLOCK_TIME(17, 42);
        } else if (CURRENT_TIME < CLOCK_TIME(17, 48)) {
            this->nextBellTime = CLOCK_TIME(17, 48);
        } else if (CURRENT_TIME < CLOCK_TIME(17, 54)) {
            this->nextBellTime = CLOCK_TIME(17, 54);
        } else {
            this->nextBellTime = CLOCK_TIME(5, 30);
        }
    } else {
        if (CURRENT_TIME < CLOCK_TIME(5, 30)) {
            this->nextBellTime = CLOCK_TIME(5, 30);
        } else if (CURRENT_TIME < CLOCK_TIME(5, 36)) {
            this->nextBellTime = CLOCK_TIME(5, 36);
        } else if (CURRENT_TIME < CLOCK_TIME(5, 42)) {
            this->nextBellTime = CLOCK_TIME(5, 42);
            gSaveContext.screenScale -= 1 * SCREEN_SCALE_FACTOR;
        } else if (CURRENT_TIME < CLOCK_TIME(5, 48)) {
            this->nextBellTime = CLOCK_TIME(5, 48);
            gSaveContext.screenScale -= 2 * SCREEN_SCALE_FACTOR;
        } else if (CURRENT_TIME < CLOCK_TIME(5, 54)) {
            this->nextBellTime = CLOCK_TIME(5, 54);
            gSaveContext.screenScale -= 3 * SCREEN_SCALE_FACTOR;
        } else if (CURRENT_TIME < CLOCK_TIME(6, 0)) {
            this->nextBellTime = CLOCK_TIME(17, 30);
            gSaveContext.screenScale -= 4 * SCREEN_SCALE_FACTOR;
        } else {
            this->nextBellTime = CLOCK_TIME(17, 30);
        }

        if ((sCsIdList[this->daytimeIndex] <= CS_ID_NONE) || (play->actorCtx.flags & ACTORCTX_FLAG_TELESCOPE_ON) ||
            (CURRENT_DAY == 3) || (CURRENT_TIME >= CLOCK_TIME(17, 0))) {
            gSaveContext.screenScale = 1000.0f;
        }
        if (gSaveContext.screenScale != 1000.0f) {
            gSaveContext.screenScaleFlag = true;
        }
    }
}

void EnTest4_Init(Actor* thisx, PlayState* play) {
    s32 eventDayCount;
    EnTest4* this = (EnTest4*)thisx;
    Player* player = GET_PLAYER(play);
    s8 csId = this->actor.csId;

    sCsIdList[THREEDAY_DAYTIME_NIGHT] = csId;
    if (csId > CS_ID_NONE) {
        CutsceneEntry* csEntry = CutsceneManager_GetCutsceneEntry(sCsIdList[THREEDAY_DAYTIME_NIGHT]);

        SET_EVENTINF(EVENTINF_HAS_DAYTIME_TRANSITION_CS);
        sCsIdList[THREEDAY_DAYTIME_DAY] = csEntry->additionalCsId;
    } else {
        CLEAR_EVENTINF(EVENTINF_HAS_DAYTIME_TRANSITION_CS);
        sCsIdList[THREEDAY_DAYTIME_DAY] = sCsIdList[THREEDAY_DAYTIME_NIGHT];
    }

    if (sIsLoaded
#if MM_VERSION >= N64_US
        || CHECK_EVENTINF(EVENTINF_TRIGGER_DAYTELOP)
#endif
    ) {

#if MM_VERSION < N64_US
        //! FAKE
        if (((&gSaveContext.save) && (&gSaveContext.save)) && (&gSaveContext.save)) {}
#endif
        Actor_Kill(&this->actor);
    } else {
        sIsLoaded = true;
        this->actor.room = -1;
        gSaveContext.screenScaleFlag = false;
        gSaveContext.screenScale = 1000.0f;

        if (CURRENT_DAY == 0) {
            if (CURRENT_TIME < CLOCK_TIME(6, 1)) {
                gSaveContext.save.time = CLOCK_TIME(6, 0);
                gSaveContext.gameMode = GAMEMODE_NORMAL;
                STOP_GAMESTATE(&play->state);
                SET_NEXT_GAMESTATE(&play->state, DayTelop_Init, sizeof(DayTelopState));
                this->daytimeIndex = THREEDAY_DAYTIME_DAY;
                gSaveContext.save.time = CLOCK_TIME(6, 0);
                Actor_Kill(&this->actor);
            } else {
                gSaveContext.save.day = 1;
                eventDayCount = gSaveContext.save.day;
                gSaveContext.save.eventDayCount = eventDayCount;
                this->daytimeIndex = THREEDAY_DAYTIME_DAY;
                this->prevTime = CURRENT_TIME;
                this->actionFunc = EnTest4_HandleEvents;
            }
        } else if (CURRENT_TIME == CLOCK_TIME(6, 0)) {
            this->daytimeIndex = THREEDAY_DAYTIME_NIGHT;

#if MM_VERSION >= N64_US
            EnTest4_HandleDayNightSwapFromInit(this, play);
#else
            EnTest4_HandleDayNightSwap(this, play);
#endif

            if ((gSaveContext.cutsceneTrigger == 0) && (sCsIdList[this->daytimeIndex] > CS_ID_NONE) &&
                !(play->actorCtx.flags & ACTORCTX_FLAG_TELESCOPE_ON)) {
                player->stateFlags1 |= PLAYER_STATE1_200;
            }
        } else {
            if ((CURRENT_TIME > CLOCK_TIME(18, 0)) || (CURRENT_TIME < CLOCK_TIME(6, 0))) {
                this->daytimeIndex = THREEDAY_DAYTIME_NIGHT;
            } else {
                this->daytimeIndex = THREEDAY_DAYTIME_DAY;
            }
            this->prevTime = CURRENT_TIME;
            this->actionFunc = EnTest4_HandleEvents;
        }
    }

    if (CURRENT_DAY == 3) {
        EnTest4_GetBellTimeOnDay3(this);
    } else {
        EnTest4_GetBellTimeAndShrinkScreenBeforeDay3(this, play);
    }

    this->prevBellTime = CURRENT_TIME;

    if ((sCsIdList[this->daytimeIndex] <= CS_ID_NONE) || (play->actorCtx.flags & ACTORCTX_FLAG_TELESCOPE_ON)) {
        gSaveContext.screenScaleFlag = false;
        gSaveContext.screenScale = 1000.0f;
    }
}

void EnTest4_Destroy(Actor* thisx, PlayState* play) {
}

/**
 * This function checks for two-specific time-based events:
 * 1) The day-night transitions
 * 2) The play bells sfx event, which contains screen shrinking and the clocktown day 3 midnight cutscene trigger
 */
void EnTest4_HandleEvents(EnTest4* this, PlayState* play) {
    static u16 sDayNightTransitionTimes[THREEDAY_DAYTIME_MAX] = {
        CLOCK_TIME(6, 0),  // THREEDAY_DAYTIME_NIGHT
        CLOCK_TIME(18, 0), // THREEDAY_DAYTIME_DAY
    };
    Player* player = GET_PLAYER(play);

    if ((play->transitionMode == TRANS_MODE_OFF) && !Play_InCsMode(play) && (play->numSetupActors <= 0) &&
        (play->roomCtx.status == 0) && !Play_IsDebugCamEnabled()) {
        u16 transitionTime = sDayNightTransitionTimes[this->daytimeIndex];
        s16 curTimeUntilTransition;
        s16 prevTimeUntilTransition;
        s16 prevTimeUntilBell;
        s16 curTimeUntilBell;

        curTimeUntilTransition = CURRENT_TIME - transitionTime;
        prevTimeUntilTransition = this->prevTime - transitionTime;

        prevTimeUntilBell = this->prevBellTime - this->nextBellTime;
        curTimeUntilBell = CURRENT_TIME - this->nextBellTime;

        // When the day-night transition time is passed:
        // `curTimeUntilTransition` will be slightly positive (ahead transition time)
        // `prevTimeUntilTransition` will be slightly negative (behind transition time)
        // Only when the signs are different will this condition pass
        if ((curTimeUntilTransition * prevTimeUntilTransition) <= 0) {
#if MM_VERSION < N64_US
            if (1) {}
#endif

            // day-night transition is occurring
            gSaveContext.unk_3CA7 = 1;
            if (play->actorCtx.flags & ACTORCTX_FLAG_PICTO_BOX_ON) {
                play->actorCtx.flags &= ~ACTORCTX_FLAG_PICTO_BOX_ON;
            }

            if (transitionTime != CLOCK_TIME(6, 0)) {
                // previously day, turning night
                EnTest4_HandleDayNightSwap(this, play);
            } else if (transitionTime == CLOCK_TIME(6, 0)) {
                // previously night, turning day
                if (CURRENT_DAY == 3) {
                    // Turn day with mooncrash
                    Interface_StartMoonCrash(play);
                    Actor_Kill(&this->actor);
                    SET_EVENTINF(EVENTINF_17);
                } else if (((sCsIdList[this->daytimeIndex] <= CS_ID_NONE) ||
                            (play->actorCtx.flags & ACTORCTX_FLAG_TELESCOPE_ON)) &&
                           (CURRENT_DAY != 3)) {
                    // Turn day without cutscene
                    EnTest4_HandleDayNightSwap(this, play);
                } else {
                    // Turn day with DayTelop cutscene
                    gSaveContext.screenScale = 0.0f;
                    Play_SetRespawnData(play, RESPAWN_MODE_DOWN, Entrance_CreateFromSpawn(0), player->unk_3CE,
                                        PLAYER_PARAMS(0xFF, PLAYER_START_MODE_B), &player->unk_3C0, player->unk_3CC);
                    func_80169EFC(play);
                    if (player->stateFlags1 & PLAYER_STATE1_800000) {
                        EnHorse* rideActor = (EnHorse*)player->rideActor;

                        if ((rideActor->type == HORSE_TYPE_EPONA) || (rideActor->type == HORSE_TYPE_2)) {
                            if (CURRENT_DAY < 3) {
                                gHorseIsMounted = true;
                            } else {
                                gHorseIsMounted = false;
                            }
                        }
                    }

                    gSaveContext.respawnFlag = -4;
                    SET_EVENTINF(EVENTINF_TRIGGER_DAYTELOP);
                    Actor_Kill(&this->actor);
                }
            }

            if ((sCsIdList[this->daytimeIndex] > CS_ID_NONE) && !(play->actorCtx.flags & ACTORCTX_FLAG_TELESCOPE_ON)) {
                player->stateFlags1 |= PLAYER_STATE1_200;
                this->prevTime = CURRENT_TIME;
            } else {
                if (this->daytimeIndex == THREEDAY_DAYTIME_NIGHT) {
                    this->daytimeIndex = THREEDAY_DAYTIME_DAY;
                } else {
                    this->daytimeIndex = THREEDAY_DAYTIME_NIGHT;
                }

                gSaveContext.save.time += CLOCK_TIME_MINUTE;
                this->prevTime = CURRENT_TIME;
            }
            return;
        }

        // When the bell sfx time is passed:
        // `curTimeUntilBell` will be slightly positive (ahead bell time)
        // `prevTimeUntilBell` will be slightly negative (behind bell time)
        // Only when the signs are different will this condition pass
        if ((curTimeUntilBell * prevTimeUntilBell) <= 0) {
            Audio_PlaySfx_BigBells(&this->actor.projectedPos, THREEDAY_GET_BIG_BELLS_SFX_VOLUME_INDEX(&this->actor));
            this->prevBellTime = CURRENT_TIME;

            if (CURRENT_DAY == 3) {
                if ((this->nextBellTime == CLOCK_TIME(0, 0)) &&
                    ((gSaveContext.save.saveInfo.inventory.items[SLOT_OCARINA] == ITEM_NONE) ||
                     (play->sceneId == SCENE_CLOCKTOWER))) {
                    // Initiate Clocktown day 3 midnight festival cutscene
                    s32 playerParams;
                    u32 entrance = gSaveContext.save.entrance;

                    if (play->actorCtx.flags & ACTORCTX_FLAG_TELESCOPE_ON) {
                        playerParams = PLAYER_PARAMS(0xFF, PLAYER_START_MODE_TELESCOPE);
                    } else {
                        playerParams = PLAYER_PARAMS(0xFF, PLAYER_START_MODE_B);
                    }

                    // if (1) { }
                    // if (1) { }
                    // if (1) { }
                    // if (1) { }

                    Play_SetRespawnData(play, RESPAWN_MODE_RETURN, entrance, player->unk_3CE, playerParams,
                                        &player->unk_3C0, player->unk_3CC);

                    // if (1) { }

                    if ((play->sceneId == SCENE_TENMON_DAI) || (play->sceneId == SCENE_00KEIKOKU)) {
                        play->nextEntrance = ENTRANCE(TERMINA_FIELD, 0);
                    } else {
                        play->nextEntrance = ENTRANCE(SOUTH_CLOCK_TOWN, 0);
                    }
                    gSaveContext.nextCutsceneIndex = 0xFFF1;
                    play->transitionTrigger = TRANS_TRIGGER_START;
                    play->transitionType = TRANS_TYPE_FADE_BLACK;
                    player->stateFlags1 |= PLAYER_STATE1_200;
                    Actor_Kill(&this->actor);
                }
                EnTest4_GetBellTimeOnDay3(this);
            } else {
                EnTest4_GetBellTimeAndShrinkScreenBeforeDay3(this, play);
            }
        }
    }
}

void EnTest4_HandleCutscene(EnTest4* this, PlayState* play) {
    if (!this->transitionCsTimer) {
        if (sCurCsId > CS_ID_NONE) {
            if (!CutsceneManager_IsNext(sCurCsId)) {
                CutsceneManager_Queue(sCurCsId);
            } else {
                CutsceneManager_Start(sCurCsId, &this->actor);
                this->transitionCsTimer = 1;
            }
        } else {
            this->transitionCsTimer = 1;
        }
    } else if (this->transitionCsTimer < 60) {
        this->transitionCsTimer++;
        if (this->transitionCsTimer == 10) {
            if (this->daytimeIndex == THREEDAY_DAYTIME_NIGHT) {
                Audio_PlaySfx(NA_SE_EV_CHICKEN_CRY_M);
            } else {
                Audio_PlaySfx_2(NA_SE_EV_DOG_CRY_EVENING);
            }
        }
        if (this->transitionCsTimer == 60) {
            Player* player = GET_PLAYER(play);

            gSaveContext.save.time += CLOCK_TIME_MINUTE;
            this->prevTime = CURRENT_TIME;

#if MM_VERSION < N64_US
            //! FAKE
            if (!(&gSaveContext)) {}
#endif

            play->numSetupActors = -play->numSetupActors;
            player->stateFlags1 &= ~PLAYER_STATE1_200;
        }
    } else {
        this->actionFunc = EnTest4_HandleEvents;
        if (this->daytimeIndex == THREEDAY_DAYTIME_NIGHT) {
            this->daytimeIndex = THREEDAY_DAYTIME_DAY;
        } else {
            this->daytimeIndex = THREEDAY_DAYTIME_NIGHT;
        }

        if (sCurCsId > CS_ID_NONE) {
            CutsceneManager_Stop(sCurCsId);
        }

        CLEAR_EVENTINF(EVENTINF_17);

#if MM_VERSION >= N64_US
        gSaveContext.hudVisibility = HUD_VISIBILITY_IDLE;
        Interface_SetHudVisibility(HUD_VISIBILITY_ALL);
#endif
    }
}

void EnTest4_UpdateWeatherClear(EnTest4* this, PlayState* play) {
    if ((CURRENT_DAY == 2) && (CURRENT_TIME >= CLOCK_TIME(7, 0)) && (CURRENT_TIME < CLOCK_TIME(17, 30)) &&
        (play->envCtx.precipitation[PRECIP_SNOW_CUR] == 0)) {
        gWeatherMode = WEATHER_MODE_RAIN;
        Environment_PlayStormNatureAmbience(play);
        play->envCtx.lightningState = LIGHTNING_ON;
        play->envCtx.precipitation[PRECIP_RAIN_MAX] = 60;
    } else if ((play->envCtx.precipitation[PRECIP_RAIN_MAX] != 0) && ((play->state.frames % 4) == 0)) {
        play->envCtx.precipitation[PRECIP_RAIN_MAX]--;
        if (play->envCtx.precipitation[PRECIP_RAIN_MAX] == 8) {
            Environment_StopStormNatureAmbience(play);
        }
    }

    if (gWeatherMode == WEATHER_MODE_RAIN) {
        this->weather = THREEDAY_WEATHER_RAIN;
    }
}

void EnTest4_UpdateWeatherRainy(EnTest4* this, PlayState* play) {
    if (((CURRENT_TIME >= CLOCK_TIME(17, 30)) && (CURRENT_TIME < CLOCK_TIME(23, 0)) &&
         (play->envCtx.precipitation[PRECIP_RAIN_MAX] != 0)) ||
        (play->envCtx.precipitation[PRECIP_SNOW_CUR] != 0)) {
        gWeatherMode = WEATHER_MODE_CLEAR;
        play->envCtx.lightningState = LIGHTNING_LAST;
    }

    if (gWeatherMode == WEATHER_MODE_CLEAR) {
        this->weather = THREEDAY_WEATHER_CLEAR;
    }
}

void EnTest4_SetSkyboxNumStars(EnTest4* this, PlayState* play) {
    s32 numStars = THREEDAY_GET_SKYBOX_NUM_STARS(&this->actor);

    if (numStars > 0) {
        gSkyboxNumStars = numStars;
    }
}

void EnTest4_Update(Actor* thisx, PlayState* play) {
    EnTest4* this = (EnTest4*)thisx;
    Player* player = GET_PLAYER(play);

    if (player->stateFlags1 & PLAYER_STATE1_2) {
        return;
    }

    this->actionFunc(this, play);

    if (Environment_GetStormState(play) != STORM_STATE_OFF) {
        switch (this->weather) {
            case THREEDAY_WEATHER_CLEAR:
                EnTest4_UpdateWeatherClear(this, play);
                break;

            case THREEDAY_WEATHER_RAIN:
                EnTest4_UpdateWeatherRainy(this, play);
                break;

            default:
                break;
        }
    }

    EnTest4_SetSkyboxNumStars(this, play);
}
