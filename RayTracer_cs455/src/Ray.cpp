#include "Ray.h"

[[nodiscard]] glm::vec3 Ray::at(float t) const
{
    return (t * direction) + origin;
}