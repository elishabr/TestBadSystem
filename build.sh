#!/bin/bash

bazel build //:all --compilation_mode=dbg
nm -C ./bazel-bin/main | grep raylinv 
nm -C ./bazel-bin/main | grep wblinv 
nm -C ./bazel-bin/main | grep gaminv
nm -C ./bazel-bin/main | grep poissinv
nm -C ./bazel-bin/libtestbat.so | grep poissinv
nm -C ./bazel-bin/libtestbat.so | grep my_wblinv_wrapper_2d
ldd ./bazel-bin/main