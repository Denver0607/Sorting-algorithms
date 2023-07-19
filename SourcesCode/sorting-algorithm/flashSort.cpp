#include "../header.h"

// Runtime
void insertionSort(int *arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int k = i - 1;
		int key = arr[i];
		while (arr[k] > key && k >= 0)
		{
			arr[k + 1] = arr[k];
			k--;
		}
		arr[k + 1] = key;
	}
}

void flashSortRunTime(int *&arr, int n, long long &time)
{
	auto start = chrono::steady_clock::now();
	int minVal = arr[0];
	int max = 0;
	int m = int(0.45 * n);
	int *l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < minVal)
			minVal = arr[i];
		if (arr[i] > arr[max])
			max = i;
	}
	if (arr[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (arr[max] - minVal);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (arr[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	swap(arr[max], arr[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1 * (arr[j] - minVal));
		}
		flash = arr[j];
		if (k < 0)
			break;
		while (j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = arr[t = --l[k]];
			arr[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertionSort(arr, n);
	auto end = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::microseconds>(end - start).count();
}

// Count Comparisons
void insertionSortCompare_1(int *arr, int n, long long &count_comparisons)
{
	for (int i = 1; ++count_comparisons && i < n; i++)
	{
		int k = i - 1;
		int key = arr[i];
		while ((++count_comparisons && arr[k] > key) && (++count_comparisons && k >= 0))
		{
			arr[k + 1] = arr[k];
			k--;
		}
		arr[k + 1] = key;
	}
}

void flashSortCompare(int *&arr, int n, long long &count_comparisons)
{
	count_comparisons = 0;
	int minVal = arr[0];
	int max = 0;
	int m = int(0.45 * n);
	int *l = new int[m];
	for (int i = 0; ++count_comparisons && i < m; i++)
		l[i] = 0;
	for (int i = 1; ++count_comparisons && i < n; i++)
	{
		if (++count_comparisons && arr[i] < minVal)
			minVal = arr[i];
		if (++count_comparisons && arr[i] > arr[max])
			max = i;
	}
	if (++count_comparisons && arr[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (arr[max] - minVal);
	for (int i = 0; ++count_comparisons && i < n; i++)
	{
		int k = int(c1 * (arr[i] - minVal));
		++l[k];
	}
	for (int i = 1; ++count_comparisons && i < m; i++)
		l[i] += l[i - 1];
	swap(arr[max], arr[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (++count_comparisons && nmove < n - 1)
	{
		while (++count_comparisons && j > l[k] - 1)
		{
			j++;
			k = int(c1 * (arr[j] - minVal));
		}
		flash = arr[j];
		if (++count_comparisons && k < 0)
			break;
		while (++count_comparisons && j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = arr[t = --l[k]];
			arr[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertionSortCompare_1(arr, n, count_comparisons);
}
