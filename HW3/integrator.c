/* YOU MUST MODIFY THIS FILE */
// Read "hw3.h" to learn about the two data types: `Range` and `RangeAnswer`

#include "hw3.h"

double integrate1(Range rng)
{
  // Set Up Variables To Be Used
  double upper_limit = rng.upperlimit;
  double lower_limit = rng.lowerlimit;
  int n = rng.intervals;
  double integral = 0;
  int i;
  double loop_val = (upper_limit - lower_limit) / n;

// Integrate by Riemann Sum
 for(i = 0; i < n; i++)
 {
  integral += loop_val * func(lower_limit + (i * loop_val));
 }
  
  return (integral); // Return answer
}

void integrate2(RangeAnswer * rngans)
{
  rngans -> answer = integrate1(rngans -> rng);
  
  return;

  /* Fill in for Part 2 */
  // run `integrate1` function
  // take the return value from `integrate1` function 
  // and assign it to attribute `answer` of the type `RangeAnswer`
}
