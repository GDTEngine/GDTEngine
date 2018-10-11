/**
 * @file     Object.cpp
 * @author   Ludvig Arlebrink
 * @date     10/10/2018
 */

#include "Object.hpp"

using namespace gdt;
using namespace engine;

priv::IEntityManager* CObject::m_pEntityManager = nullptr;
priv::IEventManager* CObject::m_pEventManager = nullptr;
priv::IPluginManager* CObject::m_pPluginManager = nullptr;

CObject::CObject()
{
}

CObject::~CObject()
{
}

priv::IEntityManager* CObject::entityManager()
{
    return m_pEntityManager;
}

priv::IEventManager* CObject::eventManager()
{
    return m_pEventManager;
}

priv::IPluginManager* CObject::pluginManager()
{
    return m_pPluginManager;
}

void CObject::provideEntityManager(priv::IEntityManager* pEntityManager)
{
    m_pEntityManager = pEntityManager;
}

void CObject::provideEventManager(priv::IEventManager* pEventManager)
{
    m_pEventManager = pEventManager;
}

void CObject::providePluginManager(priv::IPluginManager* pPluginManager)
{
    m_pPluginManager = pPluginManager;
}
