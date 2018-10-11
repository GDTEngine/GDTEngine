/**
 * @file     Entity.cpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "EntityID.hpp"
#include "EngineAPI.hpp"
#include "Object.hpp"

#include <GLM/glm.hpp>
#include <GLM/gtc/quaternion.hpp>

namespace gdt
{
    namespace engine
    {
        namespace priv
        {
            class CEntityManager;
        }

        /**
         * @brief Base class for all entities.
         */
        class ENGINE_API CEntity : public CObject
        {
            friend priv::CEntityManager;

        public:

            /**
             * @brief Default constructor.
             */
            CEntity();

            CEntity(const CEntity&) = delete;

            /**
             * @brief Destructor.
             */
            virtual ~CEntity();

            void operator=(const CEntity&) = delete;

            /**
             * @brief Get the forward vector based on the objects rotation.
             * @return Forward vector based on the objects rotation.
             */
            glm::vec3 getForward() const;

            /**
             * @brief Get the id of this entity.
             * @return ID of this entity.
             */
            EntityID getID() const;

            /**
             * @brief Get the rotation of the local pitch in degrees.
             * @return Rotation of the local pitch in degrees.
             */
            f32 getLocalPitch() const;

            /**
             * @brief Get the local position of this entity.
             * @return Local position of this entity.
             */
            glm::vec3 getLocalPosition() const;

            /**
             * @brief Get the rotation of the local roll in degrees.
             * @return Rotation of the local roll in degrees.
             */
            f32 getLocalRoll() const;

            /**
             * @brief Get the local rotation of the entity.
             * @return Local rotation of the entity.
             */
            glm::quat getLocalRotation() const;

            /**
             * @brief Get the local scale of the entity.
             * @return Local scale of the entity.
             */
            glm::vec3 getLocalScale() const;

            /**
             * @brief Get the rotation of the yaw in degrees.
             * @return Rotation of the yaw in degrees.
             */
            f32 getLocalYaw() const;

            /**
             * @brief Get the right vector based on the objects rotation.
             * @return Right vector based on the objects rotation.
             */
            glm::vec3 getRight() const;

            /**
             * @brief Get the up vector based on the objects rotation.
             * @return Up vector based on the objects rotation.
             */
            glm::vec3 getUp() const;

            /**
             * @brief Check whenever this entity is enabled or not.
             * @return true if enabled.
             */
            bool isEnabled();

            /**
             * @brief Enable or disable this entity.
             * @param true if enabled, false if not.
             *
             * Disabling this entity will also disable all of its components.
             */
            void setEnabled(bool enabled);

            /**
             * @brief Set the rotation of the local pitch in degrees.
             * @return Rotation of the local pitch in degrees.
             */
            void setLocalPitch(f32 angle);

            /**
             * @brief Set the local position of the entity.
             * @param Position of the entity.
             */
            void setLocalPosition(const glm::vec3& position);

            /**
             * @brief Set the local position of the entity.
             * @param x Local position along the x axis.
             * @param y Local position along the y axis.
             * @param z Local position along the z axis.
             */
            void setLocalPosition(f32 x, f32 y, f32 z);

            /**
             * @brief Set the rotation of the local roll in degrees.
             * @return Rotation of the local roll in degrees.
             */
            void setLocalRoll(f32 angle);

            /**
             * @brief Set the local rotation of the entity.
             * @param rotation Local rotation of the entity.
             */
            void setLocalRotation(const glm::quat& rotation);

            /**
             * @brief Set the scale of the entity.
             * @param scale Local scale of the entity.
             */
            void setLocalScale(const glm::vec3& scale);

            /**
             * @brief Set the scale of the entity.
             * @param x X local axis scale.
             * @param y Y local axis scale.
             * @param z Z local axis scale.
             */
            void setLocalScale(f32 x, f32 y, f32 z);

            /**
             * @brief Set a uniform scale of the entity.
             * @param uniform Uni
             */
            void setLocalScale(f32 uniform);

            /**
             * @brief Set the local rotation of the yaw in degrees.
             * @return Rotation of the local yaw in degrees.
             */
            void setLocalYaw(f32 angle);

        protected:

            /**
             * @brief Called when the class is instantiated.
             */
            virtual void beginPlay();

            /**
             * @brief Called when the class is destroyed.
             */
            virtual void endPlay();

            /**
             * @brief Called every frame.
             * @param deltaTime Time it took to render the last frame in seconds.
             */
            virtual void tick(f32 deltaTime);

        private:

            bool m_isEnabled;

            EntityID m_entityID;

            glm::vec3 m_position;
            glm::vec3 m_scale;
            glm::quat m_rotation;
        };
    }
}
