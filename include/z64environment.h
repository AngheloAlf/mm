#ifndef Z64_ENVIRONMENT_H
#define Z64_ENVIRONMENT_H

#include "ultra64.h"
#include "color.h"
#include "z64dma.h"
#include "z64light.h"
#include "z64math.h"

struct PlayState;
struct SkyboxContext;
struct PauseContext;
struct MessageContext;
struct GameOverContext;
struct GraphicsContext;
struct View;


typedef struct {
    /* 0x00 */ u16 unk_0;
    /* 0x02 */ u16 sceneTimeSpeed;
    /* 0x04 */ Vec3f sunPos;
    /* 0x10 */ u8 unk_10;
    /* 0x11 */ u8 unk_11;
    /* 0x12 */ u8 unk_12;
    /* 0x13 */ u8 unk_13;
    /* 0x14 */ u8 unk_14;
    /* 0x15 */ u8 skyboxDisabled;
    /* 0x16 */ u8 sunMoonDisabled;
    /* 0x17 */ u8 unk_17;
    /* 0x18 */ u8 unk_18;
    /* 0x19 */ u8 unk_19;
    /* 0x1A */ u16 unk_1A;
    /* 0x1C */ u16 unk_1C;
    /* 0x1E */ u8 unk_1E;
    /* 0x1F */ u8 unk_1F;
    /* 0x20 */ u8 unk_20;
    /* 0x21 */ u8 unk_21;
    /* 0x22 */ u16 unk_22;
    /* 0x24 */ u16 unk_24;
    /* 0x26 */ u8 unk_26;
    /* 0x28 */ LightInfo dirLight1; // sun 1
    /* 0x36 */ LightInfo unk_36; // sun 2
    /* 0x44 */ s8 unk_44;
    /* 0x48 */ DmaRequest unk_48;
    /* 0x68 */ OSMesgQueue unk_68;
    /* 0x80 */ OSMesg unk_80;
    /* 0x84 */ f32 unk_84;
    /* 0x88 */ f32 unk_88;
    /* 0x8C */ EnvLightSettings lightSettings;
    /* 0xA8 */ f32 unk_A8;
    /* 0xAC */ Vec3s windDir;
    /* 0xB4 */ f32 windSpeed;
    /* 0xB8 */ u8 numLightSettings;
    /* 0xBC */ LightSettings* lightSettingsList;
    /* 0xC0 */ u8 unk_C0;
    /* 0xC1 */ u8 unk_C1;
    /* 0xC2 */ u8 unk_C2;
    /* 0xC3 */ u8 lightSettingOverride;
    /* 0xC4 */ LightSettings unk_C4;
    /* 0xDA */ u16 unk_DA;
    /* 0xDC */ f32 lightBlend;
    /* 0xE0 */ u8 unk_E0;
    /* 0xE1 */ u8 unk_E1;
    /* 0xE2 */ s8 unk_E2;
    /* 0xE3 */ u8 unk_E3; // modified by unused func in EnWeatherTag
    /* 0xE4 */ u8 unk_E4;
    /* 0xE5 */ u8 fillScreen;
    /* 0xE6 */ u8 screenFillColor[4];
    /* 0xEA */ u8 sandstormState;
    /* 0xEB */ u8 sandstormPrimA;
    /* 0xEC */ u8 sandstormEnvA;
    /* 0xED */ u8 unk_ED;
    /* 0xEE */ u8 unk_EE[4];
    /* 0xF2 */ u8 unk_F2[8]; // [3] is used by both DemoKankyo and ObjectKankyo effect count
    /* 0xFA */ u8 unk_FA[4];
} EnvironmentContext; // size = 0x100


