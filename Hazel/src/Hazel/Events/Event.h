#pragma once

#include "hzpch.h"
#include "Hazel/core.h"

namespace Hazel
{
	// Status:
	// Currently an occured event will immediately be dispatched
	// and must be dealt with right then.
	// Feature Request:
	// For the future, a better strategy might be to buffer events in an event queue 
	// and process them during the "event" part of the update stage.

	enum class EventType :uint8_t
	{
		None = 0,
		WindowOpen, WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
	};

	enum EventCategory :uint8_t
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		// EventCategoryMouseButton = BIT(4),
		// [学习] 这里不用 enum class 是因为其不方便用做 Bit mask。
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
							   virtual EventType GetEventType() const override { return GetStaticType(); }\
							   virtual char const* GetName() const override { return #type; }
#define EVENT_CLASS_CATEGORY(category) virtual uint8_t GetCategoryFlags() const override { return category; }

	class HAZEL_API Event
	{
		friend class EventDispatcher;
	public:
		bool Handled{ false };

		virtual EventType GetEventType() const = 0;
		virtual char const* GetName() const = 0;
		virtual uint8_t GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool IsInCategory(EventCategory const& category) const
		{
			return GetCategoryFlags() & std::to_underlying(category);
		}
	};

	// [学习] C++20 约束
	template<typename T>
	concept IsEventType = std::is_base_of_v<Event, T>;

	class EventDispatcher
	{
		template<typename T> requires IsEventType<T>
		using EventFn = std::function<bool(T&)>;
	public:
		explicit EventDispatcher(Event& event)
			:m_Event(event) {}

		template<typename T> requires IsEventType<T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(*static_cast<T*>(&m_Event));
				return true;
			}
			return false;
		}

		// [学习]：引用类型的数据成员一旦被绑定到某个对象，就不能更改其引用的对象。复制赋值操作会要求重新绑定引用，而这是不允许的，因为引用一旦初始化就不能重新绑定到另一个对象。
		//EventDispatcher& operator=(const EventDispatcher& other) = delete;

	private:
		Event& m_Event;
	};

	inline std::string format_as(Event const& e) { return e.ToString(); }
}
