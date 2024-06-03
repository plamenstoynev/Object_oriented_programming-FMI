#pragma once
#include "PartialFunction.hpp"
#include "Pair.cpp"
template <class T>
class ByCriteria : public PartialFunction{
private:
    const T& function;
public:
    ByCriteria(const T& function) : function(function){}

    bool isDefinedAt(int32_t x) const override{
        Pair pair = function(x);
        return pair.getDefined(x);
    }
    
    int32_t calculate(int32_t x) const override{
        Pair pair = function(x);
        return pair.getResult(x);
    }

    int32_t operator()(int32_t x) const override{
        return calculate(x);
    }

    PartialFunction* clone() const override{
        return new ByCriteria(*this);
    }
};