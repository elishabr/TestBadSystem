/*
 * File: my_poissinv.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 23-Jan-2026 19:07:19
 */

/* Include Files */
#include "my_poissinv.h"
#include "my_raylinv_types.h"
#include "poissinv.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Преобразует равномерные случайные числа в Poissinv-распределение % с значение
 * математического ожидание случайно величины i_sc_k
 *
 * Arguments    : const emxArray_real_T *Uniform_Mat
 *                double i_sc_k
 *                emxArray_real_T *T_s_k
 * Return Type  : void
 */
void my_poissinv(const emxArray_real_T *Uniform_Mat, double i_sc_k,
                 emxArray_real_T *T_s_k)
{
  poissinv(Uniform_Mat, i_sc_k, T_s_k);
}

/*
 * File trailer for my_poissinv.c
 *
 * [EOF]
 */
