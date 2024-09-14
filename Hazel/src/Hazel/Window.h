#pragma once

#include "hzpch.h"

#include "Hazel/core.h"
#include "Hazel/Events/Event.h"

namespace Hazel
{
	struct WindowProps
	{
		std::string Title;
		uint16_t Width, Height;

		explicit WindowProps(std::string title = "Hazel Engine",
			uint16_t const& width = 1280,
			uint16_t const& height = 720)
			:Title(std::move(title)), Width(width), Height(height) {}
	};

	// Interface representing a desktop system based Window
	class HAZEL_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;
		virtual uint16_t GetWidth() const = 0;
		virtual uint16_t GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(EventCallbackFn const& callback) = 0;
		virtual void SetVSync(bool const& enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(WindowProps const& props = WindowProps());
	};
}
