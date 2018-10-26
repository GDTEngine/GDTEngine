/**
 * @file     CSharpManager.hpp
 * @author   Ludvig Arlebrink
 * @date     10/26/2018
 */

#pragma once

#include "CSharp/CSAssembly.hpp"
#include "CSharp/CSClass.hpp"
#include "CSharp/CSDomain.hpp"
#include "CSharp/CSMethod.hpp"
#include "CSharp/CSObject.hpp"
#include "EngineAPI.hpp"
#include "ICSharpManager.hpp"
#include "Object.hpp"

#include <unordered_map>

namespace gdt
{
    namespace engine
    {
        class ENGINE_API CCSharpManager : public CObject, public ICSharpManager
        {
        public:

            /**
             * @brief Default constructor.
             */
            CCSharpManager();

            /**
             * @brief Destructor.
             */
            ~CCSharpManager();

        private:

            core::CCSDomain* m_pDomain;
            core::CCSAssembly* m_pEngineAssembly;

            core::CCSMethod* m_pBehaviorTickMethod;

            std::unordered_map<std::string, core::CCSClass*> m_pBehaviorClasses;
        };
    }
}
