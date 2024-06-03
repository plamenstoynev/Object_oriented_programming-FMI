#pragma once
#include "PartialFunction.hpp"

class maximumFunction : public PartialFunction{
private:
    PartialFunction** functions;
    size_t size;
public:
    maximumFunction(PartialFunction** functions, size_t size){
        this->size = size;
        this->functions = new PartialFunction*[size];
        for(unsigned i = 0; i < size; i++)
            this->functions[i] = functions[i]->clone();
    }

    maximumFunction(const maximumFunction& other){
        copyFrom(other);
    }
    maximumFunction(maximumFunction&& other){
        moveFrom(std::move(other));
    }
    maximumFunction& operator=(const maximumFunction& other){
        if(this != &other){
            free();
            copyFrom(other);
        }
        return *this;
    }
    maximumFunction& operator=(maximumFunction&& other){
        if(this != &other){
            free();
            moveFrom(std::move(other));
        }
        return *this;
    }

    bool isDefinedAt(int32_t x) const override{
        for(unsigned i = 0; i < this->size; i++)
            if(functions[i]->isDefinedAt(x))
                return true;
        return false;
    }

    int32_t calculate(int32_t x) const override {
        int32_t max = INT32_MIN;
        for (unsigned i = 0; i < this->size; i++)
            if(this->functions[i]->calculate(x) > max)
                max = this->functions[i]->calculate(x);
        return max;
    }

    int32_t operator()(int32_t x) const override{
        return calculate(x);
    }

    PartialFunction* clone() const override{
        return new maximumFunction(*this);
    }

    ~maximumFunction(){
        free();
    }
private:
    void copyFrom(const maximumFunction& other){
        this->size = other.size;
        this->functions = new PartialFunction*[this->size];
        for(unsigned i = 0; i < this->size; i++)
            this->functions[i] = other.functions[i];
    }
    void moveFrom(maximumFunction&& other){
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