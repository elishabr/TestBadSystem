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

extern void my_poissinv_wrapper_2d(
    const double *input, int rows, int cols,
    double i_sc_k,
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
    my_poissinv(&in, i_sc_k, &out);

    free(in.size);
    free(out.size);
}

/*
 * File trailer for my_poissinv.c
 *
 * [EOF]
 */
