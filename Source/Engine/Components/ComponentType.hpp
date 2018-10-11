/**
 * @file     ComponentType.hpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "BaseTypes.hpp"

namespace gdt
{
    namespace engine
    {
        enum class EComponentType : uint32
        {
            CameraComponent,
            MeshRenderComponent
        };
    }
}
