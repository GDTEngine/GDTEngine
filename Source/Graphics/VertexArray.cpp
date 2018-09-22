/**
 * @file     VertexArray.cpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#include "VertexArray.hpp"

using namespace gdt;
using namespace graphics;

uint32 CVertexArray::m_sActiveVertexArray = 0;

CVertexArray::CVertexArray()
    : m_drawMode(EDrawMode::Triangles)
{
    glGenVertexArrays(1, &m_vertexArrayId);
}

CVertexArray::CVertexArray(CVertexArray&& other) noexcept
    : m_drawMode(other.m_drawMode)
    , m_vertexArrayId(other.m_vertexArrayId)
{
    other.m_vertexArrayId = 0;
}

CVertexArray::~CVertexArray()
{
    if (m_vertexArrayId > 0)
    {
        glDeleteVertexArrays(1, &m_vertexArrayId);
    }
}

void CVertexArray::bind() const
{
    if (m_sActiveVertexArray != m_vertexArrayId)
    {
        glBindVertexArray(m_vertexArrayId);
        m_sActiveVertexArray = m_vertexArrayId;
    }
}

void CVertexArray::drawArrays(int32 start, int32 count) const
{
    bind();
    glDrawArrays(static_cast<GLenum>(m_drawMode), start, count);
}

CVertexArray::EDrawMode CVertexArray::getDrawMode() const
{
    return m_drawMode;
}

void CVertexArray::setDrawMode(EDrawMode drawMode)
{
    m_drawMode = drawMode;
}
