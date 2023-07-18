#include "../header.h"

//Count comparisons
void bubbleSortCompare(int *&arr, int n, long long &count_comparisons)
{
    int i, j;
    bool swapped;
    count_comparisons = 0;
    for (i = 0; ++count_comparisons && i < n - 1; i++) {
        swapped = false;
        for (j = 0; ++count_comparisons && j < n - i - 1; j++) {
            if (++count_comparisons && arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (++count_comparisons && swapped == false)
            break;
    }
}

//Runtime
void bubbleSortRunTime(int *&arr, int n, long long &time)
{
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    end = chrono::system_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}
