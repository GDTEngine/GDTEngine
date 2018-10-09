/**
 * @file     PluginManager.hpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "Plugin.hpp"

#include <vector>

namespace gdt
{
    namespace engine
    {
        /**
         * @brief Manager for handling plugins.
         */
        class CPluginManager final
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

            std::vector<std::unique_ptr<core::CPlugin>> m_pPlugins;
        };
    }
}
