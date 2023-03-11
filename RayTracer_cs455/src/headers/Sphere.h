#pragma once
#include <glm/vec3.hpp>

#include "SceneObject.h"

struct Sphere : SceneObject
{
    const glm::vec3 center{};
    const float radius{};

    Sphere( const glm::vec3& center, float radius, Material sphereMaterial)
        : SceneObject(sphereMaterial),
          center(center),
          radius(radius)
    {}

    float intersect(std::shared_ptr<Ray> r) override;
    glm::vec3 getNormal(glm::vec3 point) override;
};
