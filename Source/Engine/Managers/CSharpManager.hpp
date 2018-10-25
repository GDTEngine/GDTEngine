/**
 * @file     CSharpManager.hpp
 * @author   Ludvig Arlebrink
 * @date     10/26/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "CSharp/CSAssembly.hpp"
#include "CSharp/CSClass.hpp"
#include "CSharp/CSDomain.hpp"
#include "CSharp/CSMethod.hpp"
#include "CSharp/CSObject.hpp"

#include <unordered_map>

namespace gdt
{
    namespace engine
    {
        class CCSharpManager
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

            void preTick(f32 deltaTime);

            void tick(f32 deltaTime);

            void postTick(f32 deltaTime);

        private:

            core::CCSDomain* m_pDomain;
            core::CCSAssembly* m_pEngineAssembly;

            std::unordered_map<std::string, core::CCSClass*> m_pClasses;
            std::vector<core::CCSObject*> m_pBehaviorObjects;
        };
    }
}
