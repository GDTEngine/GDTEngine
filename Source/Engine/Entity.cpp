/**
 * @file     Entity.cpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#include "Entity.hpp"

using namespace gdt;
using namespace engine;

CEntity::CEntity()
    : m_isEnabled(true)
    , m_position(glm::vec3(0.0f))
    , m_scale(glm::vec3(1.0f))
    , m_rotation(glm::quat(1.0f, 0.0f, 0.0f, 0.0f))
{
}

CEntity::~CEntity()
{
}

glm::vec3 CEntity::getForward() const
{
    return m_rotation * glm::vec3(0.0f, 0.0f, 1.0f);
}

EntityID CEntity::getID() const
{
    return m_entityID;
}

f32 CEntity::getLocalPitch() const
{
    return glm::degrees(glm::pitch(m_rotation));
}

glm::vec3 CEntity::getLocalPosition() const
{
    return m_position;
}

f32 CEntity::getLocalRoll() const
{
    return glm::degrees(glm::roll(m_rotation));
}

glm::quat CEntity::getLocalRotation() const
{
    return m_rotation;
}

glm::vec3 CEntity::getLocalScale() const
{
    return m_scale;
}

f32 CEntity::getLocalYaw() const
{
    return glm::degrees(glm::yaw(m_rotation));
}

glm::vec3 CEntity::getRight() const
{
    return m_rotation * glm::vec3(1.0f, 0.0f, 0.0f);
}

glm::vec3 CEntity::getUp() const
{
    return m_rotation * glm::vec3(0.0f, 1.0f, 0.0f);
}

bool CEntity::isEnabled()
{
    return m_isEnabled;
}

void CEntity::setEnabled(bool enabled)
{
    m_isEnabled = enabled;
}

void CEntity::setLocalPitch(f32 angle)
{
    m_rotation = glm::rotate(m_rotation, glm::radians(angle), glm::vec3(1.0f, 0.0f, 0.0f));
}

void CEntity::setLocalPosition(const glm::vec3& position)
{
    m_position = position;
}

void CEntity::setLocalPosition(f32 x, f32 y, f32 z)
{
    m_position = glm::vec3(x, y, z);
}

void CEntity::setLocalRoll(f32 angle)
{
    m_rotation = glm::rotate(m_rotation, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
}

void CEntity::setLocalRotation(const glm::quat& rotation)
{
    m_rotation = rotation;
}

void CEntity::setLocalScale(const glm::vec3& scale)
{
    m_scale = scale;
}

void CEntity::setLocalScale(f32 x, f32 y, f32 z)
{
    m_scale = glm::vec3(x, y, z);
}

void CEntity::setLocalScale(f32 uniform)
{
    m_scale = glm::vec3(uniform);
}

void CEntity::setLocalYaw(f32 angle)
{
    m_rotation = glm::rotate(m_rotation, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
}

void CEntity::beginPlay()
{
}

void CEntity::endPlay()
{
}

void CEntity::tick(f32 deltaTime)
{
}
