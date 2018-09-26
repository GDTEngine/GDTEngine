#pragma once

#include "Entity.hpp"

#include <map>
#include <string>

class CClassManager
{
public:

    using createEnityFunction = CEntity* (*)();

public:

    static CClassManager& get();

    CEntity* createEntity(const std::string& className);

    void registerEntity(const std::string& className, createEnityFunction createEnityFunction);

private:

    CClassManager() = default;
    ~CClassManager() = default;

private:

    std::map<std::string, createEnityFunction> m_entityClasses;
};
