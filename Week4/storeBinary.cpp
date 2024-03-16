#include <iostream>
#include <fstream>
#include <cstring>

struct Product{
    unsigned barcode;
    char* name;
    unsigned quantity;
    double price;

    Product() = default;
    Product(unsigned barcode, const char* name, unsigned quantity, double price){
        this->barcode = barcode;
        this->name = new char[strlen(name)];
        strcpy(this->name, name);
        this->quantity = quantity;
        this->price = price;
    }

    void print(){
        size_t sizeOfName = strlen(this->name);
        std::cout << "Name: ";
        for(size_t i = 0; i < sizeOfName; i++)
            std::cout << this->name[i];
        std::cout << std::endl;

        std::cout << "Barcode: " << this->barcode << std::endl;
        std::cout << "Quantity: " << this->quantity << std::endl;
        std::cout << "Price: " << this->price << std::endl;
    }

    void free(){
        barcode = 0;
        delete[] name;
        name = nullptr;
        quantity = 0;
        price = 0;
    }
};

struct Store{
    char name[30];
    char address[50];
    Product* products;
    double profit;

    Store() = default;
    Store(const char* name, const char* address, Product* products, double profit, size_t sizeOfProducts){
        strcpy(this->name, name);
        strcpy(this->address, address);
        this->products = new Product[sizeOfProducts];
        for(size_t i = 0; i < sizeOfProducts; i++){
            this->products[i] = products[i];
        }
        this->profit = profit;
    }

    void free(){
        delete[] products;
        products = nullptr;
        profit = 0;
    }
};

void initProduct(Product& product){
    size_t size;
    std::cin >> size;

    char* name = new char[size];
    std::cin.ignore();
    std::cin.getline(name,'\n');

    unsigned barcode, quantity;
    std::cin >> barcode >> quantity;

    double price;
    std::cin >> price;

    product = Product(barcode, name, quantity, price);
}

void initStore(Store& store){
    char name[30];
    std::cin.getline(name,30);

    char address[50];
    std::cin.getline(address, 50);

    size_t sizeOfProducts;
    std::cin >> sizeOfProducts;

    Product* products = new Product[sizeOfProducts];
    for(size_t i = 0; i < sizeOfProducts; i++)
        initProduct(products[i]);

    double profit;
    std::cin >> profit;

    store = Store(name, address, products, profit, sizeOfProducts);
}


int main(){
    Store store;
    initStore(store);
    std::cout << store.name;
    return 0;
}