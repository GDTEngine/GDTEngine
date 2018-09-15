#pragma once

#include "BaseTypes.hpp"

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <string>

namespace gdt
{
    /**
     * A window with an OpenGL context.
     */
    class CRenderWindow final
    {
    public:

        /**
         * @breif Default constructor.
         */
        CRenderWindow();

        /**
         * @breif Copy constructor deleted.
         */
        CRenderWindow(const CRenderWindow& other) = delete;

        /**
         * @breif Move constructor deleted.
         */
        CRenderWindow(const CRenderWindow&& other) = delete;

        /**
         * @breif Creates a window.
         * @param title Title of the window.
         * @param width The width of the window.
         * @param height The height of the window.
         */
        CRenderWindow(const std::string& title, int32 width, int32 height);

        /**
         * @breif Destructor.
         */
        ~CRenderWindow();

        /**
         * @breif Assignment operator deleted.
         */
        void operator=(const CRenderWindow& rhs) = delete;

        /**
         * @breif Clears what has been rendered on the window.
         * 
         * Will set this window to the current context.
         */
        void clear() const;

        /**
         * @breif Creates a window.
         * @param title Title of the window.
         * @param width The width of the window.
         * @param height The height of the window.
         */
        void create(const std::string& title, int32 width, int32 height);

        /**
         * @breif Displays what has been rendered to the window.
         * 
         * Will set this window to the current context.
         */
        void display() const;

        /**
         * @breif Get the height of the window in pixels.
         * @return Height of the window.
         */
        int32 getHeight() const;

        /**
         * @breif Get the width of the window in pixels.
         * @return Width of the window.
         */
        int32 getWidth() const;

        /**
         * @breif Check whether the window has the input focus.
         * @return 'true' if in focus.
         */
        bool hasFocus() const;

        /**
         * @breif Check whether the window is visible
         */
        bool isVisible() const;

        /**
         * @breif Make this window the current context.
         */
        void makeThisContextCurrent() const;

        /**
         * @breif Set the size of the window.
         * @param width Width of the window.
         * @param height Height of the window.
         */
        void setSize(int32 width, int32 height) const;

        /**
         * @breif Set the title of the window.
         * @param title Title of the window.
         */
        void setTitle(const std::string& title) const;

        /**
         * @breif Set the size and the position of the viewport.
         * @param x Horizontal position of the viewport.
         * @param y Vertical position of the viewport.
         * @param width Width of the viewport.
         * @param height Height of the viewport.
         */
        void setViewport(int32 x, int32 y, int32 width, int32 height) const;

        /**
         * @breif Set the window to be visible or invisible.
         * @param visible 'true' to make the window visible.
         */
        void setVisible(bool visible) const;

    private:

        static void windowSizeCallback(GLFWwindow* pRenderWindow, int32 width, int32 height);

        void windowSizeCallback(int32 width, int32 height);

    private:
        
        static bool m_sGlewInitialized;
        static bool m_sGlfwInitialized;

        GLFWwindow* m_pRenderWindow;
    };
}
