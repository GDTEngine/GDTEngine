/**
 * @file     CSAssembly.hpp
 * @author   Ludvig Arlebrink
 * @date     10/25/2018
 */

#pragma once

#include "../BaseTypes.hpp"
#include "../CoreAPI.hpp"

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <string>
#include <vector>

namespace gdt
{
    namespace core
    {
        class CCSClass;

        class CORE_API CCSAssembly final
        {
            friend class CCSDomain;

        public:

            CCSClass* getClass(const std::string& classNamespace, const std::string& className);

            std::vector<CCSClass*> getAllClasses();

        private:

            CCSAssembly();

            ~CCSAssembly();


        private:

            MonoAssembly* m_pAssembly;
            MonoImage* m_pImage;
        };
    }
}
