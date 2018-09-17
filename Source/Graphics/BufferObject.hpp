/**
 * @file     BufferObject.hpp
 * @author   Ludvig Arlebrink
 * @date     9/17/2018
 */

#pragma once

#include <GLEW/glew.h>

namespace gdt
{
    class CBufferObject
    {
    public:

        enum class EType
        {
            Float = GL_FLOAT,
        };

        enum class EUsage
        {
            DynamicDraw = GL_DYNAMIC_DRAW,
            StaticDraw = GL_STATIC_DRAW,
            StreamDraw = GL_STREAM_DRAW
        };

    public:

        CBufferObject();

        virtual ~CBufferObject();

        virtual void bind() const = 0;

    };
}
