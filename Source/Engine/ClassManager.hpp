/**
 * @file     ClassManager.hpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "Entity.hpp"

#include <unordered_map>
#include <string>

namespace gdt
{
    namespace engine
    {
        /**
         * @brief Manager for handling classes.
         */
        class CClassManager
        {
        public:

            using createEntityFunction = CEntity*(*)();

        public:

            /**
             * @brief Create an entity.
             * @param className Name of the entity class.
             */
            CEntity* createEntity(const std::string& className);

            /**
             * @brief Register an entity class.
             * @param className Name of the entity class.
             * @param function Function used to create an entity.
             */
            void registerEntity(const std::string& className, createEntityFunction function);

        private:

            CClassManager() = default;
            ~CClassManager() = default;

        private:

            std::unordered_map<std::string, createEntityFunction> m_entityClasses;
        };
    }
}
