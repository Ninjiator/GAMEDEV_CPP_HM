#include <iostream>
#include <vector>

#include "CoffeeMachine.h"

int main()
{
    CoffeeMachine machine;

    machine.initDefaultDrinks();

    while (machine.IsBooted())
    {
        machine.showMenu();
        machine.receiveInput();
        machine.update();
    }

    return 0;
}