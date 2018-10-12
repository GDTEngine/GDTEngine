/**
 * @file     RenderManager.hpp
 * @author   Ludvig Arlebrink
 * @date     10/11/2018
 */

#include "IRenderManager.hpp"

namespace gdt
{
    namespace engine
    {
        namespace priv
        {
            class ENGINE_API CRenderManager final : public IRenderManager
            {
            public:

                ~CRenderManager();
            };
        }
    }
}
