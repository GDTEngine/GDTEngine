/**
 * @file     ArrayBuffer.hpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#include "ArrayBuffer.hpp"

#include "VertexArray.hpp"

using namespace gdt;
using namespace graphics;

uint32 CArrayBuffer::m_sActiveArrayBuffer = 0;

CArrayBuffer::CArrayBuffer()
    : CBufferObject(EUsage::StaticDraw)
{
    glGenBuffers(1, &m_arrayBufferId);
}

CArrayBuffer::CArrayBuffer(CArrayBuffer&& other) noexcept
    : CBufferObject(other.getUsage())
    , m_arrayBufferId(other.m_arrayBufferId)
{
    other.m_arrayBufferId = 0;
}

CArrayBuffer::~CArrayBuffer()
{
    if (m_arrayBufferId > 0)
    {
        glDeleteBuffers(1, &m_arrayBufferId);
    }
}

void CArrayBuffer::bind() const
{
    if (m_sActiveArrayBuffer != m_arrayBufferId)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_arrayBufferId);
        m_sActiveArrayBuffer = m_arrayBufferId;
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
