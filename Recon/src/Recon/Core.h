#pragma once

#ifdef RC_PLATFORM_WINDOWS
#ifdef RC_BUILD_DLL
#define RECON_API __declspec(dllexport)
#else
#define RECON_API __declspec(dllimport)
#endif
#endif