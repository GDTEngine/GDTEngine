/**
 * @file     CSMethod.hpp
 * @author   Ludvig Arlebrink
 * @date     10/25/2018
 */

#pragma once

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

            void call(CCSObject* pObject);

            void call(CCSObject* pObject, void** pParams);

            void callStatic();

            void callStatic(void** pParams);

            void callVirtual(CCSObject* pObject);

            void callVirtual(CCSObject* pObject, void** pParams);

        private:
            
            CCSMethod();
            
            ~CCSMethod();

        private:

            MonoMethod* m_pMethod;
        };
    }
}
