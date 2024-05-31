#include "Employee.h"
class HourlyEmployee : public Employee{
private:
    unsigned overtime;
public:
    HourlyEmployee() = default;
    HourlyEmployee(const MyString& name, double salary, unsigned overtime);
    double calculateSalary() const override;
};