/**
 * @file     EditorUI.hpp
 * @author   Ludvig Arlebrink
 * @date     10/15/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "EngineAPI.hpp"

#include <imgui/imgui.h>
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

namespace gdt
{
    namespace editor
    {
        class CEditorUI
        {
        public:

            static bool button(MonoString* lable)
            {
                return ImGui::Button(mono_string_to_utf8(lable));
            }

            static f32 floatField(MonoString* lable, f32 value)
            {
                ImGui::InputFloat(mono_string_to_utf8(lable), &value);
                return value;
            }

            static int32 intField(MonoString* lable, int32 value)
            {
                ImGui::InputInt(mono_string_to_utf8(lable), &value);
                return value;
            }

            static void lable(MonoString* lable)
            {

            }

            static MonoString* textArea(MonoString* lable, MonoString* text)
            {
                return nullptr;
            }

            static MonoString* textField(MonoString* lable, MonoString* text)
            {
                return nullptr;
            }
        };
    }
}
