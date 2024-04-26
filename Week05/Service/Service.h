#pragma once
#include "Technic.h"
#include "Client.h"

const unsigned MAX_TECHNICS = 30;

class Service {
private:
    Technic technics[MAX_TECHNICS];
    unsigned currentTechnics = 0;
public:
    Service() = default;
    Service(const Technic* technics);
    Technic technicForTheClient(const Client& client);

    void addTechnic(const Technic& technic);
    void removeTechnic(const char* ID);
};
