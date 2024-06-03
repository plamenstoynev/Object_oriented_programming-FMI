#include "Case1.h"

Case1::Case1(int32_t* x, size_t size){
    this->x = new int32_t[size];
    this->size = size;
    for(unsigned i = 0; i < size; i++){
        this->x[i] = x[i];
    }
}

Pair Case1::operator()(int32_t x) const {
    for (unsigned i = 0; i < this->size; i++) {
        if (this->x[i] == x)
            return Pair();
    }
    return Pair(x);
}
