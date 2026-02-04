import numpy as np
import ctypes

lib = ctypes.CDLL("/home/elishabr/projectCPP/TestBatSystem/bazel-bin/libtestbat.so")

lib.my_wblinv_wrapper_2d.argtypes = [
    ctypes.POINTER(ctypes.c_double),  # input
    ctypes.c_int,                     # rows
    ctypes.c_int,                     # cols
    ctypes.c_double,                  # scale
    ctypes.c_double,                  # shape
    ctypes.POINTER(ctypes.c_double)   # output
]

lib.my_gaminv_wrapper_2d.argtypes = [
    ctypes.POINTER(ctypes.c_double),  # input
    ctypes.c_int,                     # rows
    ctypes.c_int,                     # cols
    ctypes.c_double,                  # scale
    ctypes.c_double,                  # shape
    ctypes.POINTER(ctypes.c_double)   # output
]

lib.my_raylinv_wrapper_2d.argtypes = [
    ctypes.POINTER(ctypes.c_double),  # input
    ctypes.c_int,                     # rows
    ctypes.c_int,                     # cols
    ctypes.c_double,                  # scale
    ctypes.POINTER(ctypes.c_double)   # output
]

lib.my_poissinv_wrapper_2d.argtypes = [
    ctypes.POINTER(ctypes.c_double),  # input
    ctypes.c_int,                     # rows
    ctypes.c_int,                     # cols
    ctypes.c_double,                  # lambda
    ctypes.POINTER(ctypes.c_double)   # output
]

def my_wblinv_py():
    mat = np.asarray([[0.1, 0.2, 0.3]], dtype=np.float64) 
    rows, cols = mat.shape

    out = np.zeros_like(mat)

    lib.my_wblinv_wrapper_2d(
        mat.ctypes.data_as(ctypes.POINTER(ctypes.c_double)),
        rows,
        cols,
        2.0,
        2.0,
        out.ctypes.data_as(ctypes.POINTER(ctypes.c_double))
    )
    return out

def my_gaminv_py():
    mat = np.asarray([[0.1, 0.2, 0.3]], dtype=np.float64) 
    rows, cols = mat.shape

    out = np.zeros_like(mat)

    lib.my_gaminv_wrapper_2d(
        mat.ctypes.data_as(ctypes.POINTER(ctypes.c_double)),
        rows,
        cols,
        2.0,
        2.0,
        out.ctypes.data_as(ctypes.POINTER(ctypes.c_double))
    )
    return out

def my_raylinv_py():
    mat = np.asarray([[0.1, 0.2, 0.3]], dtype=np.float64) 
    rows, cols = mat.shape

    out = np.zeros_like(mat)

    lib.my_raylinv_wrapper_2d(
        mat.ctypes.data_as(ctypes.POINTER(ctypes.c_double)),
        rows,
        cols,
        2.0,
        out.ctypes.data_as(ctypes.POINTER(ctypes.c_double))
    )
    return out

def my_poissinv_py():
    mat = np.asarray([[0.1, 0.2, 0.3]], dtype=np.float64) 
    rows, cols = mat.shape

    out = np.zeros_like(mat)

    lib.my_poissinv_wrapper_2d(
        mat.ctypes.data_as(ctypes.POINTER(ctypes.c_double)),
        rows,
        cols,
        2.0,
        out.ctypes.data_as(ctypes.POINTER(ctypes.c_double))
    )
    return out

print(my_wblinv_py())
print(my_gaminv_py())
print(my_raylinv_py())
print(my_poissinv_py())
