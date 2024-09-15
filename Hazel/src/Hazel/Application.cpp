#include "hzpch.h"
#include "Application.h"

#include "Log.h"
#include "GLFW/glfw3.h"

namespace Hazel
{
	//#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
#define BIND_EVENT_FN(x) [this]<typename T0> (T0 && ph1) { return x(std::forward<T0>(ph1)); }

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		HZ_CORE_INFO("{0}", e);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running=false;
		return true;
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Window->OnUpdate();
		}
	}
}
