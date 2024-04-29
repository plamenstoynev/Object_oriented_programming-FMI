#include "Engine.h"

Engine::Engine(unsigned ID,const MyString& nameManufacture, const MyString& description, unsigned horsePower) : CarPart(ID, nameManufacture, description){

}

unsigned Engine::getHorsePower() const{
    return this->horsePower;
}

void Engine::setHorsePower(unsigned horsePower){
    this->horsePower = horsePower;
}

std::ostream& operator<<(std::ostream& os, const Engine& engine){
    return operator<<(os, engine) << " - " << engine.getHorsePower() << "hp";
}