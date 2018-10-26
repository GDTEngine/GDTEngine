/**
 * @file     main.cpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#include "Editor.hpp"
#include "Engine.hpp"

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <string.h>
#include <iostream>

using namespace gdt;

int main(int argc, char* argv[])
{
    engine::CEngine* engine = new engine::CEngine;
    engine->run();

    // editor::CEditor* editor = new editor::CEditor;
    // editor->run();
}
