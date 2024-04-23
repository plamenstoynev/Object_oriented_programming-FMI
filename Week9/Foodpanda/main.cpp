#include <iostream>
#include "Restaurant.h"
int main(){
    MyString* products[3];
    products[0] = new MyString("Pizza");
    products[1] = new MyString("Pasta");
    Product product(products, 3);
    std::cout << *product.products[0] << std::endl;

    product.products[2] = new MyString("Milk");
    return 0;
}