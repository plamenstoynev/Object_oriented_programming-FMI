#include <iostream>

struct Product{
    char description[33];
    int partNum;
    double cost;
};

void inputProduct(Product& product){
    std::cin.ignore();
    std::cin.getline(product.description, '/n');
    std::cin >> product.partNum;
    std::cin >> product.cost;
}



int main(){
    size_t numOfProducts = 5;
    Product products[numOfProducts];
    for (size_t i = 0; i < numOfProducts; ++i) {
        inputProduct(products[i]);
    }

    for (size_t i = 0; i < numOfProducts; ++i) {
        std::cout << products[i].partNum << std::endl;
    }
    return 0;
}