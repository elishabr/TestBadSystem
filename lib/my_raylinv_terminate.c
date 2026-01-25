/*
 * File: my_raylinv_terminate.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 15-Jan-2026 22:37:30
 */

/* Include Files */
#include "my_raylinv_terminate.h"
#include "my_raylinv_data.h"
#include "rt_nonfinite.h"
#include "omp.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void my_raylinv_terminate(void)
{
  omp_destroy_nest_lock(&my_raylinv_nestLockGlobal);
  isInitialized_my_raylinv = false;
}

/*
 * File trailer for my_raylinv_terminate.c
 *
 * [EOF]
 */
