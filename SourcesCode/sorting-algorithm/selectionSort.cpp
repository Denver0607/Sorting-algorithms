#include "..\header.h"
// reference: codelearn.io

void selectionSort(int* a, int n){
	int indexMin;
	for (int i = 0; i < n-1; i++){
		indexMin = i;
		for (int j = i+1; j < n; j++){
			if (a[indexMin] > a[j]){
				indexMin = j;
			}
		}
		if (i != indexMin){
			int temp = a[i];
			a[i] = a[indexMin];
			a[indexMin] = temp;
		}
	}
} 

// Run Time  
void selectionSortRunTime(int* a, int n)
{
	// Start time
 	auto start = chrono::high_resolution_clock::now();

    selectionSort(a, n);

    // End time
    auto end = chrono::high_resolution_clock::now();
	// Print out
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Time taken by Selection Sort: " << duration << " microseconds" << endl;
}

// Comparison counting
void selectionSortCompare(int* a, int n, int& count){
	int indexMin;
	for (int i = 0; ++count && i < n-1; i++){
		indexMin = i;
		for (int j = i+1; ++count && j < n; j++){
			if (++count && a[indexMin] > a[j]){
				indexMin = j;
			}
		}
		if (++count && i != indexMin){
			int temp = a[i];
			a[i] = a[indexMin];
			a[indexMin] = temp;
		}
	}
} 

