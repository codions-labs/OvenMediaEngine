//
// Created by getroot on 19. 12. 9.
//

#include "rtspc_application.h"
#include "rtspc_stream.h"

#define OV_LOG_TAG "RtspcApplication"

namespace pvd
{
	std::shared_ptr<RtspcApplication> RtspcApplication::Create(const info::Application &application_info)
	{
		auto application = std::make_shared<RtspcApplication>(application_info);

		application->Start();

		return application;
	}

	RtspcApplication::RtspcApplication(const info::Application &info)
			: Application(info)
	{

	}

	RtspcApplication::~RtspcApplication()
	{

	}

	std::shared_ptr<pvd::Stream> RtspcApplication::CreateStream(const ov::String &stream_name, const std::vector<ov::String> &url_list)
	{
		logtd("OnCreateStream");
		auto stream = RtspcStream::Create(GetSharedPtrAs<pvd::Application>(), stream_name, url_list);
		return stream;
	}

	bool RtspcApplication::Start()
	{
		return pvd::Application::Start();
	}

	bool RtspcApplication::Stop()
	{
		return pvd::Application::Stop();
	}
}