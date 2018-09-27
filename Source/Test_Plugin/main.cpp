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

GDT_PLUGIN_API void startUpPlugin()
{
    std::cout << "DLL Loaded\n";
    
    CClassManager::get().registerEntity("CPlayer", []()->CEntity* { return new CPlayer; });
}

GDT_PLUGIN_API void shutDownPlugin()
{
    
}
