#include "libc64/qrand.h"

/**
 * The latest generated random number, used to generate the next number in the sequence.
 *
 * Original name: __qrand_idum
 */
u32 __qrand_idum = 1;

/**
 * Space to store a value to be re-interpreted as a float.
 *
 * Orignal name: __qrand_itemp
 */
fu __qrand_itemp;

/**
 * Generates the next pseudo-random integer.
 *
 * Original name: qrand
 */
u32 qrand(void) {
    __qrand_idum = (__qrand_idum * RAND_MULTIPLIER) + RAND_INCREMENT;

    return __qrand_idum;
}

/**
 * Seeds the internal pseudo-random number generator with a provided starting value.
 *
 * Original name: sqrand
 */
void sqrand(u32 seed) {
    __qrand_idum = seed;
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
    __qrand_idum = (__qrand_idum * RAND_MULTIPLIER) + RAND_INCREMENT;
    __qrand_itemp.i = ((__qrand_idum >> 9) | 0x3F800000);
    return __qrand_itemp.f - 1.0f;
}

/**
 * Returns a pseudo-random float between -0.5f and 0.5f in the same way as fqrand().
 *
 * Original name: fqrand2
 */
f32 fqrand2(void) {
    __qrand_idum = (__qrand_idum * RAND_MULTIPLIER) + RAND_INCREMENT;
    __qrand_itemp.i = ((__qrand_idum >> 9) | 0x3F800000);
    return __qrand_itemp.f - 1.5f;
}

//! All functions below are unused variants of the above four, that use a provided random number variable instead of the
//! internal `__qrand_idum`

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

    __qrand_itemp.i = ((*rndNum = next) >> 9) | 0x3F800000;
    return __qrand_itemp.f - 1.0f;
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

    __qrand_itemp.i = ((*rndNum = next) >> 9) | 0x3F800000;
    return __qrand_itemp.f - 1.5f;
}
