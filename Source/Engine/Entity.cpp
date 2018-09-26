#include "Entity.hpp"

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
