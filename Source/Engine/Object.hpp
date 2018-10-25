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
        /**
         * @brief Base class for objects that will interfere with the game world.
         */
        class ENGINE_API CObject
        {
            friend class CEngine;

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
            static IEntityManager* entityManager();

            /**
            * @brief Get the event manager.
            * @return Event manager.
            */
            static IEventManager* eventManager();

            /**
             * @brief Get the plugin manager.
             * @return Plugin manager.
             */
            static IPluginManager* pluginManager();

        private:

            static void provideEntityManager(IEntityManager* pEntityManager);

            static void provideEventManager(IEventManager* pEventManager);

            static void providePluginManager(IPluginManager* pPluginManager);

        private:

            static IEntityManager* m_pEntityManager;
            static IEventManager* m_pEventManager;
            static IPluginManager* m_pPluginManager;
        };
    }
}
