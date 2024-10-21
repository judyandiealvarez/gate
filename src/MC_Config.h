
#ifndef __MC_CONFIG_H_
#define __MC_CONFIG_H_

#include <bcm2835.h>
#include <stdint.h>

#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t


/**
 * GPIO
**/
#define M1_IN1 20
#define M1_IN2 21
#define M1_IN3 6
#define M1_IN4 13
#define PWMA 26
#define PWMB 12

#define MC_Digital_Write(_pin, _value) bcm2835_gpio_write(_pin, _value)


UBYTE MC_ModuleInit(void);
void  MC_ModuleExit(void);

void  MC_Delay_ms(UDOUBLE xms);
void  MC_Delay_us(UDOUBLE xus);
#endif
