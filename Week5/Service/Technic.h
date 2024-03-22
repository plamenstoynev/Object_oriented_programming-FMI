#ifndef OOP_PRACT_TECHNIC_H
#define OOP_PRACT_TECHNIC_H
#pragma once

const unsigned MAX_NAME_LENGTH = 32;
const unsigned MAX_ID_LENGTH = 10;
const unsigned Products = 9;

enum Category{
    TV,
    PC,
    Phone,
    Fridge,
    WashingMachine,
    DishWasher,
    Microwave,
    Oven,
    AirConditioner
};

class Technic {
private:
    char name[MAX_NAME_LENGTH + 1] = "Unknown";
    char ID[MAX_ID_LENGTH + 1] = "0000000000";
    bool productsCanRepair[Products] = {0,0,0,0,0,0,0,0,0};
    double profit = 0;
    unsigned countRepairs = 0;
public:
    Technic() = default;
    Technic(const char* name, const char* ID, bool* products);

    const char* getName() const;
    const char* gatID() const;
    const bool* getProducts() const;
    unsigned getCountRepairs() const;

    void setName(const char* name);
    void setID(const char* ID);
    void setProduct(const char* product);
    void setProducts(bool* Products);
};


#endif //OOP_PRACT_TECHNIC_H
