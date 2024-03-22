#include <iostream>
#include "Client.h"

Client::Client(const char* name, const char* product){
    setName(name);
    setProduct(product);
}

const char* Client::getName() const{
    return this->name;
}

Category Client::getProduct() const{
    return this->product;
}

void Client::setName(const char* name){
    if(isValidName(name))
        strcpy(this->name, name);
    else
        std::cout << "Name is not valid" << std::endl;
}

void Client::setProduct(const char* product){
    this->product = ::getProduct(product);
}