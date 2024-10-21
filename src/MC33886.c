
#include "MC33886.h"
#include "Debug.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


MOTOR Motor;


void MC33886_Stop(void)
{
	MC_Digital_Write(PWMA,0);
	MC_Digital_Write(PWMB,0);
	MC_Digital_Write(M1_IN1,0);
	MC_Digital_Write(M1_IN2,0);
	MC_Digital_Write(M1_IN3,0);
	MC_Digital_Write(M1_IN4,0);
}
void Step_FORWARD(UWORD stepdelay)
{
	MC_Digital_Write(M1_IN1,1);
	MC_Digital_Write(M1_IN2,0);
	MC_Digital_Write(M1_IN3,0);
	MC_Digital_Write(M1_IN4,0);
	MC_Delay_ms(stepdelay);
//	MC_Digital_Write(M1_IN1,0);
//	MC_Digital_Write(M1_IN2,1);
//	MC_Digital_Write(M1_IN3,0);
//	MC_Digital_Write(M1_IN4,0);
//	MC_Delay_ms(stepdelay);
	MC_Digital_Write(M1_IN1,0);
	MC_Digital_Write(M1_IN2,0);
	MC_Digital_Write(M1_IN3,1);
	MC_Digital_Write(M1_IN4,0);
	MC_Delay_ms(stepdelay);
//	MC_Digital_Write(M1_IN1,0);
//	MC_Digital_Write(M1_IN2,0);
//	MC_Digital_Write(M1_IN3,0);
//	MC_Digital_Write(M1_IN4,1);
//	MC_Delay_ms(stepdelay);
}
void Step_BACKWARD(UWORD stepdelay)
{
	MC_Digital_Write(M1_IN1,0);
	MC_Digital_Write(M1_IN2,0);
	MC_Digital_Write(M1_IN3,0);
	MC_Digital_Write(M1_IN4,1);
	MC_Delay_ms(stepdelay);
//	MC_Digital_Write(M1_IN1,0);
//	MC_Digital_Write(M1_IN2,0);
//	MC_Digital_Write(M1_IN3,1);
//	MC_Digital_Write(M1_IN4,0);
//	MC_Delay_ms(stepdelay);
	MC_Digital_Write(M1_IN1,0);
	MC_Digital_Write(M1_IN2,1);
	MC_Digital_Write(M1_IN3,0);
	MC_Digital_Write(M1_IN4,0);
	MC_Delay_ms(stepdelay);
//	MC_Digital_Write(M1_IN1,1);
//	MC_Digital_Write(M1_IN2,0);
//	MC_Digital_Write(M1_IN3,0);
//	MC_Digital_Write(M1_IN4,0);
//	MC_Delay_ms(stepdelay);
}
void MC33886_TurnStep(UBYTE dir, UWORD steps, UWORD stepdelay)
{
	
	if(steps == 0)
		return;
	
	UWORD i = 0;
	DEBUG("turn %d steps\r\n",steps);
	MC_Digital_Write(PWMA,1);
	MC_Digital_Write(PWMB,1);
	if(dir == FORWARD)
	{
		for(i = 0;i < steps; i++)
		{
			Step_FORWARD(stepdelay);
		}
	}
	else if(dir == BACKWARD)
	{
		for(i = 0;i < steps; i++)
		{
			Step_BACKWARD(stepdelay);
		}
	}
	
}
