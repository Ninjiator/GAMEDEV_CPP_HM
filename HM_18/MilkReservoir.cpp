#include "MilkReservoir.h"
#include <iostream>

void MilkReservoir::showOperations()
{
    std::cout << "\n--- Current milk level: " << getVolume() << "l out of " << MaxVolume << "l max ---\n";
    std::cout << "1. Empty reservoir - [to do]\n";
    std::cout << "2. Fill up with milk [wip] \n";
    std::cout << "3. Back to main\n";
};

void MilkReservoir::receiveInput()
{
    std::cout << "Choice: ";
    std::cin >> m_operation;
    if (!(m_operation >= 1) || !(m_operation <= 3))
    {
        std::cout << "Unknown request, please select from list [1-3]:" << std::endl;
        MilkReservoir::receiveInput();
    }
}

void MilkReservoir::update()
{
    switch (m_operation)
    {
    case 1:
        empty();
        break;
    case 2:
    {
        float newVolume = 0.0f;
        std::cout << "Filling...";
        std::cout << "How much have you filled up? (Max: " << MaxVolume << "l) ";
        std::cin >> newVolume;
        fill(newVolume);
        std::cout << std::endl;
        break;
    }
    case 3:
    default:
        break;
    }
};