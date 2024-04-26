#include <iostream>
#include <fstream>

const char* FILE_NAME = "binary.dat";

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

void writeInBinaryFile(const char* FILE_NAME,const int* arr, size_t size){
    std::ofstream file(FILE_NAME, std::ios::binary);
    size_t sizeOfArr = sizeof(int) * size;

    if(!file.is_open())
        std::cout << "File can't be open to write in it" << std::endl;

    file.write((const char*) arr, sizeOfArr);
}

void readFromBinaryFile(const char* FILE_NAME, int* arr, unsigned &size){
    std::ifstream file(FILE_NAME, std::ios::binary);
    unsigned sizeFile = sizeOfFile(FILE_NAME);


    if(!file.is_open())
        std::cout << "Can't be open to read from" << std::endl;

    file.read((char*) arr, sizeFile);

}

int maxElement(const char* FILE_NAME, int* arr, unsigned &size){
    readFromBinaryFile(FILE_NAME, arr, size);
    int max = -1;
    for(int i = 0; i < size; i++){
        if(arr[i] > max)
            max = arr[i];
    }

    return max;
}


int main(){
    int writeArr[5] = {1,2,3,4,5};
    int readArr[5] = {};
    unsigned size = 5;
    writeInBinaryFile(FILE_NAME, writeArr, size);
    readFromBinaryFile(FILE_NAME, readArr, size);
    std::cout << maxElement(FILE_NAME, readArr, size) << std::endl;
    return 0;
}