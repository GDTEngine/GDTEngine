/**
 * @file     ClassManager.hpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "EngineAPI.hpp"
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
        class ENGINE_API CClassManager
        {
        public:

            using CreateEntityFunction = CEntity * (*)();

        public:

            /**
             * @brief Get the singleton instance.
             * @return Singleton instance.
             */
            static CClassManager& get();

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
            void registerEntity(const std::string& className, CreateEntityFunction function);

        private:

            CClassManager() = default;

            ~CClassManager() = default;

        private:

            std::unordered_map<std::string, CreateEntityFunction> m_entityClasses;
        };
    }
}
