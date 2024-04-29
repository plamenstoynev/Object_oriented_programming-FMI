#include "../../String/MyString.h"
class CarPart {
private:
    unsigned ID;
    MyString nameManufacture;
    MyString description;
public:
    CarPart() = default;
    CarPart(unsigned ID, const MyString& nameManufacture, const MyString& description);

    unsigned getID() const;
    MyString getName() const;
    MyString getDescription() const;

    void setID(unsigned ID);
    void setName(const MyString& name);
    void setDescription(const MyString& description);
};