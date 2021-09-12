#include <iostream>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>


int main() {

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

    if (pcl::io::loadPCDFile<pcl::PointXYZ> ("demo.pcd", *cloud) == -1) //* load the file
    {
        PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
        return (-1);
    }
    std::cout << "Loaded "
              << cloud->width * cloud->height
              << " data points from test_pcd.pcd with the following fields: "
              << std::endl;
    for (const auto& point: *cloud)
        std::cout << "    " << point.x
                  << " "    << point.y
                  << " "    << point.z << std::endl;

    pcl::visualization::CloudViewer viewer("Cloud Viewer");

    //blocks until the cloud is actually rendered
    viewer.showCloud(cloud);

    // viewer.runOnVisualizationThreadOnce (viewerOneOff);

    //This will get called once per visualization iteration
    // viewer.runOnVisualizationThread (viewerPsycho);
    while (!viewer.wasStopped ())
    {
        //you can also do cool processing here
        //FIXME: Note that this is running in a separate thread from viewerPsycho
        //and you should guard against race conditions yourself...
      //  user_data++;
    }
    return 0;
}