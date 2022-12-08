// ***
// *** Modify this file
// ***

#include "msort.h"
#include "hw6.h"
#include <stdio.h>

/*
Merge sort function. Sorts an array with base address base, with nel elements where each element takes up space of size width.

INPUT:
base: a pointer to the beginning of the array to be sorted
nel: the number of elements in the array pointed to by base
compar: a function pointer to compare two elements in the base array

OUTPUT:
the function has no return value,
but after msort, base now should point to a sorted array
*/
#ifndef OMIT_MSORT
void msort(Student * base, int nel, int (*compar)(const void *, const void *)) {
	
	//Base case: if the array has one or fewer elements, it's already sorted
	//so just return.
	if (nel <= 1){
		return;
	}
	//Inductive case: split the array in two, sort the two pieces with msort,
	//merge the	sorted pieces
	

	//We're going to do this without explicitly creating the two separate arrays
	//We'll take advantage of the fact that to C, an array is just a pointer to
	//a region of memory. If we call msort on base, but pass in a smaller number
	//of elements, it will sort just that subarray. Similarly, if we call msort
	//but pass in the address of an element in the middle of the array, it will
	//sort the array *starting* from that element.
		
	//1. Find the midpoint of the array
	int mid = nel / 2;

	
	//2a. Sort the first half of the array (remember to adjust the # elements)

	msort(base, mid, compar);


	//2b. Sort the second half of the array. Pass in the address of the 
	//beginning of the second half of the array (remember to use the right # of 
	//elements)
	int nel2 = (nel + 1) / 2;
	
	msort(&base[mid], nel2, compar);
	
	//3a. Merge the two arrays (use merge)
	
	Student * stuptr;
	stuptr = merge(base, mid, &base[mid], nel2, compar);
	
	//3b. Copy the merged array over top of the original array (use copy)
	//Don't forget to free the array you returned from merge -- you don't need it after the copy!
	
	copy(base, stuptr, nel);
	free (stuptr);
	return;
}
#endif



/*
Merge two sorted arrays together to produce a new sorted array

INPUT:
base1: a pointer to the beginning of sorted array 1
nel1: the number of elements in array 1
base2: a pointer to the beginning of sorted array 2
nel2: the number of elements in array 2
compar: a function pointer to compare two elements in the base array

OUTPUT:
return value: a pointer to the beginning of a sorted array that is the merged version of the two input arrays
*/
#ifndef OMIT_MERGE
Student * merge(Student * base1, int nel1, Student * base2, int nel2, int (*compar)(const void *, const void *)) {
	
	//1. Allocate space for the returned merged array
	int numel = nel1 + nel2;
	Student * arr_merged;
	arr_merged = malloc(numel * sizeof(* arr_merged));

	//2. Create indices to keep track of where you are in the three arrays

	int i = 0; // Index for base1
	int n = 0; // Index for base2
	int d = 0; // Index for arr_merged
	
	//3. Go through base1 and base2, and merge them into the returned array

	while(d < (numel)){
		if (i >= nel1){
			arr_merged[d++] = base2[n++];
		}
		else if(n >= nel2){
			arr_merged[d++] = base1[i++];
		}
		else if (compar(&base1[i], &base2[n]) <= 0){
			arr_merged[d++] = base1[i++];
			}
		else{
			arr_merged[d++] = base2[n++];
		}
	}
	
	//4. Return the merged array
	return(arr_merged); // Returns first location of the array
	//FILL IN

}

/*
Copy contents of array from to array to, nel is the number of elements in each array
*/
void copy(Student * to, Student * from, int nel) {
	/*
	An efficient implementation of this would use memcpy:
	memcpy(to, from, nel * width);

	We will do an element-by-element copy so you can see how it is done
	*/
	
	//loop over the from array and copy it byte by byte to the to array.
	for (int i = 0; i < nel; i++) {
		to[i] = from[i];
	}
	
	return;
}
#endif
