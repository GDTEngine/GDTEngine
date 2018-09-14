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
         * @breif Move constructor.
         */
        CRenderWindow(const CRenderWindow&& other) noexcept;

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
         * @breif Get the height of the window in pixels.
         * @return Height of the window.
         */
        int32 getHeight() const;

        /**
         * @breif Get the width of the window in pixels.
         * @return Width of the window.
         */
        int32 getWidth() const;

    private:
        int32 m_height;
        int32 m_width;
    };
}
