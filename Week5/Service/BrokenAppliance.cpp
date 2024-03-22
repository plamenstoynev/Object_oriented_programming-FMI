#include <iostream>
#include "BrokenAppliance.h"

BrokenAppliance::BrokenAppliance(const char* product, double price, bool isInWarranty){
    setProduct(product);
    setPrice(price);
    setWarranty(isInWarranty);
}


Category BrokenAppliance::getProduct() const{
    return product;
}

double BrokenAppliance::getPrice() const{
    return price;
}

bool BrokenAppliance::getWarranty() const{
    return isInWarranty;
}

void BrokenAppliance::setProduct(const char* product){
     this->product = ::getProduct(product);
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