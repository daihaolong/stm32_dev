#include "usrat.h"
#include "delay.h"

int main(void){
uint8_t ch;
USART_Init();
USART_SendChar('c');
while (1){

    ch = USART_ReceiveChar();
    USART_SendChar(ch);
    
};


}





