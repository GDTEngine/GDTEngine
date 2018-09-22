/**
 * @file     UIRenderer.cpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#include "UIRenderer.hpp"
#include "ArrayBuffer.hpp"
#include "VertexArray.hpp"

using namespace gdt;
using namespace graphics;

CUIRenderer::CUIRenderer()
    : m_pMap(nullptr)
    , m_count(0)
{
    m_pVertexArray = std::make_unique<CVertexArray>();
    m_pVertexBuffer = std::make_unique<CArrayBuffer>();

    m_pVertexArray->setDrawMode(CVertexArray::EDrawMode::Triangles);
    m_pVertexBuffer->setData(sizeof(f32) * 2 * 1024 * 100, nullptr);
    m_pVertexBuffer->setAttributePointer(*m_pVertexArray, 0, 2, CArrayBuffer::EType::Float, sizeof(float) * 2, 0);

}

CUIRenderer::CUIRenderer(CUIRenderer&& other) noexcept
    : m_pMap(other.m_pMap)
    , m_count(other.m_count)
    , m_pVertexArray(std::move(other.m_pVertexArray))
    , m_pVertexBuffer(std::move(other.m_pVertexBuffer))
{
}

CUIRenderer::~CUIRenderer()
{
}

void CUIRenderer::begin()
{
    m_pMap = static_cast<SUIDefinition*>(m_pVertexBuffer->mapBuffer(CArrayBuffer::EAccess::WriteOnly));
    m_count = 0;
}

void CUIRenderer::end()
{
    m_pMap = nullptr;
    m_pVertexBuffer->unmapBuffer();
}

void CUIRenderer::submitPanel(const glm::vec2& position, const glm::vec2& size, const glm::vec2& anchor)
{
    m_pMap->position = position + size;
    ++m_pMap;

    m_pMap->position.x = position.x + size.x;
    m_pMap->position.y = position.y;
    ++m_pMap;

    m_pMap->position.x = position.x;
    m_pMap->position.y = position.y + size.y;
    ++m_pMap;

    m_pMap->position.x = position.x + size.x;
    m_pMap->position.y = position.y;
    ++m_pMap;

    m_pMap->position = position;
    ++m_pMap;

    m_pMap->position.x = position.x;
    m_pMap->position.y = position.y + size.x;
    ++m_pMap;
    
    m_count += 6;
}

void CUIRenderer::draw() const
{
    m_pVertexArray->drawArrays(0, m_count);
}
