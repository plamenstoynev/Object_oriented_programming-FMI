#include <iostream>
#include "Technic.h"

int main(){
    bool products[9] = {1,0,1,0,0,1,0,0,0};
    Technic technic("Plamen", "0311156778", products);

    std::cout << technic.getName();
    return 0;
}