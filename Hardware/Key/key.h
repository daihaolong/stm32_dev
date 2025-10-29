#ifndef __KEY_H__
#define __KEY_H__

#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
void Key_Init(void);

typedef enum 
{
    none_plan = -1,
    plan1,
    plan2,
    plan3
} LED_PLAN_STATUS;

#endif /* __KEY_H__ */


