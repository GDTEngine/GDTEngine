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

#include <fstream>

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

    std::vector<CMesh::SVertex> vertices(6);

    vertices[0].position = { 0.5f, 0.5f, 0.0f };
    vertices[1].position = { 0.5f, -0.5f, 0.0f };
    vertices[2].position = { -0.5f, 0.5f, 0.0f };

    vertices[3].position = { 0.5f, -0.5f, 0.0f };
    vertices[4].position = { -0.5f, -0.5f, 0.0f };
    vertices[5].position = { -0.5f, 0.5f, 0.0f };

    vertices[0].color = { 0.5f, 0.5f, 0.0f };
    vertices[1].color = { 0.5f, 0.5f, 0.0f };
    vertices[2].color = { 0.5f, 0.5f, 0.0f };

    vertices[3].color = { 0.5f, 0.5f, 0.0f };
    vertices[4].color = { 0.5f, 0.5f, 0.0f };
    vertices[5].color = { 0.5f, 0.5f, 0.0f };

    dummy = new CMesh;
    shader = new graphics::CShader;

    dummy->setVertices(vertices);

    std::ifstream vs("Default.vs.glsl");
    std::string strVs((std::istreambuf_iterator<char>(vs)),
        std::istreambuf_iterator<char>());

    vs.close();

    std::ifstream fs("Default.fs.glsl");
    std::string strFs((std::istreambuf_iterator<char>(fs)),
        std::istreambuf_iterator<char>());

    fs.close();

    shader->compileProgram(strVs, strFs);

    LOG_MSG(shader->getErrorString());
}

void CEntityManager::update(f32 deltaTime)
{
    for (auto entity : m_entites)
    {
        entity.second.pEntity->tick(deltaTime);
    }

    CClassManager::get().forEachSystem([](CSystemBase* system) { system->tick(0.1f); });

    shader->use();

    dummy->draw();
}
