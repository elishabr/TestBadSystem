/*
 * File: main.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 23-Jan-2026 19:07:19
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "my_poissinv.h"
#include "my_poissinv_emxAPI.h"
#include "my_poissinv_initialize.h"
#include "my_poissinv_terminate.h"
#include "my_poissinv_types.h"
#include "rt_nonfinite.h"


/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* Initialize the application.
You do not need to do this more than one time. */
  my_poissinv_initialize();
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_my_poissinv();
  /* Terminate the application.
You do not need to do this more than one time. */
  my_poissinv_terminate();
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_my_poissinv(void)
{
  emxArray_real_T *T_s_k;
  emxArray_real_T *Uniform_Mat;
  /* Initialize function 'my_poissinv' input arguments. */
  /* Initialize function input argument 'Uniform_Mat'. */
  Uniform_Mat = argInit_1xUnbounded_real_T();
  /* Call the entry-point 'my_poissinv'. */
  emxInitArray_real_T(&T_s_k, 2);
  my_poissinv(Uniform_Mat, argInit_real_T(), T_s_k);
  emxDestroyArray_real_T(Uniform_Mat);
  emxDestroyArray_real_T(T_s_k);
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
