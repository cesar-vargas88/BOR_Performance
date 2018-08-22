#include "ros/ros.h"
#include "performance_tests/Rate.h"

int main(int argc, char **argv)
{
  	ros::init(argc, argv, "Change_Rate_Node");
  	ros::NodeHandle n;

	ros::ServiceClient Change_Rate_Client = n.serviceClient<performance_tests::Rate>("Change_Rate_Service");

	performance_tests::Rate srv;

	while(true)
	{
		std::cout << "Input the new loop rate: ";
		std::cin >> srv.request.data;

		Change_Rate_Client.call(srv);
			
		ros::spinOnce();
	}

  	return 0;
}