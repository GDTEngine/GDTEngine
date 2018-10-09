function linkGLEW()
<<<<<<< HEAD
    filter { "kind:not StaticLib" }
        links { "glew32", "opengl32" }
        
    filter {}
end

function linkGLFW()
    filter { "kind:not StaticLib" }
        links { "glfw3dll" }

    filter {}
end
=======
	filter { "kind:not StaticLib", "system:windows" }
        links { "glew32s", "opengl32" }
        
        filter { "kind:not StaticLib", "system:not windows" }
        links { "GL", "GLEW" }
	filter {}
end

function linkGLFW()
	filter { "kind:not StaticLib", "system:windows" }
        links { "glfw3" }

        filter { "kind:not StaticLib", "system:not windows" }
        links { "glfw3", "X11", "Xxf86vm", "Xrandr", "Xinerama", "Xcursor", "pthread", "Xi", "dl" }

	filter {}
end
>>>>>>> master
