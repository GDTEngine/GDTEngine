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
        defines { "GDT_DEBUG" }

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

-- Third Party --

function includeGLM()
    includedirs "ThirdParty/GLM/Include"
end

function includeGLEW()
    defines { "GLEW_STATIC" }
	includedirs "ThirdParty/GLEW/Include"
end	

function linkGLEW()
    filter { "system:windows", "architecture:x86_64", "configurations:Debug" }
        libdirs "ThirdParty/GLEW/Lib/Win64/Debug"
        
    filter { "system:windows", "architecture:x86_64", "configurations:Release" }
	    libdirs "ThirdParty/GLEW/Lib/Win64/Release"
    
    filter {}
	
	filter { "kind:not StaticLib" }
        links { "glew32s", "opengl32" }
        
	filter {}
end

function includeGLFW()
	includedirs "ThirdParty/GLFW/Include"
end	

function linkGLFW()
    filter { "system:windows", "architecture:x86_64", "configurations:Debug" }
        libdirs "ThirdParty/GLFW/Lib/Win64/Debug"
        
    filter { "system:windows", "architecture:x86_64", "configurations:Release" }
	    libdirs "ThirdParty/GLFW/Lib/Win64/Release"

    filter {}

	filter { "kind:not StaticLib" }
        links { "glfw3" }
        
	filter {}
end

-- Source --

project "Core"
    kind "None"
    location "Source/Core"
    files { "Source/Core/**.hpp", "Source/Core/**.inl", "Source/Core/**.cpp", }

    includeGLM()

function includeCore()
    includedirs "Source/Core"
end

project "Graphics"
    kind "StaticLib"
    location "Source/Graphics"
    files { "Source/Graphics/**.hpp", "Source/Graphics/**.inl", "Source/Graphics/**.cpp" }
    excludes { "Source/Graphics/UnitTest/**" }

    includeGLM()
    includeGLEW()
    includeGLFW()

    includeCore()

function includeGraphics()
    includedirs "Source/Graphics"
end 

function linkGraphics()
    filter { "kind:not StaticLib", "system:windows" }
        links { "Graphics" }
    
    filter { "kind:not StaticLib", "system:not windows" }
        links { "Graphics" }

    filter {}

    linkGLEW()
    linkGLFW()
end

project "Engine"
    kind "StaticLib"
    location "Source/Engine"
    files { "Source/Engine/**.hpp", "Source/Engine/**.inl", "Source/Engine/**.cpp" }

    includeGLM()
    includeGLEW()
    includeGLFW()

    includeCore()
    includeGraphics()

    linkGraphics()

project "Editor"
    kind "StaticLib"
    location "Source/Editor"

project "Main"
    kind "ConsoleApp"
    location "Source/Main"
    files { "Source/Main/**.hpp", "Source/Main/**.inl", "Source/Main/**.cpp" }


project "Graphics_UnitTest"
    kind "ConsoleApp"
    files {
        "Source/Graphics/UnitTest/**.cpp",
        "Source/Graphics/UnitTest/**.hpp",
        "ThirdParty/googletest-release-1.8.1/googletest/src/gtest-all.cc",
        "ThirdParty/googletest-release-1.8.1/googlemock/src/gmock_main.cc",
        "ThirdParty/googletest-release-1.8.1/googlemock/src/gmock-all.cc" 
    }
    location "Source/Graphics/UnitTest"
    includedirs {
      "ThirdParty/googletest-release-1.8.1/googletest/include",
      "ThirdParty/googletest-release-1.8.1/googletest/src",
      "ThirdParty/googletest-release-1.8.1/googlemock/include",
      "ThirdParty/googletest-release-1.8.1/googletest/src"
    }
    includeCore()
    linkGraphics()
