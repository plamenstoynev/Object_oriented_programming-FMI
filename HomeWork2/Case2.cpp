#include "Case2.h"

Case2::Case2(int32_t* x, size_t size){
    this->x = new int32_t[size];
    this->size = size;
    for(unsigned i = 0; i < size; i++){
        this->x[i] = x[i];
    }
}

Pair Case2::operator()(int32_t x) const {
    for (unsigned i = 0; i < this->size; i++) {
        if (this->x[i] == x)
            return Pair(1);
    }
    return Pair(0);
}