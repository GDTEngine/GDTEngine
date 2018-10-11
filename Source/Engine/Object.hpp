/**
 * @file     Object.hpp
 * @author   Ludvig Arlebrink
 * @date     10/10/2018
 */

#pragma once

#include "EngineAPI.hpp"
#include "Managers/IEntityManager.hpp"
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

        /**
         * @brief Base class for objects that will interfere with the game world.
         */
        class ENGINE_API CObject
        {
            friend priv::CEngine;

        protected:

            /**
             * @brief Default constructor.
             */
            CObject();

            /**
             * @brief Destructor.
             */
            virtual ~CObject();

            /**
             * @brief Get the class manager.
             * @return Class manager.
             */
            static priv::IEntityManager* entityManager();

            /**
            * @brief Get the event manager.
            * @return Event manager.
            */
            static priv::IEventManager* eventManager();

            /**
             * @brief Get the plugin manager.
             * @return Plugin manager.
             */
            static priv::IPluginManager* pluginManager();

        private:

            static void provideEntityManager(priv::IEntityManager* pEntityManager);

            static void provideEventManager(priv::IEventManager* pEventManager);

            static void providePluginManager(priv::IPluginManager* pPluginManager);

        private:

            static priv::IEntityManager* m_pEntityManager;
            static priv::IEventManager* m_pEventManager;
            static priv::IPluginManager* m_pPluginManager;
        };
    }
}
