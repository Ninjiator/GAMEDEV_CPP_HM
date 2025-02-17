#pragma once
#include <vector>
#include <iostream>

#include "WaterReservoir.h"
#include "MilkReservoir.h"
#include "DrinkProgram.h"
#include "CoffeeGrainsContainer.h"

enum class CoffeeMachineState
{
    Sleep,
    PowerOffRequest,

    MainMenu,

    WaterReservoir,
    MilkReservoir,
    CoffeeContainer,    

    DrinkSelection,
    DrinkPreparation,

    LowWaterError,
    LowMilkError,
    LowWaterAndMilkError,

    LowCoffeeGroundedError,
    MaxUsedCoffeeError,
};


class CoffeeMachine
{
public:
    bool IsBooted() const { return !m_powerOffRequest; }

    void initDefaultDrinks();
    void addDrinkReceipt(DrinkProgram* program) { m_recipes.push_back(program); }

    void showMenu();
    void receiveInput();
    void update();
    WaterReservoir& getWaterReservoir()  { return m_waterReservoir; }
    MilkReservoir& getMilkReservoir()  { return m_milkReservoir; }
    CoffeGrainsContainer& getCoffeContainer() { return m_coffeeContainer; }
private:
    void powerOn();
    void powerOff();

    void selectNewMenuFromMain();

    void showListOfDrinks();
    void prepareDrink();
    void selectDrink();

    void showLowWaterError();
    void showLowMilkError();
    void showLowMilkAndWaterError();

    void showLowCoffeeGroundedError();
    void showMaxUsedCoffeeError();
private:
    std::vector<DrinkProgram*> m_recipes;
    DrinkProgram* m_SelectedDrink = nullptr;

    WaterReservoir m_waterReservoir;
    MilkReservoir m_milkReservoir;
    CoffeGrainsContainer m_coffeeContainer;

    int m_currentChoice = -1;
    CoffeeMachineState m_currentState = CoffeeMachineState::Sleep;

    bool m_powerOffRequest = false;

private:
    friend class DrinkProgram;
};
