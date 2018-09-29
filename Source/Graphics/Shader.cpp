/**
 * @file     Shader.cpp
 * @author   Ludvig Arlebrink
 * @date     9/17/2018
 */

#include "Shader.hpp"

#include <GLEW/glew.h>

using namespace gdt;
using namespace graphics;

uint32 CShader::m_sActiveProgramId = 0;

CShader::CShader()
    : m_status(core::EStatus::Success)
    , m_programId(0)
{
}

CShader::CShader(CShader&& other) noexcept
{
    m_status = other.m_status;
    m_programId = other.m_programId;

#if GDT_DEBUG
    m_errorString = other.m_errorString;
#endif

    other.m_programId = 0;
}

CShader::CShader(const std::string& vertexSource, const std::string& fragmentSource)
{
    compileProgram(vertexSource, "", fragmentSource);
}

CShader::CShader(const std::string& vertexSource, const std::string& geometrySource, const std::string& fragmentSource)
{
    compileProgram(vertexSource, geometrySource, fragmentSource);
}

CShader::~CShader()
{
    if (m_programId)
    {
        glDeleteProgram(m_programId);
    }
}

void CShader::compileProgram(const std::string& vertexSource, const std::string& fragmentSource)
{
    compileProgram(vertexSource, "", fragmentSource);
}

void CShader::compileProgram(const std::string& vertexSource, const std::string& geometrySource,
    const std::string fragmentSource)
{
    m_status = core::EStatus::Success;

    // Create shaders.
    uint32 vertex = glCreateShader(GL_VERTEX_SHADER);
    uint32 geometry = !geometrySource.empty() ? glCreateShader(GL_GEOMETRY_SHADER) : 0;
    uint32 fragment = glCreateShader(GL_FRAGMENT_SHADER);

    const char* vShaderCode = vertexSource.c_str();
    const char* gShaderCode = geometry ? geometrySource.c_str() : nullptr;
    const char* fShaderCode = fragmentSource.c_str();

    // Copy source.
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    if (geometry)
    {
        glShaderSource(geometry, 1, &gShaderCode, nullptr);
    }
    glShaderSource(fragment, 1, &fShaderCode, nullptr);

    // Compile shaders.
    glCompileShader(vertex);
    if (geometry)
    {
        glCompileShader(geometry);
    }
    glCompileShader(fragment);

    // Check for errors.
#if GDT_DEBUG
    m_errorString = "";
#endif
    checkShaderErrors(vertex, "Vertex");
    if (geometry)
    {
        checkShaderErrors(geometry, "Geometry");
    }
    checkShaderErrors(fragment, "Fragment");

    // Return if something went wrong.
    if (m_status == core::EStatus::Failure)
    {
        glDeleteShader(vertex);
        if (geometry)
        {
            glDeleteShader(geometry);
        }
        glDeleteShader(fragment);
        return;
    }

    // Create program and attach shaders.
    uint32 programId = glCreateProgram();
    glAttachShader(programId, vertex);
    if (geometry)
    {
        glAttachShader(programId, geometry);
    }
    glAttachShader(programId, fragment);

    // Link the program and check for errors.
    glLinkProgram(programId);
    checkProgramErrors(programId);

    // Shaders are no attached to the program and no longer needed.
    glDeleteShader(vertex);
    if (geometry)
    {
        glDeleteShader(geometry);
    }
    glDeleteShader(fragment);

    // Associate the program id with this class if 'Success', else delete the program.
    if (m_status == core::EStatus::Success)
    {
        m_programId = programId;
    }
    else
    {
        glDeleteProgram(programId);
    }
}

std::string CShader::getErrorString() const
{
#if GDT_DEBUG
    return m_errorString;
#else
    return "";
#endif
}

core::EStatus CShader::getStatus() const
{
    return m_status;
}

void CShader::setBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(m_programId, name.c_str()), static_cast<int32>(value));
}

void CShader::setFloat(const std::string& name, f32 value) const
{
    glUniform1f(glGetUniformLocation(m_programId, name.c_str()), value);
}

void CShader::setInt(const std::string& name, int32 value) const
{
    glUniform1i(glGetUniformLocation(m_programId, name.c_str()), value);
}

void CShader::setMat2(const std::string& name, const glm::mat2& value) const
{
    glUniformMatrix2fv(glGetUniformLocation(m_programId, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

void CShader::setMat3(const std::string& name, const glm::mat3& value) const
{
    glUniformMatrix3fv(glGetUniformLocation(m_programId, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

void CShader::setMat4(const std::string& name, const glm::mat4& value) const
{
    glUniformMatrix4fv(glGetUniformLocation(m_programId, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

void CShader::setVec2(const std::string& name, const glm::vec2& value) const
{
    glUniform2fv(glGetUniformLocation(m_programId, name.c_str()), 1, &value[0]);
}

void CShader::setVec3(const std::string& name, const glm::vec3& value) const
{
    glUniform3fv(glGetUniformLocation(m_programId, name.c_str()), 1, &value[0]);
}

void CShader::setVec4(const std::string& name, const glm::vec4& value) const
{
    glUniform4fv(glGetUniformLocation(m_programId, name.c_str()), 1, &value[0]);
}

void CShader::use() const
{
    if (m_programId > 0 && m_programId != m_sActiveProgramId)
    {
        glUseProgram(m_programId);
        m_sActiveProgramId = m_programId;
    }
}

void CShader::checkShaderErrors(uint32 shaderId, const std::string& type)
{
    int32 success = 0;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if (m_status == core::EStatus::Success && !success)
    {
        m_status = core::EStatus::Failure;
    }

#if GDT_DEBUG
    if (!success)
    {
        char infoLog[1024] = { '\0' };
        glGetShaderInfoLog(shaderId, 1024, nullptr, infoLog);
        m_errorString.append("SHADER ERROR:: " + type + " shader.\n");
        m_errorString.append("INFO:: ");
        m_errorString.append(infoLog);
        m_errorString.append("\n\n****************************************\n\n");
    }
#endif
}

void CShader::checkProgramErrors(uint32 programId)
{
    int32 success = 0;
    glGetProgramiv(programId, GL_LINK_STATUS, &success);
    if (m_status == core::EStatus::Success && !success)
    {
        m_status = core::EStatus::Failure;
    }

#if GDT_DEBUG
    if (!success)
    {
        char infoLog[1024] = { '\0' };
        glGetProgramInfoLog(programId, 1024, nullptr, infoLog);
        m_errorString.append("SHADER PROGRAM ERROR:: ");
        m_errorString.append(infoLog);
        m_errorString.append("\n\n****************************************\n\n");
    }
#endif
}
