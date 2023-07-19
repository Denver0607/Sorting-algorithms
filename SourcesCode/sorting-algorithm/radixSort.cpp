#include "../header.h"

//Runtime
int getMax(int *&arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int *&arr, int n, int exp)
{
    int output[n];
    int i, countdigit[10] = { 0 };

    for (i = 0; i < n; i++)
        countdigit[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        countdigit[i] += countdigit[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[countdigit[(arr[i] / exp) % 10] - 1] = arr[i];
        countdigit[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSortRunTime(int *&arr, int n, long long &time)
{
    auto start = chrono::steady_clock::now();
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
    auto end = chrono::steady_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

///Count comparisons

int getMaxCompare(int *&arr, int n, long long &count_comparisons)
{
    int mx = arr[0];
    for (int i = 1; ++count_comparisons && i < n; i++)
        if (++count_comparisons && arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSortCompare(int *&arr, int n, int exp, long long &count_comparisons)
{
    int output[n];
    int i, countdigit[10] = { 0 };

    for (i = 0; ++count_comparisons && i < n; i++)
        countdigit[(arr[i] / exp) % 10]++;

    for (i = 1; ++count_comparisons && i < 10; i++)
        countdigit[i] += countdigit[i - 1];

    for (i = n - 1; ++ count_comparisons && i >= 0; i--) {
        output[countdigit[(arr[i] / exp) % 10] - 1] = arr[i];
        countdigit[(arr[i] / exp) % 10]--;
    }

    for (i = 0; ++count_comparisons && i < n; i++)
        arr[i] = output[i];
}

void radixSortCompare(int *&arr, int n, long long &count_comparisons)
{
    count_comparisons = 0;
    int m = getMaxCompare(arr, n, count_comparisons);

    for (int exp = 1; ++count_comparisons && m / exp > 0; exp *= 10)
        countSortCompare(arr, n, exp, count_comparisons);
}

