/**
 * @file     EventManager.cpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#include "EventManager.hpp"

using namespace gdt;
using namespace engine;

CEventManager::CEventManager()
{

}

CEventManager::~CEventManager()
{

}

void CEventManager::bindAction(const std::string& actionId, core::EKeyState state, void* pObject,
    SInputAction::ActionCallback actionCallback)
{
    for (int32 i = 0; i < m_actions.size(); ++i)
    {
        if (!strcmp(m_actions[i].actionId, actionId.c_str()))
        {
            auto& callbackInfo = m_actions[i].m_pCallbackInfo[m_actions[i].m_callbacksCount];
            callbackInfo.keyState = state;
            callbackInfo.pObject = pObject;
            callbackInfo.actionCallback = actionCallback;
            ++m_actions[i].m_callbacksCount;
            return;
        }
    }
}

void CEventManager::registerAction(const SInputAction& action)
{
    m_actions.push_back(action);
}

void CEventManager::update(core::CWindow& window)
{
    for (int32 i = 0; i < m_actions.size(); ++i)
    {
        core::EKeyState state = window.getKeyState(m_actions[i].key);
        if (state != core::EKeyState::None)
        {
            for (int32 j = 0; j < m_actions[i].m_callbacksCount; ++j)
            {
                auto& callbackInfo = m_actions[i].m_pCallbackInfo[j];
                if (callbackInfo.keyState == state)
                {
                    callbackInfo.actionCallback(callbackInfo.pObject);
                }
            }
        }
    }
}
