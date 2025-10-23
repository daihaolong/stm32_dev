#include "stm32f10x.h"

void USART_Init(void);

void USART_SendChar(uint8_t ch);

uint8_t USART_ReceiveChar(void);

void USART_SendString(uint8_t *string, uint8_t lenth);

void  USART_ReceiveString(uint8_t *buffer, uint8_t * lenth);
