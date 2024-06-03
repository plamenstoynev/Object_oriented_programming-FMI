#pragma once
#include "PartialFunction.hpp"


class minimumFunction : public PartialFunction{
private:
    PartialFunction** functions = nullptr;
    size_t size;
public:
    minimumFunction(PartialFunction** functions, size_t size){
        this->size = size;
        this->functions = new PartialFunction*[size];
        for(unsigned i = 0; i < size; i++)
            this->functions[i] = functions[i]->clone();
    }

    minimumFunction(const minimumFunction& other) {
        copyFrom(other);
    }
    minimumFunction(minimumFunction&& other) {
        moveFrom(std::move(other));
    }
    minimumFunction& operator=(const minimumFunction& other) {
        if(this != &other){
            free();
            copyFrom(other);
        }
        return *this;
    }
    minimumFunction& operator=(minimumFunction&& other) {
        if(this != &other){
            free();
            moveFrom(std::move(other));
        }
        return *this;
    }

    bool isDefinedAt(int32_t x) const override{
        for(unsigned i = 0; i < this->size; i++)
            if(!this->functions[i]->isDefinedAt(x))
                return false;
        return true;
    }

    int32_t calculate(int32_t x) const override{
        int32_t min = INT32_MAX;
        for (unsigned i = 0; i < this->size; i++)
            if(this->functions[i]->calculate(x) < min)
                min = this->functions[i]->calculate(x);
        return min;
    }

    int32_t operator()(int32_t x) const override{
        return calculate(x);
    }

    PartialFunction* clone() const override{
        return new minimumFunction(*this);
    }

    ~minimumFunction(){
        free();
    }
private:
    void copyFrom(const minimumFunction& other){
        this->size = other.size;
        this->functions = new PartialFunction*[this->size];
        for(unsigned i = 0; i < this->size; i++)
            this->functions[i] = other.functions[i];
    }
    void moveFrom(minimumFunction&& other){
        this->size = other.size;
        this->functions = other.functions;
        other.functions = nullptr;
    }
    void free(){
        for(unsigned i = 0; i < this->size; i++)
            delete this->functions[i];
        delete[] this->functions;
    }
};