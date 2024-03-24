#include <iostream>
#include "Technic.h"

Technic::Technic(const char* name, const char* ID, bool* products){
    setName(name);
    setID(ID);
    setProducts(products);
}

const char* Technic::getName() const{
    return this->name;
}

const char* Technic::getID() const{
    return this->ID;
}

const bool* Technic::getProducts() const{
    return this->productsCanRepair;
}

unsigned Technic::getCountRepairs() const{
    return  this->countRepairs;
}

void Technic::setName(const char* name){
    if(isValidName(name))
        strcpy(this->name,name);
    else
        std::cout << "Name is not valid" << std::endl;
}

void Technic::setID(const char* ID){
    if(isValidID(ID))
        strcpy(this->ID, ID);
    else
        std::cout << "ID is not valid" << std::endl;
}

void Technic::setProduct(const char* product){
    Category productType = getProduct(product);
    this->productsCanRepair[productType] = true;
}

void Technic::setProducts(bool* Products){
    size_t numOfProducts = 9;

    for(size_t i = 0; i < numOfProducts; i++)
        this->productsCanRepair[i] = Products[i];
}

bool Technic::canFix(Category product) {
    return this->productsCanRepair[product];
}

