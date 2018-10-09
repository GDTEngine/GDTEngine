/**
 * @file     Engine.hpp
 * @author   Ludvig Arlebrink
 * @date     10/9/2018
 */

#pragma once

#include "Locator.hpp"

#include <memory>

namespace gdt
{
    namespace engine
    {
        namespace priv
        {
            class CEngine
            {
            public:

                CEngine();

                CEngine(const CEngine&) = delete;

                CEngine(CEngine&&) = delete;

                ~CEngine();

                void operator=(CEngine&) = delete;

                void run();

            private:

                std::shared_ptr<CLocator> m_locator;
                std::shared_ptr<CClassManager> m_pClassManager;
                std::shared_ptr<CPluginManager> m_pPluginManager;
            };
        }
    }
}
