#include "..\header.h"

void shakerSortRunTime(int *&arr, int n, long long &time) {
  auto start = chrono::steady_clock::now();
  bool swapped = true;
  int i = 0;
  int j = n - 1;

  while (swapped) {
    swapped = false;

    for (int k = 1; k < j; k++) {
      if (arr[k - 1] > arr[k]) {
        int temp = arr[k - 1];
        arr[k - 1] = arr[k];
        arr[k] = temp;
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    }

    swapped = false;

    for (int k = j - 1; k > i; k--) {
      if (arr[k - 1] < arr[k]) {
        int temp = arr[k - 1];
        arr[k - 1] = arr[k];
        arr[k] = temp;
        swapped = true;
      }
    }

    i++;
    j--;
  }
  auto end = chrono::steady_clock::now();
  time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void shakerSortCompare(int *&arr, int n, long long &count_comparisons) {
  bool swapped = true;
  int i = 0;
  int j = n - 1;
  count_comparisons = 0;

  while (++count_comparisons && swapped) {
    swapped = false;

    for (int k = 1; ++count_comparisons && k < j; k++) {
      if (++count_comparisons && arr[k - 1] > arr[k]) {
        int temp = arr[k - 1];
        arr[k - 1] = arr[k];
        arr[k] = temp;
        swapped = true;
      }
    }

    if (++count_comparisons && !swapped) {
      break;
    }

    swapped = false;

    for (int k = j - 1; ++count_comparisons && k > i; k--) {
      if (++count_comparisons && arr[k - 1] < arr[k]) {
        int temp = arr[k - 1];
        arr[k - 1] = arr[k];
        arr[k] = temp;
        swapped = true;
      }
    }

    i++;
    j--;
  }
}