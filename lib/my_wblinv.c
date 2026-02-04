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

extern void my_wblinv_wrapper_2d(
    const double *input, int rows, int cols,
    double i_sc_k, double i_fr_k,
    double *output
) {
    // Создаём входной emxArray
    emxArray_real_T in;
    in.data = (double*)input;
    in.size = (int*)malloc(2 * sizeof(int));
    in.size[0] = rows;
    in.size[1] = cols;
    in.allocatedSize = rows * cols;
    in.numDimensions = 2;
    in.canFreeData = 0;

    // Создаём выходной emxArray
    emxArray_real_T out;
    out.data = output;
    out.size = (int*)malloc(2 * sizeof(int));
    out.size[0] = rows;
    out.size[1] = cols;
    out.allocatedSize = rows * cols;
    out.numDimensions = 2;
    out.canFreeData = 0;

    // Вызов твоей функции
    my_wblinv(&in, i_sc_k, i_fr_k, &out);

    free(in.size);
    free(out.size);
}

/*
 * File trailer for my_wblinv.c
 *
 * [EOF]
 */
