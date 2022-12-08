/* You MUST modify this file */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
	
  // Note that from here on, you can access elements of the arr with
  // expressions like a[i]
	
  // initialize all elements
  int i;
  int j;
  int size_array = n;
  int target = k;
  int num_left = size_array;
  int count = 0;

 
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked

 for(i = 0; i < size_array; ++i) // Sets all numbers into the array to a starting value of 1
  {
    arr[i] = 1;
  }

  for(i = 0; i <= size_array; ++i) // Runs the eliminations until there is 1 left
  {
    while (num_left != 1) // While there is more than one person left, code still runs
    {
      for(j = 0; j < size_array; ++j) // Runs the cake game but skips counting any person who is eliminated (is a 0)
      {
        if (arr[j] !=0) // Skips those who are out
        {
          arr[j] = ++count; // Increase count
          if (arr[j] == target) // If target number is reached
          {
            count = 0; // Reset the count
            arr[j] = count; // Eliminate player
            printf("%d\n", j); // Print person
            --num_left; // Decrease number of players left
          }
        }
      }
      
    }
  }




  // print the last one
  for(i = 0; i < size_array; ++i)
  {
    if(arr[i] != 0) // Find the one element left
    {
      printf("%d\n", i); // Print the position
    }
  }



  // release the memory of the array
  free (arr);
}
#endif
