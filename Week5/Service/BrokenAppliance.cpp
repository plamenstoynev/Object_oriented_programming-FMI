#include "BrokenAppliance.h"

BrokenAppliance::BrokenAppliance(const char* product, double price, bool isInWarranty){
    setProduct(product);
    setPrice(price);
    setWarranty(isInWarranty);
}


Category BrokenAppliance::getProduct() const{

}

double BrokenAppliance::getPrice() const{

}

bool BrokenAppliance::getWarranty() const{

}

void BrokenAppliance::setProduct(const char* product){
    Category product = Technic::getProduct(product);
}

void BrokenAppliance::setPrice(double price){

}

void BrokenAppliance::setWarranty(bool warranty){

}