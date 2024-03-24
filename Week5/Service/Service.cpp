#include <algorithm>
#include <iostream>
#include "Service.h"



Service::Service(const Technic* technics){
    for(size_t i = 0; i < 30; i++)
        this->technics[i] = technics[i];
}

Technic Service::technicForTheClient(const Client& client){
    const size_t sizeOfArr = 9;
    bool arrHelper[sizeOfArr];
    for(size_t i = 0; i < 30; i++){
        if(this->technics[i].canRepair(client.getProduct().getProduct()))
            return this->technics[i];
    }
    std::cout << "There is not this technic!" << std::endl;
}

void Service::addTechnic(const Technic& technic){
    this->technics[this->currentTechnics] = technic;
    this->currentTechnics++;
}

void Service::removeTechnic(const char* ID){
    for(size_t i = 0; i < 30; i++)
        if(strcmp(this->technics[i].getID(), ID) == 0)
            std::swap(this->technics[i], this->technics[this->currentTechnics]);
    this->currentTechnics--;
}