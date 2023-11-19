#ifndef LIBC64_QRAND_H
#define LIBC64_QRAND_H

#include "ultra64.h"

//! These values are recommended by the algorithms book *Numerical Recipes in C. The Art of Scientific Computing*, 2nd
//! Edition, 1992, ISBN 0-521-43108-5. (p. 284):
//! > This is about as good as any 32-bit linear congruential generator, entirely adequate for many uses.
#define RAND_MULTIPLIER 1664525
#define RAND_INCREMENT 1013904223

u32 qrand(void);
void sqrand(u32 seed);
f32 fqrand(void);
f32 fqrand2(void);
void sqrand_r(u32* rndNum, u32 seed);
u32 qrand_r(u32* rndNum);
f32 fqrand_r(u32* rndNum);
f32 fqrand2_r(u32* rndNum);

extern fu __qrand_itemp;

#endif
