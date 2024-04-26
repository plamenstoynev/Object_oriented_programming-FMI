#include "Team.h"

Team::Team(const SoftwareEngineer *people) {
    setTeam(people);
}

const SoftwareEngineer* Team::getEngineers() const {
    return this->people;
}

void Team::setTeam(const SoftwareEngineer *team) {
    for(unsigned i = 0; i < teamSize; i++)
        this->people[i] = team[i];
}