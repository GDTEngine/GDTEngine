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

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

using namespace gdt;
using namespace engine;

CEngine::CEngine()
{
}

CEngine::~CEngine()
{
}

void CEngine::run()
{
    CEntityManager* entityManager = new CEntityManager;
    engine::CEventManager* eventManager = new engine::CEventManager;
    CPluginManager* pluginManager = new CPluginManager;

    graphics::CRenderWindow window;
    window.create("Window", 1280, 720);

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
