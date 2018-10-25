/**
 * @file     CSDomain.cpp
 * @author   Ludvig Arlebrink
 * @date     10/25/2018
 */

#include "CSDomain.hpp"
#include "CSAssembly.hpp"
#include "CSClass.hpp"
#include "CSObject.hpp"

using namespace gdt;
using namespace core;

CCSDomain::CCSDomain()
    : m_pDomain(nullptr)
{
}

CCSDomain::CCSDomain(const std::string& name)
{
    m_pDomain = mono_jit_init(name.c_str());
}

CCSDomain::~CCSDomain()
{
    if (!m_pDomain)
    {
        mono_jit_cleanup(m_pDomain);
    }
}

CCSObject* CCSDomain::newObject(CCSClass* pClass)
{
    MonoObject* pObj = mono_object_new(m_pDomain, pClass->m_pClass);
    mono_runtime_object_init(pObj);
    CCSObject* pObject = new CCSObject;
    pObject->m_pObject = pObj;
    return pObject;
}

void CCSDomain::open(const std::string& name)
{
    if (!m_pDomain)
    {
        mono_jit_cleanup(m_pDomain);
    }

    m_pDomain = mono_jit_init(name.c_str());
}

CCSAssembly* CCSDomain::openAssembly(const std::string& filename)
{
    MonoAssembly* pAssembly = mono_domain_assembly_open(m_pDomain, filename.c_str());
    if (!pAssembly)
    {
        return nullptr;
    }

    CCSAssembly* pCSAssembly = new CCSAssembly;
    pCSAssembly->m_pAssembly = pAssembly;
    pCSAssembly->m_pImage = mono_assembly_get_image(pAssembly);
    return pCSAssembly;
}
