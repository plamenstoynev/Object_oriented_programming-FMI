#include "Foodpanda.h"

Foodpanda::Foodpanda(Restaurant* restaurants, size_t sizeOfRestaurants) {
    this->sizeOfRestaurants = sizeOfRestaurants;
    this->restaurants = new Restaurant[sizeOfRestaurants];
    for(unsigned i = 0; i < sizeOfRestaurants; i++)
        this->restaurants[i] = restaurants[i];
}

bool Foodpanda::canMakeOrder(const Order &order) const {
    unsigned helper = 0;
    for(unsigned i = 0; i < this->sizeOfRestaurants; i++){
        if(this->restaurants[i].getName().c_str() != order.getRestaurantName())
            return false;
        else {
            helper = i;
            break;
        }
    }
    unsigned helperProducts = 0;
    unsigned index = 0;
    while(helperProducts != order.getSize()){
        if(order.gerProduct().products[index] == this->restaurants[helper].getProduct().products[helperProducts]){
            helperProducts++;
            index = 0;
        }
        index++;
    }
    return helperProducts == order.getSize();
}