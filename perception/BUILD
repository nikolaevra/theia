load("@org_tensorflow//tensorflow:tensorflow.bzl", "tf_cc_binary")

tf_cc_binary(
    name = "graph-loader",
    srcs = ["graph_loader.cc"],
    deps = [
        "@org_tensorflow//tensorflow/cc:cc_ops",
        "@org_tensorflow//tensorflow/cc:client_session",
        "@org_tensorflow//tensorflow/core:tensorflow",
    ],
)

cc_library(
    name = "subscriber",
    hdrs = ["subscriber.hh"],
)

cc_library(
    name = "subscription-types",
    hdrs = ["subscription_types.hh"],
)

cc_library(
    name = "publisher",
    hdrs = ["publisher.hh"],
    deps = [
        ":subscription-types",
    ],
)

cc_library(
    name = "perception-objects",
    hdrs = ["perception_objects.hh"],
)

cc_library(
    name = "detector",
    srcs = ["detector.cc"],
    hdrs = ["detector.hh"],
    deps = [
        ":publisher",
        ":subscriber",
    ]
)

cc_library(
    name = "utils",
    srcs = ["utils.cc"],
    hdrs = ["utils.hh"],
    deps = [
        ":perception-objects"
    ],
)

cc_library(
    name = "task-runner",
    hdrs = ["task_runner.hh"],
    deps = [
        "//config:config",
        ":perception-objects",
        ":data-reader",
        ":detector",
        ":iou-tracker",
        ":subscription-types",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "data-reader",
    srcs = ["data_reader.cc"],
    hdrs = ["data_reader.hh"],
    deps = [
        "@opencv//:opencv",
        ":publisher",
        ":subscription-types",
    ],
)

cc_library(
    name = "iou-tracker",
    srcs = ["iou_tracker.cc"],
    hdrs = ["iou_tracker.hh"],
    deps = [
        ":perception-objects",
        ":subscriber",
        ":utils",
    ]
)
