#include "key.h"
extern LED_PLAN_STATUS led_plans_status;
void Key_Init()
{
    // 开启时钟
    RCC->APB2ENR |= RCC_APB2ENR_IOPFEN;
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
    
    // GPIOF10引脚输入模式mode00 下拉输入cnf10
    GPIOF->CRH &= ~GPIO_CRH_MODE10;
    GPIOF->CRH &= ~GPIO_CRH_CNF10_0;
    GPIOF->CRH |= GPIO_CRH_CNF10_1;

    GPIOF->ODR &= ~GPIO_ODR_ODR10;
 
    // AFIO配置引脚复用选择器
    AFIO->EXTICR[2] |= AFIO_EXTICR3_EXTI10_PF;

    // EXTI配置

    EXTI->RTSR |= EXTI_RTSR_TR10;
    EXTI->IMR |= EXTI_IMR_MR10;

    //配置nvic

    NVIC_SetPriorityGrouping(3);   //全部都是抢占优先级
    NVIC_SetPriority(EXTI15_10_IRQn, 3);
    NVIC_EnableIRQ(EXTI15_10_IRQn);
    
}


void EXTI15_10_IRQHandler(void ){

    EXTI->PR |= EXTI_PR_PR10;
    Delay_ms(10);
    if ((GPIOF->IDR & GPIO_IDR_IDR10)!=0)
    {
        /* code */
        // LED_Toggle(LED1);
        led_plans_status = (LED_PLAN_STATUS)((led_plans_status + 1) % 3) ;
    }
    

}

