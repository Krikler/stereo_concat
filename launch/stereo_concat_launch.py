import os
from pathlib import Path
import launch
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration


def generate_launch_description():

    package_path = get_package_share_directory('stereo_concat')
    config = os.path.join(package_path, 'config', 'default_params.yaml')

    stereo_concat_node = Node(
        package='stereo_concat',
        executable='stereo_concat',
        parameters=[config],
        output='screen',
    )


    return launch.LaunchDescription([
        stereo_concat_node
    ])