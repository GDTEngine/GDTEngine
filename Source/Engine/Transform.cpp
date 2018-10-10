/**
 * @file     Transform.hpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#include "Transform.hpp"

using namespace gdt;
using namespace engine;

CTransform::CTransform()
{
}

CTransform::~CTransform()
{
}

f32 CTransform::getPitch() const
{
    return glm::degrees(glm::pitch(m_rotation));
}

glm::vec3 CTransform::getPosition() const
{
    return m_position;
}

f32 CTransform::getRoll() const
{
    return glm::degrees(glm::roll(m_rotation));
}

glm::quat CTransform::getRotation() const
{
    return m_rotation;
}

glm::vec3 CTransform::getScale() const
{
    return m_scale;
}

f32 CTransform::getYaw() const
{
    return glm::degrees(glm::yaw(m_rotation));
}

void CTransform::setPitch(f32 angle)
{
    m_rotation = glm::rotate(m_rotation, glm::radians(angle), glm::vec3(1.0f, 0.0f, 0.0f));
}

void CTransform::setPosition(const glm::vec3& position)
{
    m_position = position;
}

void CTransform::setPosition(f32 x, f32 y, f32 z)
{
    m_position = glm::vec3(x, y, z);
}

void CTransform::setRoll(f32 angle)
{
    m_rotation = glm::rotate(m_rotation, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
}

void CTransform::setRotation(const glm::quat& rotation)
{
    m_rotation = rotation;
}

void CTransform::setScale(const glm::vec3& scale)
{
    m_scale = scale;
}

void CTransform::setScale(f32 x, f32 y, f32 z)
{
    m_scale = glm::vec3(x, y, z);
}

void CTransform::setYaw(f32 angle)
{
    m_rotation = glm::rotate(m_rotation, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
}
