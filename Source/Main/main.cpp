/**
 * @file     main.cpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#include "PluginManager.hpp"
#include "RenderWindow.hpp"

using namespace gdt;

int main(int argc, char* argv[])
{
    engine::CPluginManager::get().startUp();

    graphics::CRenderWindow window;
    window.create("Window", 1280, 720);

    while(true)
    {
        glfwPollEvents();
        window.clear();

        window.display();
    }

    getchar();
}
