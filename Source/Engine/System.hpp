/**
 * @file     ComponentSystem.hpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "EngineAPI.hpp"

#define GENERATE_SYSTEM_BODY(className) \
private: \
    friend class CSystem<className>; \
    className() = default; \
    ~className() = default;

namespace gdt
{
    namespace engine
    {
        class CEntity;

        class ENGINE_API CSystemBase
        {
            friend class CEntityManager;

        protected:

            CSystemBase() = default;

            virtual ~CSystemBase() = default;

            virtual void beginPlay(CEntity* component);

            virtual void endPlay(CEntity* component);

            virtual void tick(f32 deltaTime);

        };

        template <typename SystemType>
        class CSystem : public CSystemBase
        {
        public:

            static SystemType& get();

        protected:

            CSystem() = default;

            virtual ~CSystem() = default;

        };

        template<typename SystemType>
        inline SystemType & CSystem<SystemType>::get()
        {
            static SystemType instance;
            return instance;
        }
    }
}
