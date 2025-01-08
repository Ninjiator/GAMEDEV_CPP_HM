#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int userNumCounterAndAnalysys(int userNum) // Task 1 func
{
    int positive = 0;
    int negative = 0;
    int zero = 0;
    int j = 0;

    for (int i = 0; i < userNum; i++)
    {
        cin >> j;
        if (j > 0)
        {
            positive++;
        }
        else if (j < 0)
        {
            negative++;
        }
        else
        {
            zero++;
        }
    }
    cout << "----------------------------" << endl;
    cout << "Positive " << positive << endl;
    cout << "Negative " << negative << endl;
    cout << "Zero " << zero << endl;
    return 0;
}

long long factorial_1(int count) // Task 2.1 func
{
    long long factorialResult = 1;
    for (int i = 1; i <= count; i++)
    {
        factorialResult *= i;
    }
    return factorialResult;
}

void printNaturalNumberFromMaxToMin(int count)
{
    for (int n = 0; n < count; count--)
    {
        cout << count << endl;
    }
}

void printNaturalNumberFromMinToMax(int count)
{
    for (int i = 1; i <= count; i++)
    {
        cout << i << endl;
    }
}