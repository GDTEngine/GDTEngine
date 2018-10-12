/**
 * @file     CameraComponent.hpp
 * @author   Ludvig Arlebrink
 * @date     10/11/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "Component.hpp"

namespace gdt
{
    namespace engine
    {
        struct SCameraComponent final : public SComponent
        {
        public:

            enum class EProjection : uint32
            {
                Orthographic,
                Perspective
            };

        public:

            /**
             * @breif Projection.
             */
            EProjection projection;

            /**
             * @breif Field of view.
             */
            f32 fieldOfView;
        };
    }
}
