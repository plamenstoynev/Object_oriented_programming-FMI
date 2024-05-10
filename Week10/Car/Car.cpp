#include "Car.h"

Car::Car(FuelTank fuelTank, Engine engine, Tier tiers[4], Accumulator accumulator, double kmDrive, double weight){
    this->fuelTank = fuelTank;
    this->engine = engine;
    for(int i = 0; i < 4; i++)
        this->tiers[i] = tiers[i];
    this->accumulator = accumulator;
    this->kmDrive = kmDrive;
    this->weight = weight;
}

FuelTank Car::getFuelTank() const {
    return this->fuelTank;
}

void Car::drive(double km) {
    if(this->getFuelTank().canUse(km)){
        this->fuelTank.use(km);
        this->kmDrive += km;
    }
}