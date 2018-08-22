#include "ros/ros.h"
#include "std_msgs/String.h"
#include "performance_tests/SuperAwesome.h"
#include "performance_tests/Rate.h"
#include <sstream>

int Rate = 1;
int Counter  = 0;

bool Rate_Callback(performance_tests::Rate::Request  &req, performance_tests::Rate::Response &res)
{
    Rate = req.data;
    Counter  = 0;
    
	ROS_INFO("Loop rate: %d", (int) req.data);

  	return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Publisher_Cpp");
    ros::NodeHandle n;

    ros::Publisher      SuperAwesome_Publisher  = n.advertise<performance_tests::SuperAwesome>("SuperAwesome_Topic", 1000);
    ros::ServiceServer  Rate_Server             = n.advertiseService("Change_Rate_Service", Rate_Callback);

    performance_tests::SuperAwesome msg;

    ros::Rate loop_rate(1);

    while (ros::ok())
    {
        std::stringstream ss;
        ss << ++Counter;
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());
        SuperAwesome_Publisher.publish(msg);

        ros::spinOnce();
        loop_rate = ros::Rate(Rate);
        loop_rate.sleep();
    }

    return 0;
}


