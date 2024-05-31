#include "Employee.h"
class CommisionEmployee : public Employee{
private:
    double commision;
public:
    CommisionEmployee() = default;
    CommisionEmployee(const MyString& name, double salary, double commision);

    double calculateSalary() const override;
};