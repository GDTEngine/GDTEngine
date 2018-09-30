/**
 * @file     MeshRenderSystem.hpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#pragma once

#include "ComponentSystem.hpp"
#include "EngineAPI.hpp"

namespace gdt
{
    namespace engine
    {
        class ENGINE_API CMeshRenderSystem : public CComponentSystem<CMeshRenderSystem>
        {
            GENERATE_COMPONENT_SYSTEM_BODY(CMeshRenderSystem)

        protected:

            void beginPlay(CEntity* component) override;

            void endPlay(CEntity* component) override;

            void tick() override;

        private:


        };
    }
}
