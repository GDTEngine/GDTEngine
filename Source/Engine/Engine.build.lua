group "Engine"
project "Engine"
    kind "SharedLib"
    location ""

    defines { "ENGINE_DLL_EXPORT" }

    files {
        "**.hpp",
        "**.inl",
        "**.cpp",
        "Engine.build.lua"
    }

    excludes { "UnitTest/**" }

    includedirs {
        "../../ThirdParty/GLEW/Include",
        "../../ThirdParty/GLFW/Include",
        "../../ThirdParty/GLM/Include",
        "../../ThirdParty/Mono/Include",
        "../../ThirdParty/imgui/",
        "../Core",
        "../Graphics",
        "../Engine",
    }

    filter { "system:windows", "architecture:x86_64", "configurations:Debug" }
        libdirs {
            "../../ThirdParty/GLFW/Lib/Win64/Debug",
            "../../ThirdParty/GLEW/Lib/Win64/Debug",
            "../../ThirdParty/Mono/Lib/Win64/Debug"
        }

    filter { "system:windows", "architecture:x86_64", "configurations:Release" }
        libdirs {
            "../../ThirdParty/GLFW/Lib/Win64/Release",
            "../../ThirdParty/GLEW/Lib/Win64/Release",
            "../../ThirdParty/Mono/Lib/Win64/Release"
        }

    filter {}

    linkGraphics()

function linkEngine()
    filter { "kind:not StaticLib", "system:windows" }
        links { "Engine" }
    
    filter { "kind:not StaticLib", "system:not windows" }
        links { "Engine" }

    filter {}

    linkGraphics()
end