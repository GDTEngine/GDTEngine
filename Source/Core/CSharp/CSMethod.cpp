/**
 * @file     CSMethod.cpp
 * @author   Ludvig Arlebrink
 * @date     10/25/2018
 */

#include "CSMethod.hpp"
#include "CSObject.hpp"

using namespace gdt;
using namespace core;

void CCSMethod::call(CCSObject* object)
{
    mono_runtime_invoke(m_pMethod, object->m_pObject, nullptr, nullptr);
}

void CCSMethod::call(CCSObject* object, void** params)
{
    mono_runtime_invoke(m_pMethod, object->m_pObject, params, nullptr);
}

void CCSMethod::callStatic()
{
    mono_runtime_invoke(m_pMethod, nullptr, nullptr, nullptr);
}

void CCSMethod::callStatic(void** params)
{
    mono_runtime_invoke(m_pMethod, nullptr, params, nullptr);
}

void CCSMethod::callVirtual(CCSObject* pObject)
{
    MonoMethod* pVirtualMethod = mono_object_get_virtual_method(pObject->m_pObject, m_pMethod);
    mono_runtime_invoke(pVirtualMethod, pObject->m_pObject, nullptr, nullptr);
}

void CCSMethod::callVirtual(CCSObject* pObject, void** pParams)
{
    MonoMethod* pVirtualMethod = mono_object_get_virtual_method(pObject->m_pObject, m_pMethod);
    mono_runtime_invoke(pVirtualMethod, pObject->m_pObject, nullptr, nullptr);
}

CCSMethod::CCSMethod()
    : m_pMethod(nullptr)
{
}

CCSMethod::~CCSMethod()
{
}
