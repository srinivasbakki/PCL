cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(pcd_visualize)

find_package(PCL 1.8.1 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (pcd_visualizer pcd_visualizer.cpp)
target_link_libraries (pcd_visualizer ${PCL_LIBRARIES})

#add_executable (pcd_adv_visualizer pcd_adv_visualizer.cpp)
#target_link_libraries (pcd_adv_visualizer ${PCL_LIBRARIES})
