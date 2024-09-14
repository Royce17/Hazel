#pragma once
#include "Hazel/Window.h"
#include <GLFW/glfw3.h>

namespace Hazel
{
	class WindowsWindow :public Window
	{
	public:
		explicit WindowsWindow(WindowProps const& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		uint16_t GetWidth() const override { return m_Data.Width; }
		uint16_t GetHeight() const override { return m_Data.Height; }

		// Window attributes
		void SetEventCallback(EventCallbackFn const& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool const& enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(WindowProps const& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			uint16_t Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}


