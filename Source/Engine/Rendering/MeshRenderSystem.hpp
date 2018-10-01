/**
 * @file     MeshRenderSystem.hpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#pragma once

#include "EngineAPI.hpp"
#include "System.hpp"

namespace gdt
{
    namespace engine
    {
        class ENGINE_API CMeshRenderSystem : public CSystem<CMeshRenderSystem>
        {
            GENERATE_SYSTEM_BODY(CMeshRenderSystem)

        protected:

            void beginPlay(CEntity* entity) override;

            void endPlay(CEntity* entity) override;

            void tick(f32 deltaTime) override;
        };
    }
}
