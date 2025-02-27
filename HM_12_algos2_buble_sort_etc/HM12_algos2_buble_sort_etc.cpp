#include <iostream>
#include <algorithm>
#include "Sorting.h"
using std::cout;

void print2DArrays(int arr[ROWS][COLUMNS])
{
    for (int a = 0; a < ROWS; a++)
    {
        for (int b = 0; b < COLUMNS; b++)
        {
            cout << arr[a][b] << ", ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    constexpr int arr1d_size = 10;
    cout << "Task 1: Bubble sort\nArray [BEFORE] sorting:\n1, 5, 8, 3, 4, 10, 6, 0, 9, -5\n";
    int arr1d[arr1d_size] = { 1, 5, 8, 3, 4, 10, 6, 0, 9, -5 };
    bubbleSort(arr1d, arr1d_size);
    cout << "Array [AFTER] sorting:\n";
    for (int j = 0; j < arr1d_size; j++)
    {
        cout << arr1d[j] << ", ";
    }

    cout << "\n\n\nTask 2: sorting by ROWS\n";
    int array[ROWS][COLUMNS] = {
        {70, 42, 89, 36, 67, 11},
        {41, 10, 50, 76, 31, 89},
        {94, 76, 6, 23, 100, 64},
        {66, 86, 77, 92, 8, 42},
        {59, 13, 70, 43, 34, 31}
    };
    sort(array, SortingDirection::ByRows);
    print2DArrays(array);

    cout << "\n\nTask 2.1: Sorting by columns\n";
    sort(array, SortingDirection::ByColumns);
    print2DArrays(array);


}
    
