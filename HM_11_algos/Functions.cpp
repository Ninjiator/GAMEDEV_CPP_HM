#include <iostream>
#include "Functions.h"
using std::cout;

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
			}
		}
		return true;
	case SortingDirection::Descending:
		for (int i = 1; i < size; i++)
		{
			if (arr[i - 1] < *(arr + i))
			{
				return false;
			}
		}
		return true;
	default:
		return false;
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

	for (int x = ROWS - 1; x >= 0; x--)
	{
		if (x % 2)
		{
			for (int y = 0; y < COLUMNS; y++)
			{
				cout << arr_2d[x][y] << " ";
			}
		}
		else
		{
			for (int y_reverse = COLUMNS - 1; y_reverse >= 0; y_reverse--)
			{
				cout << arr_2d[x][y_reverse] << " ";
			}
		}
		cout << "\n";
	}
}