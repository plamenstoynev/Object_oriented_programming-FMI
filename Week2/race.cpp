#include <iostream>
#include <fstream>

const char* FILE_NAME = "racing.txt";

struct Time{
    unsigned hour;
    unsigned minutes;
    unsigned seconds;
};

struct Runner{
    unsigned number;
    Time time;
};

struct Race{
    Runner runners[100];
    unsigned nRunners;
};

void writeRaceToFile(Race& race, unsigned nRunners){
    std::ofstream file(FILE_NAME, std::ios::ate);

    if(!file.is_open())
        std::cout << "Can't open file to input" << std::endl;

    race.nRunners = nRunners;

    file << nRunners;
    file << '\n';

    for(size_t i = 0; i < nRunners; i++){
        std::cout << "Enter hours" << std::endl;
        std::cin >> race.runners[i].time.hour;
        file << race.runners[i].time.hour << " ";

        std::cout << "Enter minutes" << std::endl;
        std::cin >> race.runners[i].time.minutes;
        file << race.runners[i].time.minutes << " ";

        std::cout << "Enter seconds" << std::endl;
        std::cin >> race.runners[i].time.seconds;
        file << race.runners[i].time.seconds << " ";

        std::cout << "Enter number" << std::endl;
        std::cin >> race.runners[i].number;
        file << race.runners[i].number << " ";

        file << '\n';
    }
}

void addMoreRunnersToFIle(Race& race, unsigned nRunners){
    std::ofstream file(FILE_NAME, std::ios::app);

    if(!file.is_open())
        std::cout << "Can't open file to input" << std::endl;

    unsigned tempNRunners = race.nRunners;
    race.nRunners += nRunners;


    for(size_t i = tempNRunners; i < race.nRunners; i++){
        std::cout << "Enter hours" << std::endl;
        std::cin >> race.runners[i].time.hour;
        file << race.runners[i].time.hour << " ";

        std::cout << "Enter minutes" << std::endl;
        std::cin >> race.runners[i].time.minutes;
        file << race.runners[i].time.minutes << " ";

        std::cout << "Enter seconds" << std::endl;
        std::cin >> race.runners[i].time.seconds;
        file << race.runners[i].time.seconds << " ";

        std::cout << "Enter number" << std::endl;
        std::cin >> race.runners[i].number;
        file << race.runners[i].number << " ";

        file << '\n';
    }
}

void writeRaceToFile(const Race& race){
    std::ofstream file(FILE_NAME);

    if(!file.is_open())
        std::cout << "Can't be open to write in it" << std::endl;

    file << race.nRunners;
    file << '\n';

    for(size_t i = 0; i < race.nRunners; i++){
        file << race.runners[i].time.hour << " ";
        file << race.runners[i].time.minutes << " ";
        file << race.runners[i].time.seconds << " ";
        file << race.runners[i].number << " ";
        file << '\n';
    }
}

void readRaceFromFile(Race& race){
    std::ifstream file(FILE_NAME);

    if(!file.is_open())
        std::cout<< "Can't be open for read" << std::endl;

    file >> race.nRunners;

    for(size_t i = 0; i < race.nRunners; i++){
        file >> race.runners[i].time.hour;
        file >> race.runners[i].time.minutes;
        file >> race.runners[i].time.seconds;
        file >> race.runners[i].number;
    }
}


int main(){
    Race race;
    unsigned nRunners;
    char command;

    std::cout << "Enter a number of runners" << std::endl;
    std::cin >> nRunners;

    std::cout << "Enter a command" << std::endl;
    std::cout << "If you wanna put runners in racing enter i \n"
                 "If you wanna to get runners from file enter o \n"
                 "If you wanna to add more runners to racing enter a" << std::endl;
    std::cin >> command;

    switch (command) {
        case 'i':
            writeRaceToFile(race, nRunners);
            break;
        case 'o':
            readRaceFromFile(race);
            break;
        case 'a':
            readRaceFromFile(race);
            addMoreRunnersToFIle(race, nRunners);
            writeRaceToFile(race);
            break;
    }
    return 0;
}
