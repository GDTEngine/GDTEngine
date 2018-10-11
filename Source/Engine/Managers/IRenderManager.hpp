/**
 * @file     IRenderManager.hpp
 * @author   Ludvig Arlebrink
 * @date     10/11/2018
 */

#include "EngineAPI.hpp"

namespace gdt
{
    namespace engine
    {
        namespace priv
        {
            class ENGINE_API IRenderSystem
            {
            public:

                virtual ~IRenderSystem() = default;
            };
        }
    }
}
