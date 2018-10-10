/**
 * @file     Player.hpp
 * @author   Ludvig Arlebrink
 * @date     9/27/2018
 */

#include "Player.hpp"
#include "Log.hpp"

using namespace gdt;
using namespace space;

CPlayer::CPlayer()
{
    eventManager()->registerAction(engine::SInputAction("MoveForward", core::EKeyCode::KeyW));
    eventManager()->registerAction(engine::SInputAction("MoveBack", core::EKeyCode::KeyS));
    eventManager()->registerAction(engine::SInputAction("MoveLeft", core::EKeyCode::KeyA));
    eventManager()->registerAction(engine::SInputAction("MoveRight", core::EKeyCode::KeyD));

    eventManager()->bindAction("MoveForward", core::EKeyState::Held, this, ACTION_CB(CPlayer, moveForward));
    eventManager()->bindAction("MoveBack", core::EKeyState::Held, this, ACTION_CB(CPlayer, moveBack));
    eventManager()->bindAction("MoveLeft", core::EKeyState::Held, this, ACTION_CB(CPlayer, moveLeft));
    eventManager()->bindAction("MoveRight", core::EKeyState::Held, this, ACTION_CB(CPlayer, moveRight));
}

CPlayer::~CPlayer()
{
}

void CPlayer::tick(f32 deltaTime)
{
    LOG_MSG("YEY");
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
