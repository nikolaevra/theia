visibility = ["//visibility:public"]

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


#cc_binary(
#    name = "graph-loader",
#    srcs = ["graph_loader.cc",],
#    deps = [
#        "@org_tensorflow//tensorflow/cc:cc_ops",
#        "@org_tensorflow//tensorflow/core:tensorflow",
#    ]
#)

cc_library(
    name = "perception-objects",
    srcs = ["perception_objects.hh"],
)

cc_library(
    name = "iou-tracker",
    srcs = ["iou_tracker.cc"],
    hdrs = ["iou_tracker.hh"],
    deps = [":perception-objects"]
)
