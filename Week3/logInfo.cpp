#include <iostream>
#include <fstream>
#include <ctime>

const char* FILE_NAME = "LOGS.txt";

void writeIntoFile(std::ofstream& file, char* buffer){

    time_t now = time(0);
    char timeInfo[32];
    ctime_s(timeInfo, 32, &now);

    timeInfo[24] = '\0';

    file << "[" << timeInfo << "]" << ": " << buffer << '\n';

}


void writeIntoFile(const char* , char* buffer){
    std::ofstream file(FILE_NAME, std::ios_base::app);

    if(!file.is_open())
        std::cout << "Can't be open to write" << std::endl;

    writeIntoFile(file, buffer);

}

int main(){
    char* buffer = new char [1024];
    std::cin.getline(buffer, 1024);

    writeIntoFile(FILE_NAME, buffer);

    delete[] buffer;
    return 0;
}