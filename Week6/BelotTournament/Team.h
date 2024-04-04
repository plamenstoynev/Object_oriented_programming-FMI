#pragma once
#include "SoftwareEngineer.h"

class Team {
private:
    SoftwareEngineer people[2];
public:
    Team() = default;
    Team(const SoftwareEngineer* people);




};