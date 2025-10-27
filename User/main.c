#include "usrat.h"
#include "delay.h"
#include "string.h"
uint8_t lenth;
uint8_t buffer[100];
extern uint8_t receive_complete;
int main(void){

USART_Init();

while (1){

    if (receive_complete)
    {
        /* code */
        printf("hello world to printf\n");
        printf("%d\n", 123);
        receive_complete = 0;
        USART_SendString(buffer, lenth);
        lenth = 0;
    }
    
    
};


}





