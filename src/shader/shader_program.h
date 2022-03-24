#ifndef SNOWFLAKE_SHADER_PROGRAM_H
#define SNOWFLAKE_SHADER_PROGRAM_H

#include "shader.h"

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

    [[nodiscard]] GLuint GetId() const noexcept;
    void SetId(GLuint);

 private:
    GLuint mId;
};

}  // namespace snowflake::shader

#endif  // SNOWFLAKE_SHADER_PROGRAM_H
