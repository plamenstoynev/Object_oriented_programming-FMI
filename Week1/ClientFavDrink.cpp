#include <iostream>
#include <cstring>

enum Drinks{
    whiskey = 0,
    vodka = 1,
    fanta = 2,
    cola = 3,
    water = 4,
    wine = 5,
    rom = 6,
    juice = 7
};

struct Person{
    char name[32];
    bool drink[8];
};
void inputPerson(Person& person,char name[31], bool drink[8]){
    std::strcpy(person.name, name);
    for(size_t i = 0; i < 8; i++){
        person.drink[i] = drink[i];
    }
}

bool isFavDrink(Drinks drink,const Person& person){
    return person.drink[drink];
}

void addFavDrink(Drinks drink, Person& person){
    person.drink[drink] = true;
}

void removeFavDrink(Drinks drink, Person& person){
    person.drink[drink] = false;
}

char* enumToChar(int index){
    switch(index){
        case 0:
            return "whiskey";
        case 1:
            return "vodka";
        case 2:
            return "fanta";
        case 3:
            return "cola";
        case 4:
            return "water";
        case 5:
            return "wine";
        case 6:
            return "rom";
        case 7:
            return "juice";
    }
}

void printFavDrinks(const Person& person){
    for(size_t i = 0; i < 8; i++){
        if(person.drink[i]){
            std::cout << enumToChar(i) << std::endl;
        }
    }
}

int main() {
    bool drink[8];
    char name[31];
    int answer;
    Person person;
    std::cin.getline(name,'\n');
    std::cout << "Choose if you like this drink \n "
                 "press 1 => you like it \n "
                 "press 0 => you don't like it \n "
                 "Drinks are in this order {whiskey, vodka, fanta, cola, water, wine, rom, juice}" << std::endl;
    for(size_t i = 0; i < 8; i++){
        std::cin >> answer;
        switch (answer) {
            case 0:
                drink[i] = false;
                break;
            case 1:
                drink[i] = true;
                break;
        }
        if(answer != 1 && answer != 0){
            std::cout << "You can't enter number different from 0 and 1" << std::endl;
            i--;
        }
    }

    inputPerson(person, name, drink);
    std::cout << std::boolalpha << isFavDrink(Drinks::cola,person) << std::endl;

    addFavDrink(Drinks::rom, person);
    std::cout << "Add rom to fav drinks" << std::endl;
    std::cout << std::boolalpha << "Is rom fav drink => " << isFavDrink(Drinks::rom,person) << std:: endl;


    removeFavDrink(Drinks::fanta, person);
    std::cout << "Remove fanta from fav drinks" << std::endl;
    std::cout << std::boolalpha << "Is fanta fav drink => " << isFavDrink(Drinks::fanta,person) << std:: endl;

    printFavDrinks(person);
    return 0;
}
