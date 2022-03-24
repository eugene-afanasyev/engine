#include "shader.h"

namespace snowflake::shader {

CShader::CShader(const ShaderSourceType& aSrc, GLenum aType) {
    mId = glCreateShader(aType);

    auto raw_src = new char[aSrc.size()];
    aSrc.copy(raw_src, aSrc.size());

    glShaderSource(mId, 1, &raw_src, nullptr);
}

CShader::CShader(const char* aSrc, GLenum aType) {
    mId = glCreateShader(aType);
    glShaderSource(mId, 1, &aSrc, nullptr);
}

void CShader::Compile() const {
    glCompileShader(mId);
}

void CShader::Delete() const {
    glDeleteShader(mId);
}

GLenum CShader::GetType() const noexcept {
    GLint type;
    glGetShaderiv(mId, GL_SHADER_TYPE, &type);

    return type;
}

bool CShader::IsCompiled() const noexcept {
    int shader_status_compiled;
    glGetShaderiv(mId, GL_COMPILE_STATUS, &shader_status_compiled);

    return shader_status_compiled == GL_TRUE;
}

GLuint CShader::GetId() const noexcept {
    return mId;
}

}  // namespace snowflake::shader

