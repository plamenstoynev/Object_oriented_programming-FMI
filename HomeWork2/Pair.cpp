#pragma once
#include <cstdint>

struct Pair{
    int32_t result = 0;
    bool isDefined = false;

    Pair() = default;

    Pair(int32_t result){
        this->result = result;
        this->isDefined = true;
    }

    int32_t getResult(int32_t x) const{
        return this->result;
    }

    bool getDefined(int32_t x) const{
        return this->isDefined;
    }

    void setResult(int32_t result){
        this->result = result;
    }

    void setDefine(bool define){
        this->isDefined = define;
    }

    Pair operator()(int32_t x) const{
        return *this;
    }
};