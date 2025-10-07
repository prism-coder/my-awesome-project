workspace "MyEpicProject"
    architecture "x86_64"
    startproject "MyEpicProject"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

    flags {
		"MultiProcessorCompile"
	}

    filter "system:windows"
        buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus", "/utf-8" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "MyEpicProject"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++latest"
    staticruntime "on"
   
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "Source/**.h",
        "Source/**.cpp"
    }

    includedirs {
        "Source"
    }

    filter "system:windows"
        systemversion "latest"
        defines { "PC_PLATFORM_WINDOWS" }

    filter "configurations:Debug"
        defines { "PC_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "PC_RELEASE" }
        runtime "Release"
        optimize "On"
        symbols "On"

    filter "configurations:Dist"
        kind "WindowedApp"
        defines { "PC_DIST" }
        runtime "Release"
        optimize "On"
        symbols "Off"