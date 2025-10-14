#pragma once

#include "rclcpp/rclcpp.hpp"
#include "stereo_concat/StereoConcat.hpp"

#include "sensor_msgs/msg/compressed_image.hpp"
#include "sensor_msgs/msg/image.hpp"


namespace stereo_concat {

class StereoConcatNodeHandler : public rclcpp::Node {

    StereoConcat stereo_concatenator_;

    rclcpp::Subscription<sensor_msgs::msg::CompressedImage>::SharedPtr left_image_subscriber_;

    rclcpp::Subscription<sensor_msgs::msg::CompressedImage>::SharedPtr right_image_subscriber_;

    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr concatenated_image_publisher_;

    void leftImageCallback(const sensor_msgs::msg::CompressedImage msg);

    void rightImageCallback(const sensor_msgs::msg::CompressedImage msg);

    public:
        StereoConcatNodeHandler();

        ~StereoConcatNodeHandler() = default;

        void init();
};

}