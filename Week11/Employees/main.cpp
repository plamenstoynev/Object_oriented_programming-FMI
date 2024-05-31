#include "Employee.h"
#include "CommisionEmployee.h"
#include "HourlyEmployee.h"

Employee* createEmployee(std::istream& is){
    char buffer[1024];
    is >> buffer;
    size_t length = std::strlen(buffer);
    unsigned helper = 0;
    MyString bufferString{};
    while(helper != length){
        if(buffer[helper] ==  ' '){

        }
        bufferString[helper] = buffer[helper];
        helper++;
    }
}

int main(){

}