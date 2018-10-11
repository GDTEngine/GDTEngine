/**
 * @file     main.cpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#include "Engine.hpp"

using namespace gdt;

int main(int argc, char* argv[])
{
    engine::priv::CEngine* engine = new engine::priv::CEngine;
    engine->run();
}
