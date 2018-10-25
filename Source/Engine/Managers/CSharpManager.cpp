/**
 * @file     CSharpManager.cpp
 * @author   Ludvig Arlebrink
 * @date     10/26/2018
 */

#include "CSharpManager.hpp"

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

using namespace gdt;
using namespace engine;

CCSharpManager::CCSharpManager()
{
    mono_set_dirs("Data/Mono/lib", "Data/Mono/etc");

    core::CCSDomain* pDomain = new core::CCSDomain("GDTEngine");
    core::CCSAssembly* pEngineAssembly = pDomain->openAssembly("ManagedEngine.dll");
}

CCSharpManager::~CCSharpManager()
{
}
