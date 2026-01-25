#include "my_wblinv.h"
#include <stdlib.h>

void my_wblinv_wrapper_2d(
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


import numpy as np
import ctypes

lib = ctypes.CDLL("./libmylib.so")

lib.my_wblinv_wrapper_2d.argtypes = [
    ctypes.POINTER(ctypes.c_double),  # input
    ctypes.c_int,                     # rows
    ctypes.c_int,                     # cols
    ctypes.c_double,                  # scale
    ctypes.c_double,                  # shape
    ctypes.POINTER(ctypes.c_double)   # output
]

def my_wblinv_py(mat, scale, shape):
    mat = np.asarray(mat, dtype=np.float64)
    rows, cols = mat.shape

    out = np.zeros_like(mat)

    lib.my_wblinv_wrapper_2d(
        mat.ctypes.data_as(ctypes.POINTER(ctypes.c_double)),
        rows,
        cols,
        scale,
        shape,
        out.ctypes.data_as(ctypes.POINTER(ctypes.c_double))
    )
    return out
