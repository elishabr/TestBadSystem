/*
 * File: eml_gammainc.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 23-Jan-2026 18:12:18
 */

/* Include Files */
#include "eml_gammainc.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double x
 *                double a
 *                double la
 *                double lgap1
 *                boolean_T upper
 * Return Type  : double
 */
double eml_gammainc(double x, double a, double la, double lgap1,
                    boolean_T upper)
{
  static const double dv[31] = {0.0,
                                0.15342640972002736,
                                0.081061466795327261,
                                0.054814121051917651,
                                0.0413406959554093,
                                0.033162873519936291,
                                0.027677925684998338,
                                0.023746163656297496,
                                0.020790672103765093,
                                0.018488450532673187,
                                0.016644691189821193,
                                0.015134973221917378,
                                0.013876128823070748,
                                0.012810465242920227,
                                0.01189670994589177,
                                0.011104559758206917,
                                0.010411265261972096,
                                0.0097994161261588039,
                                0.0092554621827127329,
                                0.0087687001341393862,
                                0.00833056343336287,
                                0.00793411456431402,
                                0.0075736754879518406,
                                0.007244554301320383,
                                0.00694284010720953,
                                0.0066652470327076821,
                                0.0064089941880042071,
                                0.0061717122630394576,
                                0.0059513701127588475,
                                0.0057462165130101155,
                                0.0055547335519628011};
  double rval;
  int b_i;
  if (!(x > 0.0)) {
    if (x == 0.0) {
      rval = upper;
    } else {
      rval = rtNaN;
    }
  } else if (rtIsInf(a)) {
    if (rtIsInf(x)) {
      rval = rtNaN;
    } else {
      rval = upper;
    }
  } else if (rtIsInf(x)) {
    rval = 1.0 - (double)upper;
  } else {
    double a1;
    double a2;
    double gold;
    double logpax;
    double stirlerr;
    double t;
    double tsq;
    double xD0;
    int exitg1;
    if (a <= 15.0) {
      rval = 2.0 * a;
      if (rval == floor(rval)) {
        stirlerr = dv[(int)(rval + 1.0) - 1];
      } else {
        stirlerr = ((lgap1 - (a + 0.5) * la) + a) - 0.91893853320467267;
      }
    } else {
      rval = a * a;
      stirlerr =
          ((((0.00084175084175084171 / rval - 0.00059523809523809529) / rval +
             0.00079365079365079365) /
                rval -
            0.0027777777777777779) /
               rval +
           0.083333333333333329) /
          a;
    }
    gold = a - x;
    a1 = a + x;
    if (fabs(gold) > 0.1 * a1) {
      if (a < 2.2250738585072014E-308 * x) {
        xD0 = x;
      } else if ((x < 1.0) && (a > 1.7976931348623157E+308 * x)) {
        xD0 = (a * la - a * log(x)) - a;
      } else {
        xD0 = (a * log(a / x) + x) - a;
      }
    } else {
      t = x / a;
      rval = (1.0 - t) / (t + 1.0);
      a2 = rval * rval;
      xD0 = gold * rval;
      tsq = xD0;
      t = 2.0 * (a * rval);
      rval = 3.0;
      do {
        exitg1 = 0;
        t *= a2;
        xD0 += t / rval;
        if (xD0 == tsq) {
          exitg1 = 1;
        } else {
          tsq = xD0;
          rval += 2.0;
        }
      } while (exitg1 == 0);
    }
    logpax = (-0.5 * (la + 1.8378770664093453) - stirlerr) - xD0;
    if (x > 1.0E+6) {
      stirlerr = sqrt(x);
      t = fabs(gold - 1.0) / stirlerr;
      tsq = t * t;
      if (t < 15.0) {
        rval = 0.70710678118654746 * t;
        xD0 = 3.97886080735226 / (rval + 3.97886080735226);
        a1 = 0.5 *
             ((((((((((((((((((((((0.0012710976495261409 * (xD0 - 0.5) +
                                   0.00011931402283834095) *
                                      (xD0 - 0.5) -
                                  0.0039638509736051354) *
                                     (xD0 - 0.5) -
                                 0.00087077963531729586) *
                                    (xD0 - 0.5) +
                                0.0077367252831352668) *
                                   (xD0 - 0.5) +
                               0.0038333512626488732) *
                                  (xD0 - 0.5) -
                              0.012722381378212275) *
                                 (xD0 - 0.5) -
                             0.013382364453346007) *
                                (xD0 - 0.5) +
                            0.016131532973325226) *
                               (xD0 - 0.5) +
                           0.039097684558848406) *
                              (xD0 - 0.5) +
                          0.0024936720005350331) *
                             (xD0 - 0.5) -
                         0.0838864557023002) *
                            (xD0 - 0.5) -
                        0.11946395996432542) *
                           (xD0 - 0.5) +
                       0.016620792496936737) *
                          (xD0 - 0.5) +
                      0.35752427444953105) *
                         (xD0 - 0.5) +
                     0.80527640875291062) *
                        (xD0 - 0.5) +
                    1.1890298290927332) *
                       (xD0 - 0.5) +
                   1.3704021768233816) *
                      (xD0 - 0.5) +
                  1.313146538310231) *
                     (xD0 - 0.5) +
                 1.0792551515585667) *
                    (xD0 - 0.5) +
                0.77436819911953858) *
                   (xD0 - 0.5) +
               0.49016508058531844) *
                  (xD0 - 0.5) +
              0.27537474159737679) *
             xD0 * exp(-rval * rval) * 2.5066282746310002 * exp(0.5 * tsq);
        a2 = (a1 * ((tsq - 3.0) * t) - (tsq - 4.0)) / 6.0;
        xD0 = (a1 * ((tsq * tsq - 9.0) * tsq + 6.0) -
               ((tsq - 1.0) * tsq - 6.0) * t) /
              72.0;
        rval = 5.0 * tsq;
        rval =
            (a1 *
                 (((((rval + 45.0) * tsq - 81.0) * tsq - 315.0) * tsq + 270.0) *
                  t) -
             ((((rval + 40.0) * tsq - 111.0) * tsq - 174.0) * tsq + 192.0)) /
            6480.0;
      } else {
        a1 = (((3.0 - 15.0 / tsq) / tsq - 1.0) / tsq + 1.0) / t;
        a2 = (((25.0 - 210.0 / tsq) / tsq - 4.0) / tsq + 1.0) / tsq;
        xD0 = (((130.0 - 1750.0 / tsq) / tsq - 11.0) / tsq + 1.0) / (tsq * t);
        rval =
            (((546.0 - 11368.0 / tsq) / tsq - 26.0) / tsq + 1.0) / (tsq * tsq);
      }
      if (x < a - 1.0) {
        rval = a * (((a1 / stirlerr - a2 / x) + xD0 / (x * stirlerr)) -
                    rval / (x * x));
        if (logpax < 709.782712893384) {
          rval *= exp(logpax);
        } else {
          rval = exp(logpax + log(rval));
        }
        if (upper) {
          rval = 1.0 - rval;
        }
      } else {
        rval = a * (((a1 / stirlerr + a2 / x) + xD0 / (x * stirlerr)) +
                    rval / (x * x));
        if (logpax < 709.782712893384) {
          rval *= exp(logpax);
        } else {
          rval = exp(logpax + log(rval));
        }
        if (!upper) {
          rval = 1.0 - rval;
        }
      }
    } else if (upper && (x < 1.0) && (a < 1.0)) {
      double fac;
      double n;
      fac = a * -x;
      a2 = fac / (a + 1.0);
      n = 2.0;
      do {
        exitg1 = 0;
        fac = -x * fac / n;
        t = fac / (a + n);
        a2 += t;
        if (fabs(t) <= fabs(a2) * 2.2204460492503131E-16) {
          exitg1 = 1;
        } else {
          n++;
        }
      } while (exitg1 == 0);
      rval = a * log(x) - lgap1;
      xD0 = exp(rval);
      if (!(xD0 == 1.0)) {
        if (xD0 - 1.0 == -1.0) {
          rval = -1.0;
        } else {
          rval = (xD0 - 1.0) * rval / log(xD0);
        }
      }
      rval = -((a2 + rval) + a2 * rval);
      if (rval < 0.0) {
        rval = 0.0;
      }
    } else if ((x < a) || (x < 1.0)) {
      double n;
      n = 1.0;
      if ((!(x < a)) && (a < 2.2250738585072014E-308) &&
          (x > 1.7976931348623157E+308 * a)) {
        rval = 1.0 - (double)upper;
      } else {
        int i;
        if (x > 2.2204460492503131E-16 * a) {
          double fac;
          fac = x / a;
          n = 2.0;
          do {
            exitg1 = 0;
            fac = x * fac / (a + (n - 1.0));
            if (fac < 2.2204460492503131E-16) {
              exitg1 = 1;
            } else {
              n++;
            }
          } while (exitg1 == 0);
        }
        rval = 0.0;
        i = (int)-((-1.0 - (n - 1.0)) + 1.0);
        for (b_i = 0; b_i < i; b_i++) {
          rval = x * (rval + 1.0) / (a + ((n - 1.0) - (double)b_i));
        }
        rval++;
        if (logpax < 709.782712893384) {
          rval *= exp(logpax);
        } else {
          rval = exp(logpax + log(rval));
        }
        if (rval > 1.0) {
          rval = 1.0;
        }
        if (upper) {
          rval = 1.0 - rval;
        }
      }
    } else {
      double fac;
      double n;
      int i;
      fac = 1.0;
      n = 1.0;
      do {
        exitg1 = 0;
        rval = floor(a1);
        if (n <= rval) {
          fac = (a - n) * fac / x;
          if (fabs(fac) < 2.2204460492503131E-16) {
            exitg1 = 1;
          } else {
            n++;
          }
        } else {
          exitg1 = 1;
        }
      } while (exitg1 == 0);
      if (n <= rval) {
        rval = 1.0;
      } else {
        t = floor(a);
        xD0 = a - t;
        if (xD0 == 0.0) {
          rval = 1.0;
          n = t;
        } else if (xD0 == 0.5) {
          rval = 0.70710678118654746 * sqrt(2.0 * x);
          xD0 = 3.97886080735226 / (rval + 3.97886080735226);
          rval = sqrt(3.1415926535897931 * x) * exp(x) *
                 (2.0 *
                  (0.5 *
                   ((((((((((((((((((((((0.0012710976495261409 * (xD0 - 0.5) +
                                         0.00011931402283834095) *
                                            (xD0 - 0.5) -
                                        0.0039638509736051354) *
                                           (xD0 - 0.5) -
                                       0.00087077963531729586) *
                                          (xD0 - 0.5) +
                                      0.0077367252831352668) *
                                         (xD0 - 0.5) +
                                     0.0038333512626488732) *
                                        (xD0 - 0.5) -
                                    0.012722381378212275) *
                                       (xD0 - 0.5) -
                                   0.013382364453346007) *
                                      (xD0 - 0.5) +
                                  0.016131532973325226) *
                                     (xD0 - 0.5) +
                                 0.039097684558848406) *
                                    (xD0 - 0.5) +
                                0.0024936720005350331) *
                                   (xD0 - 0.5) -
                               0.0838864557023002) *
                                  (xD0 - 0.5) -
                              0.11946395996432542) *
                                 (xD0 - 0.5) +
                             0.016620792496936737) *
                                (xD0 - 0.5) +
                            0.35752427444953105) *
                               (xD0 - 0.5) +
                           0.80527640875291062) *
                              (xD0 - 0.5) +
                          1.1890298290927332) *
                             (xD0 - 0.5) +
                         1.3704021768233816) *
                            (xD0 - 0.5) +
                        1.313146538310231) *
                           (xD0 - 0.5) +
                       1.0792551515585667) *
                          (xD0 - 0.5) +
                      0.77436819911953858) *
                         (xD0 - 0.5) +
                     0.49016508058531844) *
                        (xD0 - 0.5) +
                    0.27537474159737679) *
                   xD0 * exp(-rval * rval)));
          n = t + 1.0;
        } else {
          a2 = 1.0;
          a1 = x;
          stirlerr = 0.0;
          tsq = 1.0;
          fac = 1.0 / x;
          n = 1.0;
          rval = fac;
          gold = 0.0;
          while (fabs(rval - gold) > 2.2204460492503131E-16 * rval) {
            gold = rval;
            rval = n - xD0;
            a2 = (a1 + a2 * rval) * fac;
            stirlerr = (tsq + stirlerr * rval) * fac;
            rval = n * fac;
            a1 = x * a2 + rval * a1;
            tsq = x * stirlerr + rval * tsq;
            fac = 1.0 / a1;
            rval = tsq * fac;
            n++;
          }
          rval *= x;
          n = t + 1.0;
        }
      }
      i = (int)-((-1.0 - (n - 1.0)) + 1.0);
      for (b_i = 0; b_i < i; b_i++) {
        rval = (a - ((n - 1.0) - (double)b_i)) * rval / x + 1.0;
      }
      rval = rval * a / x;
      if (logpax < 709.782712893384) {
        rval *= exp(logpax);
      } else {
        rval = exp(logpax + log(rval));
      }
      if (rval > 1.0) {
        rval = 1.0;
      }
      if (!upper) {
        rval = 1.0 - rval;
      }
    }
  }
  return rval;
}

/*
 * File trailer for eml_gammainc.c
 *
 * [EOF]
 */
