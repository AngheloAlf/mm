#ifndef SLEEP_H
#define SLEEP_H

#include "ultra64.h"

void Sleep_Cycles(OSTime time);
void Sleep_Nsec(u32 nsec);
void Sleep_Usec(u32 usec);
void Sleep_Msec(u32 ms);
void Sleep_Sec(u32 sec);

#endif
