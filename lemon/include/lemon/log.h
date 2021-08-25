#pragma once

#include "spdlog/spdlog.h"

constexpr auto LEMON_DEFAULT_LOGGER_NAME = "lemonlogger";

#if defined(LEMON_PLATFORM_WINDOWS)
#define LEMON_BREAK __debugbreak();
#elif defined(LEMON_PLATFORM_MAC)
#define LEMON_BREAK __builtin_debugtrap();
#else 
#define LEMON_BREAK __builtin_trap();
#endif

#ifndef LEMON_CONFIG_RELEASE
#define LEMON_TRACE(...)	if(spdlog::get(LEMON_DEFAULT_LOGGER_NAME) != nullptr) { spdlog::get(LEMON_DEFAULT_LOGGER_NAME)->trace(__VA_ARGS__); }
#define LEMON_DEBUG(...)	if(spdlog::get(LEMON_DEFAULT_LOGGER_NAME) != nullptr) { spdlog::get(LEMON_DEFAULT_LOGGER_NAME)->debug(__VA_ARGS__); }
#define LEMON_INFO(...)		if(spdlog::get(LEMON_DEFAULT_LOGGER_NAME) != nullptr) { spdlog::get(LEMON_DEFAULT_LOGGER_NAME)->info(__VA_ARGS__); }
#define LEMON_WARN(...)     if(spdlog::get(LEMON_DEFAULT_LOGGER_NAME) != nullptr) { spdlog::get(LEMON_DEFAULT_LOGGER_NAME)->warn(__VA_ARGS__); }
#define LEMON_ERROR(...)	if(spdlog::get(LEMON_DEFAULT_LOGGER_NAME) != nullptr) { spdlog::get(LEMON_DEFAULT_LOGGER_NAME)->error(__VA_ARGS__); }
#define LEMON_FATAL(...)	if(spdlog::get(LEMON_DEFAULT_LOGGER_NAME) != nullptr) { spdlog::get(LEMON_DEFAULT_LOGGER_NAME)->critical(__VA_ARGS__); }

#define LEMON_ASSERT(x, msg) if((x)) {} else { LEMON_FATAL("ASSERT - {}\n\t{}\n\tin file: {}\n\ton line: {}", #x, msg, __FILE__, __LINE__); LEMON_BREAK }
#else
// Disable logging for release builds
#define LEMON_TRACE(...)		(void)0
#define LEMON_TRACE(...)		(void)0
#define LEMON_DEBUG(...)		(void)0
#define LEMON_INFO(...)			(void)0
#define LEMON_WARN(...)      	(void)0
#define LEMON_ERROR(...)		(void)0
#define LEMON_FATAL(...)		(void)0
#endif