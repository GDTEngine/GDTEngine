/**
 * @file     Locator.hpp
 * @author   Ludvig Arlebrink
 * @date     10/9/2018
 */

#pragma once

#include "ClassManager.hpp"
#include "EngineAPI.hpp"
#include "PluginManager.hpp"

#include <memory>

namespace gdt
{
    namespace engine
    {
        namespace priv
        {
            class CEngine;
        }

        class ENGINE_API CLocator final
        {
            friend priv::CEngine;

        public:

            std::shared_ptr<priv::CClassManager> classManager();

            std::shared_ptr<priv::CPluginManager> pluginManager();

        private:

            CLocator();

            ~CLocator();
        };
    }
}
