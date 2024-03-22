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

Category getProduct(const char* product){
    if(strcmp(product,"TV") == 0)
        return TV;
    else if(strcmp(product,"PC") == 0)
        return PC;
    else if(strcmp(product,"Phone") == 0)
        return Phone;
    else if(strcmp(product,"Fridge") == 0)
        return Fridge;
    else if(strcmp(product,"WashingMachine") == 0)
        return WashingMachine;
    else if(strcmp(product,"DishWasher") == 0)
        return DishWasher;
    else if(strcmp(product,"Microwave") == 0)
        return Microwave;
    else if(strcmp(product,"Oven") == 0)
        return Oven;
    else if(strcmp(product,"AirConditioner") == 0)
        return AirConditioner;
    else
        return TV;
}