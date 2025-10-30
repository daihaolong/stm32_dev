#include "delay.h"
#include "led.h"
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
    // SysTick->CTRL &= ~SysTick_CTRL_ENABLE;
    
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

void SysTick_init(void){

    SysTick->CTRL = 0x07;
    SysTick->LOAD = 72*1000 - 1;   // ms
    // NVIC_SetPriorityGrouping(3);
    // NVIC_SetPriority(SysTick_IRQn, 3);
    // NVIC_EnableIRQ(SysTick_IRQn);
    
    
   
    

}

uint16_t count = 0;

void SysTick_Handler(){

    count++;
    if (count == 500)
    {
        /* code */
        count = 0;

        LED_Toggle(LED1);
    }
    
    
}
