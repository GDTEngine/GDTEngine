/**
 * @file     Entity.cpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#include "Entity.hpp"

using namespace gdt;
using namespace engine;

CEntity::CEntity()
    : m_entityId(0)
{
}

CEntity::~CEntity()
{
}

CEntity::entityId CEntity::getEntityId() const
{
    return m_entityId;
}

void CEntity::beginPlay()
{
}

void CEntity::endPlay()
{
}

void CEntity::tick(f32 deltaTime)
{
}
