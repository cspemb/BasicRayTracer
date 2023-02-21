#pragma once
#include <glm/vec3.hpp>

class Ray
{
    const glm::vec3& origin{};
    const glm::vec3& direction{};
    
public:
    Ray(const glm::vec3& origin, const glm::vec3& direction)
        : origin(origin),
          direction(direction)
    {}

    [[nodiscard]] glm::vec3 at(float t) const;
    [[nodiscard]] const glm::vec3& getOrigin() const;
    [[nodiscard]] const glm::vec3& getDirection() const;
};
