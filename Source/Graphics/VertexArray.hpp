/**
 * @file     VertexArray.hpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#pragma once

#include "BaseTypes.hpp"

#include <GLEW/glew.h>

namespace gdt
{
    namespace graphics
    {
        /**
         * @breif A **'CVertexArray'** is an object that stores all of the state needed to supply vertex data.
         */
        class CVertexArray
        {
        public:

            /**
             * @breif Mode which will be used to draw vertices.
             */
            enum class EDrawMode
            {
                /** Draw lines. */
                Lines = GL_LINES,

                /** Draw points. */
                Points = GL_POINTS,

                /** **Default** draw mode. Draw triangles. */
                Triangles = GL_TRIANGLES
            };

        public:

            /**
             * @breif Default constructor.
             */
            CVertexArray();

            /**
             * @breif Copy constructor deleted.
             */
            CVertexArray(const CVertexArray& other) = delete;

            /**
             * @breif Move constructor.
             * @param other Source.
             */
            CVertexArray(CVertexArray&& other) noexcept;

            /**
             * @breif Destructor.
             */
            ~CVertexArray();

            void operator=(const CVertexArray& rhs) = delete;

            /**
             * @breif Bind the vertex array.
             */
            void bind() const;

            /**
             * @breif Draw arrays.
             */
            void drawArrays() const;

            /**
             * @breif Draw arrays.
             * @param start Start of the array.
             * @param count Number of vertices to draw.
             */
            void drawArrays(int32 start, int32 count) const;

            /**
             * @breif Get the draw mode for this vertex array.
             * @return Draw mode for this vertex array.
             */
            EDrawMode getDrawMode() const;

            /**
             * @breif Set the draw mode for the vertex array.
             * @param drawMode Draw mode to be used.
             */
            void setDrawMode(EDrawMode drawMode);

        private:

            EDrawMode m_drawMode;
            int32 m_count;
            static uint32 m_sActiveVertexArray;
            uint32 m_vertexArrayId;
        };
    }
}
