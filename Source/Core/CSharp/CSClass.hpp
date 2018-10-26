/**
 * @file     CSClass.hpp
 * @author   Ludvig Arlebrink
 * @date     10/25/2018
 */

#pragma once

#include "../CoreAPI.hpp"

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <string>

namespace gdt
{
    namespace core
    {
        class CCSMethod;
        class CCSObject;

        class CORE_API CCSClass final
        {
            friend class CCSAssembly;
            friend class CCSDomain;

        public:

            CCSMethod* getMethod(const std::string& methodName);

            std::string getName() const;

            bool isSubclassOf(CCSClass* pClass);

        private:

            CCSClass();
            
            ~CCSClass();

        private:

            MonoClass* m_pClass;
        };
    }
}
