/**
 * @file     PluginManager.cpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#include "PluginManager.hpp"

#include "FileIterator.hpp"
#include "Log.hpp"

using namespace gdt;
using namespace engine;

CPluginManager& CPluginManager::get()
{
    static CPluginManager instance;
    return instance;
}

void CPluginManager::startUp()
{
    core::CFileIterator fileIterator;
    if (!fileIterator.findFirstFile("Plugins/*.dll"))
    {
        return;
    }

    do
    {
        auto pPlugin = new core::CPlugin("Plugins/" + fileIterator.getFilename());

        if (pPlugin->getStatus() == core::EStatus::Failure)
        {
            LOG_ERROR("Could not load plugin: " + fileIterator.getFilename());
            break;
        }

        m_pPlugins.push_back(pPlugin);
    }
    while (fileIterator.findNext());

    for (auto& pPlugin : m_pPlugins)
    {
        pPlugin->callFunction("startUpPlugin");
        
        if (pPlugin->getStatus() == core::EStatus::Failure)
        {
            LOG_ERROR("Could not call startUpPlugin.");
        }
    }
}

void CPluginManager::shutDown()
{
    for (auto& pPlugin : m_pPlugins)
    {
        pPlugin->callFunction("shutDownPlugin");

        if (pPlugin->getStatus() == core::EStatus::Failure)
        {
            LOG_ERROR("Could not call shutDownPlugin.");
        }
    }

    m_pPlugins.clear();
}
