#include <ultra64.h>
#include <global.h>

extern s32 D_8009CD10;


//f32 Math_FTanF(f32 x) {
f32 func_80086760(f32 x) {
    f32 sin = __sinf(x);
    f32 cos = __cosf(x);
    return sin / cos;
}
//#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086760.asm")

// Math_FFloorF(f32 x) {
f32 func_80086794(f32 x) {
    //return floorf(x);
    return func_80086C70(x);
}
//#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086794.asm")

// Math_FCeilF
f32 func_800867B4(f32 x) {
    //return ceilf(x);
    return func_80086CA8(x);
}
//#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_800867B4.asm")

// Math_FRoundF
f32 func_800867D4(f32 x) {
    //return roundf(x);
    return func_80086D50(x);
}
//#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_800867D4.asm")

// Math_FTruncF
f32 func_800867F4(f32 x) {
    //return truncf(x);
    return func_80086CE0(x);
}
//#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_800867F4.asm")

// Math_FNearbyIntF
f32 func_80086814(f32 x) {
    //return nearbyintf(x);
    return func_80086D18(x);
}
//#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086814.asm")

/* Arctangent approximation using a Taylor series (one quadrant) */
// Math_FAtanTaylorQF
/*
f32 func_80086834(f32 x) {
    static const f32 coeffs[] = {
        -1.0f / 3, +1.0f / 5, -1.0f / 7, +1.0f / 9, -1.0f / 11, +1.0f / 13, -1.0f / 15, +1.0f / 17, 0.0f,
    };

    f32 poly = x;
    f32 sq = SQ(x);
    f32 exp = x * sq;
    const f32* c = coeffs;
    f32 term;

    while (1) {
        term = *c++ * exp;
        if (poly + term == poly) {
            break;
        }
        poly = poly + term;
        exp = exp * sq;
    }

    return poly;
}
*/
#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086834.asm")


/* Ditto for two quadrants */
/*
f32 Math_FAtanTaylorF(f32 x) {
    f32 t;
    f32 q;

    if (x > 0.0f) {
        t = x;
    } else if (x < 0.0f) {
        t = -x;
    } else if (x == 0.0f) {
        return 0.0f;
    } else {
        return qNaN0x10000;
    }

    if (t <= M_SQRT2 - 1.0f) {
        return Math_FAtanTaylorQF(x);
    }

    if (t >= M_SQRT2 + 1.0f) {
        q = M_PI / 2 - Math_FAtanTaylorQF(1.0f / t);
    } else {
        q = M_PI / 4 - Math_FAtanTaylorQF((1.0f - t) / (1.0f + t));
    }

    if (x > 0.0f) {
        return q;
    } else {
        return -q;
    }
}
*/
#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086880.asm")


/* Arctangent approximation using a continued fraction */
/*
f32 Math_FAtanContFracF(f32 x) {
    s32 sector;
    f32 z;
    f32 conv;
    f32 sq;
    s32 i;

    if (x >= -1.0f && x <= 1.0f) {
        sector = 0;
    } else if (x > 1.0f) {
        sector = 1;
        x = 1.0f / x;
    } else if (x < -1.0f) {
        sector = -1;
        x = 1.0f / x;
    } else {
        return qNaN0x10000;
    }

    sq = SQ(x);
    conv = 0.0f;
    z = 8.0f;
    for (i = 8; i != 0; i--) {
        conv = SQ(z) * sq / (2.0f * z + 1.0f + conv);
        z -= 1.0f;
    }
    conv = x / (1.0f + conv);

    if (sector == 0) {
        return conv;
    } else if (sector > 0) {
        return M_PI / 2 - conv;
    } else {
        return -M_PI / 2 - conv;
    }
}
*/
#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_800869A4.asm")


/*
f32 Math_FAtanF(f32 x) {
    if (!gUseAtanContFrac) {
        return Math_FAtanTaylorF(x);
    } else {
        return Math_FAtanContFracF(x);
    }
}
*/
// Math_FAtanF
f32 func_80086AF0(f32 x) {
    //if (!gUseAtanContFrac) {
    if (!D_8009CD10) {
        //return Math_FAtanTaylorF(x);
        return func_80086880(x);
    } else {
        //return Math_FAtanContFracF(x);
        return func_800869A4(x);
    }
}
//#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086AF0.asm")

// Math_FAtan2F
/*
f32 func_80086B30(f32 y, f32 x) {
    if (x == 0.0f) {
        if (y == 0.0f) {
            return 0.0f;
        }
        if (y > 0.0f) {
            return D_800990FC;
        }
        if (y < 0.0f) {
            return D_80099100;
        }
        return D_80097524;
    }
    else if (x >= 0.0f) {
        return func_80086AF0(y / x);
    }
    else if (y < 0.0f) {
        return func_80086AF0(y / x) - D_80099104;
    }
    else {
        return D_80099108 - func_80086AF0(-(y / x));
    }
}
*/
#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086B30.asm")


// Math_FAsinF
f32 func_80086C18(f32 x) {
    // return Math_FAtan2F(x, sqrtf(1.0f - SQ(x)));
    return func_80086B30(x, sqrtf(1.0f - SQ(x)));
}
//#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086C18.asm")


// Math_FAcosF
f32 func_80086C48(f32 x) {
    //return M_PI / 2 - Math_FAsinF(x);
    return D_8009910C - func_80086C18(x);
}
//#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086C48.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086C70.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086C7C.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086C88.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086C98.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086CA8.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086CB4.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086CC0.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086CD0.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086CE0.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086CEC.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086CF8.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086D08.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086D18.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086D24.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086D30.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086D40.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086D50.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086D6C.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086D8C.asm")

#pragma GLOBAL_ASM("./asm/non_matchings/boot/boot_0x80086760/func_80086DAC.asm")
