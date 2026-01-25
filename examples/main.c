/*
 * File: main.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 15-Jan-2026 22:37:30
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

// #include "my_raylinv.h"
// #include "my_raylinv_emxAPI.h"
// #include "my_raylinv_initialize.h"
// #include "my_raylinv_terminate.h"
// #include "my_raylinv_types.h"

struct emxArray_real_T {
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  unsigned int canFreeData;
};

typedef struct emxArray_real_T emxArray_real_T;

/* Function Declarations */
extern void my_raylinv(const emxArray_real_T *Uniform_Mat, double i_sc_k,
                       emxArray_real_T *T_s_k);
extern void my_wblinv(const emxArray_real_T *Uniform_Mat, double i_sc_k, double i_fr_k,
               emxArray_real_T *T_s_k);

extern void my_gaminv(const emxArray_real_T *Uniform_Mat, double i_sc_k,
                      double i_fr_k, emxArray_real_T *T_s_k);

extern void my_poissinv(const emxArray_real_T *Uniform_Mat, double i_sc_k,
                        emxArray_real_T *T_s_k);

extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);

extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);

extern void my_raylinv_initialize(void);

extern void my_raylinv_terminate(void);

extern void my_gaminv_initialize(void);

extern void my_gaminv_terminate(void);

extern void my_wblinv_initialize(void);

extern void my_wblinv_terminate(void);

extern void my_poissinv_initialize(void);

extern void my_poissinv_terminate(void);

void main_my_raylinv(void)
{
  emxArray_real_T *T_s_k;
  double date_array[] = { 0.1, 0.2, 0.3 };
  int size_array[] = {1, 3};
  emxArray_real_T Uniform_Mat = {
    .data = date_array,
    .size = size_array,
    .allocatedSize = 3,
    .numDimensions = 2,
    .canFreeData = 1
  };
  /* Initialize function 'my_raylinv' input arguments. */
  /* Initialize function input argument 'Uniform_Mat'. */
  /* Call the entry-point 'my_raylinv'. */
  emxInitArray_real_T(&T_s_k, 2);
  my_raylinv(&Uniform_Mat, 2.0, T_s_k);
  emxDestroyArray_real_T(T_s_k);
}

void main_my_wblinv(void)
{
  emxArray_real_T *T_s_k;
  double date_array[] = { 0.1, 0.2, 0.3 };
  int size_array[] = {1, 3};
  emxArray_real_T Uniform_Mat = {
    .data = date_array,
    .size = size_array,
    .allocatedSize = 3,
    .numDimensions = 2,
    .canFreeData = 1
  };
  /* Initialize function 'my_raylinv' input arguments. */
  /* Initialize function input argument 'Uniform_Mat'. */
  /* Call the entry-point 'my_raylinv'. */
  emxInitArray_real_T(&T_s_k, 2);
  my_wblinv(&Uniform_Mat, 2.0, 2.0, T_s_k);
  emxDestroyArray_real_T(T_s_k);
}

void main_my_gaminv(void)
{
  emxArray_real_T *T_s_k;
  double date_array[] = { 0.1, 0.2, 0.3 };
  int size_array[] = {1, 3};
  emxArray_real_T Uniform_Mat = {
    .data = date_array,
    .size = size_array,
    .allocatedSize = 3,
    .numDimensions = 2,
    .canFreeData = 1
  };
  /* Initialize function 'my_gaminv' input arguments. */
  /* Initialize function input argument 'Uniform_Mat'. */
  /* Call the entry-point 'my_gaminv'. */
  emxInitArray_real_T(&T_s_k, 2);
  my_gaminv(&Uniform_Mat, 2.0, 2.0, T_s_k);
  emxDestroyArray_real_T(T_s_k);
}

void main_my_poissinv(void)
{
  emxArray_real_T *T_s_k;
  double date_array[] = { 0.1, 0.2, 0.3 };
  int size_array[] = {1, 3};
  emxArray_real_T Uniform_Mat = {
    .data = date_array,
    .size = size_array,
    .allocatedSize = 3,
    .numDimensions = 2,
    .canFreeData = 1
  };
  /* Initialize function 'my_poissinv' input arguments. */
  /* Initialize function input argument 'Uniform_Mat'. */
  /* Call the entry-point 'my_poissinv'. */
  emxInitArray_real_T(&T_s_k, 2);
  my_poissinv(&Uniform_Mat, 2.0, T_s_k);
  emxDestroyArray_real_T(&Uniform_Mat);
  emxDestroyArray_real_T(T_s_k);
}

int main(int argc, char **argv)
{
  /* Initialize the application.
You do not need to do this more than one time. */
  my_raylinv_initialize();
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_my_raylinv();
  /* Terminate the application.
You do not need to do this more than one time. */
  my_raylinv_terminate();

  my_wblinv_initialize();
  main_my_wblinv();
  my_wblinv_terminate();

  my_gaminv_initialize();
  main_my_gaminv();
  my_gaminv_terminate();

  my_poissinv_initialize();
  main_my_poissinv();
  my_poissinv_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
