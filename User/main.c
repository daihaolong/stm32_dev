#include "stm32f10x.h"

int main(void){

RCC->APB1ENR |= RCC_APB2ENR_IOPAEN;
GPIOA->CRL = 0X33;
GPIOA->ODR = 0xfffe;

while (1);}
