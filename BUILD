cc_library(
    name = "testbat",
    srcs = glob(["lib/*.c"]),
    hdrs = glob(["lib/*.h"]),
    linkopts = [
        "-fopenmp",
        "-lm",
    ],
)

cc_binary(
    name = "main",
    srcs = [
        "examples/main.c",
    ],
    deps = [":testbat"],
    linkstatic=False,
)
