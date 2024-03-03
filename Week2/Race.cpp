#include <iostream>
#include <fstream>

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
    std::ofstream file("racing.txt");

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


int main(){
    Race race;
    writeRaceToFile(race, 3);
    return 0;
}
