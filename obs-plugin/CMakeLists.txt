cmake_minimum_required(VERSION 3.17)
project(virtualcam-obs-plugin)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(PkgConfig REQUIRED)
find_package(Libobs REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -std=c++11")
# We need this since we are using installed libraries using pkg-config
SET(CMAKE_MODULE_LINKER_FLAGS "-L/usr/local/lib")



pkg_check_modules(COREMEDIAIO_DAL REQUIRED coremediaio-dal)
pkg_check_modules(COREMEDIAIO_DAL_IPC REQUIRED coremediaio-dal-ipc)
find_library(AVFOUNDATION AVFoundation)
find_library(COCOA Cocoa)
find_library(COREFOUNDATION CoreFoundation)
find_library(COREMEDIA CoreMedia)
find_library(COREVIDEO CoreVideo)
find_library(COCOA Cocoa)
find_library(COREMEDIAIO CoreMediaIO)
find_library(IOSURFACE IOSurface)
find_library(IOKIT IOKit)

include_directories(${AVFOUNDATION}
					${COCOA}
					${COREFOUNDATION}
					${COREMEDIA}
					${COREVIDEO}
					${COREMEDIAIO}
					${COCOA}
                    ${IOSURFACE}
                    ${COREMEDIAIO_DAL_INCLUDE_DIRS}
					${COREMEDIAIO_DAL_IPC_INCLUDE_DIRS}
					${LIBOBS_INCLUDE_DIR}
                    client
                    Plugin)

set(virtualcam-obs-plugin_SOURCES
    plugin-main.cpp)

add_library(virtualcam-obs-plugin MODULE
	${virtualcam-obs-plugin_SOURCES})

target_link_libraries(virtualcam-obs-plugin
	${AVFOUNDATION}
	${COCOA}
	${COREFOUNDATION}
	${COREMEDIA}
	${COREVIDEO}
	${COREMEDIAIO}
	${IOSURFACE}
    ${IOKIT}
    ${COREMEDIAIO_DAL_LIBRARIES}
	${COREMEDIAIO_DAL_IPC_LIBRARIES}
	${LIBOBS_LIBRARIES})

set_target_properties(virtualcam-obs-plugin PROPERTIES
	PREFIX "")