/**
 * @file     MeshRendererComponent.hpp
 * @author   Ludvig Arlebrink
 * @date     10/11/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "Component.hpp"

namespace gdt
{
    namespace engine
    {
        struct ENGINE_API SMeshRendererComponent
        {
            int32 meshID;
        };
    }
}