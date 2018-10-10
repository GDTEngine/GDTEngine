/**
 * @file     Locator.cpp
 * @author   Ludvig Arlebrink
 * @date     10/10/2018
 */

#include "Locator.hpp"

using namespace gdt;
using namespace engine;

std::shared_ptr<priv::CClassManager> CLocator::classManager()
{
    return std::shared_ptr<priv::CClassManager>();
}

std::shared_ptr<priv::CPluginManager> CLocator::pluginManager()
{
    return std::shared_ptr<priv::CPluginManager>();
}
