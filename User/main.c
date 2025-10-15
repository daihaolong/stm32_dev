#include "delay.h"
#include "led.h"

int main(void){

uint16_t LEDS[3] = {LED1, LED2, LED3};
// 开启PA的时钟
LED_init();

while (1){

// 开启LED1  然后延迟500ms
for ( uint8_t i = 0; i < 3; i++)
{
    /* code */
    LED_On(LEDS[i]);
    Delay_ms(500);
    LED_Off(LEDS[i]);
}


};


}


