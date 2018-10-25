/**
 * @file     InputAction.hpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "KeyState.hpp"
#include "KeyCode.hpp"

#include <string>

namespace gdt
{
    namespace engine
    {
        class CEntity;

        /**
         * @brief Information about a certain action.
         */
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

            /**
             * @brief Constructor.
             * @param actionId Id of th action.
             * @param key Key related to the action.
             */
            SInputAction(const std::string& actionId, core::EKeyCode key)
            {
                memcpy(this->actionId, actionId.c_str(), actionId.size() + 1);
                this->key = key;
            }

        public:

            /**
             * @brief Id of th action.
             */
            char actionId[32];

            /**
             * @brief Key related to the action.
             */
            core::EKeyCode key;

        private:

            SCallbackInfo m_pCallbackInfo[8];
            int32 m_callbacksCount = 0;
        };
    }
}
