#include <iostream>
#include "PartialFunctionFactory.hpp"



int main(){
    PartialFunction* functionsPrt = functionFactory("func.dat");
    int mode;
    std::cout << "Enter a number to choose a mode" << std::endl;
    std::cin >> mode;
    if(mode == 1) {
        int a, b;
        std::cout << "Enter two numbers" << std::endl;
        std::cin >> a >> b;
        int temp = a < b ? a : b;
        a = a > b ? a : b;
        b = temp;
        for (int i = b; i <= a; i++)
            std::cout << functionsPrt->operator()(i) << std::endl;
    }
    else if(mode == 2) {
        int number;
        while (number != 1024) {
            std::cout << "Enter a number" << std::endl;
            std::cin >> number;
            std::cout << functionsPrt->operator()(number) << std::endl;
        }
    }
    else
        std::cout << "Invalid mode" << std::endl;

    delete functionsPrt;
    return 0;
}