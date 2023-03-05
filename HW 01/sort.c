/* MODIFY this file */

#include "sort.h"

void ssort(int * arr, int size) {
// initialize variables
	int i;
	int j;
	int temp = 0;

	#ifdef ASCENDING
	// sort in ascending order
	for(i = 0; i < size; i++)
	{
		for(j = i + 1; j < size; j++)
		{
			// check if current element is greater than next element
			if(arr[i] > arr[j])
			{
				// swap elements if current element is greater than next element
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	#else
	// sort in descending order
	for(i = 0; i < size; i++)
	{
		for(j = i + 1; j < size; j++)
		{
			// check if current element is less than next element
			if(arr[i] < arr[j])
			{
				// swap elements if current element is less than next element
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
#endif
