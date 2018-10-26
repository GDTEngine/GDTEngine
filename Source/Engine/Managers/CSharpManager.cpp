/**
 * @file     CSharpManager.cpp
 * @author   Ludvig Arlebrink
 * @date     10/26/2018
 */

#include "CSharpManager.hpp"
#include "Log.hpp"

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

using namespace gdt;
using namespace engine;

CCSharpManager::CCSharpManager()
{
    mono_set_dirs("Data/Mono/lib", "Data/Mono/etc");

    m_pDomain = new core::CCSDomain("GDTEngine");
    m_pEngineAssembly = m_pDomain->openAssembly("ManagedEngine.dll");

    core::CCSClass* pBehaviorClass = m_pEngineAssembly->getClass("GDT.Engine", "Behavior");
    m_pBehaviorTickMethod = pBehaviorClass->getMethod("Tick");

    std::vector<core::CCSClass*> pClasses = m_pEngineAssembly->getAllClasses();

    for (int32 i = 0; i < pClasses.size(); ++i)
    {
        if (pClasses[i]->isSubclassOf(pBehaviorClass) && pClasses[i]->getName() != "Behavior")
        {
            m_pBehaviorClasses.emplace("Ye", pClasses[i]);
            LOG_MSG(pClasses[i]->getName());
        }
    }

    core::CCSObject* pObject = m_pDomain->newObject(m_pBehaviorClasses.at("Ye"));
    m_pBehaviorTickMethod->callVirtual(pObject);
}

CCSharpManager::~CCSharpManager()
{
}
