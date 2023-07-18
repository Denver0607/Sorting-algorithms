#include "..\header.h"
void heapify(int *&arr, int n, int i)
{
  // Find the largest child of the root
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
  {
    largest = left;
  }

  if (right < n && arr[right] > arr[largest])
  {
    largest = right;
  }

  // If the largest child is not the root, swap them
  if (largest != i)
  {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;

    // Heapify the new root
    heapify(arr, n, largest);
  }
}

void heapSortRunTime(int *&arr, int n, long long &time)
{
  auto start = chrono::steady_clock::now();

  // Create a heap
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }

  // Heapsort
  for (int i = n - 1; i >= 0; i--)
  {
    // Swap the root with the last element
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    // Heapify the root
    heapify(arr, i, 0);
  }
  auto end = chrono::steady_clock::now();
  time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void heapifyCompare(int *&arr, int n, int i, long long &count_comparisons)
{
  // Find the largest child of the root
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (++count_comparisons && left < n && ++count_comparisons && arr[left] > arr[largest])
  {
    largest = left;
  }

  if (++count_comparisons && right < n && ++count_comparisons && arr[right] > arr[largest])
  {
    largest = right;
  }

  // If the largest child is not the root, swap them
  if (++count_comparisons && largest != i)
  {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;

    // Heapify the new root
    heapifyCompare(arr, n, largest, count_comparisons);
  }
}
void heapSortCompare(int *&arr, int n, long long &count_comparisons)
{
  // Create a heap
  count_comparisons = 0;
  for (int i = n / 2 - 1; ++count_comparisons && i >= 0; i--)
  {
    heapifyCompare(arr, n, i, count_comparisons);
  }

  // Heapsort
  for (int i = n - 1; ++count_comparisons && i >= 0; i--)
  {
    // Swap the root with the last element
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    // Heapify the root
    heapifyCompare(arr, i, 0, count_comparisons);
  }
}
