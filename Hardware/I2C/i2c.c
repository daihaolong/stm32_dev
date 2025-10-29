#include "i2c.h"

void I2C_init(void){

    // 开启 GIPO时钟
    
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;
    
    
    // 配置引脚模式，复用开漏输出
    // PB10 SCL 
    // PB11 SDA
    GPIOB->CRH |= GPIO_CRH_MODE10;  // 50MHz
    GPIOB->CRH |= GPIO_CRH_CNF10;    // CNF 11

    
    GPIOB->CRH |= GPIO_CRH_MODE11;   // 50MHz
    GPIOB->CRH |= GPIO_CRH_CNF11;  // CNF 11

    // I2C硬件工作模式

    I2C2->CR1 &= ~I2C_CR1_SMBUS;
    I2C2->CCR &= ~I2C_CCR_FS;
    

    //选择输入时钟频率
    I2C2->CR2 |= 36;
    
    // 配置CCR，对应的传输速率

    I2C2->CCR |= 180;
    
    I2C2->TRISE |= 37;


    I2C2->CR1 |= I2C_CR1_PE;


    

}

//发出起始信号
uint8_t I2C_Start(void){

    I2C2->CR1 |= I2C_CR1_START;
    uint16_t timeout= 0xffff;
    while (((I2C2->SR1 & I2C_SR1_SB)==0) &&  timeout)
    {
        /* code */
        timeout--;
    }

    return timeout ? OK : FAIL;
    

}

//设置发出停止信号
void I2C_Stop(void){

    I2C2->CR1 |= I2C_CR1_STOP;
}

//使能应答信号
void I2C_Ack(void){

    I2C2->CR1 |= I2C_CR1_ACK;
}

//使能非应答信号
void I2C_NAck(void){

    I2C2->CR1 &= ~I2C_CR1_ACK;
}

//发送一个设备地址，并等待应答
uint8_t I2C_SendAddr(uint8_t addr){

    I2C2->DR = addr;
    // 等待应答
    uint16_t timeout= 0xffff;
    while (((I2C2->SR1 & I2C_SR1_ADDR)==0) &&  timeout)
    {
        /* code */
        timeout--;
    }

    // 读一下sr2,清楚ADDR标志位
    if (timeout>0)
    {
        /* code */
        I2C2->SR2;
    }
    
    return timeout ? OK : FAIL;

}

//发送一个字节，并等待应答
uint8_t I2C_SendByte(uint8_t byte){

    uint16_t timeout= 0xffff;
    while (((I2C2->SR1 & I2C_SR1_TXE)==0) &&  timeout)
    {
        /* code */
        timeout--;
    }

    // 将要发的字节放入DR
    I2C2->DR = byte;
    timeout= 0xffff;
    while (((I2C2->SR1 & I2C_SR1_BTF)==0) &&  timeout)
    {
        /* code */
        timeout--;
    }

    return timeout ? OK : FAIL;
}

//主机从slave接收一个字节的数据
uint8_t I2C_ReadByte(void){

    uint16_t timeout= 0xffff;
    while (((I2C2->SR1 & I2C_SR1_RXNE)==0) && timeout)
    {
        /* code */
        timeout--;
    }

    return timeout ? I2C2->DR : FAIL;
    

}

