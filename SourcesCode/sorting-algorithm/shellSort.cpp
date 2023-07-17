#include "..\header.h"

void shellSort(int* a, int n){
	int interval, i, j, temp;
	for(interval = n/2; interval > 0; interval /= 2){
		for(i = interval; i < n; i++){
			temp = a[i];
			for(j = i; j >= interval && a[j - interval] > temp; j -= interval){
				a[j] = a[j - interval];				
			}
			a[j] = temp;
		}
    }
}

//Run Time
void shellSortRunTime(int* a , int n)
{
	// Start time
 	auto start = chrono::high_resolution_clock::now();

    shellSort(a, n);

    // End time
    auto end = chrono::high_resolution_clock::now();
	// Print out
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Time taken by Shell Sort: " << duration << " microseconds" << endl;
}

//Comparison counting
void shellSortCompare(int* a, int n, int& count)
{
	int interval, i, j, temp;
	for(interval = n/2; ++count && interval > 0; interval /= 2)
	{
		for(i = interval; ++count && i < n; i++)
		{
			temp = a[i];
			for(j = i; ++count && j >= interval && ++count && a[j - interval] > temp; j -= interval){
				a[j] = a[j - interval];				
			}
			a[j] = temp;
		}
    }
}
