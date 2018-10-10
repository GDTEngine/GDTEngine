/**
* @file     Engine.cpp
* @author   Ludvig Arlebrink
* @date     10/9/2018
*/

#include "Engine.hpp"
#include "Managers/ClassManager.hpp"
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
    priv::CClassManager* classManager = new priv::CClassManager;
    priv::CEventManager* eventManager = new priv::CEventManager;
    priv::CPluginManager* pluginManager = new priv::CPluginManager;

    graphics::CRenderWindow window;
    window.create("Window", 1280, 720);

    CObject::provideClassManager(classManager);
    CObject::provideEventManager(eventManager);
    CObject::providePluginManager(pluginManager);

    pluginManager->loadPlugins("Plugins/*.dll", classManager);

    classManager->createEntity("CPlayer");

    while (true)
    {
        window.handleInput();
        
        core::CWindow::pollEvents();
        
        window.clear();
        
        eventManager->update(window);
        
        window.display();
    }
}
