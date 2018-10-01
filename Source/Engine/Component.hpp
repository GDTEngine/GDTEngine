/**
 * @file     Component.hpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#pragma once

#include "EngineAPI.hpp"
#include "EntityID.hpp"

namespace gdt
{
    namespace engine
    {
        struct ENGINE_API SComponent
        {
        public:

        public:

            EntityID entityID;
            size_t structID;
        };
    }
}
