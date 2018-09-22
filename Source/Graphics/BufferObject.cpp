/**
 * @file     BufferObject.cpp
 * @author   Ludvig Arlebrink
 * @date     9/17/2018
 */

#include "BufferObject.hpp"

using namespace gdt;
using namespace graphics;

CBufferObject::CBufferObject()
    : m_usage(EUsage::StaticDraw)
{
}

CBufferObject::CBufferObject(CBufferObject&& other) noexcept
    : m_usage(other.m_usage)
{
}

CBufferObject::CBufferObject(EUsage usage)
    : m_usage(usage)
{
}

CBufferObject::~CBufferObject()
{
}

CBufferObject::EUsage CBufferObject::getUsage() const
{
    return m_usage;
}

void CBufferObject::setUsage(EUsage usage)
{
    m_usage = usage;
}
