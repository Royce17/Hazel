#pragma once
#include "core.h"
#include "Window.h"

namespace Hazel {
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// Defined in the client.
	Application* CreateApplication();
}

