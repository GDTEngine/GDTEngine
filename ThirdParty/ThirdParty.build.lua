function linkGLEW()
    filter { "kind:not StaticLib" }
        links { "glew32", "opengl32" }
        
    filter {}
end

function linkGLFW()
    filter { "kind:not StaticLib" }
        links { "glfw3dll" }

    filter {}
end