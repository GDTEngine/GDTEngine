/**
 * @file     LevelManager.hpp
 * @author   Ludvig Arlebrink
 * @date     11/11/2018
 */

#pragma once

#include "EngineAPI.hpp"

#include <string>

namespace gdt
{
    namespace engine
    {
        class ENGINE_API CLevelManager
        {
        public:

            CLevelManager();

            ~CLevelManager();

            /**
             * @brief Load a new level and unload the current one.
             * @param levelName Name of the level to load.
             */
            void loadLevel(const std::string& levelName);

        private:


        };
    }
}
