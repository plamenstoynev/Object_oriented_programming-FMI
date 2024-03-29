#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(const Product* products, unsigned productsSize, unsigned productsCount){
    this->productsCount = productsCount;
    setProductsSize(productsSize);
    setProducts(products);
}

ShoppingCart::ShoppingCart(const ShoppingCart& other){
    copyFrom(other);
}

ShoppingCart& ShoppingCart::operator=(const ShoppingCart& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

Product* ShoppingCart::getProducts() const{
    return this->products;
}

unsigned ShoppingCart::getProductsSize() const{
    return this->productsSize;
}

unsigned ShoppingCart::getProductsCount() const {
    return this->productsCount;
}

void ShoppingCart::setProducts(const Product* products){
    this->products = new Product[this->productsSize];
    for (unsigned i = 0; i < this->productsCount; ++i)
        this->products[i] = products[i];
}

void ShoppingCart::setProductsSize(unsigned productsSize){
    if(productsSize > 0)
        this->productsSize = productsSize;
    else
        return;
}

bool ShoppingCart::checkProduct(const Product &product) const {
    for(unsigned i = 0; i < this->productsCount; i++)
        if(strcmp(this->products[i].getName(), product.getName()))
            return true;

    return false;
}

void ShoppingCart::addProduct(const Product& product){
    if(this->productsCount != this->productsSize){
        if(checkProduct(product))
            return;
        else{
            this->products[this->productsCount] = product;
            this->productsCount++;
        }
    }
    else
        return;
}

void ShoppingCart::removeProduct(const Product& product){
    Product temp{};
    if(checkProduct(product)){
        for(unsigned i = 0; i < this->productsCount; i++)
            if(this->products[i].getName(), product.getName()) {
                temp = this->products[i];
                this->products[i] = this->products[this->productsCount];
                this->products[this->productsCount] = temp;
                this->productsCount--;
            }
    }
    else
        return;

}
bool ShoppingCart::isEmpty() const{
    return this->productsCount == 0;
}

double ShoppingCart::priceOfProducts() const{
    double result = 0;

    for(unsigned i = 0; i < this->productsCount; i++)
        result += this->products[i].getPrice();

    return result;
}

ShoppingCart::~ShoppingCart(){
    free();
}

void ShoppingCart::copyFrom(const ShoppingCart &other) {
    this->productsCount = other.productsCount;
    this->productsSize = other.productsSize;
    this->products = new Product[this->productsSize];

    for(unsigned i = 0; i < this->productsCount; i++)
        this->products[i] = other.products[i];

}

void ShoppingCart::free() {
    delete[] products;
    products = nullptr;

    productsCount = 0;
    productsSize = 0;
}