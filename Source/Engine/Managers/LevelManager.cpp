/**
 * @file     LevelManager.cpp
 * @author   Ludvig Arlebrink
 * @date     11/11/2018
 */

#include "LevelManager.hpp"
#include "XMLNode.hpp"

using namespace gdt;
using namespace engine;

CLevelManager::CLevelManager()
{
}

CLevelManager::~CLevelManager()
{
}

void CLevelManager::loadLevel(const std::string& levelName)
{
    core::CXMLNode* pXMLNode = new core::CXMLNode("Data/Levels/" + levelName + ".xml");



    delete pXMLNode;
}
