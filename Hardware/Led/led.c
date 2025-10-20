#include "led.h"

void LED_init(void){
// 开启PA的时钟
RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;


// 关闭LED1 PA0 



GPIOA->CRL |= GPIO_CRL_MODE0;
GPIOA->CRL &= ~GPIO_CRL_CNF0;
GPIOA->ODR |= GPIO_ODR_ODR0;

// 关闭LED2 PA1 



GPIOA->CRL |= GPIO_CRL_MODE1;
GPIOA->CRL &= ~GPIO_CRL_CNF1;
GPIOA->ODR |= GPIO_ODR_ODR1;

// 关闭LED1 PA8 


GPIOA->CRH |= GPIO_CRH_MODE8;
GPIOA->CRH &= ~GPIO_CRH_CNF8;
GPIOA->ODR |= GPIO_ODR_ODR8;

}

void LED_On(uint16_t led){
GPIOA->ODR &= ~led;

}

void LED_Off(uint16_t led){

GPIOA->ODR |= led;
}

void LED_Toggle(uint16_t led){

    if ((GPIOA->IDR & led) != 0 )
    {
        /* 读取IDR可以判断ODR的输出数据 */
        LED_On(led);

    }
    else
    {
        /* code */
        LED_Off(led);
    }
    
    

}


void LED_On_All(uint16_t led[], uint8_t size){
    
    for (uint8_t i=0; i < size; i++)
    {
        /* code */
        LED_On(led[i]);

    }
    

}
void LED_Off_All(uint16_t led[], uint8_t size){
    for (uint8_t i= 0; i < size; i++)
    {
        /* code */
        LED_Off(led[i]);

    }
}

