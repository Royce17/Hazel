#pragma once
#include "core.h"
#include "Window.h"
#include "Layer.h"
#include "LayerStack.h"
#include "Events/ApplicationEvent.h"

namespace Hazel {
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		void PopOverlay(Layer* layer);
		static Application* Get() { return s_Instance; }
		Window& GetWindow() const { return *m_Window; }
	private:
		static Application* s_Instance;
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// Defined in the client.
	Application* CreateApplication();
}

