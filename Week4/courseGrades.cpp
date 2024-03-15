#include <iostream>
#include <fstream>
#include <cstring>

const char* FILE_NAME = "grades.dat";

struct Course{
    char* name = nullptr;
    unsigned* grades = nullptr;
    size_t size = 0;

    Course() = default;
    Course(char* name, unsigned* grades, size_t sizeOfGrades){
        this->name = new char[strlen(name)];
        strcpy(this->name, name);

        this->size = sizeOfGrades;
        this->grades = new unsigned[sizeOfGrades];
        for(size_t i = 0; i < sizeOfGrades; i++){
            this->grades[i] = grades[i];
        }
    }

    double avgGrade() const{
        unsigned sumOfGrades = 0;
        for(size_t i = 0; i < this->size; i++){
            sumOfGrades += this->grades[i];
        }
        return (double)(sumOfGrades / this->size);
    }

    void free(){
        delete[] name;
        delete[] grades;
    }
};

void saveCourseToFile(std::ofstream& ofs, const Course& course){
    size_t size = strlen(course.name);
    ofs.write((const char*)&size, sizeof(size_t));
    ofs.write(course.name, size);
    ofs.write((const char*)&course.size, sizeof (size_t));
    ofs.write((const char*)course.grades, sizeof (unsigned ) * course.size);
}

void saveCourseToFile(const char* FILE_NAME, const Course& course){
    std::ofstream ofs(FILE_NAME, std::ios::binary);

    if(!ofs.is_open())
        std::cout << "Can't open to save in it" << std::endl;


    saveCourseToFile(ofs,course);
}

void readCourseFromFile(std::ifstream& ifs,Course& course){
    size_t size;

    ifs.read((char*)&size, sizeof(size_t));
    course.name = new char[size + 1];
    ifs.read(course.name, size);
    course.name[size] = '\0';


    ifs.read((char*)& course.size, sizeof(size_t));
    course.grades = new unsigned [course.size];
    ifs.read((char*)course.grades, sizeof(unsigned) * course.size);
}

void readCourseFromFile(const char* FILE_NAME, Course& course){
    std::ifstream ifs(FILE_NAME, std::ios::binary);

    if(!ifs.is_open())
        std::cout<< "Can't be open to read from" << std::endl;

    readCourseFromFile(ifs, course);
}



int main(){
    char* name;
    size_t size = 5;
    unsigned* grades = new unsigned [5];
    for(size_t i = 0; i < size; i++){
        std::cout << "Enter grade" << std::endl;
        std::cin >> grades[i];
    }
    std::cin.ignore();
    std::cin.getline(name, '\n');

    Course course1(name, grades, size);
    saveCourseToFile(FILE_NAME, course1);

    Course course2;
    readCourseFromFile(FILE_NAME, course2);

    std::cout << course2.name << std::endl;
    std::cout << course2.avgGrade() << std::endl;


    return 0;
}