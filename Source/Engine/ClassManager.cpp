/**
 * @file     ClassManager.cpp
 * @author   Ludvig Arlebrink
 * @date     9/27/2018
 */

#include "ClassManager.hpp"

using namespace gdt;
using namespace engine;

CClassManager& CClassManager::get()
{
    static CClassManager instance;
    return instance;
}

CEntity* CClassManager::createEntity(const std::string& className)
{
    return m_entityClasses.at(className)();
}

void CClassManager::registerEntity(const std::string& className, createEntityFunction function)
{
    m_entityClasses.emplace(className, function);
}
