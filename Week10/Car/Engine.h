#pragma once
#include "CarPart.h"
class Engine : public CarPart{
private:
    unsigned horsePower;
public:
    Engine() = default;
    Engine(unsigned ID,const MyString& nameManufacture, const MyString& description, unsigned horsePower);

    unsigned getHorsePower() const;

    void setHorsePower(unsigned horsePower);
};

std::ostream& operator<<(std::ostream& os, const Engine& engine);