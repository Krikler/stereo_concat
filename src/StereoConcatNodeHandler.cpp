#include "stereo_concat/StereoConcatNodeHandler.hpp"
#include "params/StereoConcatNodeHandlerParams.hpp"

namespace stereo_concat {

StereoConcatNodeHandler::StereoConcatNodeHandler() : Node("stereo_concat_node"), stereo_concatenator_() {}

void StereoConcatNodeHandler::init() {

    params::StereoConcatNodeHandlerParams params = params::StereoConcatNodeHandlerParams::readParameters(shared_from_this());

    left_image_subscriber_ = this->create_subscription<sensor_msgs::msg::CompressedImage>(
        params.left_image_topic, 10, std::bind(&StereoConcatNodeHandler::leftImageCallback, this, std::placeholders::_1)
    );

    right_image_subscriber_ = this->create_subscription<sensor_msgs::msg::CompressedImage>(
        params.right_image_topic, 10, std::bind(&StereoConcatNodeHandler::rightImageCallback, this, std::placeholders::_1)
    );

    concatenated_image_publisher_ = this->create_publisher<sensor_msgs::msg::Image>("/concatenated_image", 10); //TODO: 50 Hz legyen
}

void StereoConcatNodeHandler::leftImageCallback(const sensor_msgs::msg::CompressedImage msg) {
    //TODO
    RCLCPP_INFO(this->get_logger(), "Left image received");
    concatenated_image_publisher_->publish(stereo_concatenator_.concatImages(msg, msg)); //TODO: jobb oldali kép
}

void StereoConcatNodeHandler::rightImageCallback(const sensor_msgs::msg::CompressedImage msg) {
    //TODO
}
//TODO: Szinkronizálás

}