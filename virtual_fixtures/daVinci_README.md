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


**Object_Segmentation** *(sensor_msgs::PointCloud2)*
 Subscribes to 
 Publishes Segmented Objects from the greatest plane (tables or walls)

**Filters/PassThrough** *(sensor_msgs::PointCloud2)*
  Subscribes to 
  Publishes 

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
			9 extract_borders_node
 
 


			

