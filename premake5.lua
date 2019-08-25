workspace "Recon"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include directories relative to root folder (solution directory)

IncludeDir = {}
IncludeDir["GLFW"] = "Recon/vendor/GLFW/include"
include "Recon/vendor/GLFW"

project "Recon"
	location "Recon"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "rcpch.h"
	pchsource "Recon/src/rcpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RC_PLATFORM_WINDOWS",
			"RC_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "RC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RC_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Recon/vendor/spdlog/include;",
		"Recon/src"
	}

	links
	{
		"Recon"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RC_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "RC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RC_DIST"
		optimize "On"