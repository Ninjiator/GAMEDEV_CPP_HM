#include <iostream>
#include <algorithm>

#include "Sorting.h"

using std::cout;

//Sort in ascending way using the bubble sort algorithm
//Input:  1, 5, 8, 3, 4, 10, 6, 0, 9, -5
//Output: -5, 0, 1, 3, 4, 5, 6, 8, 9, 10,

void bubbleSort(int arr[], int size)
{
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i+1]);
            }
        }
    }
}

//Sort 2d array using any algorithm (custom quicksort, std::sort, implemented above Bubble Sort
// or using new implementation in-place)
//Input: ByRows
// 1, 5, 4
// 3, 8, 6
// 9, 5, 1
//Output:
// 1, 4, 5
// 3, 6, 8
// 1, 5, 9

//Input: ByColumns
// 1, 5, 4
// 3, 8, 6
// 9, 5, 1
//Output:
// 1, 5, 1
// 3, 5, 4
// 9, 8, 6

void sort(int arr[ROWS][COLUMNS], SortingDirection SortingDirection)
{
    switch (SortingDirection)
    {
    case SortingDirection::ByRows:
        for (int j = 0; j < ROWS; j++)
        {
            std::sort(arr[j], arr[j] + COLUMNS);
        }
        break;
    case SortingDirection::ByColumns:
        for (int i = 0; i < COLUMNS; i++)
        {
            int columns[ROWS];
            for (int j = 0; j < ROWS; j++)
            {
                columns[j] = arr[j][i];
            }

            std::sort(columns, columns + ROWS);

            for (int j = 0; j < ROWS; j++)
            {
                arr[j][i] = columns[j];
            }
        }
        break;
    default:
        break;
    }

}