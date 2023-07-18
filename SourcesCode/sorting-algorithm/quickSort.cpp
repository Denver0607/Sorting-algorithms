#include "..\header.h"

void quickSort(int *arr, int left, int right)
{
    auto start = chrono::steady_clock::now();
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

void quickSortRunTime(int *&arr, int n, long long &time)
{
    auto start = chrono::steady_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = chrono::steady_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void quickSortCounting(int *&arr, int left, int right, long long &count)
{
    int midValue = arr[(left + right) / 2];
    int i = left;
    int j = right;
    int temp;
    while (++count && i < j)
    {
        while (++count && arr[i] < midValue)
        {
            i++;
        }
        while (++count && arr[j] > midValue)
        {
            j--;
        }
        if (++count && i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (++count && i < right)
    {
        quickSortCounting(arr, i, right, count);
    }
    if (++count && left < j)
    {
        quickSortCounting(arr, left, j, count);
    }
}

void quickSortCompare(int *&arr, int n, long long &count_comparisons)
{
    quickSortCounting(arr, 0, n - 1, count_comparisons);
}
