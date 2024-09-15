#include "hzpch.h"
#include "Window.h"

#ifdef HZ_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Hazel
{
	Window* Window::Create(WindowProps const& props)
	{
#ifdef HZ_PLATFORM_WINDOWS
		return new WindowsWindow(props);
#endif
	}
}
