#include "Accumulator.h"

Accumulator::Accumulator(unsigned ID, const MyString& nameManufacture, const MyString& description, unsigned capacity, const MyString& batteryID) : CarPart(ID< nameManufacture, description){
    setCapacity(capacity);
    setBatteryID(batteryID);
}

unsigned Accumulator::getCapacity() const{
    return this->capacityElectricity;
}
MyString Accumulator::getBatteryID() const{
    return this->batteryID;
}

void Accumulator::setCapacity(unsigned capacity){
    this->capacityElectricity = capacity;
}
void Accumulator::setBatteryID(const MyString& batteryID){
    this->batteryID = batteryID;
}

std::ostream& operator<<(std::ostream& os, const Accumulator& accumulator){
    return operator<<(os, accumulator) << accumulator.getCapacity() << "Ah";
}