/**
 * @file     Window.hpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "CoreAPI.hpp"
#include "KeyState.hpp"
#include "KeyCode.hpp"

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>
#include <string>

namespace gdt
{
    namespace core
    {
        /**
         * @brief A basic window with input.
         */
        class CORE_API CWindow
        {
        public:

            /**
             * @brief Default constructor.
             */
            CWindow();

            /**
             * @brief Destructor.
             */
            virtual ~CWindow();

            /**
             * @brief Creates a window.
             * @param title Title of the window.
             * @param width The width of the window.
             * @param height The height of the window.
             */
            void create(const std::string& title, int32 width, int32 height);

            /**
             * @brief Get the current state of a key.
             * @param keyCode The key to check.
             */
            EKeyState getKeyState(EKeyCode keyCode);

            /**
             * @brief Handle window related input.
             */
            void handleInput();

            /**
             * @brief Check whether the window has the input focus.
             * @return 'true' if in focus.
             */
            bool hasFocus() const;

            /**
             * @brief Check whether the window is visible
             */
            bool isVisible() const;

            /**
             * @brief Make this window the current context.
             */
            void makeThisContextCurrent() const;

            /**
             * @brief Poll events for all windows.
             *
             * Should be called after handle events.
             */
            static void pollEvents();

        protected:

            /**
             * @brief Called when cursor has changed its position.
             * @param position Position of the cursor.
             */
            virtual void onCursorPosition(const glm::vec2& position);

            /**
             * @brief Called when the state of a key has been changed.
             * @param keyCode The that has been modified.
             * @param keyState State of the key.
             */
            virtual void onKey(EKeyCode keyCode, EKeyState keyState);

        private:

            static void cursorPositionCallback(GLFWwindow* pWindow, f64 xpos, f64 ypos);

            static void keyCallback(GLFWwindow* pWindow, int32 key, int32 scancode, int32 action, int32 mods);

        #ifdef GDT_DEBUG
            static void errorCallback(int32 error, const char* pDescription);
        #endif

        protected:

            GLFWwindow* m_pWindow;

        private:

            static bool m_sGlewInitialized;
            static bool m_sGlfwInitialized;

            EKeyCode m_pKeyPressedStack[512];
            EKeyCode m_pKeyReleasedStack[512];
            EKeyState m_pKeyStates[512];


            glm::vec2 m_relativeCursorPosition;

            int32 m_pressedCount;
            int32 m_releasedCount;
        };
    }
}
