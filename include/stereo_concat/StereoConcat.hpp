#pragma once

#include "sensor_msgs/msg/compressed_image.hpp"
#include "sensor_msgs/msg/image.hpp"

namespace stereo_concat {

class StereoConcat {

    // Store the latest concatenated image
    sensor_msgs::msg::Image latest_concatenated_image_ = sensor_msgs::msg::Image();

    /**
     * @brief Concatenates two compressed images side by side
     * 
     * @param leftImage The left compressed image.
     * @param rightImage The right compressed image.
     * @return The concatenated image.
     */
    sensor_msgs::msg::Image concatImages(sensor_msgs::msg::CompressedImage leftImage, sensor_msgs::msg::CompressedImage rightImage);

    public:

        StereoConcat() = default;

        ~StereoConcat() = default;

        /**
         * @brief Concatenates two images and store the result
         * 
         * @param leftImage The left compressed image.
         * @param rightImage The right compressed image.
         */
        void processImages(sensor_msgs::msg::CompressedImage leftImage, sensor_msgs::msg::CompressedImage rightImage);

        /**
         * @brief Get the latest concatenated image
         * 
         * @return The latest concatenated image.
         */
        sensor_msgs::msg::Image getLatestConcatenatedImage();
};

}