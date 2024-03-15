#include <iostream>
#include <fstream>
#include <cstring>

struct Product{
    unsigned barcode;
    char* name;
    unsigned quantity;
    double price;
};

struct Store{
    char name[30];
    char address[50];
    Product* products;
};



int main(){

}