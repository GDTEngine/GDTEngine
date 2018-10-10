/**
 * @file     EventManager.hpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "IEventManager.hpp"
#include "Window.hpp"

#include <vector>

namespace gdt
{
    namespace engine
    {
        namespace priv
        {
            /**
             * @brief Manages events.
             */
            class ENGINE_API CEventManager final : public IEventManager
            {
            public:

                CEventManager();

                /**
                 * @brief Destructor.
                 */
                ~CEventManager();

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

                std::vector<SInputAction> m_actions;
            };
        }
    }
}
