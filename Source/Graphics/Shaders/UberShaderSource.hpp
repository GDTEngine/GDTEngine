/**
 * @file     UberShaderSource.hpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#pragma once

namespace gdt
{
    namespace graphics
    {

        namespace shader
        {
            /**
             * @breif Vertex shader source for Uber shader.
             */
            const char* uberVertex =
                "#version 450 core\n"
                "layout (location = 0) in vec2 position;\n"
                "uniform mat4 Projection = mat4(1.0);"
                "void main()\n"
                "{\n"
                "   gl_Position = Projection * vec4(position, 0.0, 1.0);\n"
                "}\n\0";

            const char* uberGeometry =
                "#version 450 core\n"

                "}\n\0";

            /**
             * @breif Fragment shader source for Uber shader.
             */
            const char* uberFragment =
                "#version 450 core\n"
                "out vec4 FragColor;\n"
                "void main()\n"
                "{\n"
                "   FragColor = vec4(0.2f, 0.1f, 0.1f, 1.0f);\n"
                "}\n\0";
        }
    }
}
