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

void writeMessageToFile(std::ofstream& file, unsigned *arr, size_t size){
    file.write((char*)arr, size * sizeof(unsigned));
}

void writeMessageToFile(const char* FILE_NAME, unsigned *arr, size_t size){
    std::ofstream file(FILE_NAME, std::ios::binary);

    if(!file.is_open())
        std::cout << "Can't be open to write in it" << std::endl;

    writeMessageToFile(file, arr,size);
}

void readMessageFromFIle(const char* FILE_NAME,std::ifstream& file, unsigned *arr){
    unsigned size = sizeOfFile(FILE_NAME);
    file.read((char*)arr, size);
}

void readMessageFromFile(const char* FILE_NAME, unsigned *arr){
    std::ifstream file(FILE_NAME, std::ios::binary);

    if(!file.is_open())
        std::cout << "Can't be open ro read from" << std::endl;

    readMessageFromFIle(FILE_NAME, file, arr);
}


int main(){
    unsigned *arr = new unsigned[5];
    unsigned *arrNum = new unsigned [1];

    readMessageFromFile("message.dat", arr);
    readMessageFromFile("number.dat", arrNum);

    size_t sizeOfMessage = sizeOfFile("message.dat") / sizeof(unsigned);

    for (size_t i = 0; i  <  sizeOfMessage; i++) {
        arr[i] += arrNum[0];
        std::cout << arr[i] << std::endl;
    }

    delete[] arr;
    delete[] arrNum;
    return 0;
}