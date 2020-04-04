/*
	    File: CMIO_DPA_Sample_Server_VCamInputStream.h
	Abstract: n/a
	 Version: 1.2
	
*/

#if !defined(__CMIO_DPA_Sample_Server_VCamInputStream_h__)
#define __CMIO_DPA_Sample_Server_VCamInputStream_h__

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//	Includes
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "CMIO_DPA_Sample_Server_Stream.h"


#include <functional>

class Defer {
public:
    Defer(std::function<void()> deferredFunc): _deferredFunc(deferredFunc) {}
    ~Defer() { _deferredFunc(); }
private:
    std::function<void()> _deferredFunc;
};

#define _CONCAT(x, y) x ## y
#define _CONCAT2(x, y) _CONCAT(x, y)
#define DEFER(...) Defer _CONCAT2(_defer, __LINE__)( __VA_ARGS__ );

namespace CMIO { namespace DPA { namespace Sample { namespace Server
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	// VCamInputStream
	//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    class VCamInputStream: public Stream
	{
	// Construction/Destruction
    public:
                                        VCamInputStream(Device* device, CFDictionaryRef streamDictionary, CMIOObjectPropertyScope scope);

	private:
		VCamInputStream&				operator=(VCamInputStream& that); // Don't allow copying

    // Format & Frame Rate
    protected:
        void							SetStreamFormat(IOVideoStreamDescription *newStreamFormat) override;

	// Management
	public:
        virtual void                    Start(Client client, mach_port_t messagePort, UInt32 initialDiscontinuityFlags) override;
        virtual void                    Stop(Client client) override;

        void							FrameArrived(size_t frameSize, uint8_t* frameData, UInt64 vbiTime);
	};
    
}}}}
#endif
