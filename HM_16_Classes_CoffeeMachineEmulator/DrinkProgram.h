#pragma once

enum class DrinkType
{
    Espresso,
    Cappuccino
};

enum class DrinkProgramStatus
{
    Success = 0,
    LowWater,
    CleanNeeded, //not implemented yeat
    LowMilk,//TODO HW, added new status for Cappuccino

    Count
};


class DrinkProgram
{
public:
    DrinkProgram(DrinkType type, class CoffeeMachine& context);
    
    void showInfo();
    DrinkProgramStatus prepare();
    DrinkProgramStatus prepareEspresso();
    DrinkProgramStatus prepareCappuccino();
private:
    DrinkType m_drinkType;

    const float EsspressoVolume = 0.05f;
    const float CappuccinoVolume = 0.05f;
    const float CappuccinoMilkVolume = 0.12f;

    class CoffeeMachine& m_context;
};
