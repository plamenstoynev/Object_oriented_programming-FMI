#pragma once
#include "CarPart.h"
class Accumulator : public CarPart{
private:
    unsigned capacityElectricity;
    MyString batteryID;
public:
    Accumulator() = default;
    Accumulator(unsigned ID, const MyString& nameManufacture, const MyString& description, unsigned capacity, const MyString& batteryID);

    unsigned getCapacity() const;
    MyString getBatteryID() const;

    void setCapacity(unsigned capacity);
    void setBatteryID(const MyString& batteryID);
};

std::ostream& operator<<(std::ostream& os, const Accumulator& accumulator);