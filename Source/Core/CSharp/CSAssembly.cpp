/**
 * @file     CSAssembly.cpp
 * @author   Ludvig Arlebrink
 * @date     10/25/2018
 */

#include "CSAssembly.hpp"
#include "CSClass.hpp"

using namespace gdt;
using namespace core;

CCSClass* CCSAssembly::getClass(const std::string& classNamespace, const std::string& className)
{
    MonoClass* pMonoClass = mono_class_from_name(m_pImage, classNamespace.c_str(), className.c_str());
    CCSClass* pClass = new CCSClass;
    pClass->m_pClass = pMonoClass;
    return pClass;
}

CCSAssembly::CCSAssembly()
    : m_pAssembly(nullptr)
    , m_pImage(nullptr)
{
}

CCSAssembly::~CCSAssembly()
{
}
