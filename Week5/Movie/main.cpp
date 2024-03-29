#include <iostream>
#include "Movie.h"

int main(){
    Time duration(2,30,56);
    Movie movie("Starwars", "Plamen Stoynev", duration, 21);
    std::cout << std::boolalpha << movie.checkGenre(Genre::Horror) << std::endl;
    movie.printGenres();
    std::cout << std::endl;
    std::cout << movie.getName() << std::endl;

    return 0;
}