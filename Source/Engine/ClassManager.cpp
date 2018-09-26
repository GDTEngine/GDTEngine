#include "ClassManager.hpp"


CClassManager& CClassManager::get()
{
    static CClassManager instance;
    return instance;
}

CEntity* CClassManager::createEntity(const std::string& className)
{
    return m_entityClasses.at(className)();
}

void CClassManager::registerEntity(const std::string& className, createEnityFunction createEnityFunction)
{
    m_entityClasses.emplace(className, createEnityFunction);
}
