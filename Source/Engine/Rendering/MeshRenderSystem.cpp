/**
 * @file     MeshRenderSystem.hpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#include "MeshRenderSystem.hpp"
#include "TransformComponent.hpp"
#include "EntityManager.hpp"

#include <vector>

using namespace gdt;
using namespace engine;

void CMeshRenderSystem::beginPlay(CEntity* entity)
{
}

void CMeshRenderSystem::endPlay(CEntity* entity)
{
}

void CMeshRenderSystem::tick(f32 deltaTime)
{
    std::vector<SComponent*> transforms = CEntityManager::get().getComponentsOfType<STransformComponent>();

    for (auto& t : transforms)
    {
        STransformComponent* te = CEntityManager::get().getComponent<STransformComponent>(t->entityID);
        te->position.x += 1.0f;
    }
}
