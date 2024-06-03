#pragma once
#include <cstdint>
#include <iostream>
#include <exception>
class PartialFunction {
public:
    virtual ~PartialFunction(){}

    virtual bool isDefinedAt(int32_t x) const = 0;

    virtual int32_t calculate(int32_t x) const = 0;

    virtual int32_t operator()(int32_t x) const = 0;

    virtual PartialFunction* clone() const = 0;
};