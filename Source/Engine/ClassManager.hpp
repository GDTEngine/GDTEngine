/**
 * @file     ClassManager.hpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "EngineAPI.hpp"

#include <unordered_map>
#include <string>

namespace gdt
{
    namespace engine
    {
        class CEntity;
        class CSystemBase;

        struct SComponent;

        /**
         * @brief Manager for handling classes.
         */
        class ENGINE_API CClassManager
        {
        public:
            
            using ClassID = size_t;
            using StructID = size_t;

            using CreateComponentFunction = SComponent* (*)();
            using CreateEntityFunction = CEntity* (*)();
            using GetSystemFunction = CSystemBase* (*)();
            using IterateSystemsFunction = void (*)(CSystemBase*);

        public:

            template <typename ComponentType>
            ComponentType* createComponent();

            SComponent* createComponent(StructID structID);

            /**
             * @brief Create an entity.
             */
            template <typename EntityType>
            EntityType* createEntity();

            /**
             * @brief Create an entity.
             * @param className Name of the entity class.
             */
            CEntity* createEntity(ClassID classID);

            void forEachSystem(IterateSystemsFunction function);

            /**
             * @brief Get the singleton instance.
             * @return Singleton instance.
             */
            static CClassManager& get();

            template <typename SystemType>
            SystemType* getSystem();

            CSystemBase* getSystem(ClassID classID);

            template <typename ComponentType>
            void registerComponent(CreateComponentFunction function);

            void registerComponent(StructID structID, CreateComponentFunction function);

            template <typename EntityType>
            void registerEntity(CreateEntityFunction function);

            /**
             * @brief Register an entity class.
             * @param className Name of the entity class.
             * @param function Function used to create an entity.
             */
            void registerEntity(ClassID classID, CreateEntityFunction function);

            /**
             * @
             */
            template <typename SystemType>
            void registerSystem(GetSystemFunction function);

            void registerSystem(ClassID classID, GetSystemFunction function);

        private:

            CClassManager() = default;

            ~CClassManager() = default;

        private:

            std::unordered_map<StructID, CreateComponentFunction> m_componentStructs;
            std::unordered_map<ClassID, CreateEntityFunction> m_entityClasses;
            std::unordered_map<ClassID, GetSystemFunction> m_systemClasses;
        };

        template<typename ComponentType>
        ComponentType* CClassManager::createComponent()
        {
            return static_cast<ComponentType*>(createEntity(typeid(ComponentType).hash_code));
        }

        template<typename EntityType>
        EntityType* CClassManager::createEntity()
        {
            return static_cast<EntityType*>(createEntity(typeid(EntityType).hash_code));
        }

        template<typename SystemType>
        SystemType* CClassManager::getSystem()
        {
            return static_cast<SystemType*>(getSystem(typeid(SystemType).hash_code));
        }

        template<typename ComponentType>
        void CClassManager::registerComponent(CreateComponentFunction function)
        {
            registerComponent(typeid(ComponentType).hash_code(), function);
        }

        template<typename EntityType>
        void CClassManager::registerEntity(CreateEntityFunction function)
        {
            registerEntity(typeid(EntityType).hash_code(), function);
        }

        template<typename SystemType>
        void CClassManager::registerSystem(GetSystemFunction function)
        {
            registerSystem(typeid(SystemType).hash_code(), function);
        }
    }
}
