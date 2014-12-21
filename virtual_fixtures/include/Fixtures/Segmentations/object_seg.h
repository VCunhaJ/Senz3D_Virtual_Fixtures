#ifndef OBJECT_SEG_H_
#define OBJECT_SEG_H_

#include <Fixtures/virtual_fixtures.h>
#include <pcl/segmentation/extract_clusters.h>

/*Publisher and Subscriber*/
ros::Subscriber subscribe_raw_data;
ros::Publisher publish_object;

/*Objects*/
pcl::PointCloud<pcl::PointXYZRGB>::Ptr new_cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
pcl::PointCloud<pcl::PointXYZRGB>::Ptr clusterObject	(new pcl::PointCloud<pcl::PointXYZRGB>);


pcl::EuclideanClusterExtraction<pcl::PointXYZRGB> cluster;
std::vector<pcl::PointIndices> clusterIndices;

sensor_msgs::PointCloud2 objectSegmented;
std::vector<pcl::PointIndices>::const_iterator i;
std::vector<int>::const_iterator point;


/*Parameters*/
const double CLUSTER_TOLERANCE = 0.005; //(cm)
int currentCluster = 0;

#define MAXIMUM_CLUSTER_SIZE 5000
#define MINIMUM_CLUSTER_SIZE 7000





#endif
