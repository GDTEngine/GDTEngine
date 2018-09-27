/**
 * @file     Plugin.hpp
 * @author   Ludvig Arlebrink
 * @date     9/27/2018
 */

#pragma once

#include "Status.hpp"

#include <string>
#ifdef _WIN32
#include <Windows.h>
#elif __linux__
#include <dlfcn.h>
#endif // _WIN32

namespace gdt
{
    namespace core
    {
        /**
         * @brief Wrapper for dll plugin.
         */
        class CPlugin final
        {
        public:

            /**
             * @brief Default constructor.
             */
            CPlugin();

            CPlugin(const CPlugin& other) = delete;

            /**
             * @brief Move constructor.
             * @other Source.
             */
            CPlugin(CPlugin&& other) noexcept;

            /**
             * @brief Load a plugin.
             * @pluginFilepath Filepath to plugin.
             */
            explicit CPlugin(const std::string& pluginFilepath);

            /**
             * @brief Destructor.
             */
            ~CPlugin();

            void operator=(const CPlugin& rhs) = delete;

            void callFunction(const std::string& functionName);

            EStatus getStatus() const;

            /**
             * @brief Load a plugin.
             * @pluginFilepath Filepath to plugin.
             */
            void loadPlugin(const std::string& pluginFilepath);

            void reloadPlugin();

        private:

            bool m_pluginIsLoaded;
            EStatus m_status;
            std::string m_pluginFilepath;

        #ifdef _WIN32
            HINSTANCE m_pPlugin;
        #elif __linux__
            void* m_pPlugin;
        #endif // _WIN32
        };
    }
}
