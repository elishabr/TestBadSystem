/*
 * File: wblinv.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 20-Jan-2026 21:56:49
 */

/* Include Files */
#include "wblinv.h"
#include "my_raylinv_emxutil.h"
#include "my_raylinv_types.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *p
 *                double A
 *                double B
 *                emxArray_real_T *x
 * Return Type  : void
 */
void wblinv(const emxArray_real_T *p, double A, double B, emxArray_real_T *x)
{
  const double *p_data;
  double b_x;
  double u1;
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
      if ((A > 0.0) && (B > 0.0) && (p_data[k] >= 0.0) && (p_data[k] <= 1.0)) {
        b_x = p_data[k];
        if (b_x == 0.0) {
          x_data[k] = 0.0;
        } else if (b_x == 1.0) {
          x_data[k] = rtInf;
        } else {
          b_x = log(1.0 - b_x);
          u1 = 1.0 / B;
          if (rtIsInf(u1)) {
            if (-b_x == 1.0) {
              b_x = 1.0;
            } else if (-b_x > 1.0) {
              if (u1 > 0.0) {
                b_x = rtInf;
              } else {
                b_x = 0.0;
              }
            } else if (u1 > 0.0) {
              b_x = 0.0;
            } else {
              b_x = rtInf;
            }
          } else if (u1 == 0.0) {
            b_x = 1.0;
          } else if (u1 == 1.0) {
            b_x = -b_x;
          } else if (u1 == 2.0) {
            b_x = -b_x * -b_x;
          } else if (u1 == 0.5) {
            b_x = sqrt(-b_x);
          } else {
            b_x = pow(-b_x, u1);
          }
          x_data[k] = A * b_x;
        }
      } else {
        x_data[k] = rtNaN;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_x, u1)

    for (k = 0; k < i; k++) {
      if ((A > 0.0) && (B > 0.0) && (p_data[k] >= 0.0) && (p_data[k] <= 1.0)) {
        b_x = p_data[k];
        if (b_x == 0.0) {
          x_data[k] = 0.0;
        } else if (b_x == 1.0) {
          x_data[k] = rtInf;
        } else {
          b_x = log(1.0 - b_x);
          u1 = 1.0 / B;
          if (rtIsInf(u1)) {
            if (-b_x == 1.0) {
              b_x = 1.0;
            } else if (-b_x > 1.0) {
              if (u1 > 0.0) {
                b_x = rtInf;
              } else {
                b_x = 0.0;
              }
            } else if (u1 > 0.0) {
              b_x = 0.0;
            } else {
              b_x = rtInf;
            }
          } else if (u1 == 0.0) {
            b_x = 1.0;
          } else if (u1 == 1.0) {
            b_x = -b_x;
          } else if (u1 == 2.0) {
            b_x = -b_x * -b_x;
          } else if (u1 == 0.5) {
            b_x = sqrt(-b_x);
          } else {
            b_x = pow(-b_x, u1);
          }
          x_data[k] = A * b_x;
        }
      } else {
        x_data[k] = rtNaN;
      }
    }
  }
}

/*
 * File trailer for wblinv.c
 *
 * [EOF]
 */
