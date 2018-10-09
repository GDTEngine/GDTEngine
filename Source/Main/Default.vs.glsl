#version 450

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out VsOut {
    vec3 color;
} vsOut;

void main()
{
    gl_Position = vec4(position.xyz, 1.0);

    vsOut.color = color;
}
