#version 450 core

layout (location = 0) in vec2 center;
layout (location = 1) in vec2 position;
layout (location = 2) in vec2 size;
uniform mat4 Projection = mat4(1.0);

out VsOut
{
    vec2 center;
    vec2 position;
    vec2 size;
} 
vsOut;

void main()
{
    vsOut.center = center;
    vsOut.position = position;
    vsOut.size = size;
    gl_Position = Projection * vec4(position, 0.0, 1.0);
}
