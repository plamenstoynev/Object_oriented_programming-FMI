#include "helper.cpp"
const unsigned lengthName = 32;

class Client {
private:
    char name[lengthName + 1] = "Unknown";
    Category product = Category::TV;

public:
    Client() = default;
    Client(const char* name, const char* product);

    const char* getName() const;
    Category getProduct() const;

    void setName(const char* name);
    void setProduct(const char* product);
};
