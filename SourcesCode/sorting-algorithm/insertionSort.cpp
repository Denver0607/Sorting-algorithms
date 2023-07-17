#include "..\header.h"
void insertionSortComparisons(int *&arr, int n, long long &count_comparisons)
{
    count_comparisons = 0;
    int key, j;
    for (int i = 1; ++count_comparisons && i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (++count_comparisons && j >= 0 && ++count_comparisons && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSortRuntime(int *&arr, int n, long long &time)
{
    auto start = chrono::steady_clock::now();
    int key, j;
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
    auto end = chrono::steady_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}
