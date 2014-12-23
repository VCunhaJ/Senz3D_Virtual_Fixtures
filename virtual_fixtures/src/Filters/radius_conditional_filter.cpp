/*
 *
 * Author(s): Vanderlei Cunha Jr.
 * ME5205 - Professor Fischer
 * Created December 15, 2014
 *
 * @node: radius_conditional_filter_node
 * @Publisher: /daVinci/Fixture/RadiusConditionalFilte
 * @Subscriber: /daVinci/Fixture/OutliersDisplay
 * @msg: sensor_msgs::PointCloud2
 *
 * @purpose: Eliminates noise from cloud by removing all points outside of a radius treshold  
 *      
 *
 */
#include <Fixtures/virtual_fixtures.h>
#include <Fixtures/Filters/radius_conditional_filter.h>

using namespace pcl;
using namespace std;
using namespace ros;

void RadiusFilterCallBack(const sensor_msgs::PointCloud2 &rawcloud)
{

fromROSMsg(rawcloud, *notFilteredCloudPtr);

radiusFilter.setInputCloud(notFilteredCloudPtr);
radiusFilter.setRadiusSearch(0.12);
radiusFilter.setMinNeighborsInRadius((notFilteredCloudPtr->points.size()/4));
radiusFilter.filter(*radiusFilteredCloudPtr);


//Convert from PointCloud class to PointCloud2 msg
toROSMsg(*radiusFilteredCloudPtr, filteredCloud);

publish_radius_filter.publish(filteredCloud);


}

int main (int argc, char** argv)
{

ros::init(argc, argv, "radius_conditional_filter_node");
ros::NodeHandle node;
subscribe_raw_data = node.subscribe("/daVinci/Segmentation/ObjectSegmentation", 1, &RadiusFilterCallBack);
publish_radius_filter = node.advertise<sensor_msgs::PointCloud2>("/daVinci/Fixture/RadiusConditionalFilter",1);


ros::Rate loopRate(10);

while(ros::ok())
{
spinOnce();
loopRate.sleep();

}


return EXIT_SUCCESS;
}



