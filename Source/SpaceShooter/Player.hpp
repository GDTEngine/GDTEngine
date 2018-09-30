/**
 * @file     Player.hpp
 * @author   Ludvig Arlebrink
 * @date     9/27/2018
 */

#pragma once

#include "Entity.hpp"

namespace gdt
{
    namespace space
    {
        class CPlayer final : public engine::CEntity
        {
        public:

            CPlayer();

            ~CPlayer();

            void tick(f32 deltaTime) override;
        };
    }
}
