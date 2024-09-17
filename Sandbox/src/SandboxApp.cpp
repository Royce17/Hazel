#include "Hazel.h"

class ExampleLayer :public Hazel::Layer
{
public:
	explicit ExampleLayer()
		:Layer("Example") {}

	void OnUpdate() override
	{
		HZ_CLIENT_INFO("ExampleLayer::OnUpdate()");
	}
	void OnEvent(Hazel::Event& event) override
	{
		HZ_CLIENT_TRACE("{0}", event);
	}
};

class Sandbox :public Hazel::Application
{
public:
	explicit Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}