#pragma once

class ElectricCarInterface
{
public:
    virtual void chargeBattery(int amount) = 0;
    virtual ~ElectricCarInterface(){};
};

class HybridCarInterface
{

public:
    virtual void addFuel(int amount) = 0;
    virtual ~HybridCarInterface(){};
};

class MildHybridCarInterface : ElectricCarInterface, HybridCarInterface
{

public:
    virtual ~MildHybridCarInterface(){};
};