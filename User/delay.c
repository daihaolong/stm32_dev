#include "delay.h"

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
