#include "m24c02.h"
#include "delay.h"

void M24C02_Init(void){
    I2C_init();
}

void M24C02_WriteByte(uint8_t innerAddr, uint8_t byte){

    I2C_Start();
    I2C_SendAddr(W_ADDR);
    I2C_SendByte(innerAddr);
    I2C_SendByte(byte);
    I2C_Stop();
    Delay_ms(5);

}
uint8_t M24C02_ReadByte(uint8_t innerAddr){
    
    I2C_Start();
    I2C_SendAddr(W_ADDR);
    I2C_SendByte(innerAddr);
    I2C_Start();
    
    I2C_SendAddr(R_ADDR);
    I2C_NAck();
    I2C_Stop();
    uint8_t byte;
    byte = I2C_ReadByte();
    return byte;
}

void M24C02_WriteBytes(uint8_t innerAddr, uint8_t * byte, uint8_t size){

    I2C_Start();
    I2C_SendAddr(W_ADDR);
    I2C_SendByte(innerAddr);
    for (uint8_t i = 0; i < size; i++)
    {
        /* code */
        I2C_SendByte(byte[i]);
    }
    
    I2C_Stop();
    Delay_ms(5);
    
}
void M24C02_ReadBytes(uint8_t innerAddr, uint8_t * buffer, uint8_t size){
    I2C_Start();
    I2C_SendAddr(W_ADDR);
    I2C_SendByte(innerAddr);
    I2C_Start();
    I2C_SendAddr(R_ADDR);
    for (uint8_t i = 0; i < size; i++)
    {
        if (i<size-1)
        {
            /* code */
            I2C_Ack();
        }
        else
        {
            /* code */
            I2C_NAck();
            I2C_Stop();
        }

        buffer[i] = I2C_ReadByte();
        
        
    }
    
    
    
}

