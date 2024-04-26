#include <iostream>
#include "BrokenAppliance.h"

BrokenAppliance::BrokenAppliance(Category product, double price, bool isInWarranty){
    setProduct(product);
    setPrice(price);
    setWarranty(isInWarranty);
}


Category BrokenAppliance::getProduct() const{
    return this->product;
}

double BrokenAppliance::getPrice() const{
    return this->price;
}

bool BrokenAppliance::getWarranty() const{
    return this->isInWarranty;
}

void BrokenAppliance::setProduct(Category product){
     this->product = product;
}

void BrokenAppliance::setPrice(double price){
    if(price > 0)
        this->price = price;
    else
        std::cout << "Price can't be zero or below";
}

void BrokenAppliance::setWarranty(bool warranty){
    this->isInWarranty = warranty;
}