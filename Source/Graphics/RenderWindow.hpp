#pragma once

#include "BaseTypes.hpp"

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

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

        /**
         * @breif Destructor.
         */
        ~CRenderWindow();

        /**
         * @breif Assignment operator deleted.
         */
        void operator=(const CRenderWindow& rhs) = delete;

    private:

    };
}
