#include "Order.h"

Order::Order(const MyString& restaurantName, const Product products, size_t sizeOfProducts){
    this->restaurantName = restaurantName;
    this->products = products;
    this->sizeOfProducts = sizeOfProducts;
}

MyString Order::getRestaurantName() const {
    return this->restaurantName;
}
size_t Order::getSize() const {
    return this->sizeOfProducts;
}
Product Order::gerProduct() const {
    return this->products;
}