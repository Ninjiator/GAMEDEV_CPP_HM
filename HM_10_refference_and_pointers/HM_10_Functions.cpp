#include <iostream>
using std::endl;
using std::cout;
using std::cin;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap(int* a, int* b)
{
	cout << "swap *";
	int temp = *a;
	*a = *b;
	*b = temp;
}

bool find(const int* arr, int size, int elem)
{
	for (int i = 0; i < size; i++)
	{
		if (elem == *(arr + i))
		{
			return true;
		}
	}
	return false;
}

bool calculateSum(const double* arr, int arrSize, double& sum)
{
	for (int i = 0; i < arrSize; i++)
	{
		sum = sum + *(arr + i);
	}
	if (sum > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}