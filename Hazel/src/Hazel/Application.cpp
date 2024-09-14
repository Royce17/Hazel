#include "hzpch.h"
#include "Application.h"

#include "Log.h"
#include "GLFW/glfw3.h"

namespace Hazel
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() = default;

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
