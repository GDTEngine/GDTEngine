/**
 * @file     CSClass.hpp
 * @author   Ludvig Arlebrink
 * @date     10/25/2018
 */

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

            CCSMethod* findMethod(const std::string& methodName);

        private:

            CCSClass();
            
            ~CCSClass();

        private:

            MonoClass* m_pClass;
        };
    }
}
