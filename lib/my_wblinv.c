/*
 * File: my_wblinv.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 20-Jan-2026 21:56:49
 */

/* Include Files */
#include "my_wblinv.h"
#include "my_wblinv_data.h"
#include "my_wblinv_initialize.h"
#include "my_raylinv_types.h"
#include "rt_nonfinite.h"
#include "wblinv.h"


/* Function Definitions */
/*
 * Преобразует равномерные случайные числа в Weibull-распределение % с
 * параметром масштаба i_sc_k и формой i_fr_k
 *
 * Arguments    : const emxArray_real_T *Uniform_Mat
 *                double i_sc_k
 *                double i_fr_k
 *                emxArray_real_T *T_s_k
 * Return Type  : void
 */
void my_wblinv(const emxArray_real_T *Uniform_Mat, double i_sc_k, double i_fr_k,
               emxArray_real_T *T_s_k)
{
  if (!isInitialized_my_wblinv) {
    my_wblinv_initialize();
  }
  /*  Преобразование в распределение Рэлея */
  wblinv(Uniform_Mat, i_sc_k, i_fr_k, T_s_k);
}

/*
 * File trailer for my_wblinv.c
 *
 * [EOF]
 */
