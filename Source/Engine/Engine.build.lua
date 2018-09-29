group "Engine"
project "Engine"
    kind "StaticLib"
    location ""
    files {
        "**.hpp",
        "**.inl",
        "**.cpp",
        "Engine.build.lua"
    }
    excludes { "UnitTest/**" }

    includedirs {
        "../../ThirdParty/GLM/Include",
        "../Core",
        "../Graphics",
        "../Engine",
    }

function includeEngine()
    includedirs{ scriptPath() }
end

function linkEngine()
    filter { "kind:not StaticLib", "system:windows" }
        links { "Engine" }
    
    filter { "kind:not StaticLib", "system:not windows" }
        links { "Engine" }

    filter {}

    linkGraphics()
end