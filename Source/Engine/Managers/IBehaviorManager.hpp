/**
 * @file     IBehaviorManager.hpp
 * @author   Ludvig Arlebrink
 * @date     10/26/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "EngineAPI.hpp"

namespace gdt
{
    namespace engine
    {
        class ENGINE_API IBehaviorManager
        {
        public:

            /**
             * @brief Destructor.
             */
            virtual ~IBehaviorManager() = default;

            virtual void postTick(f32 deltaTime) = 0;

            virtual void preTick(f32 deltaTime) = 0;

            virtual void tick(f32 deltaTime) = 0;
        };
    }
}
