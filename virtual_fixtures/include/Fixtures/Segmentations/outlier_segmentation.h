/*
 * outlier_segmentation.h
 *
 *  Created on: Dec 14, 2014
 *      Author: root
 */

#ifndef OUTLIER_SEGMENTATION_H_
#define OUTLIER_SEGMENTATION_H_

#include<Fixtures/virtual_fixtures.h>
#ifdef _MSC_VER
#include <windows.h>
#endif

#include <stdio.h>
#include <vector>
#include <exception>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


//ros include files
#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <sensor_msgs/PointCloud.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/point_cloud_conversion.h>
#include <pcl/PointIndices.h>
#include <pcl/ros/conversions.h>
#include <image_transport/image_transport.h>

#include <pcl/filters/passthrough.h>


#include <pcl_ros/point_cloud.h>
#include <pcl_ros/io/pcd_io.h>
#include <pcl/io/io.h>
#include <pcl/point_types.h>
#include <pcl/range_image/range_image.h>
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/filters/voxel_grid.h>

//Segmentation and Indicies Extraction PCL libraries
#include <pcl/ModelCoefficients.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/surface/concave_hull.h>
#include <pcl/visualization/cloud_viewer.h>


//#include <pcl/visualization/cloud_viewer.h>

#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include <Fixtures/virtual_fixtures.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/project_inliers.h>
#include <pcl/visualization/cloud_viewer.h>

#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

#include <DepthSense.hxx>
/*Initialize Publisher and Subscriber*/
ros::Publisher pub_seg;
ros::Subscriber sub_raw_data;

/*Objects for storing manipulated cloud data  */
pcl::PointCloud<pcl::PointXYZRGB>::Ptr INLIERPoints(new pcl::PointCloud<pcl::PointXYZRGB> ); // object for storing inlier point clouds
pcl::PointCloud<pcl::PointXYZRGB>::Ptr segCloudPtr(new pcl::PointCloud<pcl::PointXYZRGB> ()); // object for storing desired points clouds
pcl::PointCloud<pcl::PointXYZRGB>::Ptr planeExtractedPtr(new pcl::PointCloud<pcl::PointXYZRGB> ());  //object for storing extracted clouds
pcl::PointCloud<pcl::PointXYZRGB>::Ptr concaveHull(new pcl::PointCloud<pcl::PointXYZRGB>); // object for displaying concave hull pointcloud
pcl::PointCloud<pcl::PointXYZRGB>::Ptr planePtr(new pcl::PointCloud<pcl::PointXYZRGB> ());
pcl::PointCloud<pcl::PointXYZRGB>::Ptr needsFilterPtr(new pcl::PointCloud<pcl::PointXYZRGB> ());
/*Segmentation and algorith driven objects*/
pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients); //object for storing model coefficients
pcl::SACSegmentation<pcl::PointXYZRGB> segmentation; // segmentation object
pcl::PointIndices::Ptr inlierIndices(new pcl::PointIndices); //point indices object


/*PointCloud2 message to be published*/
sensor_msgs::PointCloud2 pc_data;

/*Segmentation distance between each segmentation threshold and max iteration*/
double max_thresh = 0.020; //
double max_iteration = 50;
#endif /* OUTLIER_SEGMENTATION_H_ */
