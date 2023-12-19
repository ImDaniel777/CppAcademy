#pragma once

#include <iostream>

class Car
{
private:
    int mileage = 0;
    int horsePower;
    float kwPower;
protected:

    std::string chassisType;
    std::string  *_VIN = nullptr;

public:
    Car();
    Car(std::string  &VIN);

    virtual void accelerate() = 0;
    
    int getMileage() const;
    void setMileage(int value);

    int getHorsePower() const;
    void setHorsePower(int value);

    float getKwPower()const;
    void setKwPower(float value);

    std::string getChassisType()const;
    void setChassisType(std::string &value);

    std::string  getVIN()const;
    void setVIN(std::string value);

    virtual ~Car();
};