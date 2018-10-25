/**
 * @file     IEventManager.hpp
 * @author   Ludvig Arlebrink
 * @date     10/10/2018
 */

#pragma once

#include "EngineAPI.hpp"
#include "InputAction.hpp"
#include "Window.hpp"

#define ACTION_CB(className, functionName) \
    [](void* pObject) { static_cast<className*>(pObject)->functionName(); }

namespace gdt
{
    namespace engine
    {
        class ENGINE_API IEventManager
        {
        public:

            /**
             * @brief Destructor.
             */
            virtual ~IEventManager() = default;

            /**
             * @brief Bind an action.
             * @param actionId Id of the cation.
             * @param state State of the key.
             * @param pObject Instance of the object callback.
             * @param actionCallback Callback function.
             */
            virtual void bindAction(const std::string& actionId, core::EKeyState state, void* pObject,
                SInputAction::ActionCallback actionCallback) = 0;

            /**
             * @brief Register an action.
             * @param action Information about the action.
             */
            virtual void registerAction(const SInputAction& action) = 0;

            /**
             * @brief Update this manager.
             * @window Window to recive events from.
             */
            virtual void update(core::CWindow& window) = 0;
        };
    }
}
