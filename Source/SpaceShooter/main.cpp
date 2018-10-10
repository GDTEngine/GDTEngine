/**
 * @file     main.cpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#pragma once

#include "Entity.hpp"
#include "Player.hpp"
#include "Managers/ClassManager.hpp"
#include "GDTPluginAPI.hpp"

#include <string>
#include <iostream>
#include <Windows.h>

using namespace gdt;
using namespace space;

GDT_PLUGIN_API void startUpPlugin(engine::priv::CClassManager* initializer)
{
    LOG_MSG("Plugin \"SpaceShooter\" Loaded!\n");

    initializer->registerEntity("CPlayer", []()->engine::CEntity* { return new CPlayer; });
}

GDT_PLUGIN_API void shutDownPlugin()
{
    
}
