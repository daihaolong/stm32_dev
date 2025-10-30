
#include "led.h"
#include "delay.h"
#include "key.h"
uint8_t buffer[100];
uint8_t lenth;
LED_PLAN_STATUS led_plans_status;

int main(void)
{
    LED_init();
    SysTick_init();

    while (1)
    {
        /* code */


    }

}



