/**
 * @file     main.cpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#pragma once

#include "BaseTypes.hpp"

class CEntity
{
public:

    using entityId = uint32;

public:

    CEntity();

    virtual ~CEntity();

    void operator=(const CEntity&& other) = delete;

    entityId getEntityId() const;

protected:

    virtual void beginPlay();

    virtual void endPlay();

    virtual void tick(f32 deltaTime);

private:

    entityId m_entityId;
};
