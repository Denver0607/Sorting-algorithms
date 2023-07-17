#include "..\header.h"

void quickSort(int *arr, int left, int right)
{
    int midValue = arr[(left + right) / 2];
    int i = left;
    int j = right;
    int temp;
    while (i < j)
    {
        while (arr[i] < midValue)
        {
            i++;
        }
        while (arr[j] > midValue)
        {
            j--;
        }
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (i < right)
    {
        quickSort(arr, i, right);
    }
    if (left < j)
    {
        quickSort(arr, left, j);
    }
}

void quickSortRunTime(int *arr, int n, long long &time)
{
    auto start = chrono::steady_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = chrono::steady_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void quickSortComparisons(int *arr, int left, int right, long long &count_comparisons)
{
    int midValue = arr[(left + right) / 2];
    int i = left;
    int j = right;
    int temp;
    while (++count_comparisons && i < j)
    {
        while (++count_comparisons && arr[i] < midValue)
        {
            i++;
        }
        while (++count_comparisons && arr[j] > midValue)
        {
            j--;
        }
        if (++count_comparisons && i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (++count_comparisons && i < right)
    {
        quickSortComparisons(arr, i, right, count_comparisons);
    }
    if (++count_comparisons && left < j)
    {
        quickSortComparisons(arr, left, j, count_comparisons);
    }
}