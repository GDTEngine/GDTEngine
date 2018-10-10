/**
 * @file     PluginManager.hpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "EngineAPI.hpp"
#include "Plugin.hpp"

#include <vector>

namespace gdt
{
    namespace engine
    {
        namespace priv
        {
            /**
             * @brief Manager for handling plugins.
             */
            class ENGINE_API CPluginManager final
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

            private:

                std::vector<core::CPlugin*> m_pPlugins;
            };
        }
    }
}
