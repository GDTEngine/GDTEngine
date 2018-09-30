/**
 * @file     ComponentSystem.hpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#pragma once

#include "EngineAPI.hpp"

#define GENERATE_COMPONENT_SYSTEM_BODY(className) \
private: \
    friend class CComponentSystem<className>; \
    className() = default; \
    ~className() = default;

namespace gdt
{
    namespace engine
    {
        class CEntity;

        class ENGINE_API CComponentSystemBase
        {
            friend class CComponentSystemManager;

        protected:

            CComponentSystemBase() = default;

            virtual ~CComponentSystemBase() = default;

            virtual void beginPlay(CEntity* component);

            virtual void endPlay(CEntity* component);

            virtual void update();

        };

        template <typename T>
        class CComponentSystem : public CComponentSystemBase
        {
        public:

            static T& get();

        protected:

            CComponentSystem = default;

            virtual ~CComponentSystem = default;

        };

        template<typename T>
        inline T & CComponentSystem<T>::get()
        {
            static T instance;
            return instance;
        }
    }
}
