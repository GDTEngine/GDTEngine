/**
 * @file     EventManager.hpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "EngineAPI.hpp"
#include "Entity.hpp"
#include "InputAction.hpp"
#include "Window.hpp"

#include <vector>

#define ACTION_CB(className, functionName) \
    [](void* pObject) { static_cast<className*>(pObject)->functionName(); }

namespace gdt
{
    namespace engine
    {
        /**
         * @brief Manages events.
         */
        class ENGINE_API CEventManager
        {
        public:

            /**
             * @brief Bind an action.
             * @param actionId Id of the cation.
             * @param state State of the key.
             * @param pObject Instance of the object callback.
             * @param actionCallback Callback function.
             */
            void bindAction(const std::string& actionId, core::EKeyState state, void* pObject,
                SInputAction::ActionCallback actionCallback);

            /**
             * @brief Get the singleton instance.
             * @return Singleton instance.
             */
            static CEventManager& get();

            /**
             * @brief Register an action.
             * @param action Information about the action.
             */
            void registerAction(const SInputAction& action);

            /**
             * @brief Update this manager.
             * @window Window to recive events from.
             */
            void update(core::CWindow& window);

        private:

            CEventManager() = default;

            ~CEventManager() = default;

        private:

            std::vector<SInputAction> m_actions;
        };
    }
}