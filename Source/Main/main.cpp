/**
 * @file     main.cpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#include "Entity.hpp"
#include "PluginManager.hpp"
#include "ClassManager.hpp"
#include "EventManager.hpp"
#include "RenderWindow.hpp"
#include "Window.hpp"
#include "Log.hpp"

using namespace gdt;

int main(int argc, char* argv[])
{

    graphics::CRenderWindow window;
    window.create("Window", 1280, 720);

    engine::CPluginManager::get().startUp();

    engine::CEntity* player = engine::CClassManager::get().createEntity("CPlayer");

    while(true)
    {
        window.handleInput();

        core::CWindow::pollEvents();

        window.clear();
        
        engine::CEventManager::get().update(window);

        window.display();
    }

    getchar();
}
