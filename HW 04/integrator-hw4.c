// ***
// *** You MUST modify this file
// ***
#include <stdio.h>
#include <stdbool.h>
#include "hw4.h"

// must enclose the function by #ifdef TEST_INTEGRATE and #endif
#ifdef TEST_INTEGRATE
void integrate(Integration * intrg)
{
  // integrate the function stored in intrg's func
  // store the result in intrg's answer
   // Set Up Variables To Be Used
  double upper_limit = intrg ->upperlimit;
  double lower_limit = intrg -> lowerlimit;
  int n = intrg -> intervals;
  funcptr func = intrg -> func;
  double integral = 0;
  int i;
  
  double loop_val = (upper_limit - lower_limit) / n;
  

// Integrate by Riemann Sum
 for(i = 0; i < n; i++)
 {
  integral += loop_val * func(lower_limit + (i * loop_val));
 }
 intrg -> answer = integral;

return;
}
#endif // TEST_INTEGRATE

// must enclose the function by #ifdef RUN_INTEGRATE and #endif
#ifdef RUN_INTEGRATE
bool  runIntegrate(char * infilename, char * outfilename)
// return true if it can successfully open and read the input 
// and open and write the output
// return false when encountering any problem
{
  // open the input file name for reading
  FILE *fp;
  fp = fopen(infilename, "r");


  // if fopen fails, return false
  if (fp == NULL){
    return false;
  }


  // read one double from the input file and store it in 
  // intrg's lowerlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
  Integration x;
  int checker;
  checker = fscanf(fp, "%lf\n",&x.lowerlimit);
  if (checker != 1){
    fclose(fp);
    return false;
  }






  // read one double from the input file and store it in 
  // intrg's upperlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
  
  checker = fscanf(fp, "%lf\n",&x.upperlimit);
  if (checker != 1){
    fclose(fp);
    return false;
  }









  // read one int from the input file and store it in 
  // intrg's intervals
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
  
  checker = fscanf(fp, "%d\n",&x.intervals);
  if (checker != 1){
    fclose(fp);
    return false;
  }






  // close the input file

  fclose(fp);





  // open the output file for writing
  // if fopen fails, return false

    FILE *ofp = fopen(outfilename, "w");
    if (ofp == NULL){
    return false;
  }







  // create an array of funcptr called funcs with five elements:
  // func1, func2, ..., func5
  int i;
  funcptr funcs[] = {func1, func2, func3, func4, func5};
  



  // go through the elements in funcs 
  // for each element, call integrate for that function
  // write the result (stored in intrg's answer to 
  // the output file. each answer occupies one line (add "\n")
  // use fprintf
  // check the return value of fprintf. 
  // If it is less one one, close the output
  // file and return false

  for(i = 0; i< 5; ++i){
    x.func = funcs[i];
    integrate(&x);
    checker = fprintf(ofp, "%lf\n", x.answer);
    if (checker < 1){
      fclose(ofp);
      return (false);
    }
  }



  // after going through all functions in funcs
  // close the output file

  fclose(ofp);



  // if the function reaches here, return true

  return true;



}
#endif // RUN_INTEGRATE
