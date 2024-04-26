#include <iostream>
#include <fstream>

unsigned sizeOfFile(const char* FILE_NAME){
    std::ifstream file(FILE_NAME);
    unsigned size;
    unsigned temp;

    if(!file.is_open())
        return -1;

    temp = file.tellg();

    file.seekg(0,std::ios::end);
    size = file.tellg();

    file.seekg(temp);
    file.clear();

    return size;
}

int main(){
    std::cout << sizeOfFile("Week3/sizeOfFile.cpp") << std::endl;
}