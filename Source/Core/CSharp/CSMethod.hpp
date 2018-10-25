/**
 * @file     CSMethod.hpp
 * @author   Ludvig Arlebrink
 * @date     10/25/2018
 */

#include "../CoreAPI.hpp"
#include "../BaseTypes.hpp"

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

namespace gdt
{
    namespace core
    {
        class CCSObject;

        class CORE_API CCSMethod final
        {
            friend class CCSClass;

        public:

            void* callStatic();

            void* callStatic(void** params);

            void* call(CCSObject* object);

            void* call(CCSObject* object, void** params);

        private:
            
            CCSMethod();
            
            ~CCSMethod();

        private:

            MonoMethod* m_pMethod;
        };
    }
}
