// HM_4_if_else.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    //Task 1
    int a, b, c;
    cout << "Task 1" << endl;
    cout << "Enter 3 numbers" << endl;
    cin >> a >> b >> c;
    if (a > b && a > c)
    {
        cout << "a is bigger one" << endl << endl << endl;
    }
    else if (b > a && b > c)
    {
        cout << "b is bigger one" << endl << endl << endl;
    }
    else
    {
        cout << "c is bigger one" << endl << endl << endl;
    }

    //Task 2
    cout << "Task 2" << endl;
    int value;
    cout << "Enter value: \n";
    cin >> value;
    if (value == 0)
    { 
        cout << "We cannot devide 0 by 5 and 11\n\n\n";
        if ((value % 5 == 0) && (value % 11 == 0))
        {
            cout << "This value can be devided by 5 and 11 simultaneously\n\n\n";
        }
        else
        {
            cout << "This value CAN NOT be devided by 5 and 11 simultaneously\n\n\n";
        }
    }

    //Task 3
    int x, y, z;
    int sumOfTrianglesAngles = 180;
    int sumOfParams;
    cout << "Task 3" << endl;
    cout << "Enter 3 parameters for triangle angles" << endl;
    cin >> x >> y >> z;
    sumOfParams = x + y + z;
    if (sumOfParams == sumOfTrianglesAngles)
    {
        cout << "it is possible to build a triangle from these angles\n\n\n";
    }
    else if (sumOfParams >= sumOfTrianglesAngles)
    {
        cout << "the sum of the angles of the triangles cannot be greater than 180\n\n\n";
    }
    else
    {
        cout << "the sum of the angles of the triangles cannot be lesser than 180\n\n\n";
    }

    //task 4
    enum class month
    {
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December,
    };
    int inputedMonth = 0;
    cout << "Task 4" << endl;
    cout << "Enter month number from 1 to 12: \n";
    cin >> inputedMonth;

    month monthParam = static_cast<month>(inputedMonth);

    switch (monthParam)
    {
    case month::December:
    case month::January:
    case month::February:
        cout << "winter\n\n\n";
        break;
    case month::March:
    case month::April:
    case month::May:
        cout << "spring\n\n\n";
        break;
    case month::June:
    case month::July:
    case month::August:
        cout << "summer\n\n\n";
        break;
    case month::September:
    case month::October:
    case month::November:
        cout << "autumn\n\n\n";
        break;
    default:
        cout << "Out of Range 1-12\n\n\n";
        break;
    }

    //Additional Task 1
    int inputNum1;
    int inputNum2;
    cout << "Additional Task 1" << endl;
    std::cout << "Enter the first number: ";
    std::cin >> inputNum1;
    std::cout << "Enter the second number: ";
    std::cin >> inputNum2;
    
    int minValue = (inputNum1 < inputNum2) ? inputNum1 : inputNum2;
    std::cout << "The minimum value is: " << minValue << std::endl;

    //Additional Task 2
    enum class month2
    {
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December,
    };
    int inputedMonth2 = 0;
    cout << "Additional Task 2" << endl;
    cout << "Enter month number from 1 to 12: \n";
    cin >> inputedMonth2;

    month monthParam2 = static_cast<month>(inputedMonth2);

    switch (monthParam2)
    {
    case month::January:
        cout << "It's January\n";
        break;
    case month::February:
        cout << "It's February\n";
        break;
    case month::March:
        cout << "It's March\n";
        break;
    case month::April:
        cout << "It's April\n";
        break;
    case month::May:
        cout << "May\n";
        break;
    case month::June:
        cout << "It's June\n";
        break;
    case month::July:
        cout << "It's July\n";
        break;
    case month::August:
        cout << "August\n";
        break;
    case month::September:
        cout << "It's September\n";
        break;
    case month::October:
        cout << "It's October\n";
        break;
    case month::November:
        cout << "It's November\n";
        break;
    case month::December:
        cout << "December\n";
        break;
    default:
        cout << "Out of Range 1-12\n";
        break;
    }
}

