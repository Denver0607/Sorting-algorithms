#include "..\header.h"
// reference: codelearn.io

void merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
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
void mergeSort(int *a, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

// Run Time
void mergeSortRunTime(int *a, int n)
{
    // Start time
    auto start = chrono::high_resolution_clock::now();

    mergeSort(a, 0, n - 1);

    // End time
    auto end = chrono::high_resolution_clock::now();
    // Print out
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Time taken by Merge Sort: " << duration << " microseconds" << endl;
}

// Comparison counting
void mergeCount(int *arr, int l, int m, int r, int &count)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
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
void mergeSortCount(int *a, int l, int r, int &count)
{
    if (++count && l < r)
    {
        int m = l + (r - l) / 2;
        mergeSortCount(a, l, m, count);
        mergeSortCount(a, m + 1, r, count);
        mergeCount(a, l, m, r, count);
    }
}

void mergeSortCompare(int *a, int n, int &count)
{
    int l = 0;
    int r = n - 1;
    mergeSortCount(a, l, r, count);
}
