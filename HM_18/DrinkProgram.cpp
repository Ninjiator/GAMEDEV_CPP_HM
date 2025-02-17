#include "DrinkProgram.h"
#include "CoffeeMachine.h"
#include <chrono>
#include <thread>

void Espresso::showInfo()
{
  std::cout << "Espresso!";
}


DrinkProgramStatus Espresso::prepare()
{
    if (m_context.getWaterReservoir().getVolume() < EsspressoVolume)
    {
        return DrinkProgramStatus::LowWater;
    }
    else if (m_context.getCoffeContainer().getUsedVolume() == m_context.getCoffeContainer().getUsedLimit())
    {
        return DrinkProgramStatus::CleanNeeded;
    }
    else if (m_context.getCoffeContainer().getGroundedVolume() < CoffeeEsspresso)
    {
        return DrinkProgramStatus::LowCoffeeGrounded;
    }
    m_context.getWaterReservoir().useWater(EsspressoVolume);
    m_context.getCoffeContainer().useGroundedCoffee(CoffeeEsspresso);
    m_context.getCoffeContainer().fillUsedCoffeeContainer(CoffeeEsspresso);
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

void Cappuccino::showInfo()
{
    std::cout << "Cappuccino!";
}

DrinkProgramStatus Cappuccino::prepare()
{
    if ((m_context.getWaterReservoir().getVolume() < CappuccinoVolume) && (m_context.getMilkReservoir().getVolume() < MilkVolumeCappuccino))
    {
        return DrinkProgramStatus::LowWaterAndMilk;
    }
    else if (m_context.getWaterReservoir().getVolume() < CappuccinoVolume)
    {
        return DrinkProgramStatus::LowWater;
    }
    else if (m_context.getCoffeContainer().getUsedVolume() == m_context.getCoffeContainer().getUsedLimit())
    {
        return DrinkProgramStatus::CleanNeeded;
    }
    else if (m_context.getCoffeContainer().getGroundedVolume() < CoffeeCappuccino)
    {
        return DrinkProgramStatus::LowCoffeeGrounded;
    }
    else if (m_context.getMilkReservoir().getVolume() < MilkVolumeCappuccino)
    {
        return DrinkProgramStatus::LowMilk;
    }

    m_context.getCoffeContainer().useGroundedCoffee(CoffeeCappuccino);
    m_context.getCoffeContainer().fillUsedCoffeeContainer(CoffeeCappuccino);

    m_context.getWaterReservoir().useWater(CappuccinoVolume);
    m_context.getMilkReservoir().useMilk(MilkVolumeCappuccino);
    
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

void HotTea::showInfo()
{
    std::cout << "Hot Tea";
}

DrinkProgramStatus HotTea::prepare()
{
    if (m_context.getWaterReservoir().getVolume() < WaterHotTeaVolume)
    {
        return DrinkProgramStatus::LowWater;
    }
    return DrinkProgramStatus::Success;
}

void ColdTea::showInfo()
{
    std::cout << "Refreshing cold Tea with Milk";
}

DrinkProgramStatus ColdTea::prepare()
{
    if ((m_context.getWaterReservoir().getVolume() < WaterColdTeaVolume) && (m_context.getMilkReservoir().getVolume() < MilkColdTeaVolume))
    {
        return DrinkProgramStatus::LowWaterAndMilk;
    }

    if (m_context.getWaterReservoir().getVolume() < WaterColdTeaVolume)
    {
        return DrinkProgramStatus::LowWater;
    }

    if (m_context.getMilkReservoir().getVolume() < MilkColdTeaVolume)
    {
        return DrinkProgramStatus::LowMilk;
    }

    return DrinkProgramStatus::Success;
}