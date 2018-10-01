/**
 * @file     CameraComponent.hpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "Component.hpp"
#include "EngineAPI.hpp"

namespace gdt
{
    namespace engine
    {
        struct ENGINE_API SCameraComponent : public SComponent
        {
        public:

            /**
             * @brief Field of view.
             */
            f32 fieldOfView;

            f32 nearPlane;

            f32 farPlane;
        };
    }
}
