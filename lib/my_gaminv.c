/*
 * File: my_gaminv.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 23-Jan-2026 18:12:18
 */

/* Include Files */
#include "my_gaminv.h"
#include "gaminv.h"
#include "my_gaminv_data.h"
#include "my_gaminv_initialize.h"
#include "my_raylinv_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Преобразует равномерные случайные числа в Gaminv-распределение % с параметром
 * масштаба i_sc_k и формой i_fr_k
 *
 * Arguments    : const emxArray_real_T *Uniform_Mat
 *                double i_sc_k
 *                double i_fr_k
 *                emxArray_real_T *T_s_k
 * Return Type  : void
 */
void my_gaminv(const emxArray_real_T *Uniform_Mat, double i_sc_k, double i_fr_k,
               emxArray_real_T *T_s_k)
{
  if (!isInitialized_my_gaminv) {
    my_gaminv_initialize();
  }
  gaminv(Uniform_Mat, i_sc_k, i_fr_k, T_s_k);
}

/*
 * File trailer for my_gaminv.c
 *
 * [EOF]
 */
