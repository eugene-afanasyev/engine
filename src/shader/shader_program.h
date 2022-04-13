#ifndef SNOWFLAKE_SHADER_PROGRAM_H
#define SNOWFLAKE_SHADER_PROGRAM_H

#include "shader.h"

#include <glm/mat4x4.hpp>

namespace snowflake::shader {

class CShaderProgram {
 public:
    CShaderProgram() = delete;
    explicit CShaderProgram(GLuint = 0);

    CShaderProgram(const CShaderProgram&) = delete;
    CShaderProgram& operator=(const CShaderProgram&) = delete;

    ~CShaderProgram() = default;

    void AttachShader(const CShader&) const noexcept;
    void DetachShader(const CShader&) const noexcept;

    void Link() const noexcept;

    void Use() const noexcept;

    bool IsLinked() const noexcept;

    std::string GetInfoLog() const noexcept;

    GLuint GetId() const noexcept;
    void SetId(GLuint);

    void SetUniformMat4(const char* aName, const glm::mat4& aMatrix, GLsizei aCount = 1) const;
    void SetUniformInt(const char* aName, GLint aVal) const;

 private:
    GLuint mId;
};

}  // namespace snowflake::shader

#endif  // SNOWFLAKE_SHADER_PROGRAM_H
