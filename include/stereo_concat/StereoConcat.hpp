#pragma once

#include "sensor_msgs/msg/compressed_image.hpp"
#include "sensor_msgs/msg/image.hpp"

namespace stereo_concat {

class StereoConcat {

    public:

    StereoConcat() = default;

    ~StereoConcat() = default;

    sensor_msgs::msg::Image concatImages(sensor_msgs::msg::CompressedImage leftImage, sensor_msgs::msg::CompressedImage rightImage); //TODO: type

};

}