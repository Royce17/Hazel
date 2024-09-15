#pragma once

#include "Event.h"
#include "hzpch.h"

namespace Hazel
{
	class HAZEL_API MouseMovedEvent :public Event
	{
	public:
		explicit MouseMovedEvent(double const& x, double const& y)
			:m_MouseX(x), m_MouseY(y) {}

		double GetX() const { return m_MouseX; }
		double GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		double m_MouseX, m_MouseY;
	};

	class HAZEL_API MouseScrolledEvent :public Event
	{
	public:
		explicit MouseScrolledEvent(double const& xOffset, double const& yOffset)
			:m_XOffset(xOffset), m_YOffset(yOffset) {}

		double GetXOffset() const { return m_XOffset; }
		double GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		double m_XOffset, m_YOffset;
	};

	class HAZEL_API MouseButtonEvent :public Event
	{
	public:
		int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		explicit MouseButtonEvent(int button)
			: m_Button(button) {}

		int m_Button;
	};

	class HAZEL_API MouseButtonPressedEvent :public MouseButtonEvent
	{
	public:
		explicit MouseButtonPressedEvent(int const& button)
			:MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class HAZEL_API MouseButtonReleasedEvent :public MouseButtonEvent
	{
	public:
		explicit MouseButtonReleasedEvent(int const& button)
			:MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
