#include "FuelTank.h"
#include "Engine.h"
#include "Tier.h"
#include "Accumulator.h"
class Car {
private:
    FuelTank fuelTank;
    Engine engine;
    Tier tiers[4];
    Accumulator accumulator;
    double kmDrive;
    double weight;

public:
    Car() = default;
    Car(FuelTank fuelTank, Engine engine, Tier tiers[4], Accumulator accumulator, double kmDrive, double weight);

    FuelTank getFuelTank() const;

    void drive(double km);
};