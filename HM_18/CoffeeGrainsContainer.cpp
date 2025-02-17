#include "CoffeeGrainsContainer.h"

void CoffeGrainsContainer::showOperations()
{
    std::cout << "\n--- Grained coffee level: " << getGrainsVolume() << "kg out of " << MaxGrainsCoffee << "kg max ---\n";
    std::cout << "\n--- Grounded coffee level: " << getGroundedVolume() << "kg out of " << MaxGroundedCoffee << "kg max ---\n";
    std::cout << "\n--- Used coffe level: " << getUsedVolume() << "kg out of " << MaxUsedCoffe << "kg max ---\n\n";
    std::cout << "1. Empty reservoir with Used coffee\n";
    std::cout << "2. Fill up with Grained container\n";
    std::cout << "3. Ground Coffe\n";
    std::cout << "4. Back to main\n";
};

void CoffeGrainsContainer::receiveInput()
{
    std::cout << "Choice: ";
    std::cin >> m_operation;
    if (!(m_operation >= 1) || !(m_operation <= 4))
    {
        std::cout << "Unknown request, please select from list [1-4]:" << std::endl;
        CoffeGrainsContainer::receiveInput();
    }
}

void CoffeGrainsContainer::update()
{
    switch (m_operation)
    {
    case 1:
        clean();
        break;
    case 2:
    {
        float newGrainsCoffeeVolume = 0.0f;
        std::cout << "Filling...";
        std::cout << "How much have you filled up? (Max: " << MaxGrainsCoffee << "kg) ";
        std::cin >> newGrainsCoffeeVolume;
        fill(newGrainsCoffeeVolume);
        std::cout << std::endl;
        break;
    }
    case 3:
    {
        if (m_grainsCoffeeVolume != 0)
        {
            groundCoffee(m_grainsCoffeeVolume);
            break;
        }
        std::cout << "\nCoffee grains container is empty, please refill it !\n";
        break;
    }
    case 4:
    default:
        break;
    }
};

void CoffeGrainsContainer::groundCoffee(float newGroundVolume)
{
    m_groundedCoffeeVolume += newGroundVolume;
    if (m_groundedCoffeeVolume > MaxGroundedCoffee)
    {
        m_grainsCoffeeVolume = m_groundedCoffeeVolume - MaxGroundedCoffee;
        m_groundedCoffeeVolume = MaxGroundedCoffee;
    }
    m_grainsCoffeeVolume -= newGroundVolume;
}