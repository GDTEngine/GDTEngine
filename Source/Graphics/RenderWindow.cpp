/**
 * @file     RenderWindow.cpp
 * @author   Ludvig Arlebrink
 * @date     9/16/2018
 */

#include "RenderWindow.hpp"

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

using namespace gdt;
using namespace graphics;

CRenderWindow::CRenderWindow()
{
}

CRenderWindow::CRenderWindow(const std::string& title, int32 width, int32 height)
{
    create(title, width, height);
}

CRenderWindow::~CRenderWindow()
{
}

void CRenderWindow::clear() const
{
    makeThisContextCurrent();
    
    glClear(GL_COLOR_BUFFER_BIT);
}

void CRenderWindow::display() const
{
    makeThisContextCurrent();
    glfwSwapBuffers(m_pWindow);
}

int32 CRenderWindow::getHeight() const
{
    int32 width;
    int32 height;
    glfwGetWindowSize(m_pWindow, &width, &height);
    return height;
}

int32 CRenderWindow::getWidth() const
{
    int32 width;
    int32 height;
    glfwGetWindowSize(m_pWindow, &width, &height);
    return width;
}

void CRenderWindow::setSize(int32 width, int32 height) const
{
    glfwSetWindowSize(m_pWindow, width, height);
}

void CRenderWindow::setTitle(const std::string& title) const
{
    glfwSetWindowTitle(m_pWindow, title.c_str());
}

void CRenderWindow::setViewport(int32 x, int32 y, int32 width, int32 height) const
{
    makeThisContextCurrent();
    glViewport(0, 0, width, height);
}

void CRenderWindow::setVisible(bool visible) const
{
    if (visible)
    {
        glfwShowWindow(m_pWindow);
    }
    else
    {
        glfwHideWindow(m_pWindow);
    }
}

void CRenderWindow::windowSizeCallback(GLFWwindow* pRenderWindow, int32 width, int32 height)
{
    static_cast<CRenderWindow*>(glfwGetWindowUserPointer(pRenderWindow))->windowSizeCallback(width, height);
}

void CRenderWindow::windowSizeCallback(int32 width, int32 height)
{
    setViewport(0, 0, width, height);
}
