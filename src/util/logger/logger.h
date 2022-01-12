#pragma once 

// Define SPDLOG_ACTIVE_LEVEL before including spdlog.h
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Wave
{
	namespace Log
	{
		void Init();
		void Shutdown();
	};
}

#ifdef _DEBUG
#define TRACE(...)		SPDLOG_TRACE(__VA_ARGS__)
#define DEBUG(...)		SPDLOG_DEBUG(__VA_ARGS__)
#define INFO(...)		SPDLOG_INFO(__VA_ARGS__)
#else
#define TRACE(...)
#define DEBUG(...)
#define INFO(...)
#endif
#define WARN(...)		SPDLOG_WARN(__VA_ARGS__)
#define ERROR(...)		SPDLOG_ERROR(__VA_ARGS__)
#define CRITICAL(...)	SPDLOG_CRITICAL(__VA_ARGS__)
