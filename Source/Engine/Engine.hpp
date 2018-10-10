/**
 * @file     Engine.hpp
 * @author   Ludvig Arlebrink
 * @date     10/9/2018
 */

#pragma once

#include "EngineAPI.hpp"

#include <memory>

namespace gdt
{
    namespace engine
    {
        namespace priv
        {
            class ENGINE_API CEngine
            {
            public:

                CEngine();

                CEngine(const CEngine&) = delete;

                CEngine(CEngine&&) = delete;

                ~CEngine();

                void operator=(CEngine&) = delete;

                void run();
            };
        }
    }
}
