/**
 * @file     ArrayBuffer.hpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "BufferObject.hpp"
#include "GraphicsAPI.hpp"

namespace gdt
{
    namespace graphics
    {
        // Forward delcations.
        class CVertexArray;

        /**
         * @brief A vertex buffer.
         *
         * Default usage for this buffer is StaticDraw.
         */
        class GRAPHICS_API CArrayBuffer final : public CBufferObject
        {
        public:

            /**
             * @brief Default constructor.
             */
            CArrayBuffer();

            /**
             * @brief Copy constructor deleted.
             */
            CArrayBuffer(const CArrayBuffer&) = delete;

            /**
             * @brief Move constructor.
             * @param other Source.
             */
            CArrayBuffer(CArrayBuffer&& other) noexcept;

            /**
             * @brief Destructor.
             */
            ~CArrayBuffer();

            void operator=(const CVertexArray&) = delete;

            /**
             * @brief Manualy bind this buffer.
             */
            void bind() const override;

            /**
             * @brief Map this buffer.
             * @param access Indicate the access.
             */
            void* mapBuffer(EAccess access);

            /**
             * @brief Set a attribute pointer to the buffer.
             * @param vertexArray Vertex array the buffer will be attached to.
             * @param index Index of the pointer.
             * @param size Specifies the number of components per generic vertex attribute.
             * @param type Specifies the data type of each component in the array.
             * @param stride Specifies the byte offset between consecutive generic vertex attributes.
             * @param offset Specifies a offset of the first component of the first generic vertex attribute in the array.
             *
             * Calling this function will also bind this buffer.
             */
            void setAttributePointer(CVertexArray& vertexArray, int32 index, int32 size, EType type, int32 stride, int32 offset) const;

            /**
             * @brief Set the data of this buffer.
             * @param size Specifies the size in bytes of the buffer object's new data store.
             * @param dataPtr Specifies a pointer to data that will be copied into the data store for initialization, or nullptr if no data is to be copied.
             *  
             * Calling this function will also bind this buffer.
             */
            void setData(int32 size, const void* dataPtr) const;

            /**
             * @brief Unmaps the buffer.
             */
            void unmapBuffer() const;

            /**
             * @brief Manualy unbind the active vertex buffers.
             */
            static void unbind();

        private:

            static uint32 m_sActiveArrayBuffer;
            uint32 m_arrayBufferId;
        };
    }
}
