/**
 * @file     Transform.hpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "BaseTypes.hpp"

#include <GLM/glm.hpp>
#include <GLM/gtc/quaternion.hpp>

namespace gdt
{
    namespace engine
    {
        class CTransform
        {
        public:
            
            CTransform();

            virtual ~CTransform();

            /**
             * @brief Get the rotation of the pitch in degrees.
             * @return Rotation of the pitch in degrees.
             */
            f32 getPitch() const;

            glm::vec3 getPosition() const;

            /**
             * @brief Get the rotation of the roll in degrees.
             * @return Rotation of the roll in degrees.
             */
            f32 getRoll() const;

            glm::quat getRotation() const;

            glm::vec3 getScale() const;

            f32 getYaw() const;

            void setPitch(f32 angle);

            void setPosition(const glm::vec3& position);

            void setPosition(f32 x, f32 y, f32 z);

            void setRoll(f32 angle);

            void setRotation(const glm::quat& rotation);

            void setScale(const glm::vec3& scale);

            void setScale(f32 x, f32 y, f32 z);

            void setYaw(f32 angle);

        private:

            glm::vec3 m_position;
            glm::vec3 m_scale;
            glm::quat m_rotation;
        };
    }
}
