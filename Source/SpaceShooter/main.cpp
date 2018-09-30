/**
 * @file     main.cpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#pragma once

#include "Entity.hpp"
#include "Player.hpp"
#include "ClassManager.hpp"
#include "GDTPluginApi.hpp"

#include <string>
#include <iostream>
#include <Windows.h>

using namespace gdt;
using namespace space;

GDT_PLUGIN_API void startUpPlugin()
{
    std::cout << "Plugin \"SpaceShooter\" Loaded!\n";

    engine::CClassManager::get().registerEntity("CPlayer", []()->engine::CEntity* { return new CPlayer; });
}

GDT_PLUGIN_API void shutDownPlugin()
{
    
}
