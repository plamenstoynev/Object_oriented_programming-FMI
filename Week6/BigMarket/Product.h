#pragma once
#include <cstring>

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

    const char* getName() const;
    double getPrice() const;
    unsigned getQuantity() const;

    void setName(const char*);
    void setPrice(double price);
    void setQuantity(unsigned quantity);

    ~Product();
private:
    void copyFrom(const Product& other);
    void free();
};