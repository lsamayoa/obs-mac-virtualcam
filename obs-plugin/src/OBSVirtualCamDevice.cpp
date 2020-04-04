#include "OBSVirtualCamDevice.h"
#include "CAHostTimeBase.h"

namespace OBSVirtualCam
{
	OBSVirtualCamDevice::OBSVirtualCamDevice() :
        CMIO::DPA::Sample::Server::Device()
	{
		CreateStreams();
        mFrameSize = 720 * 480 * 2;
	}
	
	OBSVirtualCamDevice::~OBSVirtualCamDevice()
	{
	}

	void OBSVirtualCamDevice::CreateStreams()
	{
        UInt32 streamID = 0;
        
        CACFDictionary format;
        format.AddUInt32(CFSTR(kIOVideoStreamFormatKey_CodecType), CMIO::DPA::Sample::FrameType::kYUV422_720x480);
        format.AddUInt32(CFSTR(kIOVideoStreamFormatKey_CodecFlags), kSampleCodecFlags_30fps | kSampleCodecFlags_1001_1000_adjust);
        format.AddUInt32(CFSTR(kIOVideoStreamFormatKey_Width), 720);
        format.AddUInt32(CFSTR(kIOVideoStreamFormatKey_Height), 480);

        CACFArray formats;
        formats.AppendDictionary(format.GetDict());

        CACFDictionary streamDict;
        streamDict.AddArray(CFSTR(kIOVideoStreamKey_AvailableFormats), formats.GetCFArray());
        streamDict.AddUInt32(CFSTR(kIOVideoStreamKey_StartingDeviceChannelNumber), 1);

        mInputStream = new CMIO::DPA::Sample::Server::VCamInputStream(this, streamDict.GetDict(), kCMIODevicePropertyScopeInput);
        mInputStreams[streamID] = mInputStream;
    }
}
