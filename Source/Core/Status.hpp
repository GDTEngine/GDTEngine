/**
 * @file     Status.hpp
 * @author   Ludvig Arlebrink
 * @date     9/17/2018
 */

#pragma once

namespace gdt
{
    namespace core
    {
        /**
         * @brief Use this enum class to check status of various things.
         */
        enum class EStatus
        {
            /** Failure. */
            Failure = 0,

            /** Success. */
            Success
        };
    }
}
