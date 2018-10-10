/**
 * @file     PluginManager.hpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "EngineAPI.hpp"
#include "IPluginManager.hpp"
#include "Plugin.hpp"

#include <vector>

namespace gdt
{
    namespace engine
    {
        namespace priv
        {
            class IClassManager;

            /**
             * @brief Manager for handling plugins.
             */
            class ENGINE_API CPluginManager final : public IPluginManager
            {
            public:

                /**
                 * @brief Default constructor.
                 */
                CPluginManager();

                /**
                 * @brief Destructor.
                 */
                ~CPluginManager();

                void loadPlugins(const std::string& path, IClassManager* classManager);

            private:

                std::vector<core::CPlugin*> m_pPlugins;
            };
        }
    }
}
