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

void interop_fubar()
{
    std::cout << "fubar interop called" << std::endl;
}

int main(int argc, char* argv[])
{

    // engine::priv::CEngine* engine = new engine::priv::CEngine;
    // engine->run();

    editor::CEditor* editor = new editor::CEditor;
    editor->run();
}
