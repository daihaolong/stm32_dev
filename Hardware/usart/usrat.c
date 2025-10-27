#include "usrat.h"
uint8_t receive_complete=0;
void USART_Init(void){
    //配置时钟
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    
    // 配置工作模式
    // PA9是TX，发送，也就是输出，需要推挽输出 ,MODE 11 CNF 10
    // PA10是RX，接收，也就是输入，需要浮空输入, MODE00 CNF 01
    GPIOA->CRH |= GPIO_CRH_MODE9;
    GPIOA->CRH &= ~GPIO_CRH_CNF9_0;
    GPIOA->CRH |= GPIO_CRH_CNF9_1;

    GPIOA->CRH &= ~GPIO_CRH_MODE10;
    GPIOA->CRH |= GPIO_CRH_CNF10_0;
    GPIOA->CRH &= ~GPIO_CRH_CNF10_1;

    // 串口配置
    USART1->BRR = 0x271;


    // 串口使能
    USART1->CR1 |= (USART_CR1_UE| USART_CR1_TE | USART_CR1_RE) ;

    // 其他配置 
    USART1->CR1 &= ~USART_CR1_M;
    USART1->CR1 &= ~USART_CR1_PCE;

    // 使能中断
    USART1->CR1 |= (USART_CR1_RXNEIE | USART_CR1_IDLEIE);

    // NVIC配置
    NVIC_SetPriorityGrouping(3);
    NVIC_SetPriority(USART1_IRQn, 3);
    NVIC_EnableIRQ(USART1_IRQn);
    
    
}

void USART_SendChar(uint8_t ch){
    //判断SR_TXE是否为空，为1发完了，为0还没发完
    while ((USART1->SR & USART_SR_TXE) == 0)
    {
        /* code */
    };
    USART1->DR = ch;
    
}


void USART_SendString(uint8_t *string, uint8_t lenth){


    for (uint8_t i = 0; i < lenth; i++)
    {
        /* code */
        USART_SendChar(string[i]);
    }
    
    
    

}



//中断服务程序
void USART1_IRQHandler(void){

    if (USART1->SR & USART_SR_RXNE)
    {
        /* 接收完成一个字符 */
        buffer[lenth++] = USART1->DR;

    }
    else if (USART1->SR & USART_SR_IDLE)
    {   //字符串整体接收完成
        USART1->DR;   //清除idle标志位
        receive_complete = 1;
    }

    

}


int fputc(int c, FILE *file)
{
    USART_SendChar((uint8_t) c);
    return c;
}

