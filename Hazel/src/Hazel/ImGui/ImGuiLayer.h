#pragma once
#include "Hazel/Layer.h"

namespace Hazel
{
	class HAZEL_API ImGuiLayer :public Layer
	{
	public:
		explicit ImGuiLayer();
		~ImGuiLayer() override;

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;

	private:
		float m_Time{ 0.0f };
	};
}
