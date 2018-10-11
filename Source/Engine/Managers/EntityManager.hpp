/**
 * @file     ClassManager.hpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "EngineAPI.hpp"
#include "EntityID.hpp"
#include "IEntityManager.hpp"

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
            class ENGINE_API CEntityManager final : public IEntityManager
            {
            public:

                /**
                 * @brief The maximum amount of entities allowed.
                 */
                static const int32 MaxEntites = 1024;

            public:

                /**
                 * @brief Default constructor.
                 */
                CEntityManager();

                /**
                 * @brief Destructor.
                 */
                ~CEntityManager();

                /**
                 * @brief Create an entity.
                 * @param classID Hash id of the entity class.
                 */
                CEntity* instantiate(ClassID classID) override;

                /**
                 * @brief Register an entity class.
                 * @param classID Hash id of the entity class.
                 * @param function Function used to create an entity.
                 */
                void registerEntity(ClassID classID, CreateEntityFunction function) override;

                /**
                 * @brief Tick through all enabled and active entites.
                 * @brief deltaTime Delta time.
                 */
                void tick(f32 deltaTime);

            private:

                std::unordered_map<ClassID, CreateEntityFunction> m_entityClasses;

                EntityID m_entityCount;
                CEntity* m_pEntities[MaxEntites];
            };
        }
    }
}
