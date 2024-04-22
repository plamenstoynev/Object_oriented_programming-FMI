#include <cstdint>
#include <iostream>
#include "MultiSet.h"

const char* FILE_NAME = "MultiSet.dat";


int main(){
    MultiSet set1(3, 10);
    set1.addNum(1);
    set1.addNum(2);
    set1.addNum(3);

    MultiSet set2(3, 10);
    set2.addNum(2);
    set2.addNum(3);
    set2.addNum(4);


    MultiSet set3 = cross(set1, set2);
    set3.printNums();

    std::cout << std::endl;

    MultiSet set4 = minus(set1, set2);
    set4.printNums();

    saveToBinaryFile(FILE_NAME, set3);

    std::cout << std::endl;

    MultiSet set5;
    readFromBinaryFile(FILE_NAME, set5);
    set5.printNums();
    return 0;
}