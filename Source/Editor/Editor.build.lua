group "Editor"
project "Editor"
    kind "StaticLib"
    location ""
    files { 
        "**.hpp",
        "**.inl",
        "**.cpp",
        "Editor.build.lua"
    }
    excludes { "UnitTest/**" }

    includedirs {
        "../Core",
        "../Graphics",
        "../Engine",
    }