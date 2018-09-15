#include "RenderWindow.hpp"

using namespace gdt;

CRenderWindow::CRenderWindow()
    : m_window(nullptr)
    , m_height(0)
    , m_width(0)
{

}

CRenderWindow::CRenderWindow(const std::string& title, int32 width, int32 height)
{
    !glfwInit();
    create(title, width, height);
}

CRenderWindow::~CRenderWindow()
{
}

void CRenderWindow::clear() const
{
    makeContextCurrent();
    glClear(GL_COLOR_BUFFER_BIT);
}

void CRenderWindow::create(const std::string& title, int32 width, int32 height)
{
    glfwInit();

    width = m_width;
    height = m_height;
    m_window = glfwCreateWindow(m_width, m_height, title.c_str(), nullptr, nullptr);

    // Connect the glfw window to this instance.
    glfwSetWindowUserPointer(m_window, this);

    glfwMakeContextCurrent(m_window);
    
    glewInit();
    
    glfwSwapInterval(1);
}

void CRenderWindow::makeContextCurrent() const
{
    if (glfwGetCurrentContext() != m_window)
    {
        glfwMakeContextCurrent(m_window);
    }
}

int32 CRenderWindow::getHeight() const
{
    return m_height;
}

int32 CRenderWindow::getWidth() const
{
    return m_width;
}
