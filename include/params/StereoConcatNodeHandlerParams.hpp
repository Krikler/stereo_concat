#pragma once

#include <rclcpp/rclcpp.hpp>

namespace params {

struct StereoConcatNodeHandlerParams {
  std::string left_image_topic;
  std::string right_image_topic;
  std::string concatenated_image_topic;

  /**
   * @brief Read in the parameters from the ROS2 node
   *
   * @param node Shared Pointer to ROS2 node
   * @return StereoConcatNodeHandlerParams populated with parameters
   */
  static StereoConcatNodeHandlerParams readParameters(const rclcpp::Node::SharedPtr& node);
};

}