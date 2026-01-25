/*
 * File: gaminv.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 23-Jan-2026 18:12:18
 */

/* Include Files */
#include "gaminv.h"
#include "eml_gammainc.h"
#include "gammaln.h"
#include "my_raylinv_emxutil.h"
#include "my_raylinv_types.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *p
 *                double a
 *                double b
 *                emxArray_real_T *x
 * Return Type  : void
 */
void gaminv(const emxArray_real_T *p, double a, double b, emxArray_real_T *x)
{
  const double *p_data;
  double b_p;
  double f;
  double ftol1;
  double la;
  double lga;
  double lgap1;
  double log1mpLower;
  double nu;
  double oldz;
  double pLower;
  double z;
  double *x_data;
  int b_i;
  int i;
  int i1;
  int k;
  int sgn;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T upper;
  p_data = p->data;
  i = x->size[0] * x->size[1];
  x->size[0] = 1;
  i1 = p->size[1];
  x->size[1] = p->size[1];
  emxEnsureCapacity_real_T(x, i);
  x_data = x->data;
  i = p->size[1];
  if (p->size[1] * 10 < 1600) {
    for (k = 0; k < i1; k++) {
      if ((a >= 0.0) && (!rtIsInf(a)) && (b > 0.0) && (p_data[k] >= 0.0) &&
          (p_data[k] <= 1.0)) {
        f = p_data[k];
        if ((f > 0.0) && (f < 1.0) && (a > 0.0)) {
          la = log(a);
          lga = a;
          gammaln(&lga);
          lgap1 = a + 1.0;
          gammaln(&lgap1);
          b_p = f;
          upper = false;
          if (a == rtInf) {
            z = rtInf;
          } else if (lga == rtInf) {
            z = a;
          } else {
            nu = 2.0 * a;
            if (f > 0.5) {
              b_p = 1.0 - f;
              upper = true;
              pLower = 1.0 - (1.0 - f);
              log1mpLower = log(1.0 - f);
            } else {
              pLower = f;
              if (1.0 - f != 1.0) {
                log1mpLower = log(1.0 - f) * (-f / ((1.0 - f) - 1.0));
              } else {
                log1mpLower = -f;
              }
            }
            f = log(pLower);
            if (nu < -1.24 * f) {
              pLower *= exp(lgap1 + a * 0.693147180559945);
              f = 1.0 / a;
              if (rtIsNaN(pLower)) {
                pLower = rtNaN;
              } else if (rtIsInf(f)) {
                if (pLower == 1.0) {
                  pLower = 1.0;
                } else if (pLower > 1.0) {
                  pLower = rtInf;
                } else {
                  pLower = 0.0;
                }
              } else if (!(f == 1.0)) {
                if (f == 2.0) {
                  pLower *= pLower;
                } else if (f == 0.5) {
                  pLower = sqrt(pLower);
                } else {
                  pLower = pow(pLower, f);
                }
              }
              if (pLower < 2.2250738585072014E-306) {
                pLower = 2.2250738585072014E-306;
              }
            } else if (nu <= 0.32) {
              pLower = 0.4;
              b_i = 0;
              exitg1 = false;
              while ((!exitg1) && (b_i < 200)) {
                oldz = pLower;
                ftol1 = pLower * (pLower + 4.67) + 1.0;
                f = pLower * (pLower * (pLower + 6.66) + 6.73);
                pLower -= (1.0 - exp(((log1mpLower + lga) + 0.5 * pLower) +
                                     (a - 1.0) * 0.693147180559945) *
                                     f / ftol1) /
                          (((2.0 * pLower + 4.67) / ftol1 - 0.5) -
                           (pLower * (3.0 * pLower + 13.32) + 6.73) / f);
                if (fabs(oldz - pLower) < 0.01 * pLower) {
                  exitg1 = true;
                } else {
                  b_i++;
                }
              }
            } else {
              if (fabs(pLower - 0.5) <= 0.425) {
                f = 0.180625 - (pLower - 0.5) * (pLower - 0.5);
                z = (pLower - 0.5) *
                    (((((((2509.0809287301227 * f + 33430.575583588128) * f +
                          67265.7709270087) *
                             f +
                         45921.95393154987) *
                            f +
                        13731.693765509461) *
                           f +
                       1971.5909503065513) *
                          f +
                      133.14166789178438) *
                         f +
                     3.3871328727963665) /
                    (((((((5226.4952788528544 * f + 28729.085735721943) * f +
                          39307.895800092709) *
                             f +
                         21213.794301586597) *
                            f +
                        5394.1960214247511) *
                           f +
                       687.18700749205789) *
                          f +
                      42.313330701600911) *
                         f +
                     1.0);
              } else {
                if (pLower - 0.5 < 0.0) {
                  f = sqrt(-f);
                } else {
                  f = sqrt(-log(1.0 - pLower));
                }
                if (f <= 5.0) {
                  f -= 1.6;
                  z = (((((((0.00077454501427834139 * f +
                             0.022723844989269184) *
                                f +
                            0.24178072517745061) *
                               f +
                           1.2704582524523684) *
                              f +
                          3.6478483247632045) *
                             f +
                         5.769497221460691) *
                            f +
                        4.6303378461565456) *
                           f +
                       1.4234371107496835) /
                      (((((((1.0507500716444169E-9 * f +
                             0.00054759380849953455) *
                                f +
                            0.015198666563616457) *
                               f +
                           0.14810397642748008) *
                              f +
                          0.6897673349851) *
                             f +
                         1.6763848301838038) *
                            f +
                        2.053191626637759) *
                           f +
                       1.0);
                } else {
                  f -= 5.0;
                  z = (((((((2.0103343992922881E-7 * f +
                             2.7115555687434876E-5) *
                                f +
                            0.0012426609473880784) *
                               f +
                           0.026532189526576124) *
                              f +
                          0.29656057182850487) *
                             f +
                         1.7848265399172913) *
                            f +
                        5.4637849111641144) *
                           f +
                       6.6579046435011033) /
                      (((((((2.0442631033899397E-15 * f +
                             1.4215117583164459E-7) *
                                f +
                            1.8463183175100548E-5) *
                               f +
                           0.00078686913114561329) *
                              f +
                          0.014875361290850615) *
                             f +
                         0.13692988092273581) *
                            f +
                        0.599832206555888) *
                           f +
                       1.0);
                }
                if (pLower - 0.5 < 0.0) {
                  z = -z;
                }
              }
              ftol1 = 0.222222 / nu;
              pLower = (z * sqrt(ftol1) + 1.0) - ftol1;
              pLower *= nu * pLower * pLower;
              if (pLower > 2.2 * nu + 6.0) {
                pLower = -2.0 *
                         ((log1mpLower - (a - 1.0) * log(0.5 * pLower)) + lga);
              }
            }
            z = 0.5 * pLower;
            pLower = rtInf;
            oldz = rtInf;
            if (b_p > 1.0021E-294) {
              ftol1 = 2.2204460492503131E-14 * b_p;
            } else {
              ftol1 = 2.2251089859537388E-308;
            }
            if (upper) {
              sgn = -1;
            } else {
              sgn = 1;
            }
            nu = 0.0;
            log1mpLower = 1.7976931348623157E+308;
            b_i = 0;
            exitg1 = false;
            while ((!exitg1) && (b_i < 1000)) {
              f = (double)sgn * (eml_gammainc(z, a, la, lgap1, upper) - b_p);
              if ((f * pLower < 0.0) && (fabs(pLower) <= fabs(f))) {
                z = 0.5 * z + 0.5 * oldz;
                f = (double)sgn * (eml_gammainc(z, a, la, lgap1, upper) - b_p);
              }
              if (f > 0.0) {
                log1mpLower = z;
              } else {
                nu = z;
              }
              if ((fabs(f) < ftol1) ||
                  (fabs(z - oldz) <
                   2.2204460492503131E-16 * z + 2.2250738585072014E-308)) {
                exitg1 = true;
              } else {
                oldz = z;
                pLower = f;
                guard1 = false;
                if (b_i < 500) {
                  z *= 1.0 - f / (z * exp(((a - 1.0) * log(z) - z) - lga) +
                                  f * ((z + 1.0) - a) / 2.0);
                  if (z <= nu) {
                    if (nu == 0.0) {
                      if (fabs((double)upper - b_p) <
                          fabs(eml_gammainc(2.2250738585072014E-308, a, la,
                                            lgap1, upper) -
                               b_p)) {
                        z = 0.0;
                        exitg1 = true;
                      } else {
                        nu = 2.2250738585072014E-308;
                        guard1 = true;
                      }
                    } else {
                      guard1 = true;
                    }
                  } else {
                    if (z >= log1mpLower) {
                      z = 0.01 * nu + 0.99 * log1mpLower;
                    }
                    b_i++;
                  }
                } else {
                  double d;
                  d = 1.0E+8 * nu;
                  if (d < log1mpLower) {
                    oldz = d;
                    pLower = (double)sgn *
                             (eml_gammainc(d, a, la, lgap1, upper) - b_p);
                    if (pLower > 0.0) {
                      log1mpLower = d;
                    } else {
                      nu = d;
                    }
                  }
                  z = 0.5 * nu + 0.5 * log1mpLower;
                  b_i++;
                }
                if (guard1) {
                  z = 0.99 * nu + 0.01 * log1mpLower;
                  b_i++;
                }
              }
            }
          }
          x_data[k] = z * b;
        } else if ((a == 0.0) || (f == 0.0)) {
          x_data[k] = 0.0;
        } else if (f == 1.0) {
          x_data[k] = rtInf;
        } else {
          x_data[k] = rtNaN;
        }
      } else {
        x_data[k] = rtNaN;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        f, z, log1mpLower, nu, sgn, ftol1, oldz, pLower, b_i, upper, b_p,      \
            lgap1, lga, la, exitg1, guard1)

    for (k = 0; k < i; k++) {
      if ((a >= 0.0) && (!rtIsInf(a)) && (b > 0.0) && (p_data[k] >= 0.0) &&
          (p_data[k] <= 1.0)) {
        f = p_data[k];
        if ((f > 0.0) && (f < 1.0) && (a > 0.0)) {
          la = log(a);
          lga = a;
          gammaln(&lga);
          lgap1 = a + 1.0;
          gammaln(&lgap1);
          b_p = f;
          upper = false;
          if (a == rtInf) {
            z = rtInf;
          } else if (lga == rtInf) {
            z = a;
          } else {
            nu = 2.0 * a;
            if (f > 0.5) {
              b_p = 1.0 - f;
              upper = true;
              pLower = 1.0 - (1.0 - f);
              log1mpLower = log(1.0 - f);
            } else {
              pLower = f;
              if (1.0 - f != 1.0) {
                log1mpLower = log(1.0 - f) * (-f / ((1.0 - f) - 1.0));
              } else {
                log1mpLower = -f;
              }
            }
            f = log(pLower);
            if (nu < -1.24 * f) {
              pLower *= exp(lgap1 + a * 0.693147180559945);
              f = 1.0 / a;
              if (rtIsNaN(pLower)) {
                pLower = rtNaN;
              } else if (rtIsInf(f)) {
                if (pLower == 1.0) {
                  pLower = 1.0;
                } else if (pLower > 1.0) {
                  pLower = rtInf;
                } else {
                  pLower = 0.0;
                }
              } else if (!(f == 1.0)) {
                if (f == 2.0) {
                  pLower *= pLower;
                } else if (f == 0.5) {
                  pLower = sqrt(pLower);
                } else {
                  pLower = pow(pLower, f);
                }
              }
              if (pLower < 2.2250738585072014E-306) {
                pLower = 2.2250738585072014E-306;
              }
            } else if (nu <= 0.32) {
              pLower = 0.4;
              b_i = 0;
              exitg1 = false;
              while ((!exitg1) && (b_i < 200)) {
                oldz = pLower;
                ftol1 = pLower * (pLower + 4.67) + 1.0;
                f = pLower * (pLower * (pLower + 6.66) + 6.73);
                pLower -= (1.0 - exp(((log1mpLower + lga) + 0.5 * pLower) +
                                     (a - 1.0) * 0.693147180559945) *
                                     f / ftol1) /
                          (((2.0 * pLower + 4.67) / ftol1 - 0.5) -
                           (pLower * (3.0 * pLower + 13.32) + 6.73) / f);
                if (fabs(oldz - pLower) < 0.01 * pLower) {
                  exitg1 = true;
                } else {
                  b_i++;
                }
              }
            } else {
              if (fabs(pLower - 0.5) <= 0.425) {
                f = 0.180625 - (pLower - 0.5) * (pLower - 0.5);
                z = (pLower - 0.5) *
                    (((((((2509.0809287301227 * f + 33430.575583588128) * f +
                          67265.7709270087) *
                             f +
                         45921.95393154987) *
                            f +
                        13731.693765509461) *
                           f +
                       1971.5909503065513) *
                          f +
                      133.14166789178438) *
                         f +
                     3.3871328727963665) /
                    (((((((5226.4952788528544 * f + 28729.085735721943) * f +
                          39307.895800092709) *
                             f +
                         21213.794301586597) *
                            f +
                        5394.1960214247511) *
                           f +
                       687.18700749205789) *
                          f +
                      42.313330701600911) *
                         f +
                     1.0);
              } else {
                if (pLower - 0.5 < 0.0) {
                  f = sqrt(-f);
                } else {
                  f = sqrt(-log(1.0 - pLower));
                }
                if (f <= 5.0) {
                  f -= 1.6;
                  z = (((((((0.00077454501427834139 * f +
                             0.022723844989269184) *
                                f +
                            0.24178072517745061) *
                               f +
                           1.2704582524523684) *
                              f +
                          3.6478483247632045) *
                             f +
                         5.769497221460691) *
                            f +
                        4.6303378461565456) *
                           f +
                       1.4234371107496835) /
                      (((((((1.0507500716444169E-9 * f +
                             0.00054759380849953455) *
                                f +
                            0.015198666563616457) *
                               f +
                           0.14810397642748008) *
                              f +
                          0.6897673349851) *
                             f +
                         1.6763848301838038) *
                            f +
                        2.053191626637759) *
                           f +
                       1.0);
                } else {
                  f -= 5.0;
                  z = (((((((2.0103343992922881E-7 * f +
                             2.7115555687434876E-5) *
                                f +
                            0.0012426609473880784) *
                               f +
                           0.026532189526576124) *
                              f +
                          0.29656057182850487) *
                             f +
                         1.7848265399172913) *
                            f +
                        5.4637849111641144) *
                           f +
                       6.6579046435011033) /
                      (((((((2.0442631033899397E-15 * f +
                             1.4215117583164459E-7) *
                                f +
                            1.8463183175100548E-5) *
                               f +
                           0.00078686913114561329) *
                              f +
                          0.014875361290850615) *
                             f +
                         0.13692988092273581) *
                            f +
                        0.599832206555888) *
                           f +
                       1.0);
                }
                if (pLower - 0.5 < 0.0) {
                  z = -z;
                }
              }
              ftol1 = 0.222222 / nu;
              pLower = (z * sqrt(ftol1) + 1.0) - ftol1;
              pLower *= nu * pLower * pLower;
              if (pLower > 2.2 * nu + 6.0) {
                pLower = -2.0 *
                         ((log1mpLower - (a - 1.0) * log(0.5 * pLower)) + lga);
              }
            }
            z = 0.5 * pLower;
            pLower = rtInf;
            oldz = rtInf;
            if (b_p > 1.0021E-294) {
              ftol1 = 2.2204460492503131E-14 * b_p;
            } else {
              ftol1 = 2.2251089859537388E-308;
            }
            if (upper) {
              sgn = -1;
            } else {
              sgn = 1;
            }
            nu = 0.0;
            log1mpLower = 1.7976931348623157E+308;
            b_i = 0;
            exitg1 = false;
            while ((!exitg1) && (b_i < 1000)) {
              f = (double)sgn * (eml_gammainc(z, a, la, lgap1, upper) - b_p);
              if ((f * pLower < 0.0) && (fabs(pLower) <= fabs(f))) {
                z = 0.5 * z + 0.5 * oldz;
                f = (double)sgn * (eml_gammainc(z, a, la, lgap1, upper) - b_p);
              }
              if (f > 0.0) {
                log1mpLower = z;
              } else {
                nu = z;
              }
              if ((fabs(f) < ftol1) ||
                  (fabs(z - oldz) <
                   2.2204460492503131E-16 * z + 2.2250738585072014E-308)) {
                exitg1 = true;
              } else {
                oldz = z;
                pLower = f;
                guard1 = false;
                if (b_i < 500) {
                  z *= 1.0 - f / (z * exp(((a - 1.0) * log(z) - z) - lga) +
                                  f * ((z + 1.0) - a) / 2.0);
                  if (z <= nu) {
                    if (nu == 0.0) {
                      if (fabs((double)upper - b_p) <
                          fabs(eml_gammainc(2.2250738585072014E-308, a, la,
                                            lgap1, upper) -
                               b_p)) {
                        z = 0.0;
                        exitg1 = true;
                      } else {
                        nu = 2.2250738585072014E-308;
                        guard1 = true;
                      }
                    } else {
                      guard1 = true;
                    }
                  } else {
                    if (z >= log1mpLower) {
                      z = 0.01 * nu + 0.99 * log1mpLower;
                    }
                    b_i++;
                  }
                } else {
                  f = 1.0E+8 * nu;
                  if (f < log1mpLower) {
                    oldz = f;
                    pLower = (double)sgn *
                             (eml_gammainc(f, a, la, lgap1, upper) - b_p);
                    if (pLower > 0.0) {
                      log1mpLower = f;
                    } else {
                      nu = f;
                    }
                  }
                  z = 0.5 * nu + 0.5 * log1mpLower;
                  b_i++;
                }
                if (guard1) {
                  z = 0.99 * nu + 0.01 * log1mpLower;
                  b_i++;
                }
              }
            }
          }
          x_data[k] = z * b;
        } else if ((a == 0.0) || (f == 0.0)) {
          x_data[k] = 0.0;
        } else if (f == 1.0) {
          x_data[k] = rtInf;
        } else {
          x_data[k] = rtNaN;
        }
      } else {
        x_data[k] = rtNaN;
      }
    }
  }
}

/*
 * File trailer for gaminv.c
 *
 * [EOF]
 */
