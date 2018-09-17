/**
 * @file     VertexArray.hpp
 * @author   Ludvig Arlebrink
 * @date     9/17/2018
 */

#pragma once

#include "BaseTypes.hpp"

#include <GLEW/glew.h>

namespace gdt
{
    class CVertexArray
    {
    public:

        enum class EDrawMode
        {
            Lines = GL_LINES,
            Points = GL_POINTS,

            /** **Default** draw mode. */
            Triangles = GL_TRIANGLES
        };

    public:

        /**
         * @breif Default constructor.
         */
        CVertexArray();

        /**
         * @breif Destructor.
         */
        ~CVertexArray();

        /**
         * @breif Bind the vertex array.
         */
        void bind() const;

        void drawArrays() const;

        void drawArrays(int32 start, int32 count) const;

    private:

        EDrawMode m_drawMode;
        int32 m_count;
        static uint32 m_sActiveVertexArray;
        uint32 m_vertexArrayId;
    };
}
