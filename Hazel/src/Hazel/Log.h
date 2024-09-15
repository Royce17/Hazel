#pragma once

#include "core.h"
#include "spdlog/spdlog.h"

namespace Hazel
{
	class HAZEL_API Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// [学习] ::Hazel 中的前缀 :: 是一个全局作用域解析运算符（global scope resolution operator）。它用于确保对 Hazel 命名空间的访问始终从全局作用域开始，而不是从当前的命名空间或局部作用域中查找。

// Core log macros
#define HZ_CORE_TRACE(...)    ::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)     ::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)     ::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)    ::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_CRITICAL(...) ::Hazel::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define HZ_CLIENT_TRACE(...)    ::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_CLIENT_INFO(...)     ::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_CLIENT_WARN(...)     ::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_CLIENT_ERROR(...)    ::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_CLIENT_CRITICAL(...) ::Hazel::Log::GetClientLogger()->critical(__VA_ARGS__)