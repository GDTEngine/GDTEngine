/**
 * @file     Player.hpp
 * @author   Ludvig Arlebrink
 * @date     9/27/2018
 */

#include "Player.hpp"
#include "EventManager.hpp"
#include "EntityManager.hpp"
#include "TransformComponent.hpp"
#include "Log.hpp"

using namespace gdt;
using namespace space;

CPlayer::CPlayer()
{
    engine::CEventManager::get().registerAction(engine::SInputAction("MoveForward", core::EKeyCode::KeyW));
    engine::CEventManager::get().registerAction(engine::SInputAction("MoveBack", core::EKeyCode::KeyS));
    engine::CEventManager::get().registerAction(engine::SInputAction("MoveLeft", core::EKeyCode::KeyA));
    engine::CEventManager::get().registerAction(engine::SInputAction("MoveRight", core::EKeyCode::KeyD));

    engine::CEventManager::get().bindAction("MoveForward", core::EKeyState::Held, this, ACTION_CB(CPlayer, moveForward));
    engine::CEventManager::get().bindAction("MoveBack", core::EKeyState::Held, this, ACTION_CB(CPlayer, moveBack));
    engine::CEventManager::get().bindAction("MoveLeft", core::EKeyState::Held, this, ACTION_CB(CPlayer, moveLeft));
    engine::CEventManager::get().bindAction("MoveRight", core::EKeyState::Held, this, ACTION_CB(CPlayer, moveRight));
}

CPlayer::~CPlayer()
{
}

void CPlayer::tick(f32 deltaTime)
{
    engine::STransformComponent* transform = engine::CEntityManager::get().getComponent<engine::STransformComponent>(getID());
}

void CPlayer::moveForward()
{
    LOG_MSG("Forward");
}

void CPlayer::moveBack()
{
    LOG_MSG("Back");
}

void CPlayer::moveLeft()
{
    LOG_MSG("Left");
}

void CPlayer::moveRight()
{
    LOG_MSG("Right");
}
