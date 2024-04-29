#pragma once
#include "CarPart.h"
class Tier : public CarPart{
private:
    int width;
    int profile;
    int diameter;
public:
    Tier() = default;
    Tier(unsigned ID, const MyString& nameManufacture, const MyString& description, int width, int profile, int diameter);
    int getWidth() const;
    int getProfile() const;
    int getDiameter() const;

    void setWidth(int width);
    void setProfile(int profile);
    void setDiameter(int diameter);
};