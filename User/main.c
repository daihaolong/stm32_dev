#include "usrat.h"
#include "delay.h"
#include "string.h"
uint8_t lenth;
uint8_t buffer[100];
int main(void){

USART_Init();

while (1){

    USART_ReceiveString(buffer, &lenth);
    USART_SendString(buffer, lenth);
    
};


}





