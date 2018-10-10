function linkGLEW()
    filter { "kind:not StaticLib", "system:windows" }
        links { "glew32", "opengl32" }
        
    filter { "kind:not StaticLib", "system:not windows" }
        links { "GL", "GLEW" }
    filter {}
end

function linkGLFW()
    filter { "kind:not StaticLib", "system:windows" }
        links { "glfw3dll" }

    filter { "kind:not StaticLib", "system:not windows" }
        links { "glfw3dll", "X11", "Xxf86vm", "Xrandr", "Xinerama", "Xcursor", "pthread", "Xi", "dl" }

    filter {}
end
