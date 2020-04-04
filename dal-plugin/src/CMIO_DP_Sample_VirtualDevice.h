/*
	    File: CMIO_DP_Sample_VirtualDevice.h
	Abstract: n/a
	 Version: 1.2
		
*/

#if !defined(__CMIO_DP_Sample_VirtualDevice_h__)
#define __CMIO_DP_Sample_VirtualDevice_h__

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Super Class Includes
#include "CMIO_DP_Sample_Device.h"


namespace CMIO { namespace DP { namespace Sample
{
    
	//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	// VirtualDevice
	//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    class VirtualDevice : public Device
	{
    // Construction/Destruction
    public:
                                VirtualDevice(PlugIn& plugIn, CMIODeviceID deviceID, mach_port_t assistantPort, UInt64 guid);
	};
    
}}}

#endif
