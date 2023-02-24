#include "Camera.h"

#include <memory>

std::shared_ptr<Ray> Camera::getRay(float i, float j) const
{
    return std::make_shared<Ray>(position, minPlane + i * horizontal + j * vertical - position);
}

const glm::vec3& Camera::getPosition() const
{
    return position;
}

[[nodiscard]] const glm::vec3& Camera::getHorizontal() const
{
    return horizontal;
}

[[nodiscard]] const glm::vec3& Camera::getVertical() const
{
    return vertical;
}

[[nodiscard]] const glm::vec3& Camera::getMinPlane() const
{
    return minPlane;
}