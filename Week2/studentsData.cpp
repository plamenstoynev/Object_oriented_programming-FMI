#include <iostream>
#include <fstream>
#include <cstring>

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

void getStudentFromBuffer(const char* str, Student& student){
    char helper[100];
    size_t indexHelper = 0;
    size_t inputHelper = 0;
    while(*str != '\0'){
        if(*str == ';'){
            switch(inputHelper) {
                case 0:
                    strcpy(student.facultyNumber, helper);
                    break;
                case 1:
                    strcpy(student.name, helper);
                    break;
                case 2:
                    strcpy(student.major, helper);
                    break;
            }
            inputHelper++;
            str++;
            indexHelper = 0;
            helper[indexHelper] = '\0';

        }
        helper[indexHelper] = *str;
        indexHelper++;
        str++;
    }
    student.averageGarde = helper[0];

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

void readStudentsFromFile(Student* students, size_t size){
    std::ifstream file(FILE_NAME);
    char buffer[1024];

    if(!file.is_open())
        std::cout << "Can't be open to read" << std::endl;

    for(size_t i = 0; i < size; i++){
        file.getline(buffer, 1024);
        getStudentFromBuffer(buffer, students[i]);
    }
}

int main(){
    Student students[100];
    readStudentsFromFile(students,2);
    return 0;
}
