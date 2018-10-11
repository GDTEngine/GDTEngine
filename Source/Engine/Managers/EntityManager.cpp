/**
 * @file     EntityManager.cpp
 * @author   Ludvig Arlebrink
 * @date     9/27/2018
 */

#include "EntityManager.hpp"
#include "Entity.hpp"

using namespace gdt;
using namespace engine;
using namespace priv;


CEntityManager::CEntityManager()
    : m_entityCount(0)
{
}

CEntityManager::~CEntityManager()
{
}

CEntity* CEntityManager::instantiate(ClassID classID)
{
    CEntity* entity = m_entityClasses.at(classID)();
    entity->m_entityID = m_entityCount;
    m_pEntities[m_entityCount] = entity;
    ++m_entityCount;

    entity->beginPlay();

    return entity;
}

void CEntityManager::registerEntity(ClassID classID, CreateEntityFunction function)
{
    m_entityClasses.emplace(classID, function);
}

void CEntityManager::tick(f32 deltaTime)
{
    for (int32 i = 0; i < m_entityCount; ++i)
    {
        m_pEntities[i]->tick(deltaTime);
    }
}
