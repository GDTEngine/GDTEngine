/**
 * @file     Shader.hpp
 * @author   Ludvig Arlebrink
 * @date     9/17/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "Status.hpp"

#include <GLM/glm.hpp>
#include <string>

namespace gdt
{
    /**
     * @breif Shader program wrapper.
     */
    class CShader final
    {
    public:

        /**
         * @breif Default constructor. 
         */
        CShader();

        /**
         * @breif Copy constructor deleted.
         */
        CShader(const CShader& other) = delete;

        /**
         * @breif Move constructor.
         * @param other Object to be moved.
         */
        CShader(CShader&& other) noexcept;

        /**
         * @breif Compile a shader from source glsl code.
         * @param vertexSource Vertex shader source code.
         * @param fragmentSource Vertex shader source code.
         *
         * After compiling check for errors like the following.
         * @code
         * CShader shader;
         * shader.compile(vsSource, fsSource);
         * EStatus status = shader.getStatus();
         * if (status == EStatus::Failure)
         * {
         *     // This will only work in debug mode.
         *     LOG(shader.getErrorString());
         * }
         * @endcode
         */
        CShader(const std::string& vertexSource, const std::string& fragmentSource);

        /**
         * @breif Compile a shader from source glsl code.
         * @param vertexSource Vertex shader source code.
         * @param fragmentSource Vertex shader source code.
         *
         * After compiling check for errors like the following.
         * @code
         * CShader shader;
         * shader.compile(vsSource, gsSource, fsSource);
         * EStatus status = shader.getStatus();
         * if (status == EStatus::Failure)
         * {
         *     // This will only work in debug mode.
         *     LOG(shader.getErrorString());
         * }
         * @endcode
         */
        CShader(const std::string& vertexSource, const std::string& geometrySource, const std::string& fragmentSource);

        /**
         * @breif Destructor.
         */
        ~CShader();

        /**
         * @breif Assignment operator deleted.
         */
        void operator=(const CShader& rhs) = delete;

        /**
         * @breif Compile a shader from source glsl code.
         * @param vertexSource Vertex shader source code.
         * @param fragmentSource Vertex shader source code.
         * 
         * After compiling check for errors like the following.
         * @code
         * CShader shader;
         * shader.compile(vsSource, fsSource);
         * EStatus status = shader.getStatus();
         * if (status == EStatus::Failure)
         * {
         *     // This will only work in debug mode.
         *     LOG(shader.getErrorString());
         * }
         * @endcode
         */
        void compileProgram(const std::string& vertexSource, const std::string& fragmentSource);

        /**
         * @breif Compile a shader from source glsl code.
         * @param vertexSource Vertex shader source code.
         * @param fragmentSource Vertex shader source code.
         *
         * After compiling check for errors like the following.
         * @code
         * CShader shader;
         * shader.compile(vsSource, gsSource, fsSource);
         * EStatus status = shader.getStatus();
         * if (status == EStatus::Failure)
         * {
         *     // This will only work in debug mode.
         *     LOG(shader.getErrorString());
         * }
         * @endcode
         */
        void compileProgram(const std::string& vertexSource, const std::string& geometrySource, const std::string fragmentSource);

        /**
         * @breif Get a string of errors.
         * @return String of errors.
         * @note Only works in debug mode.
         * 
         * Check 'EStatus' by calling 'getStatus'. If EStatus is equals to 'Failure', call this class to get more information.
         */
        std::string getErrorString() const;

        /**
         * @breif Check if everything regarding shader compelation went right.
         * @return 'Success' if everything went right.
         * 
         * Call 'getErrorString' to get more information about the errors.
         */
        EStatus getStatus() const;

        /**
         * @breif Set a **'bool'** uniform.
         * @param name Name of the uniform.
         * @param value Value of uniform.
         */
        void setBool(const std::string& name, bool value) const;

        /**
         * @breif Set a **'float'** uniform.
         * @param name Name of the uniform.
         * @param value Value of uniform.
         */
        void setFloat(const std::string& name, f32 value) const;

        /**
         * @breif Set a **'int'** uniform.
         * @param name Name of the uniform.
         * @param value Value of uniform.
         */
        void setInt(const std::string& name, int32 value) const;
        /**
         * @breif Set a **'mat2'** uniform.
         * @param name Name of the uniform.
         * @param value Value of uniform.
         */
        void setMat2(const std::string& name, const glm::mat2& value) const;

        /**
         * @breif Set a **'mat3'** uniform.
         * @param name Name of the uniform.
         * @param value Value of uniform.
         */
        void setMat3(const std::string& name, const glm::mat3& value) const;

        /**
         * @breif Set a **'mat4'** uniform.
         * @param name Name of the uniform.
         * @param value Value of uniform.
         */
        void setMat4(const std::string& name, const glm::mat4& value) const;

        /**
         * @breif Set a **'vec2'** uniform.
         * @param name Name of the uniform.
         * @param value Value of uniform.
         */
        void setVec2(const std::string& name, const glm::vec2& value) const;

        /**
         * @breif Set a **'vec3'** uniform.
         * @param name Name of the uniform.
         * @param value Value of uniform.
         */
        void setVec3(const std::string& name, const glm::vec3& value) const;

        /**
         * @breif Set a 'vec4' uniform.
         * @param name Name of the uniform.
         * @param value Value of uniform.
         */
        void setVec4(const std::string& name, const glm::vec4& value) const;

        /**
         * @breif Use this shader program.
         */
        void use() const;

    private:

        void checkShaderErrors(uint32 shaderId, const std::string& type);

        void checkProgramErrors(uint32 programId);

    private:

        EStatus m_status;
        
        static uint32 m_sActiveProgramId;
        uint32 m_programId;

    #if GDT_DEBUG
        std::string m_errorString;
    #endif
    };
}