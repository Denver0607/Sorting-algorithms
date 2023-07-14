#include "func.h"

void insertionSortComparisons(int *&arr, int n, int &comparisonCounter)
{
    int key, j;
    for (int i = 1; ++comparisonCounter && i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (++comparisonCounter && j >= 0 && ++comparisonCounter && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSortRuntime(int *&arr, int n)
{
    int key, j;
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
