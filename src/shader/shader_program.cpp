#include "shader_program.h"

namespace snowflake::shader {

CShaderProgram::CShaderProgram(GLuint aId) : mId(aId) {}

void CShaderProgram::AttachShader(const CShader &aShader) const noexcept {
    glAttachShader(mId, aShader.GetId());
}

void CShaderProgram::DetachShader(const CShader &aShader) const noexcept {
    glDetachShader(mId, aShader.GetId());
}

GLuint CShaderProgram::GetId() const noexcept {
    return mId;
}

void CShaderProgram::SetId(GLuint aId) {
    mId = aId;
}

void CShaderProgram::Link() const noexcept {
    glLinkProgram(mId);
}

bool CShaderProgram::IsLinked() const noexcept {
    GLint is_linked = 0;
    glGetProgramiv(mId,  GL_LINK_STATUS, &is_linked);

    return is_linked;
}

std::string CShaderProgram::GetInfoLog() const noexcept {
    std::string info_log;

    GLint info_log_length = 0;
    glGetProgramiv(mId, GL_INFO_LOG_LENGTH, &info_log_length);

    if (info_log_length > 0) {
        auto info_log_raw = new char[info_log_length];
        glGetProgramInfoLog(mId, info_log_length, nullptr, info_log_raw);

        info_log.append(info_log_raw);
    }

    return info_log;
}

void CShaderProgram::Use() const noexcept {
    glUseProgram(mId);
}

}  // namespace snowflake::shader

