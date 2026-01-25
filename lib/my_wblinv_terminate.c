/*
 * File: my_wblinv_terminate.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 20-Jan-2026 21:56:49
 */

/* Include Files */
#include "my_wblinv_terminate.h"
#include "my_wblinv_data.h"
#include "rt_nonfinite.h"
#include "omp.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void my_wblinv_terminate(void)
{
  omp_destroy_nest_lock(&my_wblinv_nestLockGlobal);
  isInitialized_my_wblinv = false;
}

/*
 * File trailer for my_wblinv_terminate.c
 *
 * [EOF]
 */
