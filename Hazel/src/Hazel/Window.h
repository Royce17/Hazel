#pragma once

#include "hzpch.h"

#include "Hazel/core.h"
#include "Hazel/Events/Event.h"

namespace Hazel
{
	struct WindowProps
	{
		std::string Title;
		int Width, Height;

		explicit WindowProps(std::string title = "Hazel Engine",
			int const& width = 1280,
			int const& height = 720)
			:Title(std::move(title)), Width(width), Height(height) {}
	};

	// Interface representing a desktop system based Window
	class HAZEL_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(EventCallbackFn const& callback) = 0;
		virtual void SetVSync(bool const& enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(WindowProps const& props = WindowProps());
	};
}
