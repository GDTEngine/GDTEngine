/**
 * @file     CSDomain.hpp
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
        class CCSAssembly;
        class CCSClass;
        class CCSObject;

        class CORE_API CCSDomain final
        {
        public:

            CCSDomain();

            explicit CCSDomain(const std::string& name);

            ~CCSDomain();

            CCSObject* newObject(CCSClass* pClass);

            void open(const std::string& name);

            /**
             * @brief Open csharp assembly.
             * @param filename Filename for dll file.
             * @return Assembly.
             */
            CCSAssembly* openAssembly(const std::string& filename);

        private:

            MonoDomain* m_pDomain;
        };
    }
}
