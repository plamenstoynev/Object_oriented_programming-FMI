#include "Tier.h"

Tier::Tier(unsigned ID, const MyString& nameManufacture, const MyString& description, int width, int profile, int diameter) : CarPart(ID, nameManufacture, description){
    setWidth(width);
    setProfile(profile);
    setDiameter(diameter);
}

int Tier::getWidth() const{
    return this->width;
}
int Tier::getProfile() const{
    return this->profile;
}
int Tier::getDiameter() const{
    return this->diameter;
}

void Tier::setWidth(int width){
    if(width < 155 || width > 365)
        throw std::invalid_argument("Width must be between 155 and 365");
    this->width = width;
}
void Tier::setProfile(int profile){
    if(profile < 30 || profile > 80)
        throw std::invalid_argument("Profile must be between 30 and 80");
    this->profile = profile;
}
void Tier::setDiameter(int diameter){
    if(diameter < 13 || diameter > 21)
        throw std::invalid_argument("Diameter must be between 13 and 21");
    this->diameter = diameter;
}

std::ostream& operator<<(std::iostream& os, const Tier& tier){
    return operator<<(os, tier) << " - " << tier.getWidth() << "/" << tier.getProfile() << "R" << tier.getDiameter();
}