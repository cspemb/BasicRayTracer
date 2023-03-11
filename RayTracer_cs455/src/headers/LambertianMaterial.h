#pragma once
#include <glm/vec3.hpp>

#include "Material.h"
#include "Scene.h"

struct LambertianMaterial : Material
{
    const float coefDiffuse{};
    const float coefSpecular{};
    const float coefAmbient{};

    const glm::vec3 diffuseColor{};
    const glm::vec3 specularColor{};

    const float glossiness{};
    
    LambertianMaterial(float coef_diffuse, float coef_specular, float coef_ambient,
        const glm::vec3& diffuse_color, const glm::vec3& specular_color, const float glossiness)
        : coefDiffuse(coef_diffuse),
          coefSpecular(coef_specular),
          coefAmbient(coef_ambient),
          diffuseColor(diffuse_color),
          specularColor(specular_color),
          glossiness(glossiness)
    {}
};
