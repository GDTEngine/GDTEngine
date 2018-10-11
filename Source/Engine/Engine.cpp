/**
* @file     Engine.cpp
* @author   Ludvig Arlebrink
* @date     10/9/2018
*/

#include "Engine.hpp"
#include "Managers/EntityManager.hpp"
#include "Managers/EventManager.hpp"
#include "Managers/PluginManager.hpp"
#include "Object.hpp"
#include "RenderWindow.hpp"

using namespace gdt;
using namespace engine;
using namespace priv;

CEngine::CEngine()
{
}

CEngine::~CEngine()
{
}

void CEngine::run()
{
    priv::CEntityManager* entityManager = new priv::CEntityManager;
    priv::CEventManager* eventManager = new priv::CEventManager;
    priv::CPluginManager* pluginManager = new priv::CPluginManager;

    graphics::CRenderWindow window;
    window.create("Window", 1280, 720);

    CObject::provideEntityManager(entityManager);
    CObject::provideEventManager(eventManager);
    CObject::providePluginManager(pluginManager);

    pluginManager->loadPlugins("Plugins/*.dll", entityManager);

    while (true)
    {
        window.handleInput();
        
        core::CWindow::pollEvents();
        
        entityManager->tick(0.05f);

        window.clear();
        eventManager->update(window);
        window.display();
    }

    delete pluginManager;
    delete eventManager;
    delete entityManager;
}
