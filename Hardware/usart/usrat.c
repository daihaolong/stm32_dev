#include "usrat.h"

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
    
    
}

void USART_SendChar(uint8_t ch){
    //判断SR_TXE是否为空，为1 就是空，为0还没空
    while ((USART1->SR & USART_SR_TXE) == 0)
    {
        /* code */
    };
    USART1->DR = ch;
    
}

uint8_t USART_ReceiveChar(void){
//判断SR_RXNE是否为空，1收到数据可以读出，0数据没有收到
    while ((USART1->SR & USART_SR_RXNE) == 0)
    {
        /* code */
    };
    return USART1->DR;
}

void USART_SendString(uint8_t *string, uint8_t lenth){


    for (uint8_t i = 0; i < lenth; i++)
    {
        /* code */
        USART_SendChar(string[i]);
    }
    
    
    

}

void  USART_ReceiveString(uint8_t buffer[], uint8_t * lenth){
    
    uint8_t i = 0;
    while (1)
    {
        while ((USART1->SR & USART_SR_RXNE) == 0){

            if (USART1->SR & USART_SR_IDLE)
            {
                /* code */
                *lenth = i;
                return;
            }
            
        }
        buffer[i++] = USART1->DR;
    }
    
}
