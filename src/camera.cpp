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

    mYaw = -90.0f;
    mPitch = 0.0f;
    mRotationSens = 0.1f;
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

void CCamera::Rotate(double aYaw, double aPitch) {
    mYaw += aYaw;
    mPitch += aPitch;

    if(mPitch > 89.0f)
        mPitch =  89.0f;
    if(mPitch < -89.0f)
        mPitch = -89.0f;

    vec3 front;

    front.x = glm::cos(glm::radians(mYaw)) * glm::cos(glm::radians(mPitch));
    front.y = glm::sin(glm::radians(mPitch));
    front.z = glm::sin(glm::radians(mYaw)) * glm::cos(glm::radians(mPitch));

    mFront = glm::normalize(front);
}

double CCamera::GetRotationSens() const {
    return mRotationSens;
}

}  // namespace snowflake
