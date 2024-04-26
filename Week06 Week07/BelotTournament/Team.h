#pragma once
#include "SoftwareEngineer.h"

constexpr unsigned teamSize = 2;

class Team {
private:
    SoftwareEngineer people[teamSize];
public:
    Team() = default;
    Team(const SoftwareEngineer* people);

    const SoftwareEngineer* getEngineers() const;

    void setTeam(const SoftwareEngineer* team);
};