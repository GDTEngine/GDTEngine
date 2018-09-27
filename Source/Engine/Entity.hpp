/**
 * @file     Entity.cpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "BaseTypes.hpp"

namespace gdt
{
    namespace engine
    {
        /**
         * @brief Base class for all entities.
         */
        class CEntity
        {
        public:

            using entityId = uint32;

        public:

            CEntity();

            CEntity(const CEntity&) = delete;

            virtual ~CEntity();

            void operator=(const CEntity&) = delete;

            entityId getEntityId() const;

        protected:

            virtual void beginPlay();

            virtual void endPlay();

            virtual void tick(f32 deltaTime);

        private:

            entityId m_entityId;
        };
    }
}
