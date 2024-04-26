#pragma once
#include "Category.h"

class BrokenAppliance {
private:
    Category product = Category::TV;
    double price = 0.00;
    bool isInWarranty = true;

public:
    BrokenAppliance() = default;
    BrokenAppliance(Category product, double price, bool isInWarranty);

    Category getProduct() const;
    double getPrice() const;
    bool getWarranty() const;

    void setProduct(Category product);
    void setPrice(double price);
    void setWarranty(bool warranty);
};