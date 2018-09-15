#include "RenderWindow.hpp"

using namespace gdt;

int main(int argc, char* argv[])
{
    CRenderWindow* pRenderWindow = new CRenderWindow("GDTEngine", 1280, 720);

    while (true)
    {
        pRenderWindow->clear();
        pRenderWindow->display();

        glfwPollEvents();
    }

    return 0;
}