/**
 * @file     RenderWindow.cpp
 * @author   Ludvig Arlebrink
 * @date     9/16/2018
 */

#include "RenderWindow.hpp"
#include <iostream>

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

using namespace gdt;
using namespace graphics;

bool CRenderWindow::m_sGlewInitialized = false;
bool CRenderWindow::m_sGlfwInitialized = false;

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
    glfwSetErrorCallback(NULL);
}

void CRenderWindow::clear() const
{
    makeThisContextCurrent();
    glClear(GL_COLOR_BUFFER_BIT);
}

void glfwErrorCallback(int error, const char* description)
{
    LOG_ERROR(description);
}

void CRenderWindow::create(const std::string& title, int32 width, int32 height)
{
    glfwSetErrorCallback(glfwErrorCallback);
    if (!m_sGlfwInitialized)
    {
        glfwInit();
        m_sGlfwInitialized = true;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

    m_pRenderWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    // Connect the glfw window to this instance.
    glfwSetWindowUserPointer(m_pRenderWindow, this);

    glfwMakeContextCurrent(m_pRenderWindow);
    
    if (!m_sGlewInitialized)
    {
        glewInit();
        m_sGlewInitialized = true;
    }
    
    glfwSwapInterval(1);
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

bool CRenderWindow::hasFocus() const
{
    return static_cast<bool>(glfwGetWindowAttrib(m_pRenderWindow, GLFW_FOCUSED));
}

bool CRenderWindow::isVisible() const
{
    return static_cast<bool>(glfwGetWindowAttrib(m_pRenderWindow, GLFW_VISIBLE));
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
