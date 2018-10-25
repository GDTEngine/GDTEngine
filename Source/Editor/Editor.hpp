/**
 * @file     EngineAPI.hpp
 * @author   Ludvig Arlebrink
 * @date     10/14/2018
 */

#pragma once

#include "EditorAPI.hpp"

namespace gdt
{
    namespace editor
    {
        class EDITOR_API CEditor
        {
        public:

            CEditor();

            ~CEditor();

            void run();
        };
    }
}
