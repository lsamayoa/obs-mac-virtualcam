#include "OBSVirtualCamServer.h"

#include "OBSVirtualCamDevice.h"


namespace OBSVirtualCam
{

	OBSVirtualCamServer::OBSVirtualCamServer() :
        CMIO::DPA::Sample::Server::Assistant()
	{
        CreateDevices();
	}
	
    void OBSVirtualCamServer::CreateDevices()
    {
        // Grab the mutex for the Assistant's state
        CAMutex::Locker locker(mStateMutex);
        
        // Get the current device count
        UInt32 deviceCount = (UInt32)mDevices.size();
        
        // Create the new device
        OBSVirtualCam::OBSVirtualCamDevice* device = new OBSVirtualCam::OBSVirtualCamDevice();
        
        // Add it to the set of discovered devices whose capabilities are known
        mDevices.insert(device);
        
        // If any devices were successfully added, notify interested clients that a state change has taken place so they can call UpdateDeviceStates() at their convenience
        if (deviceCount != mDevices.size())
        {
            // Send out the devices state changed message
            for (ClientNotifiers::iterator it = mDeviceStateNotifiers.begin(); it != mDeviceStateNotifiers.end(); ++it)
                SendDeviceStatesChangedMessage((*it).second);

            // All the 'send-once' rights are now used up, so erase everything in the multimap
            mDeviceStateNotifiers.erase(mDeviceStateNotifiers.begin(), mDeviceStateNotifiers.end());
        }
    }
    
}
