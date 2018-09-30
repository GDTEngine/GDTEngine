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
        /**
         * @brief Manager for handling plugins.
         */
        class ENGINE_API CPluginManager final
        {
        public:

            /**
             * @brief Get the singleton instance.
             * @return Singleton instance.
             */
            static CPluginManager& get();

            /**
             * @brief Start up the manager.
             */
            void startUp();

            /**
             * @brief Shut down the manager.
             */
            void shutDown();

        private:

            CPluginManager() = default;
            ~CPluginManager() = default;

        private:

            std::vector<core::CPlugin*> m_pPlugins;
        };
    }
}
