cmake_minimum_required(VERSION 3.17)
project(mac-virtualcam)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -std=c++11")

add_subdirectory(mac-virtualcam-obs-plugin)
add_subdirectory(mac-virtualcam-dal-plugin)