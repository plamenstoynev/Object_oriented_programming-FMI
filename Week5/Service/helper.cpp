#include <cstring>

bool isFirstUpperLetter(const char* name){
    return  'A' <= name[0] && name[0] <= 'Z';
}

bool isLowerCaseOthers(const char* name){
    size_t lengthOfName = strlen(name);

    for(size_t i = 1; i < lengthOfName; i++)
        if(name[i] < 'a' || name[i] > 'z')
            return false;

    return true;
}

bool isValidName(const char* name){
    return isFirstUpperLetter(name) && isLowerCaseOthers(name);
}

bool isValidID(const char* ID){
    size_t IDLength = strlen(ID);

    for(size_t i = 0; i < IDLength; i++)
        if(ID[i] < '0' || ID[i] > '9')
            return false;

    return true;
}