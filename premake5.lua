-- Utility --

function os.winSdkVersion()
    local reg_arch = iif( os.is64bit(), "\\Wow6432Node\\", "\\" )
    local sdk_version = os.getWindowsRegistry( "HKLM:SOFTWARE" .. reg_arch .."Microsoft\\Microsoft SDKs\\Windows\\v10.0\\ProductVersion" )
    if sdk_version ~= nil then return sdk_version end
end

-- Solution --

workspace "GDTEngine"
	location "Generated"
    language "C++"
    architecture "x86_64"
    configurations { "Debug_Editor", "Debug", "Release_Editor", "Release" }
    startproject "Engine"

    filter { "configurations:Debug_Editor" }
        symbols "On"
        defines { "GDT_EDITOR", "GDT_DEBUG" }

	filter { "configurations:Debug" }
        symbols "On"
        defines { "GLEW_STATIC", "GDT_DEBUG" }

    filter { "configurations:Release_Editor" }
        optimize "On"
        defines { "GDT_EDITOR", "GDT_RELEASE"}
	
	filter { "configurations:Release" }
        optimize "On"
        defines { "GDT_RELEASE"}
	
    filter {}
    
    filter {"system:windows", "action:vs*"}
        systemversion(os.winSdkVersion() .. ".0")

    filter {}

	targetdir ("Build/Bin/%{prj.name}/%{cfg.longname}")
    objdir ("Build/Obj/%{prj.name}/%{cfg.longname}")

    -- Third party.
    include "ThirdParty/ThirdParty.build.lua"

    -- Core.
    include "Source/Core/Core.build.lua"

    -- Graphics.
    include "Source/Graphics/Graphics.build.lua"

    -- Engine.
    include "Source/Engine/Engine.build.lua"

    -- Editor.
    include "Source/Editor/Editor.build.lua"

    -- Main.
    include "Source/Main/Main.build.lua"

group "UnitTests"
project "UnitTest_Core"
    kind "ConsoleApp"
    location "Source/Core/UnitTest"

    files {
        "Source/Core/UnitTest/**.cpp",
        "Source/Core/UnitTest/**.hpp",
        "ThirdParty/googletest-release-1.8.1/googletest/src/gtest-all.cc",
        "ThirdParty/googletest-release-1.8.1/googlemock/src/gmock_main.cc",
        "ThirdParty/googletest-release-1.8.1/googlemock/src/gmock-all.cc" 
    }

    includedirs {
        "ThirdParty/googletest-release-1.8.1/googletest/include",
        "ThirdParty/googletest-release-1.8.1/googletest/src",
        "ThirdParty/googletest-release-1.8.1/googlemock/include",
        "ThirdParty/googletest-release-1.8.1/googletest/src",
        "ThirdParty/GLFW/Include",
        "ThirdParty/GLEW/Include",
        "ThirdParty/GLM/Include",
        "Source/Core"
    }

    filter { "system:windows", "architecture:x86_64", "configurations:Debug" }
        libdirs {
            "ThirdParty/GLFW/Lib/Win64/Debug",
            "ThirdParty/GLEW/Lib/Win64/Debug"
        }

    filter { "system:windows", "architecture:x86_64", "configurations:Release" }
        libdirs {
            "ThirdParty/GLFW/Lib/Win64/Release",
            "ThirdParty/GLEW/Lib/Win64/Release"
        }

    filter{}


    linkCore()

group "UnitTests"
project "UnitTest_Graphics"
    kind "ConsoleApp"
    location "Source/Graphics/UnitTest"

    files {
        "Source/Graphics/UnitTest/**.cpp",
        "Source/Graphics/UnitTest/**.hpp",
        "ThirdParty/googletest-release-1.8.1/googletest/src/gtest-all.cc",
        "ThirdParty/googletest-release-1.8.1/googlemock/src/gmock_main.cc",
        "ThirdParty/googletest-release-1.8.1/googlemock/src/gmock-all.cc",
    }

    includedirs {
        "ThirdParty/googletest-release-1.8.1/googletest/include",
        "ThirdParty/googletest-release-1.8.1/googletest/src",
        "ThirdParty/googletest-release-1.8.1/googlemock/include",
        "ThirdParty/googletest-release-1.8.1/googletest/src",
        "ThirdParty/GLFW/Include",
        "ThirdParty/GLEW/Include",
        "ThirdParty/GLM/Include",
        "Source/Core",
        "Source/Graphics"
    }

    filter { "system:windows", "architecture:x86_64", "configurations:Debug" }
        libdirs {
            "ThirdParty/GLFW/Lib/Win64/Debug",
            "ThirdParty/GLEW/Lib/Win64/Debug"
        }

    filter { "system:windows", "architecture:x86_64", "configurations:Release" }
        libdirs {
            "ThirdParty/GLFW/Lib/Win64/Release",
            "ThirdParty/GLEW/Lib/Win64/Release"
        }

    filter{}

    linkGraphics()

group "UnitTests"
project "UnitTest_Engine"
    kind "ConsoleApp"
    location "Source/Engine/UnitTest"

    files {
        "Source/Engine/UnitTest/**.cpp",
        "Source/Engine/UnitTest/**.hpp",
        "ThirdParty/googletest-release-1.8.1/googletest/src/gtest-all.cc",
        "ThirdParty/googletest-release-1.8.1/googlemock/src/gmock_main.cc",
        "ThirdParty/googletest-release-1.8.1/googlemock/src/gmock-all.cc" 
    }

    includedirs {
        "ThirdParty/googletest-release-1.8.1/googletest/include",
        "ThirdParty/googletest-release-1.8.1/googletest/src",
        "ThirdParty/googletest-release-1.8.1/googlemock/include",
        "ThirdParty/googletest-release-1.8.1/googletest/src",
        "ThirdParty/GLFW/Include",
        "ThirdParty/GLEW/Include",
        "ThirdParty/GLM/Include",
        "Source/Core",
        "Source/Graphics",
        "Source/Engine"
    }

    filter { "system:windows", "architecture:x86_64", "configurations:Debug" }
        libdirs {
            "ThirdParty/GLFW/Lib/Win64/Debug",
            "ThirdParty/GLEW/Lib/Win64/Debug"
        }

    filter { "system:windows", "architecture:x86_64", "configurations:Release" }
        libdirs {
            "ThirdParty/GLFW/Lib/Win64/Release",
            "ThirdParty/GLEW/Lib/Win64/Release"
        }

    filter{}

    linkEngine()

group "Examples"
project "SpaceShooter"
    kind "SharedLib"
    location "Source/SpaceShooter"
    files { "Source/SpaceShooter/**.hpp", "Source/SpaceShooter/**.inl", "Source/SpaceShooter/**.cpp" }
    targetdir ("Source/Main/Plugins")
    defines { "GDT_PLUGIN_DLL_EXPORT" }
    
    includedirs {
        "Source/Core",
        "Source/Graphics",
        "Source/Engine"
    }

    filter { "system:windows", "architecture:x86_64", "configurations:Debug" }
        libdirs {
            "ThirdParty/GLFW/Lib/Win64/Debug",
            "ThirdParty/GLEW/Lib/Win64/Debug"
        }

    filter { "system:windows", "architecture:x86_64", "configurations:Release" }
        libdirs {
            "ThirdParty/GLFW/Lib/Win64/Release",
            "ThirdParty/GLEW/Lib/Win64/Release"
        }
    
    linkEngine()