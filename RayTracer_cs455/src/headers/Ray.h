#pragma once
#include <glm/vec3.hpp>
#include <glm/glm.hpp>

class Ray
{
    glm::vec3 origin{};
    const glm::vec3 direction{};
    
    glm::vec3 offsetInDir(glm::vec3 origin);
    
public:
    Ray(const glm::vec3 origin, const glm::vec3& direction, bool isOffsetInDir = false)
        : direction(normalize(direction))
    {
        this->origin = isOffsetInDir ? offsetInDir(origin) : origin;
    }

    [[nodiscard]] glm::vec3 at(float t) const;
    [[nodiscard]] glm::vec3 getOrigin() const;
    [[nodiscard]] glm::vec3 getDirection() const;

};
