#pragma once

#include "sensor_msgs/msg/compressed_image.hpp"
#include "sensor_msgs/msg/image.hpp"

namespace stereo_concat {

class StereoConcat {

    sensor_msgs::msg::Image latest_concatenated_image_ = sensor_msgs::msg::Image();

    sensor_msgs::msg::Image concatImages(sensor_msgs::msg::CompressedImage leftImage, sensor_msgs::msg::CompressedImage rightImage);

    public:

        StereoConcat() = default;

        ~StereoConcat() = default;

        void processImages(sensor_msgs::msg::CompressedImage leftImage, sensor_msgs::msg::CompressedImage rightImage);

        sensor_msgs::msg::Image getLatestConcatenatedImage();
};

}