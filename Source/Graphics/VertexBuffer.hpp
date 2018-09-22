/**
 * @file     VertexBuffer.hpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "BufferObject.hpp"

namespace gdt
{
    namespace graphics
    {
        // Forward delcations.
        class CVertexArray;

        /**
         * @breif A vertex buffer.
         *
         * Default usage for this buffer is **'StaticDraw'**.
         */
        class CVertexBuffer final : public CBufferObject
        {
        public:

            /**
             * @breif Default constructor.
             */
            CVertexBuffer();

            /**
             * @breif Destructor.
             */
            ~CVertexBuffer();

            /**
             * @breif Manualy bind this buffer.
             */
            void bind() const override;

            /**
             * @breif Set a attribute pointer to the buffer.
             * @param vertexArray Vertex array the buffer will be attached to.
             * @param index Index of the pointer.
             * @param size
             * @param type
             * @param stride
             * @param offset
             *
             * Calling this function will also bind this buffer.
             */
            void setAttributePointer(CVertexArray* vertexArray, int32 index, int32 size, EType type, int32 stride, int32 offset) const;

            /**
             * @breif Set the data of this buffer.
             * @param vertexArray
             * @param size
             * @param dataPtr
             *
             * Calling this function will also bind this buffer.
             */
            void setData(CVertexArray* vertexArray, int32 size, const void* dataPtr) const;

            /**
             * @breif Manualy unbind the vertex buffers.
             */
            static void unbind();

        private:

            static uint32 m_sActiveVertexBuffer;
            uint32 m_vertexBufferId;
        };
    }
}
