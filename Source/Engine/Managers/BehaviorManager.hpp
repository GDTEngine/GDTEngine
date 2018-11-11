/**
 * @file     BehaviorManager.hpp
 * @author   Ludvig Arlebrink
 * @date     10/26/2018
 */

#pragma once

#include "CSharp/CSMethod.hpp"
#include "CSharp/CSObject.hpp"
#include "IBehaviorManager.hpp"
#include "Object.hpp"

#include <vector>

namespace gdt
{
    namespace engine
    {
        class ENGINE_API CBehaviorManager : public CObject, public IBehaviorManager
        {
        public:

            /**
             * @brief Constructor.
             */
            CBehaviorManager();

            /**
             * @brief Destructor.
             */
            ~CBehaviorManager();

            void postTick(f32 deltaTime) override;

            void preTick(f32 deltaTime) override;

            void tick(f32 deltaTime) override;

        private:
            
            core::CCSMethod* m_pPostTick;
            core::CCSMethod* m_pPreTick;
            core::CCSMethod* m_pTick;

            std::vector<core::CCSObject*> m_pBehaviors;
        };
    }
}
