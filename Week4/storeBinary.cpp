#include <iostream>
#include <fstream>
#include <cstring>

struct Product{
    unsigned barcode;
    char* name;
    unsigned quantity;
    double price;

    Product() = default;
    Product(unsigned barcode, const char* name, unsigned quantity, double price){
        this->barcode = barcode;
        this->name = new char[strlen(name)];
        strcpy(this->name, name);
        this->quantity = quantity;
        this->price = price;
    }

    void free(){
        barcode = 0;
        delete[] name;
        name = nullptr;
        quantity = 0;
        price = 0;
    }
};

struct Store{
    char name[30];
    char address[50];
    Product* products;
    double profit;

    Store() = default;
    Store(const char* name, const char* address, Product* products, double profit, size_t sizeOfProducts){
        strcpy(this->name, name);
        strcpy(this->address, address);
        for(size_t i = 0; i < sizeOfProducts; i++){
            this->products[i] = products[i];
        }
        this->profit = profit;
    }

    void free(){
        delete[] products;
        products = nullptr;
        profit = 0;
    }
};

void readStoreToFile(std::ofstream& ofs, Store& store){

}




int main(){

}