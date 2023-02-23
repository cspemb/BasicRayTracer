#pragma once
#include <memory>
#include <glm/vec3.hpp>

#include "Ray.h"

struct SceneObject
{
    const float coefDiffuse{};
    const float coefSpecular{};
    const float coefAmbient{};

    const glm::vec3 diffuseColor{};
    const glm::vec3 specularColor{};

    const float glossiness{};

    SceneObject(float coef_diffuse, float coef_specular, float coef_ambient,
        const glm::vec3& diffuse_color, const glm::vec3& specular_color, float glossiness)
        : coefDiffuse(coef_diffuse),
          coefSpecular(coef_specular),
          coefAmbient(coef_ambient),
          diffuseColor(diffuse_color),
          specularColor(specular_color),
          glossiness(glossiness)
    {
    }

    virtual ~SceneObject() = default;
    virtual float intersect(std::shared_ptr<Ray> r) = 0;
    virtual glm::vec3 getNormal(glm::vec3 point) = 0;
    
};
