/*****************************************************************************
* | File        :   MC_Config.c
* | Author      :   Waveshare team
* | Function    :   Hardware underlying interface
* | Info        :
*                Used to shield the underlying layers of each master
*                and enhance portability
*----------------
* |	This version:   V1.0
* | Date        :   2018-09-03
* | Info        :   Basic version
*
******************************************************************************/
#include "MC_Config.h"
#include "Debug.h"  //DEBUG()

#include <bcm2835.h>


/**
 * Module Initialize, use BCM2835 library.
 *
 * Example:
 * if(MC_ModuleInit())
 *   exit(0);
 */
UBYTE MC_ModuleInit(void)
{
    if(!bcm2835_init()) {
        DEBUG("bcm2835 init failed   !!! \r\n");
        return 1;
    } else {
        DEBUG("bcm2835 init success  !!! \r\n");
    }
    
    //motor 1 
    bcm2835_gpio_fsel(M1_IN1, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(M1_IN2, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(M1_IN3, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(M1_IN4, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(PWMA, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(PWMB, BCM2835_GPIO_FSEL_OUTP);

    return 0;
}

/**
 * Module Exit, close BCM2835 library.
 *
 * Example:
 * MC_ModuleExit();
 */
void MC_ModuleExit(void)
{
    bcm2835_close();
}

/**
 * Millisecond delay.
 *
 * @param xms: time.
 *
 * Example:
 * MC_Delay_ms(500);//delay 500ms
 */
void MC_Delay_ms(uint32_t xms)
{
    bcm2835_delay(xms);
}

/**
 * Microsecond delay.
 *
 * @param xus: time.
 *
 * Example:
 * MC_Delay_us(500);//delay 500us
 */
void MC_Delay_us(uint32_t xus)
{
    int j;
    for(j=xus; j > 0; j--);
}
