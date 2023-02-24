#pragma once
#include <glm/vec3.hpp>
#include <glm/glm.hpp>

class Ray
{
    const glm::vec3 origin{};
    const glm::vec3 direction{};
    
public:
    Ray(const glm::vec3 origin, const glm::vec3& direction)
        : origin(origin),
          direction(normalize(direction))
    {}

    [[nodiscard]] glm::vec3 at(float t) const;
    [[nodiscard]] glm::vec3 getOrigin() const;
    [[nodiscard]] glm::vec3 getDirection() const;
};
