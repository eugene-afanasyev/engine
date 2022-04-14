#include "camera.h"

#include <glm/geometric.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace snowflake {

CCamera::CCamera() {
    mPosition = vec3(0.0f);
    mTarget = vec3(0.0f, 0.0f, 0.0f);
    mFront = vec3(0.0f, 0.0f, -1.0f);
    auto right = glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), mFront));
    mUp = glm::cross(mPosition + mFront, right);
    mView = glm::lookAt(mPosition, mPosition + mFront, mUp);
}

void CCamera::SetTarget(const vec3& aTarget) {
    mTarget = aTarget;
}

const vec3& CCamera::GetTarget() const {
    return mTarget;
}

const vec3& CCamera::GetPosition() const {
    return mPosition;
}

const mat4& CCamera::GetView() const {
    return mView;
}

const mat4& CCamera::GetCurrentView() {
    return mView = glm::lookAt(mPosition, mPosition + mFront, mUp);
}

void CCamera::SetPosition(const vec3 &aPos) {
    mPosition = aPos;
}

void CCamera::Move(const vec3 &aVec) {
    mPosition += aVec;
}

const vec3 &CCamera::GetFront() const {
    return mFront;
}

const vec3 &CCamera::GetUp() const {
    return mUp;
}

}  // namespace snowflake
