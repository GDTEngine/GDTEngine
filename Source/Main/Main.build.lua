group "Main"
project "Main"
    kind "ConsoleApp"
    location ""
    files { 
        "**.hpp", 
        "**.inl",
        "**.cpp",
        "Main.build.lua"
    }

    includedirs {
        "../../ThirdParty/GLEW/Include",
        "../../ThirdParty/GLFW/Include",
        "../../ThirdParty/GLM/Include",
        "../Core",
        "../Graphics",
        "../Engine",
        "../Editor/"
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

    linkEngine()