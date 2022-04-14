#ifndef engine_camera_h
#define engine_camera_h

#include "type.h"

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

namespace snowflake {

class CCamera;

class CCamera {
 public:
    CCamera();

    const vec3& GetTarget() const;
    const vec3& GetPosition() const;
    const vec3& GetFront() const;
    const vec3& GetUp() const;

    const mat4& GetView() const;
    const mat4& GetCurrentView();

    void Move(const vec3& aVec);

    void SetTarget(const vec3& aTarget);
    void SetPosition(const vec3& aPos);

 private:
    vec3 mPosition;
    vec3 mTarget;
    vec3 mFront;
    vec3 mUp;

    mat4 mView;
};

}  // namespace engine

#endif  // engine_camera_h
