#pragma once

#include "rclcpp/rclcpp.hpp"
#include "stereo_concat/StereoConcat.hpp"

#include "sensor_msgs/msg/compressed_image.hpp"
#include "sensor_msgs/msg/image.hpp"

#include "message_filters/subscriber.h"
#include "message_filters/time_synchronizer.h"


namespace stereo_concat {

class StereoConcatNodeHandler : public rclcpp::Node {

    StereoConcat stereo_concatenator_;

    message_filters::Subscriber<sensor_msgs::msg::CompressedImage> left_image_subscriber_;

    message_filters::Subscriber<sensor_msgs::msg::CompressedImage> right_image_subscriber_;

    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr concatenated_image_publisher_;

    std::shared_ptr<message_filters::TimeSynchronizer<sensor_msgs::msg::CompressedImage,sensor_msgs::msg::CompressedImage>> sync_;

    rclcpp::TimerBase::SharedPtr timer_;

    void imagesCallback(const sensor_msgs::msg::CompressedImage::ConstSharedPtr& left_msg, const sensor_msgs::msg::CompressedImage::ConstSharedPtr& right_msg);

    public:
        StereoConcatNodeHandler();

        ~StereoConcatNodeHandler() = default;

        void init();

        void onTimer();
};

}