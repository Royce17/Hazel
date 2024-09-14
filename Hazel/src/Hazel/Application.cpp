#include "hzpch.h"
#include "Application.h"

#include "Log.h"
#include "Events/ApplicationEvent.h"

namespace Hazel
{
	Application::Application() = default;

	Application::~Application() = default;

	void Application::Run()
	{
		WindowResizeEvent e(1200,800);
		HZ_CLIENT_TRACE(e);

		while (true);
	}
}
