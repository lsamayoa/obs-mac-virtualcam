cmake_minimum_required(VERSION 3.5)
project(virtualcam-mac-obs-plugin)

find_package(Libobs REQUIRED)

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
					${LIBOBS_INCLUDE_DIR}
					../src/CoreMediaIO/PublicUtility
					../src/CoreAudio/PublicUtility
					../src/CoreMediaIO/PublicUtility/IOSurfaceAssistant
					../src/CoreMediaIO/PublicUtility/POSIXThreadAssistant
					../src/CoreMediaIO/PublicUtility/IOVideoAssistant
					../src/CoreMediaIO/PublicUtility/IOStreamAssistant
					../src/CoreMediaIO/PublicUtility/IOKitAssistant
					../src/CoreMediaIO/PublicUtility/CoreMediaAssistant
					../src/CoreMediaIO/PublicUtility/CoreVideoAssistant
					../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties
					../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Base
					../src/CoreMediaIO/DeviceAbstractionLayer/Devices/IOV/PlugIn
					../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample
					../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant
					../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server
					../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/Device
					../src/generated)

set(virtualcam-mac-obs-plugin_HEADERS
	../src/CoreMediaIO/PublicUtility/IOSurfaceAssistant/CMIO_SA_Assistance.h
	../src/CoreMediaIO/PublicUtility/POSIXThreadAssistant/CMIO_PTA_NotificationPortThread.h
	../src/CoreMediaIO/PublicUtility/IOVideoAssistant/CMIO_IOVA_Assistance.h
	../src/CoreMediaIO/PublicUtility/IOStreamAssistant/CMIO_IOSA_Assistance.h
	../src/CoreMediaIO/PublicUtility/IOKitAssistant/CMIO_IOKA_NotificationPort.h
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_FirstOutputPresentationTimeStamp.h
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_Deck.h
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_Base.h
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Base/CMIO_DP_ControlDictionary.h
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/IOV/PlugIn/CMIO_DP_IOV_ControlDictionary.h
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/Device/CMIO_DPA_Sample_Server_VCamInputStream.h
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/Device/CMIO_DPA_Sample_Server_Stream.h
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/CMIO_DPA_Sample_Server_VCamAssistant.h
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/Device/CMIO_DPA_Sample_Server_VCamDevice.h
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/CMIO_DPA_Sample_Server_MIGInterface.h
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/Device/CMIO_DPA_Sample_Server_Frame.h
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/Device/CMIO_DPA_Sample_Server_Deck.h
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/Device/CMIO_DPA_Sample_Server_Device.h
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/Device/CMIO_DPA_Sample_Server_ClientStream.h
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/CMIO_DPA_Sample_Server_Assistant.h
	../src/CoreMediaIO/PublicUtility/DALAssistant/CMIO_DALA_Object.h
	../src/CoreMediaIO/PublicUtility/CMIODebugMacros.h
	../src/CoreAudio/PublicUtility/CAProcess.h
	../src/CoreAudio/PublicUtility/CAPThread.h
	../src/CoreAudio/PublicUtility/CAMutex.h
	../src/CoreAudio/PublicUtility/CAHostTimeBase.h
	../src/CoreAudio/PublicUtility/CAGuard.h
	../src/CoreAudio/PublicUtility/CACFString.h
	../src/CoreAudio/PublicUtility/CACFNumber.h
	../src/CoreAudio/PublicUtility/CACFDictionary.h
	../src/CoreAudio/PublicUtility/CACFArray.h)

set(virtualcam-mac-obs-plugin_SOURCES
	../src/CoreMediaIO/PublicUtility/IOSurfaceAssistant/CMIO_SA_Assistance.cpp
	../src/CoreMediaIO/PublicUtility/POSIXThreadAssistant/CMIO_PTA_NotificationPortThread.cpp
	../src/CoreMediaIO/PublicUtility/IOVideoAssistant/CMIO_IOVA_Assistance.cpp
	../src/CoreMediaIO/PublicUtility/IOStreamAssistant/CMIO_IOSA_Assistance.cpp
	../src/CoreMediaIO/PublicUtility/IOKitAssistant/CMIO_IOKA_NotificationPort.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_FirstOutputPresentationTimeStamp.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_Deck.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/CMIO_DPA_Sample_VCamServer.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_Base.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Base/CMIO_DP_ControlDictionary.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/IOV/PlugIn/CMIO_DP_IOV_ControlDictionary.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/Device/CMIO_DPA_Sample_Server_VCamInputStream.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/Device/CMIO_DPA_Sample_Server_Stream.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/CMIO_DPA_Sample_Server_VCamAssistant.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/Device/CMIO_DPA_Sample_Server_VCamDevice.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/CMIO_DPA_Sample_Server_MIGInterface.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/Device/CMIO_DPA_Sample_Server_Frame.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/Device/CMIO_DPA_Sample_Server_Deck.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/Device/CMIO_DPA_Sample_Server_Device.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/Device/CMIO_DPA_Sample_Server_ClientStream.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/CMIO_DPA_Sample_Server_Assistant.cpp
	../src/CoreMediaIO/PublicUtility/DALAssistant/CMIO_DALA_Object.cpp
	../src/CoreMediaIO/PublicUtility/CMIODebugMacros.cpp
	../src/CoreAudio/PublicUtility/CAProcess.cpp
	../src/CoreAudio/PublicUtility/CAPThread.cpp
	../src/CoreAudio/PublicUtility/CAMutex.cpp
	../src/CoreAudio/PublicUtility/CAHostTimeBase.cpp
	../src/CoreAudio/PublicUtility/CAGuard.cpp
	../src/CoreAudio/PublicUtility/CACFString.cpp
	../src/CoreAudio/PublicUtility/CACFNumber.cpp
	../src/CoreAudio/PublicUtility/CACFDictionary.cpp
	../src/CoreAudio/PublicUtility/CACFArray.cpp
	../src/generated/CMIODPASampleServer.cpp
	../src/plugin-main.cpp)


add_library(virtualcam-mac-obs-plugin MODULE
	${virtualcam-mac-obs-plugin_SOURCES}
	${virtualcam-mac-obs-plugin_HEADERS})

target_link_libraries(virtualcam-mac-obs-plugin
	${AVFOUNDATION}
	${COCOA}
	${COREFOUNDATION}
	${COREMEDIA}
	${COREVIDEO}
	${COREMEDIAIO}
	${IOSURFACE}
	${IOKIT}
	${LIBOBS_LIB})

set_target_properties(virtualcam-mac-obs-plugin PROPERTIES
		PREFIX "")

# install(TARGETS v4l2sink
# 	LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/obs-plugins)