/**
 * @file     CameraComponent.hpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#include "Component.hpp"
#include "EngineAPI.hpp"

namespace gdt
{
    namespace engine
    {
        struct ENGINE_API SMeshRenderComponent : public SComponent
        {
            int32 meshId;
        };
    }
}
