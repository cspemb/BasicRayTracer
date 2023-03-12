#pragma once
#include <glm/vec3.hpp>

#include "Material.h"
#include "Scene.h"

class LambertianMaterial : public Material
{
    glm::vec3 calculateDiffuse(const Scene& scene, glm::vec3 normal) const;
    glm::vec3 calculateSpecular(const Scene& scene, glm::vec3 normal, std::shared_ptr<Ray> r) const;
    glm::vec3 calculateAmbient(const Scene& scene) const;
    
public:
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

    glm::vec3 getColor(const Scene& scene, glm::vec3 normal, std::shared_ptr<Ray> r, bool isInShadow) override;
};
