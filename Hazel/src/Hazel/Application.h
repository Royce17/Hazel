#pragma once
#include "core.h"

namespace Hazel {
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Defined in the client.
	Application* CreateApplication();
}

