#pragma once
#include "../../String/MyString.h"
#include "Restaurant.h"

class Order {
private:
    MyString restaurantName;
    size_t sizeOfProducts = 0;
    Product products;
public:
    Order() = default;
    Order(const MyString& restaurantName, const Product products, size_t sizeOfProducts);

    MyString getRestaurantName() const;
    size_t getSize() const;
    Product gerProduct() const;
};