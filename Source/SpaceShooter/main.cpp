/**
 * @file     main.cpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#pragma once

#include "Entity.hpp"
#include "Player.hpp"
#include "Managers/EntityManager.hpp"
#include "GDTPluginAPI.hpp"

#include <string>
#include <iostream>
#include <Windows.h>

using namespace gdt;
using namespace space;

GDT_PLUGIN_API void startUpPlugin(engine::priv::CEntityManager* initializer)
{
    LOG_MSG("Plugin \"SpaceShooter\" Loaded!\n");

    initializer->registerEntity(typeid(CPlayer).hash_code(), []()->engine::CEntity* { return new CPlayer; });

    initializer->instantiate(typeid(CPlayer).hash_code());
}

GDT_PLUGIN_API void shutDownPlugin()
{
    
}
