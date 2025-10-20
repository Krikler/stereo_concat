import os
from pathlib import Path
import launch
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.substitutions import LaunchConfiguration


def generate_launch_description():

    package_path = get_package_share_directory('stereo_concat')
    config = os.path.join(package_path, 'config', 'default_params.yaml')
    
    bag_path = os.path.expanduser('~/ros2_bags/onboarding.mcap')

    stereo_concat_node = Node(
        package='stereo_concat',
        executable='stereo_concat',
        parameters=[config],
        output='screen',
    )

    ros_bag_play = ExecuteProcess(
        cmd=['ros2', 'bag', 'play', '-l', bag_path],
        output='screen'
    )


    return launch.LaunchDescription([
        stereo_concat_node,
        ros_bag_play
    ])