#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "z64.h"

f32 OLib_Vec3fDist(Vec3f* a, Vec3f* b);
f32 OLib_Vec3fDistOutDiff(Vec3f* a, Vec3f* b, Vec3f* dest);
f32 OLib_Vec3fDistXZ(Vec3f* a, Vec3f* b);
f32 OLib_ClampMinDist(f32 val, f32 min);
f32 OLib_ClampMaxDist(f32 val, f32 max);
Vec3f OLib_Vec3fDistNormalize(Vec3f* a, Vec3f* b);
Vec3f OLib_VecSphToVec3f(VecSph* sph);
Vec3f OLib_VecGeoToVec3f(VecGeo* geo);
VecSph OLib_Vec3fToVecSph(Vec3f* vec);
VecGeo OLib_Vec3fToVecGeo(Vec3f* vec);
VecSph OLib_Vec3fDiffToVecSph(Vec3f* a, Vec3f* b);
VecGeo OLib_Vec3fDiffToVecGeo(Vec3f* a, Vec3f* b);
Vec3f OLib_AddVecGeoToVec3f(Vec3f* a, VecGeo* geo);
Vec3f OLib_Vec3fDiffRad(Vec3f* a, Vec3f* b);
Vec3f OLib_Vec3fDiffDegF(Vec3f* a, Vec3f* b);
Vec3s OLib_Vec3fDiffBinAng(Vec3f* a, Vec3f* b);
void OLib_Vec3fDiff(PosRot* a, Vec3f* b, Vec3f* dest, s16 mode);
void OLib_Vec3fAdd(PosRot* a, Vec3f* b, Vec3f* dest, s16 mode);

void Room_Noop(PlayState* play, Room* room, Input* input, s32 arg3);
void Room_Init(PlayState* play, RoomContext* roomCtx);
size_t Room_AllocateAndLoad(PlayState* play, RoomContext* roomCtx);
s32 Room_StartRoomTransition(PlayState* play, RoomContext* roomCtx, s32 index);
s32 Room_HandleLoadCallbacks(PlayState* play, RoomContext* roomCtx);
void Room_Draw(PlayState* play, Room* room, u32 flags);

void func_8012EBF8(PlayState* play, RoomContext* roomCtx);

void Play_SetMotionBlurAlpha(u32 alpha);
void Play_EnableMotionBlur(u32 alpha);
void Play_DisableMotionBlur(void);
void Play_SetMotionBlurPriorityAlpha(u32 alpha);
void Play_EnableMotionBlurPriority(u32 alpha);
void Play_DisableMotionBlurPriority(void);
void Play_TriggerPictoPhoto(void);
Gfx* Play_SetFog(PlayState* this, Gfx* gfx);
void Play_Destroy(GameState* thisx);
void Play_CompressI8ToI5(void* srcI8, void* destI5, size_t size);
void Play_DecompressI5ToI8(void* srcI5, void* destI8, size_t size);
void Play_Update(PlayState* this);
void Play_Draw(PlayState* this);
void Play_Main(GameState* thisx);
bool Play_InCsMode(PlayState* this);
f32 Play_GetFloorSurfaceImpl(PlayState* this, MtxF* mtx, CollisionPoly** poly, s32* bgId, Vec3f* pos);
void Play_GetFloorSurface(PlayState* this, MtxF* mtx, Vec3f* pos);
void* Play_LoadFile(PlayState* this, RomFile* entry);
void Play_InitEnvironment(PlayState* this, s16 skyboxId);
void Play_GetScreenPos(PlayState* this, Vec3f* worldPos, Vec3f* screenPos);
s16 Play_CreateSubCamera(PlayState* this);
s16 Play_GetActiveCamId(PlayState* this);
s32 Play_ChangeCameraStatus(PlayState* this, s16 camId, s16 status);
void Play_ClearCamera(PlayState* this, s16 camId);
Camera* Play_GetCamera(PlayState* this, s16 camId);
s32 Play_SetCameraAtEye(PlayState* this, s16 camId, Vec3f* at, Vec3f* eye);
s32 Play_SetCameraAtEyeUp(PlayState* this, s16 camId, Vec3f* at, Vec3f* eye, Vec3f* up);
s32 Play_SetCameraFov(PlayState* this, s16 camId, f32 fov);
s32 Play_SetCameraRoll(PlayState* this, s16 camId, s16 roll);
void Play_CopyCamera(PlayState* this, s16 destCamId, s16 srcCamId);
s32 func_80169A50(PlayState* this, s16 camId, Player* player, s16 setting);
s32 Play_ChangeCameraSetting(PlayState* this, s16 camId, s16 setting);
void func_80169AFC(PlayState* this, s16 camId, s16 timer);
u16 Play_GetActorCsCamSetting(PlayState* this, s32 csCamDataIndex);
Vec3s* Play_GetActorCsCamFuncData(PlayState* this, s32 csCamDataIndex);
s16 Play_GetOriginalSceneId(s16 sceneId);
void Play_SaveCycleSceneFlags(GameState* thisx);
void Play_SetRespawnData(GameState* thisx, s32 respawnMode, u16 entrance, s32 roomIndex, s32 playerParams, Vec3f* pos, s16 yaw);
void Play_SetupRespawnPoint(GameState* thisx, s32 respawnMode, s32 playerParams);
void func_80169EFC(GameState* thisx);
void func_80169F78(GameState* thisx);
void func_80169FDC(GameState* thisx);
s32 Play_CamIsNotFixed(GameState* thisx);
s32 FrameAdvance_IsEnabled(GameState* thisx);
s32 func_8016A02C(GameState* thisx, Actor* actor, s16* yaw);
s32 Play_IsUnderwater(PlayState* this, Vec3f* pos);
s32 Play_IsDebugCamEnabled(void);
void Play_AssignPlayerCsIdsFromScene(GameState* thisx, s32 spawnCsId);
void Play_FillScreen(GameState* thisx, s16 fillScreenOn, u8 red, u8 green, u8 blue, u8 alpha);
void Play_Init(GameState* thisx);

