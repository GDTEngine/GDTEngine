/**
 * @file     Object.cpp
 * @author   Ludvig Arlebrink
 * @date     10/10/2018
 */

#include "Object.hpp"

using namespace gdt;
using namespace engine;

priv::IClassManager* CObject::m_pClassManager = nullptr;
priv::IEventManager* CObject::m_pEventManager = nullptr;
priv::IPluginManager* CObject::m_pPluginManager = nullptr;

CObject::CObject()
{
}

CObject::~CObject()
{
}

priv::IClassManager* CObject::classManager()
{
    return m_pClassManager;
}

priv::IEventManager* CObject::eventManager()
{
    return m_pEventManager;
}

priv::IPluginManager* CObject::pluginManager()
{
    return m_pPluginManager;
}

void CObject::provideClassManager(priv::IClassManager* classManager)
{
    m_pClassManager = classManager;
}

void CObject::provideEventManager(priv::IEventManager* eventManager)
{
    m_pEventManager = eventManager;
}

void CObject::providePluginManager(priv::IPluginManager* pluginManager)
{
    m_pPluginManager = pluginManager;
}
