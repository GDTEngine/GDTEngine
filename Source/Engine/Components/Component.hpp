/**
 * @file     Component.hpp
 * @author   Ludvig Arlebrink
 * @date     10/11/2018
 */

#pragma once

#include "EntityID.hpp"

namespace gdt
{
    namespace engine
    {
        struct SComponent
        {
        public:

            EntityID entityID;
        };
    }
}
