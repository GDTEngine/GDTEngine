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
        "../../ThirdParty/GLM/Include",
        "../Core",
        "../Graphics",
        "../Engine",
        "../Editor/"
    }

    linkEngine()

    filter { "system:windows", "architecture:x86_64", "configurations:Debug" }
        libdirs "../../ThirdParty/GLFW/Lib/Win64/Debug"
        libdirs "../../ThirdParty/GLEW/Lib/Win64/Debug"
    
    filter { "system:windows", "architecture:x86_64", "configurations:Release" }
        libdirs "../../ThirdParty/GLFW/Lib/Win64/Release"
        libdirs "../../ThirdParty/GLEW/Lib/Win64/Release"