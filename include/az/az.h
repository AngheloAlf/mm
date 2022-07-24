#ifndef AZ_H
#define AZ_H


#ifndef AZ
#define AZ 0
#endif

#if AZ != 0
#define AZ_MAIN(gameState) az_Main(gameState)
#else
#define AZ_MAIN(gameState)
#endif

void az_Main(GameState* gameState);


#ifndef AZ_TRANSLATE_STR
#define AZ_TRANSLATE_STR 0
#endif

#if AZ_TRANSLATE_STR == 0
#define AZ_MULTILANG_STR(orig, translation) orig
#else
#define AZ_MULTILANG_STR(orig, translation) translation
#endif

#endif
