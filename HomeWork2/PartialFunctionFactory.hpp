#include "PartialFunction.hpp"
#include "ByCriteria.hpp"
#include "maximumFunction.hpp"
#include "minimumFunction.hpp"
#include "Case0.h"
#include "Case1.h"
#include "Case2.h"
#include <fstream>

PartialFunction* functionFactory(const char* FILE_NAME){
    std::ifstream file(FILE_NAME, std::ios::binary);
    if(!file.is_open()){
        throw std::runtime_error("File not found");
    }
    int16_t N, T;
    file.read((char*)&N, sizeof(N));
    file.read((char*)&T, sizeof(T));
    if(N < 0 || N > 32)
        throw std::runtime_error("Invalid N");

    if(T < 0 || T > 5)
        throw std::runtime_error("Invalid T");

    if(T == 0){
        int32_t* arr = new int32_t[N];
        int32_t* values = new int32_t[N];
        file.read((char*)arr, N * sizeof(int32_t));
        file.read((char*)values, N * sizeof(int32_t));
        Case0* c0 = new Case0(arr, values, N);
        PartialFunction* ptr = new ByCriteria<Case0>(*c0);
        delete[] arr;
        delete[] values;
        c0 = nullptr;
        return ptr->clone();
    }
    else if(T == 1){
        int32_t* arr = new int32_t[N];
        file.read((char*)arr, N * sizeof(int32_t));
        Case1* c1 = new Case1(arr, N);
        PartialFunction* ptr = new ByCriteria<Case1>(*c1);
        delete[] arr;
        c1 = nullptr;
        return ptr->clone();
    }
    else if(T == 2){
        int32_t* arr = new int32_t[N];
        file.read((char*)arr, N * sizeof(int32_t));
        Case2* c2 = new Case2(arr, N);
        PartialFunction* ptr = new ByCriteria<Case2>(*c2);
        delete[] arr;
        c2 = nullptr;
        return ptr->clone();
    }
    else if(T == 3){
        char buffer[256];
        PartialFunction** ptr = new PartialFunction*[N];
        for(int i = 0; i < N; i++){
            file.read(buffer, 256);
            ptr[i] = functionFactory(buffer);
        }
        return new maximumFunction(ptr, N);
    }
    else if(T == 4){
        char buffer[256];
        PartialFunction** ptr = new PartialFunction * [N];
        for(int i = 0; i < N; i++){
            file.read(buffer, 256);
            ptr[i] = functionFactory(buffer);
        }
        return new minimumFunction(ptr, N);
    }
    else{
        throw std::runtime_error("Invalid T");
    }
}