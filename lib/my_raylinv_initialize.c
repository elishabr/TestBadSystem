/*
 * File: my_raylinv_initialize.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 15-Jan-2026 22:37:30
 */

/* Include Files */
#include "my_raylinv_initialize.h"
#include "my_raylinv_data.h"
#include "rt_nonfinite.h"
#include "omp.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void my_raylinv_initialize(void)
{
  omp_init_nest_lock(&my_raylinv_nestLockGlobal);
  isInitialized_my_raylinv = true;
}

/*
 * File trailer for my_raylinv_initialize.c
 *
 * [EOF]
 */
