/**
 * @file     CSClass.cpp
 * @author   Ludvig Arlebrink
 * @date     10/25/2018
 */

#include "CSClass.hpp"
#include "CSMethod.hpp"

using namespace gdt;
using namespace core;

CCSMethod* CCSClass::findMethod(const std::string& methodName)
{
    MonoMethod* pMonoMethod = nullptr;
    void* pIterator = nullptr;

    while ((pMonoMethod = mono_class_get_methods(m_pClass, &pIterator)))
    {
        if (strcmp(mono_method_get_name(pMonoMethod), methodName.c_str()) == 0)
        {
            CCSMethod* pMethod = new CCSMethod;
            pMethod->m_pMethod = pMonoMethod;
            return pMethod;
        }
    }

    return nullptr;
}

CCSClass::CCSClass()
{
}

CCSClass::~CCSClass()
{
}