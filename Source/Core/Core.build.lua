group "Engine"
project "Core"
    kind "SharedLib"
    location ""

    defines { "CORE_DLL_EXPORT" }

    files {
        "**.hpp",
        "**.inl",
        "**.cpp",
        "Core.build.lua"
    }

    excludes { "UnitTest/**" }

    includedirs {
        "../../ThirdParty/GLFW/Include",
        "../../ThirdParty/GLEW/Include",
        "../../ThirdParty/GLM/Include"
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

    linkGLEW()
    linkGLFW()


function linkCore()
    filter { "kind:not StaticLib", "system:windows" }
        links { "Core" }

    filter { "kind:not StaticLib", "system:not windows" }
        links { "Core" }

    filter {}

    linkGLEW()
    linkGLFW()
end