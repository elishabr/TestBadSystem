/*
 * File: poissinv.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 23-Jan-2026 19:07:19
 */

/* Include Files */
#include "poissinv.h"
#include "eml_erfcore.h"
#include "gammainc.h"
#include "my_raylinv_emxutil.h"
#include "my_raylinv_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *p
 *                double lambda
 *                emxArray_real_T *x
 * Return Type  : void
 */
void poissinv(const emxArray_real_T *p, double lambda, emxArray_real_T *x)
{
  const double *p_data;
  double z;
  double *x_data;
  int b_k;
  int eint;
  int i;
  int k;
  int nIterations;
  p_data = p->data;
  nIterations = x->size[0] * x->size[1];
  x->size[0] = 1;
  i = p->size[1];
  x->size[1] = p->size[1];
  emxEnsureCapacity_real_T(x, nIterations);
  x_data = x->data;
  for (k = 0; k < i; k++) {
    double d;
    d = p_data[k];
    if ((d >= 0.0) && (d <= 1.0) && (lambda >= 0.0)) {
      if ((lambda == 0.0) || (d == 0.0)) {
        x_data[k] = 0.0;
      } else if (d == 1.0) {
        x_data[k] = rtInf;
      } else if (lambda > 10.0) {
        creal_T y;
        double P;
        double b_x;
        double c_x;
        b_x = 2.0 * d;
        nIterations = 2;
        if (b_x > 1.7) {
          z = sqrt(-log((2.0 - b_x) / 2.0));
          c_x = -(((1.641345311 * z + 3.429567803) * z - 1.624906493) * z -
                  1.970840454) /
                ((1.6370678 * z + 3.5438892) * z + 1.0);
          for (b_k = 0; b_k < 2; b_k++) {
            z = (eml_erfcore(-c_x) - (2.0 - b_x)) /
                (1.1283791670955126 * exp(-c_x * c_x));
            c_x -= z / (c_x * z + 1.0);
          }
        } else if (b_x < 0.3) {
          z = sqrt(0.69314718055994529 - log(b_x));
          if (b_x < 1.0947644252537633E-47) {
            if (b_x < 7.7532508072625747E-267) {
              nIterations = 4;
            } else {
              nIterations = 3;
            }
          }
          c_x = (((1.641345311 * z + 3.429567803) * z - 1.624906493) * z -
                 1.970840454) /
                ((1.6370678 * z + 3.5438892) * z + 1.0);
          for (b_k = 0; b_k < nIterations; b_k++) {
            z = -(eml_erfcore(c_x) - b_x) /
                (1.1283791670955126 * exp(-c_x * c_x));
            c_x -= z / (c_x * z + 1.0);
          }
        } else {
          z = (1.0 - b_x) * (1.0 - b_x);
          c_x = (1.0 - b_x) *
                (((-0.140543331 * z + 0.914624893) * z - 1.645349621) * z +
                 0.886226899) /
                ((((0.012229801 * z - 0.329097515) * z + 1.442710462) * z -
                  2.118377725) *
                     z +
                 1.0);
          for (b_k = 0; b_k < 2; b_k++) {
            double absx;
            /* ========================== COPYRIGHT NOTICE
             * ============================ */
            /*  The algorithms for calculating ERF(X) and ERFC(X) are derived */
            /*  from FDLIBM, which has the following notice: */
            /*                                                                          */
            /*  Copyright (C) 1993 by Sun Microsystems, Inc. All rights
             * reserved.       */
            /*                                                                          */
            /*  Developed at SunSoft, a Sun Microsystems, Inc. business. */
            /*  Permission to use, copy, modify, and distribute this */
            /*  software is freely granted, provided that this notice */
            /*  is preserved. */
            /* =============================    END
             * ================================ */
            absx = fabs(c_x);
            if (rtIsNaN(c_x)) {
              z = rtNaN;
            } else if (rtIsInf(c_x)) {
              if (c_x < 0.0) {
                z = -1.0;
              } else {
                z = 1.0;
              }
            } else if (absx < 0.84375) {
              if (absx < 3.7252902984619141E-9) {
                if (absx < 2.8480945388892178E-306) {
                  z = 0.125 * (8.0 * c_x + 1.0270333367641007 * c_x);
                } else {
                  z = c_x + 0.12837916709551259 * c_x;
                }
              } else {
                z = c_x * c_x;
                z = c_x +
                    c_x * ((z * (z * (z * (z * -2.3763016656650163E-5 -
                                           0.0057702702964894416) -
                                      0.02848174957559851) -
                                 0.3250421072470015) +
                            0.12837916709551256) /
                           (z * (z * (z * (z * (z * -3.9602282787753681E-6 +
                                                0.00013249473800432164) +
                                           0.0050813062818757656) +
                                      0.0650222499887673) +
                                 0.39791722395915535) +
                            1.0));
              }
            } else if (absx < 1.25) {
              P = (absx - 1.0) *
                      ((absx - 1.0) *
                           ((absx - 1.0) *
                                ((absx - 1.0) *
                                     ((absx - 1.0) *
                                          ((absx - 1.0) *
                                               -0.0021663755948687908 +
                                           0.035478304325618236) -
                                      0.11089469428239668) +
                                 0.31834661990116175) -
                            0.37220787603570132) +
                       0.41485611868374833) -
                  0.0023621185607526594;
              z = (absx - 1.0) *
                      ((absx - 1.0) *
                           ((absx - 1.0) *
                                ((absx - 1.0) *
                                     ((absx - 1.0) *
                                          ((absx - 1.0) * 0.011984499846799107 +
                                           0.013637083912029051) +
                                      0.12617121980876164) +
                                 0.071828654414196266) +
                            0.540397917702171) +
                       0.10642088040084423) +
                  1.0;
              if (c_x >= 0.0) {
                z = P / z + 0.84506291151046753;
              } else {
                z = -0.84506291151046753 - P / z;
              }
            } else if (absx > 6.0) {
              if (c_x < 0.0) {
                z = -1.0;
              } else {
                z = 1.0;
              }
            } else {
              double R;
              z = 1.0 / (absx * absx);
              if (absx < 2.8571434020996094) {
                R = z * (z * (z * (z * (z * (z * (z * -9.8143293441691455 -
                                                  81.2874355063066) -
                                             184.60509290671104) -
                                        162.39666946257347) -
                                   62.375332450326006) -
                              10.558626225323291) -
                         0.69385857270718176) -
                    0.0098649440348471482;
                P = z * (z * (z * (z * (z * (z * (z * (z * -0.0604244152148581 +
                                                       6.5702497703192817) +
                                                  108.63500554177944) +
                                             429.00814002756783) +
                                        645.38727173326788) +
                                   434.56587747522923) +
                              137.65775414351904) +
                         19.651271667439257) +
                    1.0;
              } else {
                R = z * (z * (z * (z * (z * (z * -483.5191916086514 -
                                             1025.0951316110772) -
                                        637.56644336838963) -
                                   160.63638485582192) -
                              17.757954917754752) -
                         0.799283237680523) -
                    0.0098649429247001;
                P = z * (z * (z * (z * (z * (z * (z * -22.440952446585818 +
                                                  474.52854120695537) +
                                             2553.0504064331644) +
                                        3199.8582195085955) +
                                   1536.729586084437) +
                              325.79251299657392) +
                         30.338060743482458) +
                    1.0;
              }
              if (!rtIsNaN(absx)) {
                z = frexp(absx, &eint);
                nIterations = eint;
              } else {
                z = rtNaN;
                nIterations = 0;
              }
              z = floor(z * 2.097152E+6) / 2.097152E+6 *
                  ldexp(1.0, nIterations);
              z = exp(-z * z - 0.5625) * exp((z - absx) * (z + absx) + R / P) /
                  absx;
              if (c_x < 0.0) {
                z--;
              } else {
                z = 1.0 - z;
              }
            }
            z = (z - (1.0 - b_x)) / (1.1283791670955126 * exp(-c_x * c_x));
            c_x -= z / (c_x * z + 1.0);
          }
        }
        z = ceil(sqrt(lambda) * (-1.4142135623730951 * c_x) + lambda);
        if (z < 0.0) {
          z = 0.0;
        }
        y = gammainc(lambda, z + 1.0);
        P = p_data[k];
        if (y.re < P) {
          do {
            z++;
          } while (!!((gammainc(lambda, z + 1.0)).re < d));
        } else if (y.re > P) {
          while ((gammainc(lambda, z)).re >= d) {
            z--;
          }
        }
        x_data[k] = z;
      } else {
        for (z = 0.0; (gammainc(lambda, z + 1.0)).re < d; z++) {
        }
        x_data[k] = z;
      }
    } else {
      x_data[k] = rtNaN;
    }
  }
}

/*
 * File trailer for poissinv.c
 *
 * [EOF]
 */
