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
    std::cin.getline(student.major, 2);
    std::cin >> student.averageGarde;
}

//this func is get from AI bot
double stringToDouble(const char* str) {
    double result = 0.0;
    double factor = 1.0;
    bool decimalPointEncountered = false;
    for (; *str; ++str) {
        if (*str == '.') {
            decimalPointEncountered = true;
            continue;
        }
        int digit = *str - '0';
        if (digit >= 0 && digit <= 9) {
            if (decimalPointEncountered) {
                factor /= 10.0;
                result += digit * factor;
            } else {
                result = result * 10.0 + digit;
            }
        }
    }
    return result;
}

void getStudentFromBuffer(const char* str, Student& student){
    char helper[100];
    char empty[100];
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
                case 3:
                    helper[indexHelper] = '\0';
                    student.averageGarde = stringToDouble(helper);
                    break;
            }
            inputHelper++;
            str++;
            indexHelper = 0;
            strcpy(helper, empty);

        }
        helper[indexHelper] = *str;
        indexHelper++;
        str++;
    }

}

void writeStudentToFile(Student* student, size_t size){
    std::ofstream file(FILE_NAME);

    if(!file.is_open())
        std::cout << "Can't be open to write" << std::endl;

    std::cout << "Input information for students in this categories => faculty number, name, major and average grade" << std::endl;
    for(size_t i = 0; i < size; i++){
        inputStudent(student[i]);
        file << student[i].facultyNumber << ';' << student[i].name << ';' << student[i].major << ';' << student[i].averageGarde <<';' << '\n';
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

void getHighestGradeStudentMajor(Student* students, size_t size, const char* major){
    double avgGrade = 0;
    size_t index = -1;
    for(size_t i = 0; i < size; i ++){
        if(avgGrade < students[i].averageGarde && strcmp(students[i].major, major)) {
            avgGrade = students[i].averageGarde;
            index = i;
        }
    }
    std::cout << students[index].name << " " << avgGrade << std::endl;
}

void getAverageGradeMajor(Student* students, size_t size, const char* major){
    double avgGrade = 0;
    for(size_t i = 0; i < size; i++){
        if(strcmp(students[i].major, major))
            avgGrade += students[i].averageGarde;
    }
    avgGrade = avgGrade / size;
    std::cout << avgGrade;
}

int main(){
    Student student[100];
    readStudentsFromFile(student, 2);
    getHighestGradeStudentMajor(student, 2, "IS");
    return 0;
}
