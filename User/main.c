#include "stm32f10x.h"

int main(void){

RCC->APB1ENR = 4;
GPIOA->CRL = 0X33;
GPIOA->ODR = 0xfffe;

while (1);}
