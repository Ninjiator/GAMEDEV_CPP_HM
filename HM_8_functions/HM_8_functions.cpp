#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "LoopFunctions.h"
#include "RecursiveFunctions.h"
using std::cin;
using std::cout;
using std::endl;

double getArea(float radius) // Task 3 func
{
    return M_PI * pow(radius, 2);
}
double getCircumference(float radius) 
{
   return 2 * M_PI * radius;
}
int main()
{
    // Task 1
    int userNum;
    cout << "Task 1:\nEnter the nums: ";
    cin >> userNum;
    userNumCounterAndAnalysys(userNum);

    //Task 2.1 factorial via loop
    cout << "\nTask 2 factorial via loop\nEnter a num for factorial calculation :";
    cin >> userNum;
    cout << "Factorial of " << userNum << " = " << factorial_1(userNum) << endl << endl;

    //Task 2.2 factorial via recursion
    cout << "Task 2.2 factorial via recursion\nEnter a num for factorial calculation :";
    cin >> userNum;
    cout << "Factorial of " << userNum << " = " << factorial_2(userNum) << endl << endl;

    //Task 3
    float circleRadius;
    cout << "Task 3\nEnter circle radius for area & circumference calculation : ";
    cin >> circleRadius;

    cout << "\nCircle Area is :" << getArea(circleRadius) << endl << endl;
    cout << "Circle Circumference is :" << getCircumference(circleRadius) << endl << endl;

    //Task 4.1
    int userNaturalNums = 0;
    cout << "Task 4\nEnter a N natural nums for print:";
    cin >> userNaturalNums;
    cout << "From max to min: \n";
    printNaturalNumberFromMaxToMin(userNaturalNums);

    //Task 4.2
    cout << "From min to max: \n";
    printNaturalNumberFromMinToMax(userNaturalNums);

    //Task 4.3
    cout << "From max to min via recursion: \n";
    printNaturalNumberRecursion(userNaturalNums);
}
