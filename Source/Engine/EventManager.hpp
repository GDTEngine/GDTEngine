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
        class ENGINE_API CEventManager
        {
        public:

            void bindAction(const std::string& actionId, core::EKeyState state, void* pObject,
                SInputAction::ActionCallback actionCallback);

            static CEventManager& get();

            void registerAction(const SInputAction& action);

            void update(core::CWindow& window);

        private:

            CEventManager() = default;

            ~CEventManager() = default;

        private:

            std::vector<SInputAction> m_actions;
        };
    }
}