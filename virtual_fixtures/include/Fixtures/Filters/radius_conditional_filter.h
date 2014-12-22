#ifndef RADIUS_CONDITIONAL_FILTER_H
#define RADIUS_CONDITIONAL_FILTER_H

#include <Fixtures/virtual_fixtures.h>
using namespace std;
using namespace pcl;
using namespace ros;

/*Publisher and Subscriber*/
Subscriber subscribe_raw_data;
Publisher publish_radius_filter;

/*Class Objects*/

PointCloud<PointXYZRGB>::Ptr notFilteredCloudPtr(new pcl::PointCloud<PointXYZRGB>);
PointCloud<PointXYZRGB>::Ptr radiusFilteredCloudPtr(new pcl::PointCloud<PointXYZRGB>);
RadiusOutlierRemoval<PointXYZRGB> radiusFilter;
/*Sensor Messages*/
sensor_msgs::PointCloud2 filteredCloud;

/*Parameters*/
const double RADIUS = 0.12;



#endif
