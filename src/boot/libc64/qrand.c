#include "libc64/qrand.h"

/**
 * The latest generated random number, used to generate the next number in the sequence.
 *
 * Original name: __qrand_idum
 */
u32 sRandInt = 1;

/**
 * Space to store a value to be re-interpreted as a float.
 *
 * Orignal name: __qrand_itemp
 */
fu gRandFloat;

#ifdef __GNUC__
u32 Rand_Next(void) __attribute__ ((weak, alias ("qrand")));
void Rand_Seed(u32 seed) __attribute__ ((weak, alias ("sqrand")));
f32 Rand_ZeroOne(void) __attribute__ ((weak, alias ("fqrand")));
f32 Rand_Centered(void) __attribute__ ((weak, alias ("fqrand2")));
void Rand_Seed_Variable(u32* rndNum, u32 seed) __attribute__ ((weak, alias ("sqrand_r")));
u32 Rand_Next_Variable(u32* rndNum) __attribute__ ((weak, alias ("qrand_r")));
f32 Rand_ZeroOne_Variable(u32* rndNum) __attribute__ ((weak, alias ("fqrand_r")));
f32 Rand_Centered_Variable(u32* rndNum) __attribute__ ((weak, alias ("fqrand2_r")));
#else
#pragma weak Rand_Next = qrand
#pragma weak Rand_Seed = sqrand
#pragma weak Rand_ZeroOne = fqrand
#pragma weak Rand_Centered = fqrand2
#pragma weak Rand_Seed_Variable = sqrand_r
#pragma weak Rand_Next_Variable = qrand_r
#pragma weak Rand_ZeroOne_Variable = fqrand_r
#pragma weak Rand_Centered_Variable = fqrand2_r
#endif

/**
 * Generates the next pseudo-random integer.
 *
 * Original name: qrand
 */
u32 qrand(void) {
    sRandInt = (sRandInt * RAND_MULTIPLIER) + RAND_INCREMENT;

    return sRandInt;
}

/**
 * Seeds the internal pseudo-random number generator with a provided starting value.
 *
 * Original name: sqrand
 */
void sqrand(u32 seed) {
    sRandInt = seed;
}

/**
 * Returns a pseudo-random float between 0.0f and 1.0f from the internal PRNG.
 *
 * @note Works by generating the next integer, masking it to an IEEE-754 compliant float between 1.0f and 2.0f, and
 * subtracting 1.0f.
 *
 * @remark This is also recommended by Numerical Recipes, pp. 284-5.
 *
 * Original name: fqrand
 */
f32 fqrand(void) {
    sRandInt = (sRandInt * RAND_MULTIPLIER) + RAND_INCREMENT;
    gRandFloat.i = ((sRandInt >> 9) | 0x3F800000);
    return gRandFloat.f - 1.0f;
}

/**
 * Returns a pseudo-random float between -0.5f and 0.5f in the same way as fqrand().
 *
 * Original name: fqrand2
 */
f32 fqrand2(void) {
    sRandInt = (sRandInt * RAND_MULTIPLIER) + RAND_INCREMENT;
    gRandFloat.i = ((sRandInt >> 9) | 0x3F800000);
    return gRandFloat.f - 1.5f;
}

//! All functions below are unused variants of the above four, that use a provided random number variable instead of the
//! internal `sRandInt`

/**
 * Seeds a provided pseudo-random number with a provided starting value.
 *
 * @see sqrand
 *
 * Original name: sqrand_r
 */
void sqrand_r(u32* rndNum, u32 seed) {
    *rndNum = seed;
}

/**
 * Generates the next pseudo-random number from the provided rndNum.
 *
 * @see qrand
 *
 * Original name: qrand_r
 */
u32 qrand_r(u32* rndNum) {
    u32 t = (*rndNum * RAND_MULTIPLIER) + RAND_INCREMENT;

    *rndNum = t;
    return t;
}

/**
 * Generates the next pseudo-random float between 0.0f and 1.0f from the provided rndNum.
 *
 * @see fqrand
 *
 * Original name: fqrand_r
 */
f32 fqrand_r(u32* rndNum) {
    u32 next = (*rndNum * RAND_MULTIPLIER) + RAND_INCREMENT;

    gRandFloat.i = ((*rndNum = next) >> 9) | 0x3F800000;
    return gRandFloat.f - 1.0f;
}

/**
 * Generates the next pseudo-random float between -0.5f and 0.5f from the provided rndNum.
 *
 * @see fqrand, fqrand2
 *
 * Original name: fqrand2_r
 */
f32 fqrand2_r(u32* rndNum) {
    u32 next = (*rndNum * RAND_MULTIPLIER) + RAND_INCREMENT;

    gRandFloat.i = ((*rndNum = next) >> 9) | 0x3F800000;
    return gRandFloat.f - 1.5f;
}
