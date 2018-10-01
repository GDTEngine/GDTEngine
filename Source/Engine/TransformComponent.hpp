/**
 * @file     TransformComponent.hpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "Component.hpp"
#include "EntityID.hpp"

#include <GLM/glm.hpp>
#include <GLM/gtc/quaternion.hpp>

namespace gdt
{
    namespace engine
    {
        struct ENGINE_API STransformComponent : public SComponent
        {
        public:

            EntityID parent = 0;

            glm::vec3 position = glm::vec3(0.0f);

            glm::vec3 scale = glm::vec3(0.0f);

            glm::quat rotation = glm::quat(0.0f, 0.0f, 0.0f, 0.0f);
        };
    }
}
