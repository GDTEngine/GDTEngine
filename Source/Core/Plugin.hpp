/**
 * @file     Plugin.hpp
 * @author   Ludvig Arlebrink
 * @date     9/27/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "CoreAPI.hpp"
#include "Status.hpp"

#include <string>
#ifdef _WIN32
#include <Windows.h>
#elif __linux__
 // @todo Linux implementation.
#endif // _WIN32

namespace gdt
{
    namespace core
    {
        /**
         * @brief Wrapper for dll plugin.
         */
        class CORE_API CPlugin final
        {
        public:

            /**
             * @brief Default constructor.
             */
            CPlugin();

            CPlugin(const CPlugin&) = delete;

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

            void operator=(const CPlugin&) = delete;

            /**
             * @brief Call a c function in the plugin without no params or return type.
             * @param functionName Name of the function to call.
             */
            void callFunction(const std::string& functionName);

            /**
             * @brief Get a string of errors.
             * @return String of errors.
             * @note Only works in debug mode.
             *
             * Check 'EStatus' by calling 'getStatus'. If EStatus is equals to 'Failure', call this class to get more information.
             */
            std::string getErrorString() const;

            /**
             * @brief Check if everything regarding shader compelation went right.
             * @return 'Success' if everything went right.
             *
             * Call 'getErrorString' to get more information about the errors.
             */
            EStatus getStatus() const;

            /**
             * @brief Load a plugin.
             * @pluginFilepath Filepath to plugin.
             */
            void loadPlugin(const std::string& pluginFilepath);

            /**
             * @brief Reload the plugin.
             */
            void reloadPlugin();

            /**
             * @brief Unload the plugin.
             */
            void unloadPlugin();

        private:

            bool m_pluginIsLoaded;
            EStatus m_status;

        #ifdef GDT_DEBUG || GDT_EDITOR
            std::string m_errorString;
        #endif // GDT_DEBUG || GDT_EDITOR

            std::string m_pluginFilepath;

        #ifdef _WIN32
            HINSTANCE m_pPlugin;
        #elif __linux__
            void* m_pPlugin;
        #endif // _WIN32
        };
    }
}
