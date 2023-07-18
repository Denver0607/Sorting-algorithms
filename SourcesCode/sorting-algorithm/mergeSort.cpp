#include "../header.h"
// reference: codelearn.io

void merge(int*&arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1];
    int *R = new int[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int*& arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Run Time
void mergeSortRunTime(int*& arr, int n, long long& time)
{
    // Start time
    auto start = chrono::high_resolution_clock::now();

    mergeSort(arr, 0, n - 1);

    // End time
    auto end = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(end - start).count();
}

// Comparison counting
void mergeCount(int *arr, int l, int m, int r, long long &count)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1];
    int *R = new int[n2];
    for (i = 0; ++count && i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; ++count && j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (++count && i < n1 && ++count && j < n2)
    {
        if (++count && L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (++count && i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (++count && j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSortCount(int*& arr, int l, int r, long long &count)
{
    if (++count && l < r)
    {
        int m = l + (r - l) / 2;
        mergeSortCount(arr, l, m, count);
        mergeSortCount(arr, m + 1, r, count);
        mergeCount(arr, l, m, r, count);
    }
}

void mergeSortCompare(int*& arr, int n, long long &count_comparisons)
{
    int l = 0;
    int r = n - 1;
    mergeSortCount(arr, l, r, count_comparisons);
}
