#pragma once
#include <cstring>
#include <cstdint>
#include <iostream>


enum Genre : uint8_t{
    Action = 1 << 0,
    Comedy = 1 << 1,
    Drama = 1 << 2,
    Fantasy = 1 << 3,
    Horror = 1 << 4,
    Mystery = 1 << 5,
    Romance = 1 << 6,
    END = 1 << 7
};

void getGenre(Genre genre);
Genre iterateGenre(Genre genre);
Genre startGenre();
Genre endGenre();