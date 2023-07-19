#include "../header.h"
// reference: codelearn.io

// Run Time  
void selectionSortRunTime(int*& arr, int n, long long & time)
{
	// Start time
 	auto start = chrono::steady_clock::now();

	int indexMin;
	for (int i = 0; i < n-1; i++){
		indexMin = i;
		for (int j = i+1; j < n; j++){
			if (arr[indexMin] > arr[j]){
				indexMin = j;
			}
		}
		if (i != indexMin){
			int temp = arr[i];
			arr[i] = arr[indexMin];
			arr[indexMin] = temp;
		}
	}

    // End time
	auto end = chrono::steady_clock::now();
	
	time=chrono::duration_cast<chrono::microseconds>(end - start).count();
    
}

// Comparison counting
void selectionSortCompare(int*& arr, int n, long long & count_comparisons){
	count_comparisons = 0;
	int indexMin;
	for (int i = 0; ++count_comparisons && i < n-1; i++){
		indexMin = i;
		for (int j = i+1; ++count_comparisons && j < n; j++){
			if (++count_comparisons && arr[indexMin] > arr[j]){
				indexMin = j;
			}
		}
		if (++count_comparisons && i != indexMin){
			int temp = arr[i];
			arr[i] = arr[indexMin];
			arr[indexMin] = temp;
		}
	}
} 
