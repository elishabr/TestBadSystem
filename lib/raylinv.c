/*
 * File: raylinv.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 15-Jan-2026 22:37:30
 */

/* Include Files */
#include "raylinv.h"
#include "my_raylinv_emxutil.h"
#include "my_raylinv_types.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *p
 *                double b
 *                emxArray_real_T *x
 * Return Type  : void
 */
void raylinv(const emxArray_real_T *p, double b, emxArray_real_T *x)
{
  const double *p_data;
  double *x_data;
  int i;
  int i1;
  int k;
  p_data = p->data;
  i = x->size[0] * x->size[1];
  x->size[0] = 1;
  i1 = p->size[1];
  x->size[1] = p->size[1];
  emxEnsureCapacity_real_T(x, i);
  x_data = x->data;
  i = p->size[1];
  if (p->size[1] < 1600) {
    for (k = 0; k < i1; k++) {
      if ((b > 0.0) && (p_data[k] >= 0.0) && (p_data[k] <= 1.0)) {
        if (p_data[k] == 0.0) {
          x_data[k] = 0.0;
        } else if (p_data[k] == 1.0) {
          x_data[k] = rtInf;
        } else {
          x_data[k] = sqrt(-2.0 * (b * b) * log(1.0 - p_data[k]));
        }
      } else {
        x_data[k] = rtNaN;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (k = 0; k < i; k++) {
      if ((b > 0.0) && (p_data[k] >= 0.0) && (p_data[k] <= 1.0)) {
        if (p_data[k] == 0.0) {
          x_data[k] = 0.0;
        } else if (p_data[k] == 1.0) {
          x_data[k] = rtInf;
        } else {
          x_data[k] = sqrt(-2.0 * (b * b) * log(1.0 - p_data[k]));
        }
      } else {
        x_data[k] = rtNaN;
      }
    }
  }
}

/*
 * File trailer for raylinv.c
 *
 * [EOF]
 */
