/**
 * @file     VertexArray.hpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "GraphicsAPI.hpp"
#include "VertexArray.hpp"

#include <GLEW/glew.h>

namespace gdt
{
    namespace graphics
    {
        /**
         * @brief A CArrayBuffer is an object that stores all of the state needed to supply vertex data.
         */
        class GRAPHICS_API CVertexArray
        {
        public:

            /**
             * @brief Mode which will be used to draw vertices.
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
             * @brief Default constructor.
             */
            CVertexArray();

            CVertexArray(const CVertexArray&) = delete;

            /**
             * @brief Move constructor.
             * @param other Source.
             */
            CVertexArray(CVertexArray&& other) noexcept;

            /**
             * @brief Destructor.
             */
            ~CVertexArray();

            void operator=(const CVertexArray&) = delete;

            /**
             * @brief Bind the vertex array.
             */
            void bind() const;

            /**
             * @brief Draw arrays.
             * @param start Start of the array.
             * @param count Number of vertices to draw.
             */
            void drawArrays(int32 start, int32 count) const;

            /**
             * @brief Get the draw mode for this vertex array.
             * @return Draw mode for this vertex array.
             */
            EDrawMode getDrawMode() const;

            /**
             * @brief Set the draw mode for the vertex array.
             * @param drawMode Draw mode to be used.
             */
            void setDrawMode(EDrawMode drawMode);

            /**
             * @brief Manualy unbind the active vertex array.
             */
            static void unbind();

        private:

            EDrawMode m_drawMode;
            static uint32 m_sActiveVertexArray;
            uint32 m_vertexArrayId;
        };
    }
}
