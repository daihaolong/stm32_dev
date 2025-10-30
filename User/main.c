#include "led.h"
#include "timer6.h"
#include "delay.h"



int main(void)
{
    LED_init();
    Timer6_init();
    SysTick_init();

    while (1)
    {
        /* code */


    }

}



