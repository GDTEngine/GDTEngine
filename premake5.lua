-- Solution --

workspace "GDTEngine"
	location "Generated"
	language "C++"
    architecture "x86_64"
    configurations { "Debug", "Release" }
    startproject "Engine"
	filter { "configurations:Debug" }
		symbols "On"
	
	filter { "configurations:Release" }
		optimize "On"
	
	filter { }
	targetdir ("Build/Bin/%{prj.name}/%{cfg.longname}")
    objdir ("Build/Obj/%{prj.name}/%{cfg.longname}")

-- Third Party --

function includeGLEW()
	includedirs "ThirdParty/GLEW/Include"
end	

function linkGLEW()
    filter { "system:windows", "architecture:x86_64", "configurations:Debug" }
        libdirs "ThirdParty/GLEW/Lib/Win64/Debug"
        
    filter { "system:windows", "architecture:x86_64", "configurations:Release" }
	    libdirs "ThirdParty/GLEW/Lib/Win64/Release"
    
    filter {}
	
	filter { "kind:not StaticLib" }
        links { "glews" }
        
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
    files { "Source/Core/**.hpp", "Source/Core/**.inl", "Source/Core/**.cpp" }

function includeCore()
    includedirs "Source/Core"
end

project "Graphics"
    kind "StaticLib"
    location "Source/Graphics"
    files { "Source/Graphics/**.hpp", "Source/Graphics/**.inl", "Source/Graphics/**.cpp" }

    includeCore()
    includeGLEW()
    includeGLFW()

function includeGraphics()
    includedirs "Source/Graphics"
end 

function linkGraphics()
    filter { "kind:not StaticLib", "system:windows" }
        links { "Graphics", "OpenGL32" }
    
    filter { "kind:not StaticLib", "system:not windows" }
        links { "Graphics", "GL" }
        
    filter {}

    includeGLEW()
    includeGLFW()

    linkGLEW()
    linkGLFW()
end

project "Engine"
    kind "ConsoleApp"
    location "Source/Engine"
    files { "Source/Engine/**.hpp", "Source/Engine/**.inl", "Source/Engine/**.cpp" }

    includeCore()
    includeGraphics()

    linkGraphics()