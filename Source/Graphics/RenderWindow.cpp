/**
 * @file     RenderWindow.cpp
 * @author   Ludvig Arlebrink
 * @date     9/16/2018
 */

#include "RenderWindow.hpp"

using namespace gdt;
using namespace graphics;

CRenderWindow::CRenderWindow()
    : m_pRenderWindow(nullptr)
{
}

CRenderWindow::CRenderWindow(const std::string& title, int32 width, int32 height)
{
    create(title, width, height);
}

CRenderWindow::~CRenderWindow()
{
    if (m_pRenderWindow)
    {
        glfwDestroyWindow(m_pRenderWindow);
    }
}

void CRenderWindow::clear() const
{
    makeThisContextCurrent();
    glClear(GL_COLOR_BUFFER_BIT);
}

void CRenderWindow::display() const
{
    makeThisContextCurrent();
    glfwSwapBuffers(m_pRenderWindow);
}

int32 CRenderWindow::getHeight() const
{
    int32 width;
    int32 height;
    glfwGetWindowSize(m_pRenderWindow, &width, &height);
    return height;
}

int32 CRenderWindow::getWidth() const
{
    int32 width;
    int32 height;
    glfwGetWindowSize(m_pRenderWindow, &width, &height);
    return width;
}

void CRenderWindow::makeThisContextCurrent() const
{
    if (glfwGetCurrentContext() != m_pRenderWindow)
    {
        glfwMakeContextCurrent(m_pRenderWindow);
    }
}

void CRenderWindow::setSize(int32 width, int32 height) const
{
    glfwSetWindowSize(m_pRenderWindow, width, height);
}

void CRenderWindow::setTitle(const std::string& title) const
{
    glfwSetWindowTitle(m_pRenderWindow, title.c_str());
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
        glfwShowWindow(m_pRenderWindow);
    }
    else
    {
        glfwHideWindow(m_pRenderWindow);
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
