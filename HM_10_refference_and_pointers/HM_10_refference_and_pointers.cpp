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
		if(elem == *(arr + i))
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

int main()
{
	//Task 1.1
	int num_1 = 0;
	int num_2 = 0;
	cout << "Task 1.2\nEnter nums for swap:\n";
	cout << "Num_1: ";
	cin >> num_1;
	cout << "Num_2: ";
	cin >> num_2;
	swap(num_1, num_2);
	cout << "Num_1: " << num_1;
	cout << "\nNum_2: " << num_2;

	//Task 1.2
	int num1 = 0;
	int num2 = 0;
	cout << "\n\nTask 1.2\nEnter nums for swap:\n";
	cout << "Num_1: ";
	cin >> num1;
	cout << "Num_2: ";
	cin >> num2;
	swap(num1, num2);
	cout << "Num_1: " << num1;
	cout << "\nNum_2: " << num2;

	//Task 2
	cout << "\n\nTask 2\n";
	int searchedNum = -2;
	const int lenght = 10;
	const int myArray[lenght] = { 5, 8, 4, 3, 6, 7, 2, 0, -2, 91 };
	cout << "Let's found [" << searchedNum << "] in array size 10: ";
	for (int i = 0; i < lenght; i++)
	{
		cout << myArray[i] << ' ';
	}
	cout << "\nIs [-2] present in array ? -> " << std::boolalpha <<find(myArray, lenght, searchedNum);

	//Task 3
	cout << "\n\nTask 3\n";
	cout << "Is summ of all elements in array2 is > 0?";
	double sum = 0;
	const double myArray2[lenght] = { -5, 1, 0, 1, 2, -10, 2.5, 3, 12 };
	cout << "\nArray 2 is :\n";
	for (int i = 0; i < lenght; i++)
	{
		cout << myArray2[i] << ' ';
	}
	cout << "\nResult is: [" << std::boolalpha << calculateSum(myArray2, lenght, sum) << "] sum of all elements = " << sum;


}

