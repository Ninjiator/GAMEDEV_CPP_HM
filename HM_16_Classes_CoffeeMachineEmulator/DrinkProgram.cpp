#include "DrinkProgram.h"
#include "CoffeeMachine.h"
#include <chrono>
#include <thread>

DrinkProgram::DrinkProgram(DrinkType type, CoffeeMachine& context) :
    m_drinkType(type),
    m_context(context) {}

void DrinkProgram::showInfo()
{
    switch (m_drinkType)
    {
    case DrinkType::Espresso:
        std::cout << "Espresso!";
        break;
    case DrinkType::Cappuccino:
        std::cout << "Cappuccino!";
        break;
    default:
        break;
    }
}

DrinkProgramStatus DrinkProgram::prepare()
{
    switch (m_drinkType)
    {
    case DrinkType::Espresso:
    {
        return prepareEspresso();
    }
    case DrinkType::Cappuccino:
    {
        return prepareCappuccino(); 
    }
    default:
        break;
    };

    return DrinkProgramStatus::Success;
}

DrinkProgramStatus DrinkProgram::prepareEspresso()
{
    if (m_context.m_waterReservoir.getVolume() < EsspressoVolume)
    {
        return DrinkProgramStatus::LowWater;
    }

    m_context.m_waterReservoir.useWater(EsspressoVolume);

    std::cout << "\n\nGrrr ";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "\nPreparing... Espresso... ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (int i = 5; i > 3; i--)
    {
        std::cout << i << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "..Hanging... ";
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "DONE!\n\n";

    return DrinkProgramStatus::Success;
};

DrinkProgramStatus DrinkProgram::prepareCappuccino()
{
            //Milk... Rturn appropriate error if smth goes wrong +-
                //Note: Some coffeeMachineі don't check milk strictly, that is they try
                //to prepare the drink even if there's not enough milk present, up to you to decide exact logic 
    if (m_context.m_waterReservoir.getVolume() < CappuccinoVolume)
    {
        return DrinkProgramStatus::LowWater;
    }

    if (m_context.m_milkReservoir.getVolume() < MilkVolumeCappuccino)
    {
        return DrinkProgramStatus::LowMilk;
    }

    m_context.m_waterReservoir.useWater(CappuccinoVolume);
    m_context.m_milkReservoir.useMilk(MilkVolumeCappuccino);

    std::cout << "\n\nGrrr ";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "\nPreparing... Cappuccino... ";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Adding...a Milk... ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Pff....pfff.... ";
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::this_thread::sleep_for(std::chrono::seconds(1));

    for (int i = 5; i > 3; i--)
    {
        std::cout << i << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "..Hanging... ";
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "DONE!\n\n";

    return DrinkProgramStatus::Success;
};