/**
* @file     Engine.cpp
* @author   Ludvig Arlebrink
* @date     10/9/2018
*/

#include "Engine.hpp"
#include "Managers/BehaviorManager.hpp"
#include "Managers/CSharpManager.hpp"
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
    CEntityManager* pEntityManager = new CEntityManager;
    CObject::provideEntityManager(pEntityManager);

    CEventManager* pEventManager = new CEventManager;
    CObject::provideEventManager(pEventManager);
    
    CPluginManager* pPluginManager = new CPluginManager;
    CObject::providePluginManager(pPluginManager);

    CCSharpManager* pCSsharpManager = new CCSharpManager;
    CObject::provideCSharpManager(pCSsharpManager);

    CBehaviorManager* pBehaviorManager = new CBehaviorManager;
    CObject::provideBehaviorManager(pBehaviorManager);

    graphics::CRenderWindow window;
    window.create("Window", 1280, 720);

    while (true)
    {
        window.handleInput();
        core::CWindow::pollEvents();      

        pBehaviorManager->preTick(0.01f);
        pBehaviorManager->tick(0.01f);
        pBehaviorManager->postTick(0.01f);

        window.clear();
        pEventManager->update(window);
        window.display();
    }

    delete pPluginManager;
    delete pEventManager;
    delete pEntityManager;
}
