#ifndef _ROS_H_
#define _ROS_H_

#include "ros/node_handle.h"
#include "ESP32Hardware.h"

namespace ros
{
    typedef ros::NodeHandle_<ESP32Hardware, 25, 25, 1024, 1024> NodeHandle;
}

#endif
