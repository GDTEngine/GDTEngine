/**
 * @file     Object.cpp
 * @author   Ludvig Arlebrink
 * @date     10/10/2018
 */

#include "Object.hpp"

using namespace gdt;
using namespace engine;

IBehaviorManager* CObject::m_pBehaviorManager = nullptr;
ICSharpManager* CObject::m_pCSharpManager = nullptr;
IEntityManager* CObject::m_pEntityManager = nullptr;
IEventManager* CObject::m_pEventManager = nullptr;
IPluginManager* CObject::m_pPluginManager = nullptr;

CObject::CObject()
{
}

CObject::~CObject()
{
}

IBehaviorManager* CObject::behaviorManager()
{
    return m_pBehaviorManager;
}

ICSharpManager* CObject::csharpManager()
{
    return m_pCSharpManager;
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

void CObject::provideBehaviorManager(IBehaviorManager* pBehaviorManager)
{
    m_pBehaviorManager = pBehaviorManager;
}

void CObject::provideCSharpManager(ICSharpManager* pCSharpManager)
{
    m_pCSharpManager = pCSharpManager;
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
