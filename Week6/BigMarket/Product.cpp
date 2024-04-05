#include <ostream>
#include "Product.h"

Product::Product(const char* name, double price, unsigned quantity){
    setName(name);
    setPrice(price);
    setQuantity(quantity);
}

Product::Product(const Product& other){
    copyFrom(other);
}

Product& Product::operator=(const Product& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

Product& Product::operator++() {
    this->quantity++;
    return *this;
}

Product& Product::operator++(int) {
    this->quantity++;
    return *this;
}

const char* Product::getName() const{
    return this->name;
}

double Product::getPrice() const{
    return this->price;
}

unsigned Product::getQuantity() const{
    return this->quantity;
}

void Product::setName(const char* name){
    if(this->name != name || name){
        unsigned lengthName = strlen(name);
        this->name = new char[lengthName + 1];
        strcpy(this->name, name);
    }
    else
        return;
}

void Product::setPrice(double price){
    if(price > 0)
        this->price = price;
    else
        return;
}

void Product::setQuantity(unsigned quantity){
    if(quantity > 0)
        this->quantity = quantity;
    else
        return;
}

Product::~Product(){
    free();
}

void Product::copyFrom(const Product &other) {
    unsigned lengthName = strlen(other.name);
    this->name = new char[lengthName + 1];
    strcpy(this->name, other.name);

    this->price = other.price;
    this->quantity = other.quantity;
}

void Product::free() {
    delete[] name;
    name = nullptr;

    price = 0;
    quantity = 0;
}

std::ostream& operator<<(std::ostream& os, const Product& product){
    return os << "Product:" << product.getName() << " price:" << product.getPrice() << " quantity:" << product.getQuantity();
}