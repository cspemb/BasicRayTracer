#pragma once
#include <glm/vec3.hpp>

class Ray
{
    glm::vec3 origin{};
    glm::vec3 direction{};
    
public:
    Ray(const glm::vec3& origin, const glm::vec3& direction)
        : origin(origin),
          direction(direction)
    {}

    [[nodiscard]] glm::vec3 at(float t) const;
};
