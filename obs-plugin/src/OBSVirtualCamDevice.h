#if !defined(__OBSVirtualCamDevice_h__)
#define __OBSVirtualCamDevice_h__

#include "CMIO_DPA_Sample_Server_Device.h"
#include "CMIO_DPA_Sample_Server_VCamInputStream.h"

namespace OBSVirtualCam
{
    
    class OBSVirtualCamDevice: public CMIO::DPA::Sample::Server::Device
	{

	public:
									OBSVirtualCamDevice();
		virtual						~OBSVirtualCamDevice();
	
	private:
		OBSVirtualCamDevice&					operator=(OBSVirtualCamDevice& that); // Don't allow copying
        
    public:
        CMIO::DPA::Sample::Server::VCamInputStream*            mInputStream;
        void						CreateStreams();
        size_t                      mFrameSize;
	};
}
#endif
