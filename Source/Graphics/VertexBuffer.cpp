/**
 * @file     VertexArray.hpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#include "VertexBuffer.hpp"

#include "VertexArray.hpp"

using namespace gdt;
using namespace graphics;

uint32 CVertexBuffer::m_sActiveVertexBuffer = 0;

CVertexBuffer::CVertexBuffer()
    : CBufferObject(EUsage::StaticDraw)
{
    glGenBuffers(1, &m_vertexBufferId);
}

CVertexBuffer::CVertexBuffer(CVertexBuffer&& other) noexcept
    : CBufferObject(other.getUsage())
    , m_vertexBufferId(other.m_vertexBufferId)
{
    other.m_vertexBufferId = 0;
}

CVertexBuffer::~CVertexBuffer()
{
    if (m_vertexBufferId > 0)
    {
        glDeleteBuffers(1, &m_vertexBufferId);
    }
}

void CVertexBuffer::bind() const
{
    if (m_sActiveVertexBuffer != m_vertexBufferId)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferId);
        m_sActiveVertexBuffer = m_vertexBufferId;
    }
}

void CVertexBuffer::setAttributePointer(CVertexArray& vertexArray, int32 index, int32 size, EType type, int32 stride,
    int32 offset) const
{
    vertexArray.bind();
    bind();

    glVertexAttribPointer(index, size, static_cast<GLenum>(type), GL_FALSE, stride, reinterpret_cast<void*>(offset));
    glEnableVertexAttribArray(index);
}

void CVertexBuffer::setData(CVertexArray& vertexArray, int32 size, const void* dataPtr) const
{
    vertexArray.bind();
    bind();

    glBufferData(GL_ARRAY_BUFFER, size, dataPtr, static_cast<GLenum>(getUsage()));
}

void CVertexBuffer::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
