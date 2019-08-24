#pragma once 
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Recon {

	class RECON_API Log {

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}


//Core Log Macros
#define RC_CORE_TRACE(...) ::Recon::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RC_CORE_INFO(...)  ::Recon::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RC_CORE_WARN(...)  ::Recon::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RC_CORE_ERROR(...) ::Recon::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RC_CORE_FATAL(...) ::Recon::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define RC_TRACE(...)      ::Recon::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RC_INFO(...)       ::Recon::Log::GetClientLogger()->info(__VA_ARGS__)
#define RC_WARN(...)       ::Recon::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RC_ERROR(...)      ::Recon::Log::GetClientLogger()->error(__VA_ARGS__)
#define RC_FATAL(...)      ::Recon::Log::GetClientLogger()->fatal(__VA_ARGS__)

