/**
 * @file     main.cpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#include "PluginManager.hpp"

using namespace gdt;

int main(int argc, char* argv[])
{
    engine::CPluginManager::get().startUp();

    getchar();
}
