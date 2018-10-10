/**
 * @file     main.cpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#include "Engine.hpp"

using namespace gdt;

int main(int argc, char* argv[])
{
//    graphics::CRenderWindow window;
//    window.create("Window", 1280, 720);

    engine::priv::CEngine* engine = new engine::priv::CEngine;
    engine->run();

//    while(true)
//    {
//        window.handleInput();
//
//        core::CWindow::pollEvents();
//
//        window.clear();
//        
//        // engine::CEventManager::get().update(window);
//
//        window.display();
//    }
//
//    getchar();
}
