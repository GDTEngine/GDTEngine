/**
 * @file     Object.cpp
 * @author   Ludvig Arlebrink
 * @date     10/10/2018
 */

#include "Object.hpp"

using namespace gdt;
using namespace engine;

IEntityManager* CObject::m_pEntityManager = nullptr;
IEventManager* CObject::m_pEventManager = nullptr;
IPluginManager* CObject::m_pPluginManager = nullptr;

CObject::CObject()
{
}

CObject::~CObject()
{
}

IEntityManager* CObject::entityManager()
{
    return m_pEntityManager;
}

IEventManager* CObject::eventManager()
{
    return m_pEventManager;
}

IPluginManager* CObject::pluginManager()
{
    return m_pPluginManager;
}

void CObject::provideEntityManager(IEntityManager* pEntityManager)
{
    m_pEntityManager = pEntityManager;
}

void CObject::provideEventManager(IEventManager* pEventManager)
{
    m_pEventManager = pEventManager;
}

void CObject::providePluginManager(IPluginManager* pPluginManager)
{
    m_pPluginManager = pPluginManager;
}
