#include <iostream>
#include <fstream>

const char* FILE_NAME = "students_data.txt";

struct Student{
    char facultyNumber[11];
    char name[31];
    char major[3];
    double averageGarde;
};

void inputStudent(Student& student){
    std::cin.getline(student.facultyNumber, 11);
    std::cin.getline(student.name, 31);
    std::cin.getline(student.major, 3);
    std::cin >> student.averageGarde;
}

void writeStudentToFile(Student* student){
    std::ifstream file(FILE_NAME);

    if(!file.is_open())
        std::cout << "Can't be open to write" << std::endl;


}

void readStudentsFromFile(){
    std::ofstream (FILE_NAME);
}

int main(){
    return 0;
}
