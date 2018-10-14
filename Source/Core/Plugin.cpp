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
    unloadPlugin();
}

void CPlugin::callFunction(const std::string& functionName)
{
    if (!m_pluginIsLoaded)
    {
        m_status = EStatus::Failure;
        return;
    }

#ifdef _WIN32

    auto function = reinterpret_cast<void(_cdecl *)()>(GetProcAddress(m_pPlugin, functionName.c_str()));
    if (!function)
    {
        m_status = EStatus::Failure;
        return;
    }

    function();

#elif __linux__

    // @todo Linux implementation.

#endif // _WIN32

    m_status = EStatus::Success;
}

std::string CPlugin::getErrorString() const
{
#ifdef GDT_DEBUG || GDT_EDITOR
    return m_errorString;
#else
    return "";
#endif // GDT_DEBUG || GDT_EDITOR
}

EStatus CPlugin::getStatus() const
{
    return m_status;
}

void CPlugin::loadPlugin(const std::string& pluginFilepath)
{
#ifdef _WIN32
    
    m_pPlugin = LoadLibraryExA(pluginFilepath.c_str(), nullptr, 0);

    if (!m_pPlugin)
    {
        m_status = EStatus::Failure;

    #ifdef GDT_DEBUG || GDT_EDITOR
        m_errorString = "Failed to load plugin: " + m_pluginFilepath;
    #endif

        return;
    }

#elif __linux__

    // @todo Linux implementation.

#endif // _WIN32

    m_status = EStatus::Success;
    m_pluginIsLoaded = true;
    m_pluginFilepath = pluginFilepath;
}

void CPlugin::reloadPlugin()
{
    unloadPlugin();
    loadPlugin(m_pluginFilepath);

#ifdef GDT_DEBUG || GDT_EDITOR
    if (m_status == EStatus::Failure)
    {
        m_errorString = "Failed to reload plugin: " + m_pluginFilepath;
    }
#endif
}

void CPlugin::unloadPlugin()
{
#ifdef _WIN32
    FreeLibrary(m_pPlugin);
#elif __linux__

    // @todo Linux implementation.

#endif // _WIN32

    m_pluginIsLoaded = false;
    m_status = EStatus::Success;
}
