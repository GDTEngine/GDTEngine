/**
 * @file     Object.hpp
 * @author   Ludvig Arlebrink
 * @date     10/10/2018
 */

#pragma once

#include "EngineAPI.hpp"
#include "Managers/IClassManager.hpp"
#include "Managers/IPluginManager.hpp"
#include "Managers/IEventManager.hpp"

#include <memory>

namespace gdt
{
    namespace engine
    {
        namespace priv
        {
            class CEngine;
        }

        class ENGINE_API CObject
        {
            friend priv::CEngine;

        protected:

            CObject();

            virtual ~CObject();

            static priv::IClassManager* classManager();

            static priv::IEventManager* eventManager();

            static priv::IPluginManager* pluginManager();

        private:

            static void provideClassManager(priv::IClassManager* classManager);

            static void provideEventManager(priv::IEventManager* eventManager);

            static void providePluginManager(priv::IPluginManager* pluginManager);

        private:

            static priv::IClassManager* m_pClassManager;
            static priv::IEventManager* m_pEventManager;
            static priv::IPluginManager* m_pPluginManager;
        };
    }
}
