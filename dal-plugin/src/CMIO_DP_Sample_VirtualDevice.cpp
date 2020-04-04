/*
	    File: CMIO_DP_Sample_VirtualDevice.cpp
	Abstract: n/a
	 Version: 1.2
	
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// includes
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Self Include
#include "CMIO_DP_Sample_VirtualDevice.h"

#pragma mark -
namespace CMIO { namespace DP { namespace Sample
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	// VirtualDevice()
	//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    VirtualDevice::VirtualDevice(PlugIn& plugIn, CMIODeviceID deviceID, mach_port_t assistantPort, UInt64 guid):
        Device(plugIn, deviceID, assistantPort, guid)
    {
        mDeviceUID = CFSTR("OBS Virtual Camera Video");
        mDeviceName = CFSTR("OBS Virtual Camera");
    }
    
}}}
