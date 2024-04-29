#include "CarPart.h"

CarPart::CarPart(unsigned ID, const MyString& nameManufacture, const MyString& description){
    setID(ID);
    setName(nameManufacture);
    setDescription(description);
}

unsigned CarPart::getID() const{
    return this->ID;
}
MyString CarPart::getName() const{
    return this->nameManufacture;
}
MyString CarPart::getDescription() const{
    return this->description;
}

void CarPart::setID(unsigned ID){
    this->ID = ID;
}
void CarPart::setName(const MyString& name){
    this->nameManufacture = name;
}
void CarPart::setDescription(const MyString& description){
    this->description = description;
}