group "Engine"
project "Graphics"
    kind "StaticLib"
    location ""
    
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

function linkGraphics()
    filter { "kind:not StaticLib", "system:windows" }
        links { "Graphics" }
    
    filter { "kind:not StaticLib", "system:not windows" }
        links { "Graphics" }

    filter {}
    linkCore()
end