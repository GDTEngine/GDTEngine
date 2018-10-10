/**
 * @file     ClassManager.hpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "EngineAPI.hpp"
#include "IClassManager.hpp"

#include <unordered_map>
#include <string>

namespace gdt
{
    namespace engine
    {
        namespace priv
        {
            /**
             * @brief Manager for handling classes.
             */
            class ENGINE_API CClassManager final : public IClassManager
            {
            public:

                CClassManager();

                /**
                 * @brief Destructor.
                 */
                ~CClassManager();

                /**
                 * @brief Create an entity.
                 * @param className Name of the entity class.
                 */
                CEntity* createEntity(const std::string& className) override;

                /**
                 * @brief Register an entity class.
                 * @param className Name of the entity class.
                 * @param function Function used to create an entity.
                 */
                void registerEntity(const std::string& className, CreateEntityFunction function) override;

            private:

                std::unordered_map<std::string, CreateEntityFunction> m_entityClasses;
            };
        }
    }
}
