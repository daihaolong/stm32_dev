#include "m24c02.h"
#include "usrat.h"
#include <string.h>
#include "led.h"
#include "key.h"
uint8_t lenth;
uint8_t buffer[100];
extern uint8_t receive_complete;
uint32_t led_plans[3][2];
LED_PLAN_STATUS led_plans_status = none_plan;
void LoadPlans(uint8_t * str);
void LedFlow(void);


int main(void)
{
    LED_init();
    M24C02_Init();
    USART_Init();
    Key_Init();

    while (1)
    {
        /* code */
        if (receive_complete)
        {
            /* code */
            receive_complete = 0;
            M24C02_WriteBytes(0X00, buffer, lenth);
            lenth = 0;
            LoadPlans(buffer);
        }
        
        LedFlow();
        
    }

}


void LoadPlans(uint8_t * str){
    sscanf((char *)str, "%d,%d#%d,%d#%d,%d", 
        &led_plans[0][0], &led_plans[0][1],
        &led_plans[1][0], &led_plans[1][1],
        &led_plans[2][0], &led_plans[2][1]);
    
    for (uint8_t i = 0; i < 3; i++)
        {
            for (uint8_t j = 0; j < 2; j++)
            {   
                switch (led_plans[i][j])
                {
                case 1:
                    led_plans[i][j] = LED1;
                    break;
                case 2:
                    led_plans[i][j] = LED2;
                    break;
                case 3:
                    led_plans[i][j] = LED3;
                    break;
                default:
                    break;

                }
                
            }

            
        }

}

void LedFlow(void){
    switch (led_plans_status)
    {
    case plan1:
    for (uint8_t i = 0; i < 2; i++)
    {
        /* code */
        LED_On(led_plans[0][i]);
        Delay_ms(500);
        LED_Off(led_plans[0][i]);
    }
        break;
    case plan2:
        /* code */
    for (uint8_t i = 0; i < 2; i++)
    {
        /* code */
        LED_On(led_plans[1][i]);
        Delay_ms(500);
        LED_Off(led_plans[1][i]);
    }
        break;
    case plan3:
        /* code */
    for (uint8_t i = 0; i < 2; i++)
    {
        /* code */
        LED_On(led_plans[2][i]);
        Delay_ms(500);
        LED_Off(led_plans[2][i]);
    }
        break;
    default:
        break;
    }
}






