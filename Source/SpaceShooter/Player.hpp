/**
 * @file     Player.hpp
 * @author   Ludvig Arlebrink
 * @date     9/27/2018
 */

#pragma once

#include "Entity.hpp"
#include "Log.hpp"
#include "SpaceShooterAPI.hpp"

namespace gdt
{
    namespace space
    {
        class SPACESHOOTER_API CPlayer final : public engine::CEntity
        {
        public:

            CPlayer();

            ~CPlayer();

            void tick(f32 deltaTime) override;

        private:

            void moveForward();

            void moveBack();

            void moveLeft();

            void moveRight();
        };
    }
}
