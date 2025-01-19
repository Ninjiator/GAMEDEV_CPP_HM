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

//#2 & #2.1
enum class SortingDirection
{
	Ascending,
	Descending
};

bool isSorted(const int* arr, int size, SortingDirection SortingDirection)
{
	switch (SortingDirection)
	{
	case SortingDirection::Ascending:
		for (int i = 1; i < size; i++)
		{
			if (arr[i - 1] > *(arr + i))
			{
				return false;
				break;
			}
		}
		return true;
	case SortingDirection::Descending:
		for (int i = 1; i < size; i++)
		{
			if (arr[i - 1] < *(arr + i))
			{
				return false;
				break;
			}
		}
		return true;
	default:
		break;
	}
}

//#3_1
void traverseTopDownRightLeftByColumns(int arr_2d[ROWS][COLUMNS])
{
	for (int j = COLUMNS - 1; j >= 0; j--)
	{
		for (int i = 0; i < ROWS; i++)
		{
			cout << arr_2d[i][j] << " ";
		}
		cout << "\n";
	}
}
//#3_2
void traverseLeftRightDownTopSwitchingByRows(int arr_2d[ROWS][COLUMNS])
{
	for (int x = ROWS-1; x >= 0; x--)
	{
		for (int y = 0; y < COLUMNS; y++)
		{
			cout << arr_2d[x][y] << " ";
		}
		cout << "\n";
	}
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
	const int arrayIsSorted[length] = { 8, 5, 4, 3, 2 };
	cout << "is Array_2 is sorted by Ascending? -> " << isSorted(arrayIsSorted, length, SortingDirection::Ascending);
	cout << "\nis Array_2 is sorted by Descending? -> " << std::boolalpha << isSorted(arrayIsSorted, length, SortingDirection::Descending);

	cout << "\n\nTask 3:\n ";
	traverseTopDownRightLeftByColumns(arr_2d);
	cout << "\n\nTask 4: \n";
	traverseLeftRightDownTopSwitchingByRows(arr_2d);
	cout << "\n" << arr_2d[2][5]; //36
	cout << "\n" << arr_2d[3][5]; //46
}

