/**
 * @file     Entity.cpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "EngineAPI.hpp"

namespace gdt
{
    namespace engine
    {
        /**
         * @brief Base class for all entities.
         */
        class ENGINE_API CEntity
        {
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

        public:

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


        };
    }
}
