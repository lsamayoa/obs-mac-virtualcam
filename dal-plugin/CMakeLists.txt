cmake_minimum_required(VERSION 3.17)
project(virtualcam-dal-plugin)

find_package(PkgConfig REQUIRED)
# We need this since we are using installed libraries using pkg-config
SET(CMAKE_MODULE_LINKER_FLAGS "-L/usr/local/lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -std=c++11")

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
                    src)

set(virtualcam-dal-plugin_HEADERS
    src/CMIO_DP_Sample_ControlIDs.h
    src/CMIO_DP_Sample_Device.h
    src/CMIO_DP_Sample_Plugin.h
    src/CMIO_DP_Sample_Stream.h
    src/CMIO_DP_Sample_VirtualDevice.h
    src/Properties/CMIO_DP_Sample_Property_HogMode.h)

set(virtualcam-dal-plugin_SOURCES
    src/CMIO_DP_Sample_Device.cpp
    src/CMIO_DP_Sample_Plugin.cpp
    src/CMIO_DP_Sample_Stream.cpp
    src/CMIO_DP_Sample_VirtualDevice.cpp
    src/CMIO_DP_SampleVCam_PluginInterface.cpp
    src/Properties/CMIO_DP_Sample_Property_HogMode.cpp)


add_library(virtualcam-dal-plugin MODULE
	${virtualcam-dal-plugin_SOURCES}
	${virtualcam-dal-plugin_HEADERS})

target_link_libraries(virtualcam-dal-plugin
	${AVFOUNDATION}
	${COCOA}
	${COREFOUNDATION}
	${COREMEDIA}
	${COREVIDEO}
	${COREMEDIAIO}
	${IOSURFACE}
    ${IOKIT}
    ${COREMEDIAIO_DAL_LIBRARIES}
    ${COREMEDIAIO_DAL_IPC_LIBRARIES})

# Note: May not be necessary
target_link_options(virtualcam-dal-plugin
    PUBLIC -exported_symbols_list ${PROJECT_SOURCE_DIR}/src/SampleVCam.exp
)

set_target_properties(virtualcam-dal-plugin
    PROPERTIES
    BUNDLE_EXTENSION plugin
    MACOSX_BUNDLE_INFO_PLIST ${PROJECT_SOURCE_DIR}/src/Info.plist
    BUNDLE TRUE)

add_custom_command(TARGET virtualcam-dal-plugin
    POST_BUILD
    COMMAND /usr/bin/codesign --force --deep --sign - --timestamp=none ${CMAKE_CURRENT_BINARY_DIR}/virtualcam-dal-plugin.plugin
    COMMENT "Codesign plugin"
)