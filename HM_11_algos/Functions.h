#pragma once

constexpr unsigned int ROWS = 4;
constexpr unsigned int COLUMNS = 6;

//#1
bool find(int arr_2d[ROWS][COLUMNS], int toFind);

//#2 & #2.1
enum class SortingDirection
{
	Ascending,
	Descending
};
bool isSorted(const int* arr, int size, SortingDirection SortingDirection);
//#3_1
void traverseTopDownRightLeftByColumns(int arr_2d[ROWS][COLUMNS]);
//#3_2
void traverseLeftRightDownTopSwitchingByRows(int arr_2d[ROWS][COLUMNS]);