/**
 * @file     UberShaderSource.hpp
 * @author   Ludvig Arlebrink
 * @date     9/17/2018
 */

#pragma once

namespace gdt
{
    namespace shader
    {
        /**
         * @breif Vertex shader source for Uber shader.
         */
        const char* uberVertex =
            "#version 450 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\n\0";

        /**
         * @breif Fragment shader source for Uber shader.
         */
        const char* uberFragment =
            "#version 450 core\n"
            "out vec4 FragColor;\n"
            "void main()\n"
            "{\n"
            "   FragColor = vec4(1.0f, 0.1f, 0.1f, 1.0f);\n"
            "}\n\0";
    }
}
