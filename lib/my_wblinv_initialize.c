/*
 * File: my_wblinv_initialize.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 20-Jan-2026 21:56:49
 */

/* Include Files */
#include "my_wblinv_initialize.h"
#include "my_wblinv_data.h"
#include "rt_nonfinite.h"
#include "omp.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void my_wblinv_initialize(void)
{
  omp_init_nest_lock(&my_wblinv_nestLockGlobal);
  isInitialized_my_wblinv = true;
}

/*
 * File trailer for my_wblinv_initialize.c
 *
 * [EOF]
 */
