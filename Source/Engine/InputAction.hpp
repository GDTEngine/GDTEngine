/**
 * @file     InputAction.hpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "Entity.hpp"
#include "KeyState.hpp"
#include "KeyCode.hpp"

#include <string>

namespace gdt
{
    namespace engine
    {
        struct SInputAction
        {
            friend class CEventManager;

        public:

            using ActionCallback = void(*)(void*);

        private:

            struct SCallbackInfo
            {
                ActionCallback actionCallback;
                void* pObject;
                core::EKeyState keyState;
            };

        public:

            SInputAction(const std::string& actionId, core::EKeyCode key)
            {
                memcpy(this->actionId, actionId.c_str(), actionId.size() + 1);
                this->key = key;
            }

        public:

            char actionId[32];
            core::EKeyCode key;

        private:

            SCallbackInfo m_pCallbackInfo[8];
            int32 m_callbacksCount = 0;
        };
    }
}
