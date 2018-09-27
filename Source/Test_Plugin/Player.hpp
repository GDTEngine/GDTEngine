/**
 * @file     Player.hpp
 * @author   Ludvig Arlebrink
 * @date     9/27/2018
 */

#pragma once

#include "Entity.hpp"
#include <iostream>

class CPlayer final : public CEntity
{
public:

    CPlayer();

    ~CPlayer();

    void tick(f32 deltaTime) override;
};
