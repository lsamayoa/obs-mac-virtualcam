#if !defined(__OBSVirtualCamServer_h__)
#define __OBSVirtualCamServer_h__

#include "CMIO_DPA_Sample_Server_Assistant.h"

namespace OBSVirtualCam
{
    class OBSVirtualCamServer: public CMIO::DPA::Sample::Server::Assistant
	{
	public:
									OBSVirtualCamServer();
        
    private:
        void                            CreateDevices();
	};
}
#endif
