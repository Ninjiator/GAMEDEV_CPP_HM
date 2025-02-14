#include "CoffeeGrainsContainer.h"

void CoffeGrainsContainer::showOperations()
{
    std::cout << "\n--- Grained coffe level: " << getGrainsVolume() << "kg out of " << MaxGrainsCoffee << "kg max ---\n";
    std::cout << "1. Empty reservoir\n";
    std::cout << "2. Fill up with milk\n";
    std::cout << "3. Back to main\n";
};

void CoffeGrainsContainer::receiveInput()
{

};

void CoffeGrainsContainer::update()
{

};
