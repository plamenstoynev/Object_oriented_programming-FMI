#include <iostream>
#include "ModifiableIntegerFunction.h"

const char* FILE_NAME = "ModifiableIntegerFunction.dat";

int16_t function(int16_t num){
    return num * 2;
}

int16_t function2(int16_t num){
    return num * 3;
}

int main(){
    ModifiableIntegerFunction mif1(function);
    ModifiableIntegerFunction mif2(function2);

    mif1 = mif1 + mif2;

    std::cout << mif2.getValue(2) << std::endl;

    saveToBinaryFile(FILE_NAME, mif1);

    ModifiableIntegerFunction mif3(function);
    readFromBinaryFile(FILE_NAME, mif3);

    std::cout << mif3.getValue(2) << std::endl;
    return 0;
}