#include "Case0.h"

Case0::Case0(int32_t* x,int32_t* values, uint16_t sizeOfNumbers){
    this->x = new int32_t[sizeOfNumbers];
    this->size = sizeOfNumbers;
    this->pairs = new Pair[sizeOfNumbers];
    for(unsigned i = 0; i < sizeOfNumbers; i++){
        this->x[i] = x[i];
        this->pairs[i] = Pair(values[i]);
    }
}

Pair Case0::operator()(int32_t x) const {
    for (unsigned i = 0; i < this->size; i++) {
        if (this->x[i] == x)
            return this->pairs[i];
    }
    return Pair();
}