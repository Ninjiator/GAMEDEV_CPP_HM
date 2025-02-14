#pragma once

enum class DrinkProgramStatus
{
    Success = 0,
    LowWater,
    CleanNeeded, //not implemented yeat
    LowMilk, //added  for Cappuccino
    LowWaterAndMilk, //added  for Cappuccino

    Count
};


class DrinkProgram
{
public:
    DrinkProgram(class CoffeeMachine& context) : m_context(context) {}

    virtual void showInfo() = 0;
    virtual DrinkProgramStatus prepare() = 0;
    
protected:
    class CoffeeMachine& m_context;
};


class Coffee : public DrinkProgram
{
public:
    Coffee(CoffeeMachine& context) : DrinkProgram(context) {}
private:
};


class Espresso : public Coffee
{
public:
    Espresso(CoffeeMachine& context) : Coffee(context) {}
    
    void showInfo() override;
    DrinkProgramStatus prepare() override;
private:
    const float EsspressoVolume = 0.05f;
};


class Cappuccino : public Coffee
{
public:
    Cappuccino(CoffeeMachine& context) : Coffee(context) {}
    
    void showInfo() override;
    DrinkProgramStatus prepare() override;
private:
    const float CappuccinoVolume = 0.05f;
    const float MilkVolumeCappuccino = 0.12f;
};


class Tea : public DrinkProgram
{
public:
    Tea(CoffeeMachine& context) : DrinkProgram(context) {}
private:
};

class HotTea : public Tea
{
public:
    HotTea(CoffeeMachine& context) : Tea(context) {}

    virtual void showInfo();
    virtual DrinkProgramStatus prepare();
private:
    const float WaterHotTeaVolume = 0.2f;
};

class ColdTea : public Tea
{
public:
    ColdTea(CoffeeMachine& context) : Tea(context) {}

    virtual void showInfo();
    virtual DrinkProgramStatus prepare();
private:
    const float WaterColdTeaVolume = 0.2f;
    const float MilkColdTeaVolume = 0.2f;
};
