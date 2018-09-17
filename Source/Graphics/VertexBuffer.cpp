/**
 * @file     VertexArray.hpp
 * @author   Ludvig Arlebrink
 * @date     9/17/2018
 */

#include "VertexBuffer.hpp"

#include "VertexArray.hpp"

using namespace gdt;

uint32 CVertexBuffer::m_sActiveVertexBuffer = 0;

CVertexBuffer::CVertexBuffer()
    : m_usage(EUsage::StaticDraw)
{
    glGenBuffers(1, &m_vertexBufferId);
}

CVertexBuffer::~CVertexBuffer()
{
    glDeleteBuffers(1, &m_vertexBufferId);
}

void CVertexBuffer::bind() const
{
    if (m_sActiveVertexBuffer != m_vertexBufferId)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferId);
        m_sActiveVertexBuffer = m_vertexBufferId;
    }
}

void CVertexBuffer::setAttributePointer(CVertexArray* vertexArray, int32 index, int32 size, EType type, int32 stride,
    int32 offset)
{
    vertexArray->bind();
    bind();

    glVertexAttribPointer(index, size, static_cast<GLenum>(type), GL_FALSE, stride, reinterpret_cast<void*>(offset));
    glEnableVertexAttribArray(index);
}

void CVertexBuffer::setData(CVertexArray* vertexArray, int32 size, const void* dataPtr)
{
    vertexArray->bind();
    bind();

    glBufferData(GL_ARRAY_BUFFER, size, dataPtr, static_cast<GLenum>(m_usage));
}

