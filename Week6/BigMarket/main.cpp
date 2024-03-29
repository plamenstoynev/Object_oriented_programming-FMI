#include <iostream>
#include <fstream>
#include "ShoppingCart.h"

const char* FILE_NAME = "products.txt";

void writeProductsInTxtFile(std::ofstream& ofs, const Product* products, unsigned productsCount){
    ofs << productsCount;
    ofs << '\n';

    for(unsigned i = 0; i < productsCount; i++){
        ofs << products[i].getName() << " " << products[i].getPrice() << " " << products[i].getQuantity() << std::endl;
    }
}

void writeProductsInTxtFile(const char* FILE_NAME, const Product* products, unsigned productsCount){
    std::ofstream ofs(FILE_NAME);

    if(!ofs.is_open())
        return;

    writeProductsInTxtFile(ofs, products, productsCount);
}

void readProductsFromTxtFile(std::ifstream& ifs, Product*& products, unsigned productsCount){
    ifs >> productsCount;
    products = new Product[productsCount];
    char name[100];
    double price;
    unsigned quantity;

    for (unsigned i = 0; i < productsCount; ++i) {
        ifs >> name >> price >> quantity;

        products[i].setName(name);
        products[i].setPrice(price);
        products[i].setQuantity(quantity);
    }

}

void readProductsFromTxtFile(const char* FILE_NAME, Product*& products, unsigned productsCount){
    std::ifstream ifs(FILE_NAME);

    if(!ifs.is_open())
        return;

    readProductsFromTxtFile(ifs, products, productsCount);
}

int main(){
}