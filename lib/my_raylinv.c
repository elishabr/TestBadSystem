/*
 * File: my_raylinv.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 15-Jan-2026 22:37:30
 */

/* Include Files */
#include "my_raylinv.h"
#include "my_raylinv_data.h"
#include "my_raylinv_initialize.h"
#include "my_raylinv_types.h"
#include "raylinv.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Генерирует массив Rayleigh-распределённых случайных величин
 *  длиной T_ind_k с параметром масштаба i_sc_k
 *
 * Arguments    : const emxArray_real_T *Uniform_Mat
 *                double i_sc_k
 *                emxArray_real_T *T_s_k
 * Return Type  : void
 */
void my_raylinv(const emxArray_real_T *Uniform_Mat, double i_sc_k,
                emxArray_real_T *T_s_k)
{
  if (!isInitialized_my_raylinv) {
    my_raylinv_initialize();
  }
  /*  Преобразование в распределение Рэлея */
  raylinv(Uniform_Mat, i_sc_k, T_s_k);
}

extern void my_raylinv_wrapper_2d(
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
    my_raylinv(&in, i_sc_k, &out);

    free(in.size);
    free(out.size);
}

/*
 * File trailer for my_raylinv.c
 *
 * [EOF]
 */
