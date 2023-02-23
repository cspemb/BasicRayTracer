#pragma once
#include <glm/vec3.hpp>

#include "SceneObject.h"

struct Sphere : SceneObject
{
    const glm::vec3 center{};
    const float radius{};

    Sphere( const glm::vec3& center, float radius, float coef_diffuse, float coef_specular, float coef_ambient, const glm::vec3& diffuse_color,
        const glm::vec3& specular_color, float glossiness)
        : SceneObject(coef_diffuse, coef_specular, coef_ambient, diffuse_color, specular_color, glossiness),
          center(center),
          radius(radius)
    {}

    float intersect(std::shared_ptr<Ray> r) override;
    glm::vec3 getNormal(glm::vec3 point) override;
};
