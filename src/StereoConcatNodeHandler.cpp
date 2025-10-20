#include "stereo_concat/StereoConcatNodeHandler.hpp"
#include "params/StereoConcatNodeHandlerParams.hpp"

#include "message_filters/subscriber.h"
#include "message_filters/time_synchronizer.h"

#include <chrono>

using namespace std::chrono_literals;

namespace stereo_concat {

StereoConcatNodeHandler::StereoConcatNodeHandler() : Node("stereo_concat_node"), stereo_concatenator_() {}

void StereoConcatNodeHandler::init() {

    params::StereoConcatNodeHandlerParams params = params::StereoConcatNodeHandlerParams::readParameters(shared_from_this());

    left_image_subscriber_.subscribe(this, params.left_image_topic);
    right_image_subscriber_.subscribe(this, params.right_image_topic);

    sync_ = std::make_shared<message_filters::TimeSynchronizer<sensor_msgs::msg::CompressedImage, sensor_msgs::msg::CompressedImage>>(left_image_subscriber_, right_image_subscriber_, 10);
    sync_->registerCallback(std::bind(&StereoConcatNodeHandler::imagesCallback, this, std::placeholders::_1, std::placeholders::_2));

    concatenated_image_publisher_ = this->create_publisher<sensor_msgs::msg::Image>(params.concatenated_image_topic, 10);

    timer_ = this->create_wall_timer(20ms, std::bind(&StereoConcatNodeHandler::onTimer, this));
}

void StereoConcatNodeHandler::imagesCallback(const sensor_msgs::msg::CompressedImage::ConstSharedPtr& left_msg, const sensor_msgs::msg::CompressedImage::ConstSharedPtr& right_msg) {
    stereo_concatenator_.processImages(*left_msg, *right_msg);
}

void StereoConcatNodeHandler::onTimer() {
    concatenated_image_publisher_->publish(stereo_concatenator_.getLatestConcatenatedImage());
}

}