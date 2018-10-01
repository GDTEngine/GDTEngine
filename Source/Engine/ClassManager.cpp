/**
 * @file     ClassManager.cpp
 * @author   Ludvig Arlebrink
 * @date     9/27/2018
 */

#include "ClassManager.hpp"
#include "Entity.hpp"
#include "Component.hpp"
#include "System.hpp"

using namespace gdt;
using namespace engine;

SComponent* CClassManager::createComponent(StructID structID)
{
    return m_componentStructs.at(structID)();
}

CEntity* CClassManager::createEntity(ClassID classID)
{
    return m_entityClasses.at(classID)();
}

void CClassManager::forEachSystem(IterateSystemsFunction function)
{
    for (auto& system : m_systemClasses)
    {
        function(system.second());
    }
}

CClassManager& CClassManager::get()
{
    static CClassManager instance;
    return instance;
}

CSystemBase* CClassManager::getSystem(ClassID classID)
{
    return m_systemClasses.at(classID)();
}

void CClassManager::registerComponent(StructID structID, CreateComponentFunction function)
{
    m_componentStructs.emplace(structID, function);
}

void CClassManager::registerEntity(ClassID classID, CreateEntityFunction function)
{
    m_entityClasses.emplace(classID, function);
}

void CClassManager::registerSystem(ClassID classID, GetSystemFunction function)
{
    m_systemClasses.emplace(classID, function);
}
