/**
 * @file     main.cpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#include "Entity.hpp"
#include "ClassManager.hpp"
#include "EventManager.hpp"
#include "EntityManager.hpp"
#include "Log.hpp"
#include "RenderWindow.hpp"
#include "PluginManager.hpp"
#include "Window.hpp"

using namespace gdt;

int main(int argc, char* argv[])
{

    graphics::CRenderWindow window;
    window.create("Window", 1280, 720);

    engine::CEntityManager::get().startUp();
    engine::CPluginManager::get().startUp();


    engine::CEntityManager::get().shutDown();

    while(true)
    {
        window.handleInput();

        core::CWindow::pollEvents();

        window.clear();
        
        engine::CEventManager::get().update(window);

        engine::CEntityManager::get().update(0.1f);

        window.display();
    }

    getchar();
}
