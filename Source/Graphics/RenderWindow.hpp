/**
 * @file     RenderWindow.hpp
 * @author   Ludvig Arlebrink
 * @date     9/16/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "Window.hpp"

#include <string>

namespace gdt
{
    namespace graphics
    {
        /**
         * @brief A window with an OpenGL context.
         */
        class CRenderWindow final : public core::CWindow
        {
        public:

            /**
             * @brief Default constructor.
             */
            CRenderWindow();

            CRenderWindow(const CRenderWindow&) = delete;

            CRenderWindow(CRenderWindow&&) = delete;

            /**
             * @brief Creates a window.
             * @param title Title of the window.
             * @param width The width of the window.
             * @param height The height of the window.
             */
            CRenderWindow(const std::string& title, int32 width, int32 height);

            /**
             * @brief Destructor.
             */
            ~CRenderWindow();

            void operator=(const CRenderWindow&) = delete;

            /**
             * @brief Clears what has been rendered on the window.
             *
             * Will set this window to the current context.
             */
            void clear() const;

            /**
             * @brief Displays what has been rendered to the window.
             *
             * Will set this window to the current context.
             */
            void display() const;

            /**
             * @brief Get the height of the window in pixels.
             * @return Height of the window.
             */
            int32 getHeight() const;

            /**
             * @brief Get the width of the window in pixels.
             * @return Width of the window.
             */
            int32 getWidth() const;

            /**
             * @brief Make this window the current context.
             */
            void makeThisContextCurrent() const;

            /**
             * @brief Set the size of the window.
             * @param width Width of the window.
             * @param height Height of the window.
             */
            void setSize(int32 width, int32 height) const;

            /**
             * @brief Set the title of the window.
             * @param title Title of the window.
             */
            void setTitle(const std::string& title) const;

            /**
             * @brief Set the size and the position of the viewport.
             * @param x Horizontal position of the viewport.
             * @param y Vertical position of the viewport.
             * @param width Width of the viewport.
             * @param height Height of the viewport.
             */
            void setViewport(int32 x, int32 y, int32 width, int32 height) const;

            /**
             * @brief Set the window to be visible or invisible.
             * @param visible 'true' to make the window visible.
             */
            void setVisible(bool visible) const;

        private:

            static void windowSizeCallback(GLFWwindow* pRenderWindow, int32 width, int32 height);

            void windowSizeCallback(int32 width, int32 height);

        private:

            GLFWwindow* m_pRenderWindow;
        };
    }
}
