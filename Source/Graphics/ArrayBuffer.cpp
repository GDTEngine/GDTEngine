/**
 * @file     ArrayBuffer.hpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#include "ArrayBuffer.hpp"

#include "VertexArray.hpp"

using namespace gdt;
using namespace graphics;

uint32 CArrayBuffer::m_sActiveVertexBuffer = 0;

CArrayBuffer::CArrayBuffer()
    : CBufferObject(EUsage::StaticDraw)
{
    glGenBuffers(1, &m_vertexBufferId);
}

CArrayBuffer::CArrayBuffer(CArrayBuffer&& other) noexcept
    : CBufferObject(other.getUsage())
    , m_vertexBufferId(other.m_vertexBufferId)
{
    other.m_vertexBufferId = 0;
}

CArrayBuffer::~CArrayBuffer()
{
    if (m_vertexBufferId > 0)
    {
        glDeleteBuffers(1, &m_vertexBufferId);
    }
}

void CArrayBuffer::bind() const
{
    if (m_sActiveVertexBuffer != m_vertexBufferId)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferId);
        m_sActiveVertexBuffer = m_vertexBufferId;
    }
}

void* CArrayBuffer::mapBuffer(EAccess access)
{
    bind();
    return glMapBuffer(GL_ARRAY_BUFFER, static_cast<GLenum>(access));
}

void CArrayBuffer::setAttributePointer(CVertexArray& vertexArray, int32 index, int32 size, EType type, int32 stride,
    int32 offset) const
{
    vertexArray.bind();
    bind();

    glVertexAttribPointer(index, size, static_cast<GLenum>(type), GL_FALSE, stride, reinterpret_cast<void*>(offset));
    glEnableVertexAttribArray(index);
}

void CArrayBuffer::setData(int32 size, const void* dataPtr) const
{
    bind();
    glBufferData(GL_ARRAY_BUFFER, size, dataPtr, static_cast<GLenum>(getUsage()));
}

void CArrayBuffer::unmapBuffer() const
{
    bind();
    glUnmapBuffer(GL_ARRAY_BUFFER);
}

void CArrayBuffer::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
