#include <obs-module.h>
#include <obs.hpp>
#include <pthread.h>

#include <servers/bootstrap.h>

#include "CMIODPASampleServer.h"
#include "CMIO_DPA_Sample_Server_VCamAssistant.h"
#include "CMIO_DPA_Sample_Server_VCamDevice.h"
#include "CMIO_DPA_Sample_Server_VCamInputStream.h"
#include "CAHostTimeBase.h"

CMIO::DPA::Sample::Server::VCamDevice *virtualCamDevice;

boolean_t MessagesAndNotifications(mach_msg_header_t* request, mach_msg_header_t* reply)
{
    // Invoke the MIG created CMIODPASampleServer() to see if this is one of the client messages it handles
    boolean_t processed = CMIODPASampleServer(request, reply);
    
    // If CMIODPASampleServer() did not process the message see if it is a MACH_NOTIFY_NO_SENDERS notification
    if (not processed and MACH_NOTIFY_NO_SENDERS == request->msgh_id)
    {
        CMIO::DPA::Sample::Server::VCamAssistant::Instance()->ClientDied(request->msgh_local_port);
        processed = true;
    }
    
    return processed;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// main()
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void *virtualCamMain(void *)
{
    DebugMessage("starting up");

    // Don't allow any exceptions to escape
	try
	{
		// Check in with the bootstrap port under the agreed upon name to get the servicePort with receive rights
		mach_port_t servicePort;
		name_t serviceName = "com.apple.cmio.DPA.SampleVCam";
		kern_return_t err = bootstrap_check_in(bootstrap_port, serviceName, &servicePort);
		if (BOOTSTRAP_SUCCESS != err)
		{
			DebugMessage("bootstrap_check_in() failed: 0x%x", err);
            return NULL;
//			exit(43);
		}

		// Add the service port to the Assistant's port set
		mach_port_t portSet = CMIO::DPA::Sample::Server::VCamAssistant::Instance()->GetPortSet();
        virtualCamDevice = dynamic_cast<CMIO::DPA::Sample::Server::VCamDevice*>(*(CMIO::DPA::Sample::Server::VCamAssistant::Instance()->mDevices.begin()));
		err = mach_port_move_member(mach_task_self(), servicePort, portSet);
		if (KERN_SUCCESS != err)
		{
			DebugMessage("Unable to add service port to port set: 0x%x", err);
            return NULL;
//			exit(2);
		}

		// Service incoming messages from the clients and notifications which were signed up for
		while (true)
		{
			(void) mach_msg_server(MessagesAndNotifications, 8192, portSet, MACH_MSG_OPTION_NONE);
		}
	}
	catch (const CAException& exception)
	{
        return NULL;
//        exit(exception.GetError());
	}
	catch (...)
	{
		DebugMessage("Terminated by an an unknown exception");
        return NULL;
//		exit(44);
	}
}


OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE("mac-virtualcam", "en-US")
MODULE_EXPORT const char *obs_module_description(void)
{
	return "macOS virtual webcam output";
}

obs_output_t *output;

static const char *virtualcam_output_get_name(void *type_data)
{
    (void)type_data;
    return obs_module_text("macOS Virtual Webcam");
}

static void *virtualcam_output_create(obs_data_t *settings, obs_output_t *output)
{
    blog(LOG_DEBUG, "VIRTUALCAM output_create");
}

static void virtualcam_output_destroy(void *data)
{
    blog(LOG_DEBUG, "VIRTUALCAM output_destroy");
}

static bool virtualcam_output_start(void *data)
{
    blog(LOG_DEBUG, "VIRTUALCAM output_start");
    pthread_t thread1;
    pthread_create(&thread1, NULL, virtualCamMain, (void *)"Thread 1");

    // TODO(johnboiles): Right now we're hardcoded for 720x480 but that should probably change
    struct video_scale_info conversion = {};
    conversion.format = VIDEO_FORMAT_UYVY;
    conversion.width = 720;
    conversion.height = 480;
    obs_output_set_video_conversion(output, &conversion);
    if (!obs_output_begin_data_capture(output, 0)) {
        return false;
    }

    return true;
}

static void virtualcam_output_stop(void *data, uint64_t ts)
{
    blog(LOG_DEBUG, "VIRTUALCAM output_stop");
    obs_output_end_data_capture(output);
}

static void virtualcam_output_raw_video(void *data, struct video_data *frame)
{
    uint8_t *outData = frame->data[0];
    UInt64 vbiTime = CAHostTimeBase::GetCurrentTimeInNanos();
    virtualCamDevice->mInputStream->FrameArrived(virtualCamDevice->mFrameSize, outData, vbiTime);
}

struct obs_output_info virtualcam_output_info = {
    .id = "virtualcam_output",
    .flags = OBS_OUTPUT_VIDEO,
    .get_name = virtualcam_output_get_name,
    .create = virtualcam_output_create,
    .destroy = virtualcam_output_destroy,
    .start = virtualcam_output_start,
    .stop = virtualcam_output_stop,
    .raw_video = virtualcam_output_raw_video,
};

void start()
{
    OBSData settings;
    output = obs_output_create("virtualcam_output", "virtualcam_output", settings, NULL);
    bool started = obs_output_start(output);
    obs_data_release(settings);
}

bool obs_module_load(void)
{
    blog(LOG_DEBUG, "LOADING VIRTUALCAM");
    obs_register_output(&virtualcam_output_info);

    start();
    
    return true;
}
