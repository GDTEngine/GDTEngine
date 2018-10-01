/**
 * @file     EntityManager.cpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#include "EntityManager.hpp"
#include "ClassManager.hpp"
#include "Entity.hpp"
#include "Component.hpp"
#include "System.hpp"

// Systems.
#include "Rendering/MeshRenderSystem.hpp"

// Components.
#include "Rendering/CameraComponent.hpp"
#include "Rendering/MeshRenderComponent.hpp"
#include "TransformComponent.hpp"

using namespace gdt;
using namespace engine;

SComponent* CEntityManager::addComponent(CClassManager::StructID structID, EntityID entityID)
{
    SComponent* component = CClassManager::get().createComponent(structID);
    component->entityID = entityID;
    component->structID = structID;

    auto itr = m_components.find(structID);

    if (itr != m_components.end())
    {
        itr->second.push_back(component);
    }
    else
    {
        std::vector<SComponent*> components;
        components.push_back(component);
        m_components.emplace(structID, components);
    }

    auto entity = m_entites.at(entityID);
    entity.pComponents->push_back(component);

    return component;
}

CEntityManager& CEntityManager::get()
{
    static CEntityManager instance;
    return instance;
}

CEntity* CEntityManager::instantiate(CClassManager::ClassID classID)
{
    CEntity* entity = CClassManager::get().createEntity(classID);
    entity->m_entityID = m_entityID;

    SEntityInfo entityInfo;
    entityInfo.pEntity = entity;
    entityInfo.pComponents = new std::vector<SComponent*>;

    m_entites.emplace(m_entityID, entityInfo);
    addComponent<STransformComponent>(m_entityID);
    ++m_entityID;

    entity->beginPlay();

    return entity;
}

void CEntityManager::startUp()
{
    // Systems.
    CClassManager::get().registerSystem<CMeshRenderSystem>([]()->CSystemBase* { return &CMeshRenderSystem::get(); });

    // Components.
    // Default.
    CClassManager::get().registerComponent<STransformComponent>([]()->SComponent* { return new STransformComponent; });
    
    // Rendering.
    CClassManager::get().registerComponent<SCameraComponent>([]()->SComponent* { return new SCameraComponent; });
    CClassManager::get().registerComponent<SMeshRenderComponent>([]()->SComponent* { return new SMeshRenderComponent; });
}

void CEntityManager::shutDown()
{
    instantiate(m_initialEntity);
}

void CEntityManager::update(f32 deltaTime)
{
    for (auto entity : m_entites)
    {
        entity.second.pEntity->tick(deltaTime);
    }

    CClassManager::get().forEachSystem([](CSystemBase* system) { system->tick(0.1f); });
}
