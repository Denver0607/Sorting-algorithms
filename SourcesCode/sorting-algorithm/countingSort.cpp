#include "../header.h"

void countingSortRunTime(int *&arr, int n, long long &time)
{
    auto start = chrono::steady_clock::now();
    int max = arr[0], min = arr[0];
    vector<int> ans = vector<int>(n);
    for (int i = 1; i < n; ++i)
    {
        if (max < arr[i])
            max = arr[i];
        if (min > arr[i])
            min = arr[i];
    }
    vector<int> count(max - min + 1, 0);
    for (int i = 0; i < n; i++)
    {
        count[arr[i] - min]++;
        ans[i] = arr[i];
    }
    for (int i = 1; i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        arr[count[ans[i] - min] - 1] = ans[i];
        count[ans[i] - min]--;
    }
    auto end = chrono::steady_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void countingSortCompare(int *&arr, int n, long long &count_comparisons)
{
    int max = arr[0], min = arr[0];
    vector<int> ans = vector<int>(n);
    for (int i = 1; ++count_comparisons && i < n; ++i)
    {
        if (++count_comparisons && max < arr[i])
            max = arr[i];
        if (++count_comparisons && min > arr[i])
            min = arr[i];
    }
    vector<int> count(max - min + 1, 0);
    for (int i = 0; ++count_comparisons && i < n; i++)
    {
        count[arr[i] - min]++;
        ans[i] = arr[i];
    }
    for (int i = 1; ++count_comparisons && i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; ++count_comparisons && i >= 0; i--)
    {
        arr[count[ans[i] - min] - 1] = ans[i];
        count[ans[i] - min]--;
    }
}
