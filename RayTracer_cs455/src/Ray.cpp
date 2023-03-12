#include "Ray.h"

[[nodiscard]] glm::vec3 Ray::at(float t) const
{
    return (t * direction) + origin;
}

[[nodiscard]] glm::vec3 Ray::getOrigin() const
{
    return origin;
}

[[nodiscard]] glm::vec3 Ray::getDirection() const
{
    return direction;
}

glm::vec3 Ray::offsetInDir(glm::vec3 point)
{
    constexpr float offset = .001f;
    return point + direction * offset;
}
