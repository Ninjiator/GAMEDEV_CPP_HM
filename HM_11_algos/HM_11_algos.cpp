#include <iostream>
using std::cout;
using std::cin;

constexpr unsigned int ROWS = 4;
constexpr unsigned int COLUMNS = 6;
//#1
bool find(int arr_2d[ROWS][COLUMNS], int toFind) 
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLUMNS; j++)
		{
			if ((arr_2d[i][j]) == toFind)
			{
				return true;
			}
		}
	return false;
}
//#2
bool isSorted(const int* arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		if (arr[i-1] > *(arr + i))
		{
			return false;
		}
	}
	return true;
}
//#2_additional

//{1, 2, 3, 4, 5} SortingDirection::Ascending - true, SortingDirection::Descending - false
//{5, 4, 3, 2, 1} SortingDirection::Ascending - false, SortingDirection::Descending - true
//{1, 2, 5, 4, 3} SortingDirection::Ascending - false, SortingDirection::Descending - false

enum class SortingDirection
{
	Ascending,
	Descending
};
//#3_1
void traverseTopDownRightLeftByColumns(int arr_2d[ROWS][COLUMNS])
{
	//Output result into std::cout
}
//#3_2
void traverseLeftRightDownTopSwitchingByRows(int arr_2d[ROWS][COLUMNS])
{
   //Output result into std::cout
}

int main()
{
	cout << "Task 1: ";
	int searched = 24;
	int arr_2d[ROWS][COLUMNS] = {
	  {11, 12, 13, 14, 15, 16 },
	  {21, 22, 23, 24, 25, 26 },
	  {31, 32, 33, 34, 35, 36 },
	  {41, 42, 43, 44, 45, 46 }
	};
	cout << "\nCan we find " << searched << " in a 2D array ? -> [" << std::boolalpha << find(arr_2d, searched) << "]";

	cout << "\n\nTask 2: ";
	int const length = 5;
	const int arrayIsSorted[length] = { 1, 4, 5, 8, 7 };
	cout << "is Array_2 is sorted by growth? -> " << std::boolalpha << isSorted(arrayIsSorted, length);


}

