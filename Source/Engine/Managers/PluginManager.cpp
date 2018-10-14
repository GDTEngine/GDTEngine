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
using namespace priv;

CPluginManager::CPluginManager()
{
}

CPluginManager::~CPluginManager()
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

void CPluginManager::loadPlugins(const std::string& path, IEntityManager* classManager)
{
    core::CFileIterator fileIterator;
    if (!fileIterator.findFirstFile(path))
    {
        return;
    }

    auto position = path.find_last_of("/");
    std::string subpath = path.substr(0, position + 1);

    do
    {
        auto pPlugin = new core::CPlugin(subpath + fileIterator.getFilename());

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
        pPlugin->callFunction("startUpPlugin", classManager);

        if (pPlugin->getStatus() == core::EStatus::Failure)
        {
            LOG_ERROR("Could not call startUpPlugin.");
        }
    }
}
