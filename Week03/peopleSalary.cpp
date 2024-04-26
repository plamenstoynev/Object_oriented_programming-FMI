#include <iostream>
#include <fstream>

const char* FILE_NAME = "people.dat";

const size_t sizeOfName = 24;

struct Person{
    char name[sizeOfName];
    unsigned salary;
};

void inputPerson(Person& person){
    std::cin >> person.name;
    std::cin >> person.salary;
}

void printPerson(const Person& person){
    std::cout << "Name: " << person.name << " || Salary: " << person.salary << std::endl;
}

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

void addPersonToFIle(std::ofstream& file,Person* person){

    inputPerson(*person);

    file.write((const char*)person, sizeof(Person));
}

void addPersonToFIle(const char* FILE_NAME, Person* person){
    std::ofstream file(FILE_NAME, std::ios::app | std::ios::binary);

    if(!file.is_open())
       std::cout << "Can't be open to write in it" << std::endl;

    addPersonToFIle(file, person);
}

void readFromFie(std::ifstream& file, Person* person){
    size_t size = sizeOfFile("people.dat");
    file.read((char*) person, size);
}

void readFromFile(const char* FILE_NAME, Person* person){
    std::ifstream file(FILE_NAME, std::ios::binary);

    if(!file.is_open())
        std::cout << "Can't be open to read from it" << std::endl;

    readFromFie(file, person);
}

unsigned avgSalary(const Person* people, unsigned size){
    unsigned salaries = 0;
    for(size_t i = 0; i < size; i++){
        salaries += people[i].salary;
    }
    return salaries / size;
}

void printOverAvgSalary(const Person* people , unsigned size){
    unsigned salary = avgSalary(people, size);
    for(size_t i = 0; i < size; i++){
        if(people[i].salary >= salary)
            printPerson(people[i]);
    }
}


int main(){
    unsigned size = sizeOfFile(FILE_NAME) / sizeof(Person);
    Person* people = new Person[size];
    readFromFile(FILE_NAME, people);
    printOverAvgSalary(people,size);
    delete[] people;
    return 0;
}