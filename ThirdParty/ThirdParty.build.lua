function linkGLEW()
	filter { "kind:not StaticLib" }
        links { "glew32s", "opengl32" }
        
	filter {}
end

function linkGLFW()
	filter { "kind:not StaticLib" }
        links { "glfw3" }

	filter {}
end