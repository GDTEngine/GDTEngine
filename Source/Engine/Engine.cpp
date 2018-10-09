/**
* @file     Engine.cpp
* @author   Ludvig Arlebrink
* @date     10/9/2018
*/

#include "Engine.hpp"

using namespace gdt;
using namespace engine;
using namespace priv;

CEngine::CEngine()
{
}

CEngine::~CEngine()
{
}

void CEngine::run()
{
    m_pClassManager = std::make_shared<CClassManager>();
    m_pPluginManager = std::make_shared<CPluginManager>();

    while (true)
    {

    }
}
