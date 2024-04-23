#include "Restaurant.h"
Restaurant::Restaurant(const MyString& name, Product product){
    setName(name);
    setProducts(product);
}

MyString Restaurant::getName() const{
    return this->name;
}
Product Restaurant::getProduct() const{
    return this->products;
}
MyString Restaurant::getProducts(unsigned index) const{
    return *this->products.products[index];
}

void Restaurant::setName(const MyString& name){
    this.name = name;
}
void Restaurant::setProducts(const Product& products){
    this->products = products;
}