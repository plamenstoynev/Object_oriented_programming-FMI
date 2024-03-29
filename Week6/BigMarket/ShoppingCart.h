#pragma once
#include "Product.h"
class ShoppingCart {
private:
    Product* products = nullptr;
    unsigned productsSize = 0;
    unsigned productsCount = 0;

public:
    ShoppingCart() = default;
    ShoppingCart(const Product* products, unsigned productsSize, unsigned productsCount);
    ShoppingCart(const ShoppingCart& other);
    ShoppingCart& operator=(const ShoppingCart& other);

    Product* getProducts() const;
    unsigned getProductsSize() const;
    unsigned getProductsCount() const;

    void setProducts(const Product* products);
    void setProductsSize(unsigned productsSize);

    bool checkProduct(const Product& product) const;
    void addProduct(const Product& product);
    void removeProduct(const Product& product);
    bool isEmpty() const;
    double priceOfProducts() const;


    ~ShoppingCart();

private:
    void copyFrom(const ShoppingCart& other);
    void free();
};