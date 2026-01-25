#!/bin/bash

bazel build //:all --compilation_mode=dbg
nm -C ./bazel-bin/main | grep raylinv 
nm -C ./bazel-bin/main | grep wblinv 
nm -C ./bazel-bin/main | grep gaminv
nm -C ./bazel-bin/main | grep poissinv
ldd ./bazel-bin/main