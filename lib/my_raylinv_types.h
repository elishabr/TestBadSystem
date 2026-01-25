/*
 * File: my_raylinv_types.h
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 15-Jan-2026 22:37:30
 */

#ifndef MY_RAYLINV_TYPES_H
#define MY_RAYLINV_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#endif
/*
 * File trailer for my_raylinv_types.h
 *
 * [EOF]
 */
