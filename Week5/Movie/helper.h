#pragma once
#include <cstring>
#include <cstdint>
#include <iostream>


enum Genre : uint8_t{
    Action = 1 << 0,
    Comedy = 1 << 1,
    Drama = 1 << 2,
    Fantasy = 1 << 3,
    Horror = 1 << 4,
    Mystery = 1 << 5,
    Romance = 1 << 6,
    END = 1 << 7
};

bool isValidName(const char* name);
bool isValidID(const char* ID);
Genre getProduct(const char* product);
bool isFirstUpperLetter(const char* name);
bool isLowerCaseOthers(const char* name);