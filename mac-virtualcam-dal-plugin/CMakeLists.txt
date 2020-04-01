project(virtualcam-mac-dal-plugin)

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
                    # Verified to be necessary
                    ../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Client
                    ../src/CoreMediaIO/PublicUtility/DALAssistant
                    ../src/generated)

set(virtualcam-mac-dal-plugin_SOURCES
	../src/CoreMediaIO/PublicUtility/IOSurfaceAssistant/CMIO_SA_Assistance.cpp
	../src/CoreMediaIO/PublicUtility/POSIXThreadAssistant/CMIO_PTA_NotificationPortThread.cpp
	../src/CoreMediaIO/PublicUtility/IOStreamAssistant/CMIO_IOSA_Assistance.cpp
	../src/CoreMediaIO/PublicUtility/IOKitAssistant/CMIO_IOKA_NotificationPort.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_ScheduledOutputNotificationProc.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_Deck.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_FirstOutputPresentationTimeStamp.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Base/CMIO_DP_ControlDictionary.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/Device/CMIO_DPA_Sample_Server_ClientStream.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Server/Device/CMIO_DPA_Sample_Server_Frame.cpp
	../src/CoreAudio/PublicUtility/CACFDistributedNotification.cpp
	../src/CoreAudio/PublicUtility/CAGuard.cpp
	../src/CoreMediaIO/PublicUtility/CMIO_SMPTETimeBase.cpp
	../src/CoreAudio/PublicUtility/CAPThread.cpp
	../src/CoreMediaIO/PublicUtility/POSIXThreadAssistant/CMIO_PTA_CFMachPortThread.cpp
	../src/CoreMediaIO/PublicUtility/IOVideoAssistant/CMIO_IOVA_Assistance.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Base/CMIO_DP_UserInfo.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Base/CMIO_DP_Stream.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/PlugIn/CMIO_DP_Sample_VirtualDevice.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/PlugIn/CMIO_DP_Sample_Stream.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/PlugIn/Properties/CMIO_DP_Sample_Property_HogMode.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/PlugIn/CMIO_DP_Sample_PlugIn.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/PlugIn/CMIO_DP_Sample_IOBackedDevice.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/PlugIn/CMIO_DP_Sample_Device.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/PlugIn/CMIO_DP_SampleVCam_PlugInInterface.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_SuspendedByUser.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_SMPTETimeCallback.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_OutputBuffers.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_NoData.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_HogMode.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_FormatList.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_EndOfData.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_DeviceMaster.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_Clock.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_ClientSyncDiscontinuity.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Properties/CMIO_DP_Property_Base.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Base/CMIO_DP_PlugIn.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Base/CMIO_DP_Object.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/IOV/PlugIn/CMIO_DP_IOV_ControlDictionary.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/IOV/PlugIn/CMIO_DP_IOV_Control.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Base/CMIO_DP_HardwarePlugInInterface.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Base/CMIO_DP_DeviceSettings.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Base/CMIO_DP_DeviceCommands.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Base/CMIO_DP_Device.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Base/CMIO_DP_Control.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/DP/Base/CMIO_DP_Command.cpp
	../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/Assistant/Client/CMIO_DPA_Sample_ClientExtras.cpp
	../src/CoreMediaIO/PublicUtility/DALAssistant/CMIO_DALA_System.cpp
	../src/CoreMediaIO/PublicUtility/CMIODebugPrintf.cpp
	../src/CoreMediaIO/PublicUtility/CMIODebugMacros.cpp
	../src/CoreAudio/PublicUtility/CAVolumeCurve.cpp
	../src/CoreAudio/PublicUtility/CAProcess.cpp
	../src/CoreAudio/PublicUtility/CAMutex.cpp
	../src/CoreAudio/PublicUtility/CAHostTimeBase.cpp
	../src/CoreAudio/PublicUtility/CACFString.cpp
	../src/CoreAudio/PublicUtility/CACFPreferences.cpp
	../src/CoreAudio/PublicUtility/CACFNumber.cpp
	../src/CoreAudio/PublicUtility/CACFMachPort.cpp
	../src/CoreAudio/PublicUtility/CACFDictionary.cpp
	../src/generated/CMIODPASampleClient.cpp
	../src/CoreAudio/PublicUtility/CACFArray.cpp)

add_library(virtualcam-mac-dal-plugin MODULE
    ${virtualcam-mac-dal-plugin_SOURCES}
    ${virtualcam-mac-dal-plugin_HEADERS})

target_link_libraries(virtualcam-mac-dal-plugin
    ${AVFOUNDATION}
    ${COCOA}
    ${COREFOUNDATION}
    ${COREMEDIA}
    ${COREVIDEO}
    ${COREMEDIAIO}
    ${IOSURFACE}
    ${IOKIT})

# Note: May not be necessary
target_link_options(virtualcam-mac-dal-plugin
    PUBLIC -exported_symbols_list ${PROJECT_SOURCE_DIR}/../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/PlugIn/SampleVCam.exp
)

set_target_properties(virtualcam-mac-dal-plugin
    PROPERTIES
    BUNDLE_EXTENSION plugin
    MACOSX_BUNDLE_INFO_PLIST ${PROJECT_SOURCE_DIR}/../src/CoreMediaIO/DeviceAbstractionLayer/Devices/Sample/PlugIn/Info.plist
    BUNDLE TRUE)

add_custom_command(TARGET virtualcam-mac-dal-plugin
    POST_BUILD
    COMMAND /usr/bin/codesign --force --deep --sign - --timestamp=none ${CMAKE_CURRENT_BINARY_DIR}/virtualcam-mac-dal-plugin.plugin
    COMMENT "Codesign plugin"
)