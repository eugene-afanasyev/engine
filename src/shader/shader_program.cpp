#include "shader_program.h"

namespace snowflake::shader {

CShaderProgram::CShaderProgram(GLuint aId) : mId(aId) {}

void CShaderProgram::AttachShader(const CShader &aShader) noexcept {
    glAttachShader(mId, aShader.GetId());
}

void CShaderProgram::DetachShader(const CShader &aShader) noexcept {
    glDetachShader(mId, aShader.GetId());
}

GLuint CShaderProgram::GetId() const noexcept {
    return mId;
}

void CShaderProgram::SetId(GLuint aId) {
    mId = aId;
}

}  // namespace snowflake::shader