// void func_800F5090(void);
// void func_800F50D4(void);
void Environment_Init(struct PlayState* play, EnvironmentContext* envCtx, s32 arg2);
u32 func_800F5954(u8* param_1, u32 param_2, u32 param_3, u8 param_4, u8 param_5);
f32 Environment_LerpWeight(u16 max, u16 min, u16 val);
// void func_800F5B10(UNK_TYPE1 param_1, UNK_TYPE1 param_2, UNK_TYPE1 param_3, UNK_TYPE1 param_4, UNK_TYPE2 param_5);
void Environment_UpdateSkybox(u8 skyboxId, EnvironmentContext* envCtx, struct SkyboxContext* skyboxCtx);
void func_800F6834(struct PlayState* play, s32 waterLightsIndex);
void func_800F694C(struct PlayState* play);
// void func_800F6A04(void);
// void func_800F6A40(void);
// void func_800F6AB8(void);
void func_800F6B44(struct PlayState* play, EnvironmentContext* envCtx, s32 iParm3, s32 iParm4, s16* param_5);
// void func_800F6CEC(void);
// void func_800F6EA4(void);
// UNK_TYPE4 Kankyo_IsSceneUpsideDown(struct PlayState* play);
void func_800F6FF8(struct PlayState* play, EnvironmentContext* envCtx, LightContext* lightCtx);
// void func_800F8554(void);
// void func_800F88C4(void);
// void func_800F8970(void);
// void func_800F8A9C(void);
void Environment_Update(struct PlayState* play, EnvironmentContext* envCtx, LightContext* lightCtx, struct PauseContext* pauseCtx, struct MessageContext* msgCtx, struct GameOverContext* gameOverCtx, struct GraphicsContext* gfxCtx);
// void func_800F8D84(void);
void Environment_DrawSunLensFlare(struct PlayState* play, EnvironmentContext* envCtx, struct View* view, struct GraphicsContext* gfxCtx, Vec3f pos);
void func_800F9824(struct PlayState* play, EnvironmentContext* envCtx, struct View* view, struct GraphicsContext* gfxCtx, Vec3f vec, f32 arg5, f32 arg6, s8 arg7, s8 arg8);
// void func_800FA39C(void);
// void func_800FA3C4(void);
void Environment_DrawRain(struct PlayState* play, struct View* view, struct GraphicsContext* gfxCtx);
void func_800FAAB4(struct PlayState* play, u8 arg1);
// void func_800FAC20(void);
// void func_800FAF74(UNK_TYPE1 param_1, UNK_TYPE1 param_2, UNK_TYPE1 param_3, UNK_TYPE1 param_4, UNK_TYPE1 param_5);
// void func_800FB010(void);
void Environment_AddLightningBolts(struct PlayState* play, u8 num);
// void func_800FB388(void);
void func_800FB758(struct PlayState* play);
// void func_800FB9B4(void);
void Environment_DrawCustomLensFlare(struct PlayState* play);
void Kankyo_InitGameOverLights(struct PlayState* play);
void Kankyo_FadeInGameOverLights(struct PlayState* play);
void Kankyo_FadeOutGameOverLights(struct PlayState* play);
// void func_800FC3DC(void);
void Environment_FillScreen(struct GraphicsContext* gfxCtx, u8 red, u8 green, u8 blue, u8 alpha, u8 drawFlags);
void Environment_DrawSandstorm(struct PlayState* play, u8 sandstormState);
s32 func_800FD2B4(struct PlayState* play, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
void func_800FD538(Color_RGB8* param_1, Color_RGB8* param_2, f32 param_3, Vec3s* param_4);
void func_800FD59C(struct PlayState* play, Color_RGB8* pzParm2, f32 fParm3);
void func_800FD5E0(struct PlayState* play, Color_RGB8* pzParm2, f32 fParm3);
void func_800FD654(struct PlayState* play, Color_RGB8* pzParm2, f32 fParm3);
void func_800FD698(struct PlayState* play, s16 arg1, s16 arg2, f32 arg3);
// u32 get_days_elapsed(void);
// void reset_days_elapsed(void);
// u32 get_current_day(void);
void func_800FD750(u16 seqId);
s32 func_800FD768(void);
void func_800FD78C(struct PlayState* play);
void func_800FD858(struct PlayState* play);
void func_800FD928(s32 param_1);
// void func_800FD980(void);
// void func_800FDAF8(UNK_TYPE1 param_1, UNK_TYPE1 param_2, UNK_TYPE1 param_3, UNK_TYPE1 param_4, UNK_TYPE4 param_5);
// void func_800FDC94(void);
void func_800FE390(struct PlayState* play);
void func_800FE3E0(struct PlayState* play);
void Environment_StopTime(void);
void Environment_StartTime(void);
u8 Environment_IsTimeStopped(void);
u32 func_800FE4B8(struct PlayState* play);
s32 func_800FE590(struct PlayState* play);
// void func_800FE5D0(void);
// UNK_TYPE4 func_800FE610(void);
u32 func_800FE620(struct PlayState* play);
void func_800FE658(f32 arg0);
// UNK_TYPE4 func_800FE6F8(UNK_TYPE4 param_1, s16 param_2, s16 param_3);
// void func_800FE778(void);
// void func_800FE788(void);
// void func_800FE798(void);
void func_800FE7A8(Color_RGBA8* inColor, Color_RGBA8* outColor);
s32 func_800FE9B4(struct PlayState* play);
void func_800FEA50(struct PlayState* play);
void func_800FEAB0(void);
// void func_800FEAC0(void);
void func_800FEAF4(EnvironmentContext* envCtx);


// extern UNK_TYPE4 D_801BDB90;
// extern UNK_TYPE4 D_801BDB94;
// extern UNK_TYPE4 D_801BDB98;
// extern UNK_TYPE2 D_801BDB9C;
// extern UNK_TYPE1 D_801BDBA0;
// extern UNK_TYPE1 D_801BDBA4;
// extern UNK_TYPE1 D_801BDBA8;
extern u8 gWeatherMode;
// extern UNK_TYPE1 D_801BDBB4;
// extern UNK_TYPE1 D_801BDBB8;
// extern UNK_TYPE1 D_801BDBBC;
// extern UNK_TYPE1 D_801BDBC0;
// extern UNK_TYPE1 D_801BDBC4;
extern u8 D_801BDBC8;
// extern UNK_TYPE1 D_801BDBCC;
// extern UNK_TYPE1 D_801BDCF4;
// extern UNK_TYPE1 D_801BE38E;
// extern UNK_TYPE1 D_801BE38F;
// extern UNK_TYPE1 D_801BE390;
// extern UNK_TYPE1 D_801BE4D4;
// extern UNK_TYPE1 D_801BE4F4;
// extern UNK_TYPE1 D_801BE534;
// extern UNK_TYPE1 D_801BE6D4;
// extern UNK_TYPE1 D_801BE874;
// extern UNK_TYPE4 D_801BE894;
// extern UNK_TYPE4 D_801BE8BC;
// extern UNK_TYPE4 D_801BE8E4;
// extern UNK_TYPE1 D_801BE90C;
// extern UNK_TYPE1 D_801BE92C;
// extern UNK_TYPE1 D_801BE944;


// extern UNK_TYPE2 D_801DD880;
// extern UNK_TYPE1 D_801DD8E0;
// extern UNK_TYPE4 D_801DD900;
extern f32 D_801DD940;
extern f32 D_801DD944;
extern f32 D_801DD948;
extern f32 D_801DD94C;
extern f32 D_801DD950;
extern f32 D_801DD954;
extern f32 D_801DD958;
extern f32 D_801DD95C;
extern f32 D_801DD960;
extern f32 D_801DD964;
extern f32 D_801DD968;
extern f32 D_801DD96C;
extern f32 D_801DD970;
extern f32 D_801DD974;
extern f32 D_801DD978;
extern f32 D_801DD97C;
extern f32 D_801DD980;
extern f32 D_801DD984;
extern f32 D_801DD988;
extern f32 D_801DD98C;
extern f32 D_801DD990;
extern f32 D_801DD9EC;
extern f32 D_801DD9F0;
extern f32 D_801DD9F4;
extern f32 D_801DD9F8;
extern f32 D_801DD9FC;
extern f32 D_801DDA7C;


extern u8 D_801F4E30;
// extern UNK_TYPE1 D_801F4E31;
extern s8 D_801F4E32;
extern Vec3f D_801F4E38;
extern f32 D_801F4E44;
extern f32 D_801F4E48;
extern s16 D_801F4E4C;
extern s8 D_801F4E4E;
extern Vec3f D_801F4E50;
extern f32 D_801F4E5C;
extern f32 D_801F4E60;
extern s16 D_801F4E64;
extern u8 D_801F4E68;
extern f32 D_801F4E70;
// extern UNK_TYPE1 D_801F4E74;
extern u16 D_801F4E78;
extern s16 D_801F4E7A;
// extern UNK_TYPE1 D_801F4E80;
// extern UNK_TYPE1 D_801F4EE0;
// extern UNK_TYPE1 D_801F4EE8;
// extern UNK_TYPE1 D_801F4EF8;
// extern UNK_TYPE1 D_801F4F00;
// extern UNK_TYPE1 D_801F4F10;
// extern UNK_TYPE1 D_801F4F14;
// extern UNK_TYPE1 D_801F4F18;
// extern UNK_TYPE1 D_801F4F1C;
// extern UNK_TYPE1 D_801F4F20;
// extern UNK_TYPE1 D_801F4F24;
// extern UNK_TYPE1 D_801F4F28;
// extern UNK_TYPE1 D_801F4F2C;
// extern UNK_TYPE1 D_801F4F2E;
// extern UNK_TYPE1 D_801F4F30;
// extern UNK_TYPE1 D_801F4F31;
// extern UNK_TYPE1 D_801F4F32;
// extern UNK_TYPE1 D_801F4F33;
// extern UNK_TYPE1 D_801F4F34;
// extern UNK_TYPE1 D_801F4F38;

#endif
