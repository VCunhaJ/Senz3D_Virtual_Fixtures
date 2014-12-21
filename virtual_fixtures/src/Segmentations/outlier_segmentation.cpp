/*
 * outlier_segmentation.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: Vanderlei Cunha Jr.
 */
#include<Fixtures/virtual_fixtures.h>
#include<Fixtures/Segmentations/outlier_segmentation.h>
//#include<Fixtures/Segmentations/plane_seg.h>

using namespace std;
using namespace pcl;
using namespace ros;


void VoxelFilter(PointCloud<PointXYZRGB>::Ptr raw, PointCloud<PointXYZRGB>::Ptr cloud)
{
	// Create the filtering object: downsample the dataset using a leaf size of 1cm

VoxelGrid<PointXYZRGB> voxel;
voxel.setInputCloud (needsFilterPtr);
voxel.setLeafSize (0.01f, 0.01f, 0.01f);
voxel.filter(*segCloudPtr);
 std::cout<<" Cloud after Voxel Filter "<<raw->points.size()<<std::endl;

}


/*------------------------------------------------------------------------------------------------*/
void outlierDisplay(const sensor_msgs::PointCloud2& msg){



//Convert from PointCloud2 msg to PointCloud class object
 pcl::fromROSMsg(msg, *segCloudPtr);


segmentation.setOptimizeCoefficients(true); //enable model coefficient refinement (optional)
segmentation.setModelType(SACMODEL_PLANE); //configure object to look for a plane
segmentation.setMethodType(SAC_RANSAC); //use RANSAC method model
segmentation.setDistanceThreshold(max_thresh); // how close a point must be to the model in order to be considered an inlier.
segmentation.setMaxIterations(max_iteration);


int i=0, nr_points= (int) segCloudPtr->points.size();
while(segCloudPtr->points.size() > 0.3*nr_points)
{
	segmentation.setInputCloud(segCloudPtr);
	segmentation.segment(*inlierIndices, *coefficients);

	if (inlierIndices->indices.size() == 0)
	{
			std::cerr<<"Wall Not Found"<<std::endl;
			break;
	}

	pcl::ExtractIndices<PointXYZRGB> ex;
	ex.setInputCloud(segCloudPtr);
	ex.setIndices(inlierIndices);
	ex.setNegative(false);
	ex.filter(*planePtr);
	ex.setNegative(true);
	ex.filter(*planeExtractedPtr);
	*segCloudPtr = *planeExtractedPtr;

std::cerr<<"The points in this plane are: "<<planeExtractedPtr->width*planeExtractedPtr->height<<" data points."<<std::endl;
//Convert from PointCloud class to PointCloud2 msg
pcl::toROSMsg(*segCloudPtr, pc_data);

pub_seg.publish(pc_data);

}

}

/*------------------------------------------------------------------------------------------------*/
int main (int argc, char** argv){

	//Initiate ROS

ros::init(argc, argv,"outlier_display_node");
ros::NodeHandle node;


	//Subscribe to raw data topic

sub_raw_data = node.subscribe("daVinci/Fixture/PassthroughFilter", 1, &outlierDisplay);
pub_seg = node.advertise<sensor_msgs::PointCloud2>("/daVinci/Fixture/OutliersDisplay", 1);
ros::Rate loopRate(10);
while(node.ok()){

	ros::spin();
	loopRate.sleep();

	}
return 0;
}
