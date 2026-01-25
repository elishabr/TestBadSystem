/*
 * File: my_gaminv_initialize.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 23-Jan-2026 18:12:18
 */

/* Include Files */
#include "my_gaminv_initialize.h"
#include "my_gaminv_data.h"
#include "rt_nonfinite.h"
#include "omp.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void my_gaminv_initialize(void)
{
  omp_init_nest_lock(&my_gaminv_nestLockGlobal);
  isInitialized_my_gaminv = true;
}

/*
 * File trailer for my_gaminv_initialize.c
 *
 * [EOF]
 */
