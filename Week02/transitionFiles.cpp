#include <fstream>
#include <iostream>

const char* copyFILE_NAME = "copyingFrom.txt";
const char* readFILE_NAME = "readingFrom.txt";
void transitionFIles(const char* copyFILE_NAME, const char* readFILE_NAME){
    std::ifstream readFile(readFILE_NAME);
    std::ofstream copyFile(copyFILE_NAME);

    if(!copyFile.is_open())
        std::cout << "Can't open copy" << std::endl;

    if(!readFile.is_open())
        std::cout << "Can't open read";

    while(!readFile.eof()){
        char buffer[1024];
        readFile.getline(buffer, 1024);
        copyFile << buffer;
        copyFile << '\n';
    }
}



int main(){
    transitionFIles(copyFILE_NAME,readFILE_NAME);
    return 0;
}
