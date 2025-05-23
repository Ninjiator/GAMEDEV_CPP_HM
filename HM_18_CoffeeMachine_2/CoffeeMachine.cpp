#include "CoffeeMachine.h"

void CoffeeMachine::initDefaultDrinks()
{
    m_recipes.push_back(new Espresso(*this));
    m_recipes.push_back(new Cappuccino(*this));
    m_recipes.push_back(new HotTea(*this));
    m_recipes.push_back(new ColdTea(*this));
}

void CoffeeMachine::showMenu()
{
    switch (m_currentState)
    {
    case CoffeeMachineState::Sleep:
        std::cout << "1. POWER ON\n";
        break;
    case CoffeeMachineState::MainMenu:
    {
        std::cout << "\n1. Prepare Drink\n";
        std::cout << "2. Access Water Reservoir\n";
        std::cout << "3. Access Milk Reservoir\n";
        std::cout << "4. Access Coffe Grain Container\n";
        std::cout << "5. Power off\n";
        break;
    }
    case CoffeeMachineState::DrinkSelection:
    {
        showListOfDrinks();
        break;
    }
    case CoffeeMachineState::WaterReservoir:
        m_waterReservoir.showOperations();
        break;
    case CoffeeMachineState::MilkReservoir:
        m_milkReservoir.showOperations();
        break;
    case CoffeeMachineState::CoffeeContainer:
        m_coffeeContainer.showOperations();
        break;
    default:
        break;
    }
}

void CoffeeMachine::receiveInput()
{
    switch (m_currentState)
    {
    case CoffeeMachineState::Sleep:
    case CoffeeMachineState::MainMenu:
    case CoffeeMachineState::DrinkSelection:
    {
        std::cout << "Choice: ";
        std::cin >> m_currentChoice;
        break;
    }
    case CoffeeMachineState::WaterReservoir:
        m_waterReservoir.receiveInput();
        break;
    case CoffeeMachineState::MilkReservoir:
        m_milkReservoir.receiveInput();
        break;
    case CoffeeMachineState::CoffeeContainer:
        m_coffeeContainer.receiveInput();
        break;
    default:
        break;
    }
}

void CoffeeMachine::update()
{
    switch (m_currentState)
    {
    case CoffeeMachineState::Sleep:
    {
        powerOn();
        break;
    }
    case CoffeeMachineState::MainMenu:
        //Moving to sub-menu animation
        selectNewMenuFromMain();
        break;
    case CoffeeMachineState::DrinkSelection:
        //Moving to drinks sub-menu cool animation
        selectDrink();
        break;
    case CoffeeMachineState::DrinkPreparation:
        prepareDrink();
        break;
    case CoffeeMachineState::WaterReservoir:
        m_waterReservoir.update();
        m_currentState = CoffeeMachineState::MainMenu;
        break;
    case CoffeeMachineState::MilkReservoir:
        m_milkReservoir.update();
        m_currentState = CoffeeMachineState::MainMenu;
        break;
    case CoffeeMachineState::CoffeeContainer:
        m_coffeeContainer.update();
        m_currentState = CoffeeMachineState::MainMenu;
        break;
    case CoffeeMachineState::PowerOffRequest:
    {
        powerOff();
        break;
    }
    case CoffeeMachineState::LowWaterError:
    {
        showLowWaterError();
        break;
    }
    case CoffeeMachineState::LowMilkError:
    {
        showLowMilkError();
        break;
    }
    case CoffeeMachineState::LowWaterAndMilkError:
    {
        showLowMilkAndWaterError();
        break;
    }
    case CoffeeMachineState::LowCoffeeGroundedError:
        showLowCoffeeGroundedError();
        break;
    case CoffeeMachineState::MaxUsedCoffeeError:
        showMaxUsedCoffeeError();
        break;
    default:
        break;
    }
}

