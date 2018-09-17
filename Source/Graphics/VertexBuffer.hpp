/**
 * @file     VertexBuffer.hpp
 * @author   Ludvig Arlebrink
 * @date     9/17/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "BufferObject.hpp"

namespace gdt
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

        void bind() const override;

        void setAttributePointer(CVertexArray* vertexArray, int32 index, int32 size, EType type, int32 stride, int32 offset);

        void setData(CVertexArray* vertexArray, int32 size, const void* dataPtr);

    private:

        EUsage m_usage;

        static uint32 m_sActiveVertexBuffer;
        uint32 m_vertexBufferId;
    };
}
