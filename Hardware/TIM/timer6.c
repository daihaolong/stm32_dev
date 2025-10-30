#include "timer6.h"
#include "led.h"
void Timer6_init(void)
{   
    RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
    TIM6->PSC = 7200 - 1;   // 72 M / 7200 = 10000Hz = 0.1 ms
    TIM6->ARR = 10000 - 1;
    TIM6->DIER |= TIM_DIER_UIE;
    
    
    NVIC_SetPriorityGrouping(3);
    NVIC_SetPriority(TIM6_IRQn, 1);
    NVIC_EnableIRQ(TIM6_IRQn);

    TIM6->CR1 |= TIM_CR1_CEN;

}

uint8_t first_flag = 0;

void TIM6_IRQHandler(void){


    TIM6->SR &= ~TIM_SR_UIF;
    if (first_flag==0)
    {
        /* code */
        first_flag = 1;
        return;
    }
    
    LED_Toggle(LED2);
}

