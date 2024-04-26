#pragma once
#include "Restaurant.h"
#include "Order.h"

class Foodpanda {
private:
    Restaurant* restaurants = nullptr;
    size_t sizeOfRestaurants = 0;
public:
       Foodpanda() = default;
       Foodpanda(Restaurant* restaurant, size_t sizeOfRestaurant);
       Foodpanda(const Foodpanda& other) = delete;
       Foodpanda& operator=(const Foodpanda& other) = delete;

       bool canMakeOrder(const Order& order) const;
private:
    void free();
};