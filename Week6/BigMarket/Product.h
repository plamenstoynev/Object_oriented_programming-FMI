#pragma once
#include <cstring>
#include <iostream>

class Product {
private:
    char* name = nullptr;
    double price = 0;
    unsigned quantity = 0;
public:
    Product() = default;
    Product(const char* name, double price, unsigned quantity);
    Product(const Product& other);
    Product& operator=(const Product& other);
    Product& operator++();
    Product& operator++(int);

    const char* getName() const;
    double getPrice() const;
    unsigned getQuantity() const;

    void setName(const char*);
    void setPrice(double price);
    void setQuantity(unsigned quantity);

    friend std::istream& operator>>(std::istream& is, Product& product);

    ~Product();
private:
    void copyFrom(const Product& other);
    void free();
};

std::ostream& operator<<(std::ostream& os, const Product& product);
