cc_library(
    name = "testbat",
    srcs = glob(["lib/*.c"]),
    hdrs = glob(["lib/*.h"]),
)

cc_binary(
    name = "main",
    srcs = [
        "examples/main.c",
    ],
    deps = [":testbat"],
    linkopts = [
        "-fopenmp",
        "-lm",
    ],
    linkstatic=False,
)
