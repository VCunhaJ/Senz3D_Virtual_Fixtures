/*
 * reconstruction_triangulation.cpp
 *
 *  Created on: Dec 16, 2014
 *      Author: Vanderlei Cunha Jr.
 *
 *
 */
#include<Fixtures/virtual_fixtures.h>
#include<Fixtures/Segmentations/reconstruction_triangulation.h>
using namespace std;
using namespace pcl;
using namespace ros;

void reconstructionTriangulation(const sensor_msgs::PointCloud2 &segCloud){

 fromROSMsg(segCloud, *cloud);

 IndicesPtr indices (new std::vector <int>);
 pcl::PassThrough<pcl::PointXYZRGB> pass;
 pass.setInputCloud (cloud);
 pass.setFilterFieldName ("z");
 pass.setFilterLimits (0.0, 1.0);
 pass.filter (*indices);

 regionGrowing.setInputCloud (cloud);
 regionGrowing.setIndices(indices);
 regionGrowing.setSearchMethod(tree);
 regionGrowing.setDistanceThreshold(10);
 regionGrowing.setPointColorThreshold(6);
 regionGrowing.setRegionColorThreshold (5);
 regionGrowing.setMinClusterSize (600);


  regionGrowing.extract (clusters);

  PointCloud <PointXYZRGB>::Ptr colored_cloud = regionGrowing.getColoredCloud ();
  pcl::visualization::CloudViewer viewer ("Cluster Viewer");
  viewer.showCloud (colored_cloud);

	pcl::toROSMsg(*colored_cloud, pc_data);
  while (!viewer.wasStopped ())
  {
				pub.publish(pc_data);
    boost::this_thread::sleep (boost::posix_time::microseconds (100));
    
  }


}

int main(int argc, char** argv)
{

	ros::init(argc, argv, "reconstruction_triangulation_node");
	ros::NodeHandle node;

	sub = node.subscribe("/softkinetic_camera/depth/points",1, &reconstructionTriangulation);
 pub = node.advertise<sensor_msgs::PointCloud2>("/daVinci/Fixture/Reconstruction_Triangulation", 1);

	Rate loop_rate(10);
	while(ros::ok()){

	ros::spin();
 loop_rate.sleep();

	}

}
