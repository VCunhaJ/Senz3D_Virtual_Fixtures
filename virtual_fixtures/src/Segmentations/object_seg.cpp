/*
 * Author(s): Vanderlei Cunha Jr.
 * ME5205 - Professor Fischer
 * Created December 13, 2014
 *
 * @node: object_seg_node
 * @Publisher: /daVinci/Segmentation/ObjectSegmentation
 * @Subscriber: /daVinci/Fixture/OutliersDisplay
 * @msg: sensor_msgs::PointCloud2
 *
 * @purpose: uses Euclidean Cluster extraction algorithm to define how many objects are on the plane
 *
 *
 */
#include <Fixtures/virtual_fixtures.h>
#include <Fixtures/Segmentations/object_seg.h>

using namespace pcl;
using namespace std;
using namespace ros;

void EuclideanCluster(PointCloud<PointXYZRGB>::Ptr new_cloud)
{

cluster.setClusterTolerance(CLUSTER_TOLERANCE);
cluster.setMinClusterSize(MINIMUM_CLUSTER_SIZE);
cluster.setMaxClusterSize(MAXIMUM_CLUSTER_SIZE);
cluster.setInputCloud(new_cloud);
cluster.extract(clusterIndices);

for(i = clusterIndices.begin(); i!=clusterIndices.end(); ++i){
   for(point = i->indices.begin(); point != i->indices.end(); point++)
											clusterObject->points.push_back(cloud->points[*point]);
						clusterObject->width = clusterObject->points.size();
						clusterObject->height = 1;
						clusterObject->is_dense = true;

   if(clusterObject->points.size() <= 0)
       break;

currentCluster++;
   }

std::cerr<<"Cluster "<<currentCluster<<" has "<<clusterObject->points.size()<< " points" <<std::endl;
}

void segmentationCallBack(const sensor_msgs::PointCloud2 &filteredCloud)
{

fromROSMsg(filteredCloud, *cloud);

search::KdTree<PointXYZRGB>::Ptr kdTree(new search::KdTree<PointXYZRGB>);
kdTree->setInputCloud(cloud);

EuclideanCluster(cloud);


toROSMsg(*cloud,objectSegmented);
publish_object.publish(objectSegmented);
}

int main (int argc, char** argv)
{

ros::init(argc, argv, "object_seg_node");
ros::NodeHandle node;

subscribe_raw_data = node.subscribe("/daVinci/Fixture/OutliersDisplay", 1, &segmentationCallBack);
publish_object = node.advertise<sensor_msgs::PointCloud2>("/daVinci/Segmentation/ObjectSegmentation",1);

ros::Rate loopRate(10);
while(ros::ok())
{
ros::spin();
loopRate.sleep();

}

return EXIT_SUCCESS;
}



