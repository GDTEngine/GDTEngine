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

std::vector<CCSClass*> CCSAssembly::getAllClasses()
{
    std::vector<CCSClass*> pClassList;

    const MonoTableInfo* pTableInfo = mono_image_get_table_info(m_pImage, MONO_TABLE_TYPEDEF);
    int32 rows = mono_table_info_get_rows(pTableInfo);

    for (int32 i = 0; i < rows; ++i)
    {
        MonoClass* pMonoClass = nullptr;
        uint32 cols[MONO_TYPEDEF_SIZE];
        mono_metadata_decode_row(pTableInfo, i, cols, MONO_TYPEDEF_SIZE);
        const char* pName = mono_metadata_string_heap(m_pImage, cols[MONO_TYPEDEF_NAME]);
        const char* pNamespace = mono_metadata_string_heap(m_pImage, cols[MONO_TYPEDEF_NAMESPACE]);
        pMonoClass = mono_class_from_name(m_pImage, pNamespace, pName);

        CCSClass* pClass = new CCSClass;
        pClass->m_pClass = pMonoClass;

        pClassList.push_back(pClass);
    }

    return pClassList;
}


CCSAssembly::CCSAssembly()
    : m_pAssembly(nullptr)
    , m_pImage(nullptr)
{
}

CCSAssembly::~CCSAssembly()
{
}
