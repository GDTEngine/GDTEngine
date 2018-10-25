/**
 * @file     CSObject.hpp
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
        class CORE_API CCSObject final
        {
            friend class CCSDomain;
            friend class CCSMethod;

        public:

             

        private:

            CCSObject();

            ~CCSObject();

        private:

            MonoObject* m_pObject;
        };
    }
}
