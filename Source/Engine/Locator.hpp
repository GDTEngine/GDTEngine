/**
 * @file     Locator.hpp
 * @author   Ludvig Arlebrink
 * @date     10/9/2018
 */

#pragma once

#include "ClassManager.hpp"
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

        class CLocator final
        {
            friend priv::Engine;

        public:

            std::shared_ptr<CClassManager> classManager();

            std::shared_ptr<CPluginManager> pluginManager();

        private:

            CLocator();

            ~CLocator();
        };
    }
}
