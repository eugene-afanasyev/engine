#include "shader.h"
#include <iostream>

namespace snowflake::shader {

CShader::CShader(const ShaderSourceType& aSrc, GLenum aType) {
    mId = glCreateShader(aType);
    const char* raw_src = aSrc.c_str();

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

std::string CShader::GetInfoLog() const noexcept {
    std::string info_log;

    GLint info_log_length = 0;
    glGetShaderiv(mId, GL_INFO_LOG_LENGTH, &info_log_length);

    if (info_log_length > 0) {
        auto info_log_raw = new char[info_log_length];
        glGetShaderInfoLog(mId, info_log_length, nullptr, info_log_raw);

        info_log.append(info_log_raw);
    }

    return info_log;
}

}  // namespace snowflake::shader