void Graph_FaultClient(void);
void Graph_InitTHGA(TwoHeadGfxArena* arena, Gfx* buffer, s32 size);
void Graph_SetNextGfxPool(GraphicsContext* gfxCtx);
GameStateOverlay* Graph_GetNextGameState(GameState* gameState);
uintptr_t Graph_FaultAddrConv(uintptr_t address, void* param);
void Graph_Init(GraphicsContext* gfxCtx);
void Graph_Destroy(GraphicsContext* gfxCtx);
void Graph_TaskSet00(GraphicsContext* gfxCtx, GameState* gameState);
void Graph_UpdateGame(GameState* gameState);
void Graph_ExecuteAndDraw(GraphicsContext* gfxCtx, GameState* gameState);
void Graph_Update(GraphicsContext* gfxCtx, GameState* gameState);
void Graph_ThreadEntry(void* arg);

void func_80183070(void);

AudioTask* AudioThread_Update(void);
void AudioThread_QueueCmdF32(u32 opArgs, f32 data);
void AudioThread_QueueCmdS32(u32 opArgs, s32 data);
void AudioThread_QueueCmdS8(u32 opArgs, s8 data);
void AudioThread_QueueCmdU16(u32 opArgs, u16 data);
s32 AudioThread_ScheduleProcessCmds(void);
u32 AudioThread_GetExternalLoadQueueMsg(u32* retMsg);
u8* AudioThread_GetFontsForSequence(s32 seqId, u32* outNumFonts);
s32 func_80193C5C(void);
s32 AudioThread_ResetAudioHeap(s32 specId);
void AudioThread_PreNMIInternal(void);
s32 AudioThread_GetEnabledNotesCount(void);
u32 AudioThread_NextRandom(void);
void AudioThread_InitMesgQueues(void);

void Audio_InvalDCache(void* buf, size_t size);
void Audio_WritebackDCache(void* buf, size_t size);

void func_8019AE40(s32 param_1, s32 param_2, u32 param_3, s32 param_4);
void func_8019AEC0(UNK_PTR param_1, UNK_PTR param_2);

void Audio_Init(void);
void Audio_InitSound(void);
void Audio_Update(void);
void Audio_ResetForAudioHeapStep3(void);
void Audio_ResetForAudioHeapStep2(void);
void Audio_ResetForAudioHeapStep1(s32 specId);
void Audio_PreNMI(void);

#endif
