#include <stdio.h>
#include <stdint.h>

uint8_t encode(uint8_t num){
    if(num > 9){
        return -1;
    }
    return ~num;
}

uint8_t decode(uint8_t num){
    if(num > 9){
        return -1;
    }
    return ~num;
}