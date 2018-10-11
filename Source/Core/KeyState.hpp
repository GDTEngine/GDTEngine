/**
 * @file     KeyState.hpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "BaseTypes.hpp"

namespace gdt
{
    namespace core
    {
        /**
         * @brief Describes a state of a key.
         */
        enum class EKeyState : int32
        {
            /** The key is untouched. */
            None = 0,

            /** The key was pressed. */
            Pressed,

            /** The key held down. */
            Held,

            /** The key was released. */
            Released
        };
    }
}
