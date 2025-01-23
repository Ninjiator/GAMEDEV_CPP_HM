#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;

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
                std::swap(arr, arr);
            }
        }
    }
}

constexpr unsigned int ROWS = 5;
constexpr unsigned int COLUMNS = 6;

enum class SortingDirection
{
    ByRows,
    ByColumns
};

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

void sort(int arr[ROWS][COLUMNS])
{
    for (int n = 0; n < ROWS; n++)
    {
        std::sort(arr[n], arr[n] + COLUMNS);
    }
}

void sort2(int arr[ROWS][COLUMNS])
{
    for (int n = 0; n < COLUMNS; n++)
    {
        std::sort(arr[n], arr[n] + ROWS);
    }
}

void print_2d_arrays(int arr[ROWS][COLUMNS])
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
    cout << "\n\n\n";

    cout << "Task 2: sorting by ROWS\n";
    int array[ROWS][COLUMNS] = {
        {70, 42, 89, 36, 67, 11},
        {41, 10, 50, 76, 31, 89},
        {94, 76, 6, 23, 100, 64},
        {66, 86, 77, 92, 8, 42},
        {59, 13, 70, 43, 34, 31}
    };
    sort(array);
    print_2d_arrays(array);

    cout << "Task 2.1: Sorting by columns"

}
    
