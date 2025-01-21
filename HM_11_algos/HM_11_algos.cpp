#include <iostream>
#include "Functions.h"
using std::cout;

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

	cout << "\n\nTask 3: traverseTopDownRightLeftByColumns\n";
	traverseTopDownRightLeftByColumns(arr_2d);
	cout << "\n\nTask 4: traverseLeftRightDownTopSwitchingByRows\n";
	traverseLeftRightDownTopSwitchingByRows(arr_2d);
	
	
}

