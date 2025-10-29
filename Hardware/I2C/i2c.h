#ifndef __I2C_H__
#define __I2C_H__

#include "stm32f10x.h"
#define OK 1
#define FAIL 0

void I2C_init(void);

//发出起始信号
uint8_t I2C_Start(void);


//设置发出停止信号
void I2C_Stop(void);


//使能应答信号
void I2C_Ack(void);


//使能非应答信号
void I2C_NAck(void);

//发送一个设备地址，并等待应答
uint8_t I2C_SendAddr(uint8_t addr);

//发送一个字节，并等待应答
uint8_t I2C_SendByte(uint8_t byte);

//主机从slave接收一个字节的数据
uint8_t I2C_ReadByte(void);


#endif /* __I2C_H__ */


