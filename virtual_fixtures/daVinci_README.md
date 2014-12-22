daVinci Virtual Fixtures
===================================

General description
---------------------
This package fuses multiple PCL-oriented nodes that utilizes the softkinetic API package via Senz3D Interactive Gesture Camera
in ROS and performs Virtual Fixtures Operations for the da Vinci Virtual Environment 



#### Parameters
**camera_link** *(string, default: "/softkinetic_link")*   
 The frame ID of the camera.

**confidence_threshold** *(int, default: 150)*   
 Confidence threshold for DepthNode configuration.
 Sensor noise is filtered by increasing the threshold.
 Threshold needs to be within [0, 32767].


#### Published Topics

**Feedback/Softkinetic_Bringup** *(sensor_msgs::PointCloud2)*
 @node: softkinetic_bringup_node
 @Publisher: 
 @Subscriber:NONE
 @msg: sensor_msgs::PointCloud2
 @purpose: 

**Filters/PassThrough** *(sensor_msgs::PointCloud2)*
 @node: passthrough_filter_node
 @Publisher: daVinci/Fixture/PassthroughFilter
 @Subscriber: /softkinetic_camera/depth/points
 @msg: sensor_msgs::PointCloud2
 @purpose: iterates through cloud once, filters out non-finite points and points outside intervals (0,1.5) on the "z" field

**Filters/RadiusConditional** *(sensor_msgs::PointCloud2)*
 @node: 
 @Publisher: 
 @Subscriber:
 @msg: sensor_msgs::PointCloud2
 @purpose:

**Segmentation/OutlierDisplay** *(sensor_msgs::PointCloud2)*
 @node: outlier_display_node
 @Publisher: /daVinci/Fixture/OutliersDisplay
 @Subscriber: /daVinci/Fixture/PassthroughFilter
 @msg: sensor_msgs::PointCloud2
 @purpose: finds the biggest plane (wall or table) using RANSAC (SAC_RANSAC) plane model fitting and removes biggest plane and displays the remaining points
     

**Segmentation/Object_Segmentation** *(sensor_msgs::PointCloud2)*
 @node: 
 @Publisher: 
 @Subscriber:
 @msg: sensor_msgs::PointCloud2
 @purpose:

**Images/Fixed_Base_Tool** *(sensor_msgs::PointCloud2)*
 @node: 
 @Publisher: 
 @Subscriber:
 @msg: sensor_msgs::PointCloud2
 @purpose:

**Images/Normal_Components** *(sensor_msgs::PointCloud2)*
 @node: 
 @Publisher: 
 @Subscriber:
 @msg: sensor_msgs::PointCloud2
 @purpose:

**Registration/Preoperative** *(sensor_msgs::PointCloud2)*
 @node: 
 @Publisher: 
 @Subscriber:
 @msg: sensor_msgs::PointCloud2
 @purpose:
**Registration/Intraoperative** *(sensor_msgs::PointCloud2)*
 @node: 
 @Publisher: 
 @Subscriber:
 @msg: sensor_msgs::PointCloud2
 @purpose:
**Registration/Cloud_to_Cloud_Registration** *(sensor_msgs::PointCloud2)*
 @node: 
 @Publisher: 
 @Subscriber:
 @msg: sensor_msgs::PointCloud2
 @purpose:

**Data Analysis/** 


#### Launch Files
**virtual_fixtures_display.launch** *(visualization::RViz)*
  Displays the following nodes on RViz

			1 softkinetic_bringup_node
			2 passthrough_filter_node
			3 fixed_base_tool_node
			4 object_seg_node
			5 outlier_display_nod
			6 reconstruction_triangulation_node
			7 pre_operative_image_node
			8 concave_hull_node

 
 


			

