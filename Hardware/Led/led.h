#ifndef __LED_H__
#define __LED_H__
#include "stm32f10x.h"

#define LED1 GPIO_ODR_ODR0
#define LED2 GPIO_ODR_ODR1
#define LED3 GPIO_ODR_ODR8

void LED_init(void);

void LED_On(uint16_t led);

void LED_Off(uint16_t led);

void LED_Toggle(uint16_t led);


void LED_On_All(uint16_t led[], uint8_t size);
void LED_Off_All(uint16_t led[], uint8_t size);


#endif /* __LED_H__ */

