#include "FuelTank.h"

FuelTank::FuelTank(double size){
    this->size = size;
    this->capacity = size;
}

double FuelTank::getSize() const{
    return this->size;
}
double FuelTank::getCapacity() const{
    return this->capacity;
}

void FuelTank::use(double usingFuel){
    if(canUse(usingFuel))
        throw std::invalid_argument("Don't have enough fuel");

    this->capacity -= usingFuel;
}
void FuelTank::reload(double reload){
    this->capacity += reload;

    if(this->capacity > this->size)
        this->capacity = this->size;
}

bool FuelTank::canUse(double usingFuel) const {
    return this->capacity - usingFuel < 0;
}