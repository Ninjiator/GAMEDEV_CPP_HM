#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int factorial_2(int count) // Task 2.2 func
{
    if (count > 1)
    {
        return count * factorial_2(count - 1);
    }
    else
    {
        return 1;
    }
}

void printNaturalNumberRecursion(int count)
{
    if (count >= 1)
    {
        cout << count << endl;
        printNaturalNumberRecursion(count - 1);
    }
}