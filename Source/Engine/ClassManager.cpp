/**
 * @file     ClassManager.cpp
 * @author   Ludvig Arlebrink
 * @date     9/27/2018
 */

#include "ClassManager.hpp"

using namespace gdt;
using namespace engine;

CEntity* CClassManager::createEntity(const std::string& className)
{
    return m_entityClasses.at(className)();
}

void CClassManager::registerEntity(const std::string& className, CreateEntityFunction function)
{
    m_entityClasses.emplace(className, function);
}
