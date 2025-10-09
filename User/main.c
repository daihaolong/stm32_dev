#include "stdint.h"

int main(void){
*(uint32_t *)(0x40021000 + 0x18) = 4;
*(uint32_t *)(0x40010800 + 0x00) = 3;
*(uint32_t *)(0x40010800 + 0x0c) = 0xfffe;
while (1);}
