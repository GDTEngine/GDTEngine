group "Editor"
project "Editor"
    kind "SharedLib"
    location ""

    defines { "EDITOR_DLL_EXPORT" }

    files { 
        "**.hpp",
        "**.inl",
        "**.cpp",
        "Editor.build.lua"
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

    filter { "system:not windows", "architecture:x86_64", "configurations:Debug" }
        libdirs {
            "../../ThirdParty/GLFW/Lib/Unix64/Debug",
            "../../ThirdParty/GLEW/Lib/Unix64/Debug",
        }   

    filter { "system:windows", "architecture:x86_64", "configurations:Release" }
        libdirs {
            "../../ThirdParty/GLFW/Lib/Win64/Release",
            "../../ThirdParty/GLEW/Lib/Win64/Release",
            "../../ThirdParty/Mono/Lib/Win64/Release"
        }

    filter { "system:not windows", "architecture:x86_64", "configurations:Release" }
        libdirs {
            "../../ThirdParty/GLFW/Lib/Unix64/Release",
            "../../ThirdParty/GLEW/Lib/Unix64/Release"
        }

        linkEngine()

function linkEditor()
    filter { "kind:not StaticLib", "system:windows" }
        links { "Editor" }
        
    filter { "kind:not StaticLib", "system:not windows" }
        links { "Editor" }
    
    filter {}

    linkEngine()
end