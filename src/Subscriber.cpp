#include "ros/ros.h"
#include "std_msgs/String.h"
#include "performance_tests/SuperAwesome.h"

void SuperAwesomeCallback(const performance_tests::SuperAwesome::ConstPtr& msg)
{
    ROS_INFO("%s", msg->data.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Subscriber_Cpp");
    ros::NodeHandle n;   
    ros::Subscriber SuperAwesome_Subscriber = n.subscribe("SuperAwesome_Topic", 1000, SuperAwesomeCallback);
    ros::spin();
    
    return 0;
}