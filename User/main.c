#include "stm32f10x.h"

void Delay_us(uint16_t us);
void Delay_ms(uint16_t ms);
void Delay_s(uint16_t s);

int main(void){

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

while (1){

// 开启LED1  然后延迟500ms
GPIOA->ODR &= ~GPIO_ODR_ODR0;
Delay_ms(500);
GPIOA->ODR |= GPIO_ODR_ODR0;

// 开启LED2  然后延迟500ms
GPIOA->ODR &= ~GPIO_ODR_ODR1;
Delay_ms(500);
GPIOA->ODR |= GPIO_ODR_ODR1;

// 开启LED3  然后延迟500ms
GPIOA->ODR &= ~GPIO_ODR_ODR8;
Delay_ms(500);
GPIOA->ODR |= GPIO_ODR_ODR8;

};


}

void Delay_us(uint16_t us){

    //1. 装载值
    SysTick->LOAD = 72 * us;
    //2. 配置系统时钟1 且不产生中断0 使能定时器1

    SysTick->CTRL = 0x05;

    // 3等待计数为0
    while ( (SysTick->CTRL & SysTick_CTRL_COUNTFLAG) == 0 )
    {
        /* code */
    }
    // 关闭定时器
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE;
    
}


void Delay_ms(uint16_t ms){

    while (ms--)
    {
        /* code */
         Delay_us(1000);
    }
    
       
    
    

}


void Delay_s(uint16_t s){

    while (s--)
    {
        /* code */
        Delay_ms(1000);
    }
    
    

}

