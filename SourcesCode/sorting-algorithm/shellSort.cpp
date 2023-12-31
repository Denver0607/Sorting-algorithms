#include "../header.h"

//Run Time
void shellSortRunTime(int*& arr , int n, long long& time)
{
	// Start time
 	auto start = chrono::steady_clock::now();

   	int interval, i, j, temp;
	for(interval = n/2; interval > 0; interval /= 2){
		for(i = interval; i < n; i++){
			temp = arr[i];
			for(j = i; j >= interval && arr[j - interval] > temp; j -= interval){
				arr[j] = arr[j - interval];				
			}
			arr[j] = temp;
		}
    }

  	// End time
	auto end = chrono::steady_clock::now();
	// Print out
	time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

//Comparison counting
void shellSortCompare(int*& arr, int n, long long & count_comparisons)
{
	count_comparisons = 0;
	int interval, i, j, temp;
	for(interval = n/2; ++count_comparisons && interval > 0; interval /= 2)
	{
		for(i = interval; ++count_comparisons && i < n; i++)
		{
			temp = arr[i];
			for(j = i; ++count_comparisons && j >= interval && ++count_comparisons && arr[j - interval] > temp; j -= interval){
				arr[j] = arr[j - interval];				
			}
			arr[j] = temp;
		}
    }
}
