#pragma once
#include <glm/vec3.hpp>

#include "SceneObject.h"

struct Sphere : SceneObject
{
    const glm::vec3 center{};
    const float radius{};
    
    const float coefDiffuse{};
    const float coefSpecular{};
    const float coefAmbient{};

    const glm::vec3 diffuseColor{};
    const glm::vec3 specularColor{};

    const float glossiness{};

    Sphere(const glm::vec3& center, float radius, float coef_diffuse, float coef_specular, float coef_ambient,
        const glm::vec3& diffuse_color, const glm::vec3& specular_color, float glossiness)
        : center(center),
          radius(radius),
          coefDiffuse(coef_diffuse),
          coefSpecular(coef_specular),
          coefAmbient(coef_ambient),
          diffuseColor(diffuse_color),
          specularColor(specular_color),
          glossiness(glossiness)
    {}

    float intersect(std::shared_ptr<Ray> r) override;
    glm::vec3 getNormal(glm::vec3 point) override;
};
