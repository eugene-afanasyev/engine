#ifndef SNOWFLAKE_SHADER_H
#define SNOWFLAKE_SHADER_H

#include "glad/glad.h"

#include <memory>
#include <array>

namespace snowflake::shader {

using ShaderSourceType = std::string;

class CShader {
 public:
    CShader() = delete;
    CShader(const ShaderSourceType& aSrc, GLenum aType);
    CShader(const char* aSrc, GLenum aType);

    void Compile() const;
    void Delete() const;

    [[nodiscard]] GLenum GetType()    const noexcept;
    [[nodiscard]] GLuint GetId()      const noexcept;

    [[nodiscard]] bool IsCompiled() const noexcept;

 private:
    GLuint mId;
};

}  // namespace snowflake::shader

#endif  // SNOWFLAKE_SHADER_H
