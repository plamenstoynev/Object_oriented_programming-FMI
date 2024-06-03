#pragma once
#include <cstdint>
#include "Pair.cpp"
class Case2 {
private:
    int32_t* x = nullptr;
    size_t size;
public:
    Case2(int32_t* x, size_t size);
    Pair operator()(int32_t x) const;
};