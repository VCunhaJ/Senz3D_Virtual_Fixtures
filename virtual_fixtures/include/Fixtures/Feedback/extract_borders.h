/*
 * extract_borders.h
 *
 *  Created on: Dec 17, 2014
 *      Author: root
 */

#ifndef EXTRACT_BORDERS_H_
#define EXTRACT_BORDERS_H_

#include <pcl/io/pcd_io.h>
#include <pcl/range_image/range_image.h>
#include <pcl/visualization/range_image_visualizer.h>
#include <Fixtures/virtual_fixtures.h>

using namespace pcl;
using namespace ros;
using namespace std;

Subscriber sub_object;
Publisher pub_range;

PointCloud<PointXYZ>::Ptr rangePointPtr (new pcl::PointCloud<PointXYZ>);

// Angular resolution is the angular distance between pixels.
// Kinect: 57° horizontal FOV, 43° vertical FOV, 640x480 (chosen here).
// Xtion: 58° horizontal FOV, 45° vertical FOV, 640x480.
float angularResolutionX = (float)(57.0f / 640.0f * (M_PI / 180.0f));
float angularResolutionY = (float)(43.0f / 480.0f * (M_PI / 180.0f));


// Maximum horizontal and vertical angles. For example, for a full panoramic scan,
// the first would be 360º. Choosing values that adjust to the real sensor will
// decrease the time it takes, but don't worry. If the values are bigger than
// the real ones, the image will be automatically cropped to discard empty zones.
float maxAngleX = (float)(60.0f * (M_PI / 180.0f));
float maxAngleY = (float)(50.0f * (M_PI / 180.0f));

#endif /* EXTRACT_BORDERS_H_ */
