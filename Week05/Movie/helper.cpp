#include "helper.h"

void getGenre(Genre genre){
    switch (genre) {
        case Action:
            std::cout << "Action";
            break;
        case Comedy:
            std::cout << "Comedy";
            break;
        case Drama:
            std::cout << "Drama";
            break;
        case Fantasy:
            std::cout << "Fantasy";
            break;
        case Horror:
            std::cout << "Horror";
            break;
        case Mystery:
            std::cout << "Mystery";
            break;
        case Romance:
            std::cout << "Romance";
            break;

        default:
            break;
    }
}

Genre iterateGenre(Genre genre){
    return Genre(genre << 1);
}

Genre startGenre(){
    return Action;
}

Genre endGenre(){
    return END;
}