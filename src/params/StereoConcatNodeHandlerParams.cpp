#include "params/StereoConcatNodeHandlerParams.hpp"

namespace params {

StereoConcatNodeHandlerParams StereoConcatNodeHandlerParams::readParameters(
    const rclcpp::Node::SharedPtr& node
) {
    StereoConcatNodeHandlerParams params;

    params.left_image_topic = node->declare_parameter(
        "topics.left_image", "/left/image_rect_color/compressed"
    );

    params.right_image_topic = node->declare_parameter(
        "topics.right_image", "/right/image_rect_color/compressed"
    );

    params.concatenated_image_topic = node->declare_parameter(
        "topics.concatenated_image", "/concatenated_image"
    );

    return params;
}

}