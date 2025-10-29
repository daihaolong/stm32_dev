#include "m24c02.h"
#include "usrat.h"
#include <string.h>

uint8_t lenth;
uint8_t buffer[100];

int main(void){

M24C02_Init();
USART_Init();
printf("I2C exame start\n");

M24C02_WriteByte(0x00, 'a');
M24C02_WriteByte(0x01, 'b');
M24C02_WriteByte(0x02, 'c');

uint8_t byte1 = M24C02_ReadByte(0x00);
uint8_t byte2 = M24C02_ReadByte(0x01);
uint8_t byte3 = M24C02_ReadByte(0x02);

printf("byte1 = %c\t byte2 = %c\t byte3 = %c\t \n", byte1, byte2, byte3);

M24C02_WriteBytes(0x10, "123456", 6);
uint8_t buff[100] = {0};
M24C02_ReadBytes(0x10, buff, 6);
printf("%s\r\n", buff);
memset(buff, 0, 6);

M24C02_WriteBytes(0x20, "0123456789abcdefghijk", 21);

M24C02_ReadBytes(0x20, buff, 21);
printf("%s\r\n", buff);
}





