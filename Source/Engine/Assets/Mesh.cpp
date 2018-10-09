/**
* @file     Mesh.cpp
* @author   Ludvig Arlebrink
* @date     10/9/2018
*/

#include "Mesh.hpp"

using namespace gdt;
using namespace engine;

CMesh::CMesh()
{
}

CMesh::~CMesh()
{
}

void CMesh::bind()
{
    m_vertexArray.bind();
}

void CMesh::setVertices(const std::vector<SVertex>& vertices)
{
    m_vertices = vertices;
    m_arrayBuffer.setData(m_vertices.size() * sizeof(SVertex), &m_vertices[0]);
    m_arrayBuffer.setAttributePointer(m_vertexArray, 0, 3, graphics::CBufferObject::EType::Float, sizeof(SVertex), 0);
    m_arrayBuffer.setAttributePointer(m_vertexArray, 1, 3, graphics::CBufferObject::EType::Float, sizeof(SVertex), sizeof(glm::vec3));
}

void CMesh::draw()
{
    m_vertexArray.drawArrays(0, m_vertices.size());
}
