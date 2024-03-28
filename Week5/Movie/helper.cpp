#include "helper.h"

void getGenre(Genre genre){
    switch (genre) {
        case Action:
            std::cout << "Action" << std::endl;
            break;
        case Comedy:
            std::cout << "Comedy" << std::endl;
            break;
        case Drama:
            std::cout << "Drama" << std::endl;
            break;
        case Fantasy:
            std::cout << "Fantasy" << std::endl;
            break;
        case Horror:
            std::cout << "Horror" << std::endl;
            break;
        case Mystery:
            std::cout << "Mystery" << std::endl;
            break;
        case Romance:
            std::cout << "Romance" << std::endl;
            break;

        default:
            break;
    }
}


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