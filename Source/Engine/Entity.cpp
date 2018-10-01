/**
 * @file     Entity.cpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#include "Entity.hpp"

using namespace gdt;
using namespace engine;

CEntity::CEntity()
{
}

CEntity::~CEntity()
{
}

EntityID CEntity::getID() const
{
    return m_entityID;
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
