#pragma once
#include "Pair.cpp"
class Case0{
private:
    int32_t* x = nullptr;
    size_t size;
    Pair* pairs= nullptr;
public:
    Case0(int32_t* x,int32_t* values, uint16_t sizeOfNumbers);
    Pair operator()(int32_t x) const;
private:

};