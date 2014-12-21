#ifndef 	PASSTHROUGH_FILTER_H
#define PASSTHROUGH_FILTER_H

#include <Fixtures/virtual_fixtures.h>


/*Publisher and Subscriber*/
ros::Subscriber subscribe_raw_data;
ros::Publisher publish_filter;


pcl::PointCloud<pcl::PointXYZRGB>::Ptr filter_cloud_object(new pcl::PointCloud<pcl::PointXYZRGB>);

pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);

sensor_msgs::PointCloud2 filteredCloud;

#define LOWER_LIMIT 0
#define UPPER_LIMIT 2


#endif
