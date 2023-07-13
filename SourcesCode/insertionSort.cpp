#include <bits/stdc++.h>
#include <chrono>
using namespace std;

void insertionSortComparisons(int *arr, int n, int &comparisonCounter)
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
    cout << "Comparisons (if required): " << comparisonCounter << endl;
}

void insertionSortRuntime(int *arr, int n)
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
    auto end = chrono::steady_clock::now();
    cout << "Running time (if required): " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
}

// int main()
// {
//     int *arr, *b;
//     int n, comparisonCounter;
//     comparisonCounter = 0;
//     cout << "n = ";
//     cin >> n;
//     arr = new int[n];
//     b = new int[n];
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = n - i - 1;
//         b[i] = n - i - 1;
//     }
//     insertionSortComparisons(arr, n, comparisonCounter);
//     insertionSortRuntime(b, n);
//     return 0;
// }