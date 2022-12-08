/* MODIFY this file */

#include "sort.h"

void ssort(int * arr, int size) {
	
	int i;
	int j;
	int temp = 0;
	#ifdef ASCENDING
	for(i = 0; i < size; i++)
	{
		for(j = i + 1; j < size; j++)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	#else
	for(i = 0; i < size; i++)
	{
		for(j = i + 1; j < size; j++)
		{
			if(arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	#endif
}