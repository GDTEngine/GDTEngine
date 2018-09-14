-- Solution --

workspace "GDTEngine"
	location "Generated"
	language "C++"
	architecture "x86_64"
	configurations { "Debug", "Release" }
	filter { "configurations:Debug" }
		flags { "Symbols" }
	
	filter { "configurations:Release" }
		optimize "On"
	
	filter { }
	targetdir ("Build/Bin/%{prj.name}/%{cfg.longname}")
    objdir ("Build/Obj/%{prj.name}/%{cfg.longname}")

-- Third Party --

function includeGLFW()
	includedirs "ThirdParty/GLFW/Include"
end	

function linkGLFW()
	libdirs "ThirdParty/GLFW/Lib"
	
	filter { "kind:not StaticLib" }
		links { "glfw3" }
	filter {}
end

function includeGLEW()
	includedirs "ThirdParty/GLFW/Include"
end	

function linkGLEW()
	libdirs "ThirdParty/GLFW/Lib"
	
	filter { "kind:not StaticLib" }
		links { "glfw3" }
	filter {}
end

-- Source --

project "Graphics"
    kind "StaticLib"
    files "Source/Graphics/**"
    includeGLFW()

function includeGraphics()
    include "Source/Graphics/"
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
    files "Source/Engine/**"

    includeGraphics()

    linkGraphics()