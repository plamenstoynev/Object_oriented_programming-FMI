#include <iostream>
#include <fstream>
#include <cstring>

char* reverse(char* str){
    unsigned lengthStr = strlen(str);
    unsigned helper = 0;
    char* result = new char[lengthStr];
    while(lengthStr != 0){
        result[helper] = str[lengthStr - 1];
        lengthStr--;
        helper++;
    }
    result[helper] = '\0';
    return result;
}

void transitionFIles(const char* copyFILE_NAME, const char* readFILE_NAME){
    std::ifstream readFile(readFILE_NAME);
    std::ofstream copyFile(copyFILE_NAME);

    if(!copyFile.is_open())
        std::cout << "Can't open copy" << std::endl;

    if(!readFile.is_open())
        std::cout << "Can't open read";

    while(!readFile.eof()){
        char buffer[1024];
        char reverseBuffer[1024];
        readFile.getline(buffer, 1024);
        strcpy(reverseBuffer, reverse(buffer));
        copyFile << reverseBuffer;
        copyFile << '\n';
    }
}

int main(){
    transitionFIles("result.txt", "copying.txt" );
    return 0;
}