/**
 * @file     EntityManager.hpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#pragma once

#include "Assets/Mesh.hpp"
#include "Shader.hpp"
#include "ClassManager.hpp"
#include "EngineAPI.hpp"
#include "EntityID.hpp"
#include "Log.hpp"

#include <unordered_map>
#include <string>

namespace gdt
{
    namespace engine
    {
        class CEntity;
        struct SComponent;

        class ENGINE_API CEntityManager
        {
        private:

            struct SEntityInfo
            {
                CEntity* pEntity = nullptr;
                std::vector<SComponent*>* pComponents = nullptr;
            };

        public:

            template <typename ComponentType>
            ComponentType* addComponent(EntityID entityID);

            SComponent* addComponent(CClassManager::StructID structID, EntityID entityID);

            static CEntityManager& get();

            template <typename ComponentType>
            ComponentType* getComponent(EntityID entityID);

            template <typename ComponentType>
            std::vector<SComponent*> getComponentsOfType();

            template <typename EntityType>
            EntityType* instantiate();

            CEntity* instantiate(CClassManager::ClassID classID);

            template <typename EntityType>
            void setInitialEntity();

                /**
             * @brief Internal. Start up the manager.
             */
            void startUp();

            /**
             * @brief Internal. Shut down the manager.
             */
            void shutDown();

            /**
             * @brief Internal. Update the manager.
             */
            void update(f32 deltaTime);

        private:

            CEntityManager() = default;

            ~CEntityManager() = default;

        private:

            EntityID m_entityID = 1;

            std::unordered_map<EntityID, SEntityInfo> m_entites;
            std::unordered_map<CClassManager::StructID, std::vector<SComponent*>> m_components;

            CClassManager::ClassID m_initialEntity;

            CMesh* dummy;
            graphics::CShader* shader;
        };

        template<typename ComponentType>
        ComponentType* CEntityManager::addComponent(EntityID entityID)
        {
            return static_cast<ComponentType*>(addComponent(typeid(ComponentType).hash_code(), entityID));
        }

        template<typename ComponentType>
        ComponentType* CEntityManager::getComponent(EntityID entityID)
        {
            SEntityInfo& entityInfo = m_entites.at(entityID);

            for (auto& component : *entityInfo.pComponents)
            {
                if (component->structID = typeid(ComponentType).hash_code())
                {
                    return static_cast<ComponentType*>(component);
                }
            }

            return nullptr;
        }

        template<typename ComponentType>
        std::vector<SComponent*> CEntityManager::getComponentsOfType()
        {
            return m_components.at(typeid(ComponentType).hash_code());
        }

        template<typename EntityType>
        EntityType* CEntityManager::instantiate()
        {
            return static_cast<EntityType*>(instantiate(typeid(EntityType).hash_code()));
        }
        
        template<typename EntityType>
        void CEntityManager::setInitialEntity()
        {
            m_initialEntity = typeid(EntityType).hash_code();
        }
    }
}
