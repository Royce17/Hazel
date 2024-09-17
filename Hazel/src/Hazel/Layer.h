#pragma once

#include "hzpch.h"
#include "Events/Event.h"

namespace Hazel
{
	class HAZEL_API Layer
	{
	public:
		explicit Layer(std::string const& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach();
		virtual void OnDetach();
		virtual void OnUpdate();
		virtual void OnEvent(Event& event);

		std::string const& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};
}
