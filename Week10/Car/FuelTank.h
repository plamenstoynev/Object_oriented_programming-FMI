#include <iostream>
class FuelTank {
private:
    double size;
    double capacity;
public:
    FuelTank() = default;
    FuelTank(double size);

    double getSize() const;
    double getCapacity() const;

    void use(double usingFuel);
    void reload(double reload);
};