#ifndef __MC33886_H_
#define __MC33886_H_

#include "MC_Config.h"

//Motor Dir
#define FORWARD 0
#define BACKWARD 1


typedef struct {
    UBYTE Dir;
    UBYTE EnablePin;
    UBYTE DirPin;
    UBYTE StepPin;
    UBYTE M0Pin;
    UBYTE M1Pin;
    UBYTE M2Pin;
} MOTOR;

void MC33886_Stop(void);
void MC33886_TurnStep(UBYTE dir, UWORD steps, UWORD stepdelay);
#endif
