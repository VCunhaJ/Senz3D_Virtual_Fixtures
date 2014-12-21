/*
 * normal_cloud.cpp
 *
 *  Created on: Dec 17, 2014
 *      Author: Vanderlei Cunha Jr.
 *
 *
 */
#include<Fixtures/virtual_fixtures.h>
#include<Fixtures/Feedback/normal_cloud.h>

using namespace std;
using namespace ros;
using namespace pcl;


int main (int argc, char** argv)
{

ros::init(argc, argv, "normal_cloud_node");
ros::NodeHandle node;
///daVinci/Fixture/OutliersDisplay
subscribe_object= node.subscribe("/daVinci/Fixture/OutliersDisplay", 1, &ConcaveCallBack);
publish_normal = node.advertise<sensor_msgs::PointCloud2>("daVinci/Fixture/Feedback/NormalEstimation",1);


ros::Rate loopRate(10);
while(node.ok())
{
spin();
loopRate.sleep();

}

return 0;
//return EXIT_SUCCESS;
}
