/**
 * @file     Window.cpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#include "Window.hpp"
#include "Log.hpp"

using namespace gdt;
using namespace core;

bool CWindow::m_sGlewInitialized = false;
bool CWindow::m_sGlfwInitialized = false;

CWindow::CWindow()
    : m_pWindow(nullptr)
    , m_pressedCount(0)
    , m_releasedCount(0)
{
    for (int32 i = 0; i < 512; ++i)
    {
        m_pKeyStates[i] = EKeyState::None;
    }
}

CWindow::~CWindow()
{
}

EKeyState CWindow::getKeyState(EKeyCode keyCode)
{
    return m_pKeyStates[static_cast<int32>(keyCode)];
}

void CWindow::create(const std::string& title, int32 width, int32 height)
{
    if (!m_sGlfwInitialized)
    {
        glfwInit();
        m_sGlfwInitialized = true;

    #ifdef GDT_DEBUG
        glfwSetErrorCallback(errorCallback);
    #endif // GDT_DEBUG
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

    m_pWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    // Connect the glfw window to this instance.
    glfwSetWindowUserPointer(m_pWindow, this);

    glfwSetKeyCallback(m_pWindow, keyCallback);

    glfwMakeContextCurrent(m_pWindow);

    if (!m_sGlewInitialized)
    {
        glewInit();
        m_sGlewInitialized = true;
    }

    glfwSwapInterval(1);
}

void CWindow::handleInput()
{
    for (int32 i = 0; i < m_pressedCount; ++i)
    {
        m_pKeyStates[static_cast<int32>(m_pKeyPressedStack[i])] = EKeyState::Held;
    }

    m_pressedCount = 0;

    for (int32 i = 0; i < m_releasedCount; ++i)
    {
        m_pKeyStates[static_cast<int32>(m_pKeyPressedStack[i])] = EKeyState::None;
    }

    m_releasedCount = 0;
}

bool CWindow::hasFocus() const
{
    return static_cast<bool>(glfwGetWindowAttrib(m_pWindow, GLFW_FOCUSED));
}

bool CWindow::isVisible() const
{
    return static_cast<bool>(glfwGetWindowAttrib(m_pWindow, GLFW_VISIBLE));
}

void CWindow::makeThisContextCurrent() const
{
    if (glfwGetCurrentContext() != m_pWindow)
    {
        glfwMakeContextCurrent(m_pWindow);
    }
}

void CWindow::pollEvents()
{
    glfwPollEvents();
}

void CWindow::onCursorPosition(const glm::vec2& position)
{
    m_relativeCursorPosition = position;
}

void CWindow::onKey(EKeyCode keyCode, EKeyState keyState)
{
    m_pKeyStates[static_cast<int32>(keyCode)] = keyState;

    if (keyState == EKeyState::Pressed)
    {
        m_pKeyStates[static_cast<int32>(keyCode)] = EKeyState::Pressed;
        m_pKeyPressedStack[m_pressedCount] = keyCode;
        ++m_pressedCount;
    }
    else if (keyState == EKeyState::Released)
    {
        m_pKeyStates[static_cast<int32>(keyCode)] = EKeyState::Released;
        m_pKeyReleasedStack[m_releasedCount] = keyCode;
        ++m_releasedCount;
    }
}

void CWindow::cursorPositionCallback(GLFWwindow* pWindow, f64 xpos, f64 ypos)
{
    CWindow* pWin = static_cast<CWindow*>(glfwGetWindowUserPointer(pWindow));
    pWin->onCursorPosition(glm::vec2(static_cast<f32>(xpos), static_cast<f32>(ypos)));
}

void CWindow::keyCallback(GLFWwindow* pWindow, int32 key, int32 scancode, int32 action, int32 mods)
{
    CWindow* pWin = static_cast<CWindow*>(glfwGetWindowUserPointer(pWindow));

    if (action == GLFW_PRESS)
    {
        pWin->onKey(static_cast<EKeyCode>(key), EKeyState::Pressed);
    }
    else if (action == GLFW_RELEASE)
    {
        pWin->onKey(static_cast<EKeyCode>(key), EKeyState::Released);
    }
}

#ifdef GDT_DEBUG
void CWindow::errorCallback(int32 error, const char* pDescription)
{
    LOG_ERROR(error << " " << pDescription);
}
#endif
