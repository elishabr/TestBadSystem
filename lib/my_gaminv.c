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

extern void my_gaminv_wrapper_2d(
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
    my_gaminv(&in, i_sc_k, i_fr_k, &out);

    free(in.size);
    free(out.size);
}

/*
 * File trailer for my_gaminv.c
 *
 * [EOF]
 */