void CoffeeMachine::powerOn()
{
    if (m_currentChoice == 1)
    {
        std::cout << "\nGrrrr... Self diagnostics... Checking water level...\n";
        if ((m_waterReservoir.getVolume() <= 0.0f) && (m_milkReservoir.getVolume() <= 0.0f))
        {
            m_currentState = CoffeeMachineState::LowWaterAndMilkError;
        }
        else if (m_milkReservoir.getVolume() <= 0.0f)
        {
            m_currentState = CoffeeMachineState::LowMilkError;
        }
        else if (m_waterReservoir.getVolume() <= 0.0f)
        {
            m_currentState = CoffeeMachineState::LowWaterError;
        }
        else
        {
            m_currentState = CoffeeMachineState::MainMenu;
        }
    }
}

void CoffeeMachine::powerOff()
{
    std::cout << "Grrrrrr.... Bye-bye... (Cool animation's playing)\n\n\n";
    m_powerOffRequest = true;
}

void CoffeeMachine::selectNewMenuFromMain()
{
    switch (m_currentChoice)
    {
    case 1:
        m_currentState = CoffeeMachineState::DrinkSelection;
        break;
    case 2:
        m_currentState = CoffeeMachineState::WaterReservoir;
        break;
    case 3:
        m_currentState = CoffeeMachineState::MilkReservoir;
        break;
    case 4:
        m_currentState = CoffeeMachineState::CoffeeContainer;
        break;
    case 5:
        m_currentState = CoffeeMachineState::PowerOffRequest;
        break;
    default:
        m_currentState = CoffeeMachineState::MainMenu;
        break;
    }
}

void CoffeeMachine::showListOfDrinks()
{
    std::cout << std::endl;
    for (int i = 0; i < m_recipes.size(); i++)
    {
        std::cout << i + 1 << ". ";
        m_recipes[i]->showInfo();
        std::cout << std::endl;
    } 
}

void CoffeeMachine::selectDrink()
{
    const int receipeIdx = m_currentChoice - 1;
    if (receipeIdx >= 0 && receipeIdx < m_recipes.size())
    {
        m_SelectedDrink = m_recipes[receipeIdx];
    }

    if (m_SelectedDrink != nullptr)
    {
        m_currentState = CoffeeMachineState::DrinkPreparation;
    }
    else
    {
        m_currentState = CoffeeMachineState::DrinkSelection;
    }
}

void CoffeeMachine::showLowWaterError()
{
    std::cout << "LOW WATER, please refill the water container!\n";
    m_currentState = CoffeeMachineState::MainMenu;
}

void CoffeeMachine::showLowMilkError()
{
    std::cout << "LOW MILK, please refill the milk container!\n";
    m_currentState = CoffeeMachineState::MainMenu;
}

void CoffeeMachine::showLowMilkAndWaterError()
{
    std::cout << "MILK and WATER containers are empty, please refill them!\n";
    m_currentState = CoffeeMachineState::MainMenu;
}

void CoffeeMachine::showLowCoffeeGroundedError()
{
    std::cout << "Grounded Coffee container is empty, please refill !\n";
    m_currentState = CoffeeMachineState::MainMenu;
}

void CoffeeMachine::showMaxUsedCoffeeError()
{
    std::cout << "Clean up used Coffee!\n";
    m_currentState = CoffeeMachineState::MainMenu;
}


void CoffeeMachine::prepareDrink()
{
    if (m_SelectedDrink == nullptr)
    {
        m_currentState = CoffeeMachineState::DrinkSelection;
        return;
    }

    const DrinkProgramStatus status = m_SelectedDrink->prepare();

    if (status == DrinkProgramStatus::Success)
    {
        m_currentState = CoffeeMachineState::MainMenu;
    }
    else if (status == DrinkProgramStatus::LowWater)
    {
        m_currentState = CoffeeMachineState::LowWaterError;
    }
    else if (status == DrinkProgramStatus::LowMilk)
    {
        m_currentState = CoffeeMachineState::LowMilkError;
    }
    else if (status == DrinkProgramStatus::LowWaterAndMilk)
    {
        m_currentState = CoffeeMachineState::LowWaterAndMilkError;
    }
    else if (status == DrinkProgramStatus::LowCoffeeGrounded)
    {
        m_currentState = CoffeeMachineState::LowCoffeeGroundedError;
    }
    else if (status == DrinkProgramStatus::CleanNeeded)
    {
        m_currentState = CoffeeMachineState::MaxUsedCoffeeError;
    }
}