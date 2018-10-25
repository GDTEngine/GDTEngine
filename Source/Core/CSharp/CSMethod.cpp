/**
 * @file     CSMethod.cpp
 * @author   Ludvig Arlebrink
 * @date     10/25/2018
 */

#include "CSMethod.hpp"
#include "CSObject.hpp"

using namespace gdt;
using namespace core;

void* CCSMethod::callStatic()
{
    mono_runtime_invoke(m_pMethod, nullptr, nullptr, nullptr);
    return nullptr;
}

void* CCSMethod::callStatic(void** params)
{
    mono_runtime_invoke(m_pMethod, nullptr, params, nullptr);
    return nullptr;
}

void* CCSMethod::call(CCSObject* object)
{
    mono_runtime_invoke(m_pMethod, object->m_pObject, nullptr, nullptr);
    return nullptr;
}

void* CCSMethod::call(CCSObject* object, void** params)
{
    mono_runtime_invoke(m_pMethod, object->m_pObject, params, nullptr);
    return nullptr;
}

CCSMethod::CCSMethod()
    : m_pMethod(nullptr)
{
}

CCSMethod::~CCSMethod()
{
}
