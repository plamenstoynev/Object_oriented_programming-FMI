#pragma once
#include "BrokenAppliance.h"

const unsigned lengthName = 32;

class Client {
private:
    char name[lengthName + 1] = "Unknown";
    BrokenAppliance product;

public:
    Client() = default;
    Client(const char* name, const BrokenAppliance& product);

    const char* getName() const;
    BrokenAppliance getProduct() const;

    void setName(const char* name);
    void setProduct(const BrokenAppliance& product);
};