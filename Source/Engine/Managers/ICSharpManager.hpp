/**
 * @file     ICSharpManager.hpp
 * @author   Ludvig Arlebrink
 * @date     10/26/2018
 */

#pragma once

#include "BaseTypes.hpp"

namespace gdt
{
    namespace engine
    {
        class ENGINE_API ICSharpManager
        {
        public:

            /**
             * @brief Destructor.
             */
            virtual ~ICSharpManager() = default;
        };
    }
}