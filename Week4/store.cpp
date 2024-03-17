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
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->quantity = quantity;
        this->price = price;
    }

    void increaseQuantity(unsigned quantity) {
        this->quantity += quantity;
    }

    void print() const {
        std::cout << "Barcode: " << this->barcode << std::endl;
        std::cout << "Name: " << this->name << std::endl;
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
    size_t sizeOfProducts;
    Product products[100];
    double profit;

    Store() = default;
    Store(const char* name, const char* address, Product* products, double profit, size_t sizeOfProducts){
        strcpy(this->name, name);
        strcpy(this->address, address);
        this->sizeOfProducts = sizeOfProducts;
        for(size_t i = 0; i < sizeOfProducts; i++){
            this->products[i] = products[i];
        }
        this->profit = profit;
    }

    size_t searchProductByBarcode(unsigned barcode) const {
        for(size_t i = 0; i < this->sizeOfProducts; i++){
            if(this->products[i].barcode == barcode) {
                return i;
            }
        }
        return -1;
    }

    bool isAvailable(unsigned barcode) const {
        size_t temp = searchProductByBarcode(barcode);
        if(temp == -1)
            return false;

        return this->products[temp].quantity >= 0;
    }

    void increaseQuantityOfProduct(unsigned barcode, unsigned quantity){
        size_t temp = searchProductByBarcode(barcode);
        if(temp == -1)
            std::cout << "Product is not available" << std::endl;
        else
            this->products[temp].increaseQuantity(quantity);
    }

    void addProduct(const Product& product){
        this->products[this->sizeOfProducts] = product;
        this->sizeOfProducts++;
    }

    void sellProduct(unsigned barcode, unsigned quantity) {
        if (!isAvailable(barcode))
            std::cout << "Product is not available" << std::endl;
        else {
            size_t temp = searchProductByBarcode(barcode);

            if (this->products[temp].quantity - quantity > 0) {
                this->products[temp].quantity -= quantity;
                this->profit += this->products[temp].price * quantity;
                std::cout << "You buy: " << quantity << " " << this->products[temp].name << std::endl;
            } else
                std::cout << "The store doesn't have quantity you want" << std::endl;
        }
    }

    void print() const {
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Address: " << this->address << std::endl;
        std::cout << "Profit: " << this->profit << std::endl;
        std::cout << "Products: " << std::endl;
        for (size_t i = 0; i < this->sizeOfProducts; i++)
            this->products[i].print();

    }

    void free(){
        for(size_t i = 0;i < this->sizeOfProducts;i++)
            this->products[i].free();
        sizeOfProducts = 0;
        profit = 0;
    }
};

void initProduct(Product& product){
    size_t size = 1000;
    char* name = new char[size];
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
    Product* products = new Product[4];
    Product p1(1, "Milk", 10, 2.5);
    Product p2(2, "Bread", 20, 1.5);
    Product p3(3, "Cheese", 5, 3.5);
    Product p4(4, "Yogurt", 15, 1.2);
    Product p5(5, "Chocolate", 30, 2.0);
    products[0] = p1;
    products[1] = p2;
    products[2] = p3;
    products[3] = p4;

    Store store("Kaufland", "Sofia", products, 1000, 4);

    store.print();
    std::cout << "-------------------" << std::endl;
    std::cout << "Buy 5 milks" << std::endl;
    store.sellProduct(1, 5);

    std::cout << "-------------------" << std::endl;
    std::cout << "Increase quantity of milk" << std::endl;
    store.increaseQuantityOfProduct(1, 4);

    std::cout << "-------------------" << std::endl;
    std::cout << "Add new product" << std::endl;
    store.addProduct(p5);
    store.print();


    store.free();
    return 0;
}