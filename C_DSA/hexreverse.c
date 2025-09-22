#include <stdio.h>
#include <stdint.h>

uint32_t revHex(uint32_t tempNum){
    
    uint32_t result =0 ;
    
    uint8_t temp[4]={0};
    uint8_t i=0;
    for(i=0;tempNum;i++){
        temp[i]=(tempNum)&0xff;                             //get the last 8 bits
        temp[i]=(((temp[i]<<4)&0xf0)|((temp[i]>>4)&0x0f)); //swap the 4 bits
        tempNum=(tempNum>>8);                             //right shift 8 bit
        result=(result<<8)|(temp[i]);                     //left shift 8 bit and add the new 8 bits
    }
    return result;
}

int main()
{
    uint32_t a = 0x123456;
    uint32_t result = 0;
    result = revHex(a);
    printf("0x%x\n", a);
    printf("0x%x \n", result);
    return 0;
}
