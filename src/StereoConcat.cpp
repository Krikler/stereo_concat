#include "stereo_concat/StereoConcat.hpp"
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include "rclcpp/rclcpp.hpp"

namespace stereo_concat {

sensor_msgs::msg::Image StereoConcat::concatImages(sensor_msgs::msg::CompressedImage leftImage, sensor_msgs::msg::CompressedImage rightImage) {
    cv::Mat leftMat = cv::imdecode(cv::Mat(leftImage.data), cv::IMREAD_COLOR);
    cv::Mat rightMat = cv::imdecode(cv::Mat(rightImage.data), cv::IMREAD_COLOR);
    cv::Mat concatenatedMat;

    cv::hconcat(leftMat, rightMat, concatenatedMat);

    return *cv_bridge::CvImage(leftImage.header, "bgr8", concatenatedMat).toImageMsg();
}

sensor_msgs::msg::Image StereoConcat::getLatestConcatenatedImage() {
    return latest_concatenated_image_;
}

void StereoConcat::processImages(sensor_msgs::msg::CompressedImage leftImage, sensor_msgs::msg::CompressedImage rightImage) {
    latest_concatenated_image_ = concatImages(leftImage, rightImage);
}

}