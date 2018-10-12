/**
 * @file     ClassManager.hpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "ClassID.hpp"
#include "Components/ComponentType.hpp"
#include "EngineAPI.hpp"
#include "EntityID.hpp"

#include <string>

namespace gdt
{
    namespace engine
    {
        class CEntity;
        struct SComponent;

        namespace priv
        {
            /**
             * @brief Manager for handling entities.
             */
            class ENGINE_API IEntityManager
            {
            public:

                using CreateEntityFunction = CEntity* (*)();

            public:

                virtual ~IEntityManager() = default;

                virtual SComponent* addComponent(EntityID entityID, EComponentType componentType) = 0;

                /**
                 * @brief Create an entity.
                 * @param classID Hash id of the entity class.
                 */
                virtual CEntity* instantiate(ClassID classID) = 0;

                /**
                 * @brief Register an entity class.
                 * @param classID Hash id of the entity class.
                 * @param function Function used to create an entity.
                 */
                virtual void registerEntity(ClassID classID, CreateEntityFunction function) = 0;
            };
        }
    }
}
