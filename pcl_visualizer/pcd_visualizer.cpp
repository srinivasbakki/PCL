#include <iostream>
#include <math.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>

int main()
{
  float th, phi, r;
  float x,y,z;
  
  pcl::PointCloud<pcl::PointXYZRGB> cloud; //cloud
  pcl::PointXYZRGB point; //plceholder for points    

  r = 0.5; //unit sphere

  //construct the point cloud and then visualize the same
  for(phi=0; phi <= 2*M_PI; phi+= 0.01) // rotate the entire circle
    {      
      z = r * cos(phi);
      point.z = z;
      for(th = 0; th <= 2*M_PI; th+=0.01)
	{
	  point.x = r * sin(phi) * cos(th);
	  point.y = r * sin(phi) * sin(th);
          point.b = 51;
	  point.b = 87;
	  point.b = 255;
	  cloud.push_back(point);
	}
    }
  cloud.is_dense = true;
  cloud.height = 1; //check what this height is
  cloud.width = cloud.points.size();

  /* Here compltes the point cloud formation */

  /* Write the cloud to a file and the give that to the visualizer */
  pcl::io::savePCDFileASCII ("sphere_pcd.pcd", cloud);
    
  /* Now, visualize it */

  pcl::visualization::PCLVisualizer viewer("Cloud Viewer");
  /* our point cloud file contains color information too, hence use  PointXYZRGB */
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr pcd_file (new pcl::PointCloud<pcl::PointXYZRGB>);

  // load the file and provide the pointer to file object
  pcl::io::loadPCDFile ("sphere_pcd.pcd", *pcd_file);

  // add the pcd file to visualizer
  viewer.addPointCloud(pcd_file, "pcd_file");

  viewer.spin();
  return 0;
  
}
