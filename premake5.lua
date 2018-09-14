-- Solution --

workspace "GDTEngine"
	location "Generated"
	language "C++"
	architecture "x86_64"
	configurations { "Debug", "Release" }
	filter { "configurations:Debug" }
		symbols "On"
	
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
    filter { "system:windows", "architecture:x86_64", "configurations:Debug" }
        libdirs "ThirdParty/GLFW/Lib/Win64/Debug"
        
    filter { "system:windows", "architecture:x86_64", "configurations:Release" }
	    libdirs "ThirdParty/GLFW/Lib/Win64/Release"
    
    filter {}

	filter { "kind:not StaticLib" }
        links { "glfw3" }
        
	filter {}
end

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
        links { "glfw3" }
        
	filter {}
end

-- Source --

project "Graphics"
    kind "StaticLib"
    location "Source/Graphics"
    files "Source/Graphics/**"
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
    files "Source/Engine/**"

    includeGraphics()

    linkGraphics()