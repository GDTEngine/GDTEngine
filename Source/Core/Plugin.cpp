/**
 * @file     Plugin.hpp
 * @author   Ludvig Arlebrink
 * @date     9/27/2018
 */

#include "Plugin.hpp"

using namespace gdt;
using namespace core;

CPlugin::CPlugin()
    : m_pluginIsLoaded(false)
    , m_status(EStatus::Success)
    , m_pPlugin(nullptr)
{
}

CPlugin::CPlugin(CPlugin&& other) noexcept
    : m_pluginIsLoaded(other.m_pluginIsLoaded)
    , m_status(other.m_status)
    , m_pPlugin(other.m_pPlugin)
{
    other.m_pPlugin = nullptr;
}

CPlugin::CPlugin(const std::string& pluginFilepath)
{
    loadPlugin(pluginFilepath);
}

CPlugin::~CPlugin()
{
}

void CPlugin::callFunction(const std::string& functionName)
{
    if (!m_pluginIsLoaded)
    {
        m_status = EStatus::Failure;
        return;
    }

#ifdef _WIN32
    auto function = reinterpret_cast<int(_cdecl *)()>(GetProcAddress(m_pPlugin, functionName.c_str()));
    if (!function)
    {
        m_status = EStatus::Failure;
    }
#elif __linux__
    if (!function)
    {
        m_status = EStatus::Failure;
    }
#endif // _WIN32
}

EStatus CPlugin::getStatus() const
{
    return m_status;
}

void CPlugin::loadPlugin(const std::string& pluginFilepath)
{
#ifdef _WIN32
    m_pPlugin = LoadLibrary(TEXT(pluginFilepath.c_str()));
    if (!m_pPlugin)
    {
        m_status = EStatus::Failure;
        return;
    }
#elif __linux__

#endif // _WIN32

    m_pluginIsLoaded = true;
    m_pluginFilepath = pluginFilepath;
}

void CPlugin::reloadPlugin()
{

}
