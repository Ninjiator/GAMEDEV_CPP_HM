#pragma once

constexpr unsigned int ROWS = 5;
constexpr unsigned int COLUMNS = 6;

enum class SortingDirection
{
    ByRows,
    ByColumns
};

void bubbleSort(int arr[], int size);
void sort(int arr[ROWS][COLUMNS], SortingDirection SortingDirection);