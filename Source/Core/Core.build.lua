group "Engine"
project "Core"
    kind "StaticLib"
    location ""
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
        "../../ThirdParty/GLM/Include",
    }

function linkCore()
    filter { "kind:not StaticLib", "system:windows" }
        links { "Core" }

    filter { "kind:not StaticLib", "system:not windows" }
        links { "Core" }

    filter {}

    linkGLEW()
    linkGLFW()
end