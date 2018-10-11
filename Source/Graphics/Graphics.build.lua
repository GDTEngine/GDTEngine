group "Engine"
project "Graphics"
    kind "SharedLib"
    location ""

    defines { "GRAPHICS_DLL_EXPORT" }
    
    files {
        "**.hpp",
        "**.inl",
        "**.cpp",
        "Graphics.build.lua"
    }

    excludes { "UnitTest/**" }

    includedirs {
        "../../ThirdParty/GLFW/Include",
        "../../ThirdParty/GLEW/Include",
        "../../ThirdParty/GLM/Include",
        "../Core"
    }

    filter { "system:windows", "architecture:x86_64", "configurations:Debug" }
        libdirs {
            "../../ThirdParty/GLFW/Lib/Win64/Debug",
            "../../ThirdParty/GLEW/Lib/Win64/Debug"
        }

    filter { "system:windows", "architecture:x86_64", "configurations:Release" }
        libdirs {
            "../../ThirdParty/GLFW/Lib/Win64/Release",
            "../../ThirdParty/GLEW/Lib/Win64/Release"
        }

    filter {}

    linkCore()

function linkGraphics()
    filter { "kind:not StaticLib", "system:windows" }
        links { "Graphics" }
    
    filter { "kind:not StaticLib", "system:not windows" }
        links { "Graphics" }

    filter {}
    linkCore()
end