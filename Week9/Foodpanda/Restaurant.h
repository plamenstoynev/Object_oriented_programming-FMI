#pragma once
#include "..\..\String\MyString.h"

struct Product{
    MyString** products;
    size_t size;

    Product() = default;
    Product(MyString** products, size_t size){
        this->size = size;
        this->products = new MyString* [size];

        int helper = 0;
        while(helper != size){
            this->products[helper] = products[helper];
            helper++;
        }
    }
    Product(const Product& other){
        copyFrom(other);
    }
    Product& operator=(const Product& other){
        if(this != & other){
            free();
            copyFrom(other);
        }
    }
    ~Product(){
        free();
    }
private:
    void copyFrom(const Product& other) {
        this->size = other.size;
        this->products = new MyString *[other.size];

        int helper = 0;
        while (helper != this->size) {
            this->products[helper] = other.products[helper];
            helper++;
        }
    }
    void free(){
        for(int i = 0; i < size; i++){
            delete products[i];
        }
        delete[] products;
        this->size = 0;
    }
};


class Restaurant{
private:
    MyString name;
    Product products;
public:
    Restaurant() = default;
    Restaurant(const MyString& name, Product product);

    MyString getName() const;
    Product getProduct() const;
    MyString getProducts(unsigned index) const;

    void setName(const MyString& name);
    void setProducts(const Product& products);
};