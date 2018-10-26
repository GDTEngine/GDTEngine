/**
 * @file     BehaviorManager.cpp
 * @author   Ludvig Arlebrink
 * @date     10/26/2018
 */

#include "BehaviorManager.hpp"

using namespace gdt;
using namespace engine;

CBehaviorManager::CBehaviorManager()
{
}

CBehaviorManager::~CBehaviorManager()
{
}

void CBehaviorManager::postTick(f32 deltaTime)
{
    for (int32 i = 0; i < m_pBehaviors.size(); ++i)
    {
        m_pPostTick->call(m_pBehaviors[i]);
    }
}

void CBehaviorManager::preTick(f32 deltaTime)
{
    for (int32 i = 0; i < m_pBehaviors.size(); ++i)
    {
        m_pPreTick->call(m_pBehaviors[i]);
    }
}

void CBehaviorManager::tick(f32 deltaTime)
{
    for (int32 i = 0; i < m_pBehaviors.size(); ++i)
    {
        m_pTick->call(m_pBehaviors[i]);
    }
}
