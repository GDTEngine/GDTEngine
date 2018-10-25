/**
* @file     IPluginManager.hpp
* @author   Ludvig Arlebrink
* @date     10/10/2018
*/

#pragma once

#include "EngineAPI.hpp"
#include "InputAction.hpp"

namespace gdt
{
    namespace engine
    {
        class ENGINE_API IPluginManager
        {
        public:

            /**
             * @brief Destructor.
             */
            virtual ~IPluginManager() = default;
        };
    }
}