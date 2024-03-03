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

void writeStudentToFile(Student* student, size_t size){
    std::ofstream file(FILE_NAME);

    if(!file.is_open())
        std::cout << "Can't be open to write" << std::endl;

    std::cout << "Input information for students in this categories => faculty number, name, major and average grade" << std::endl;
    for(size_t i = 0; i < size; i++){
        inputStudent(student[i]);
        file << student[i].facultyNumber << ';' << student[i].name << ';' << student[i].major << ';' << student[i].averageGarde <<'\n';
        std::cin.ignore();
    }
}

void readStudentsFromFile(){
    std::ofstream (FILE_NAME);
}

int main(){
    Student students[100];
    writeStudentToFile(students, 2);
    return 0;
}
